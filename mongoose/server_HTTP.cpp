#define MG_ENABLE_HTTP_STREAMING_MULTIPART 1
#include "mongoose.h"
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <stdio.h>
#include <iostream>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

using namespace std;

static const char *s_http_port = "8000";
static struct mg_serve_http_opts s_http_server_opts;
struct timeval start;

static void handle_search(struct mg_connection *nc, struct http_message *hm , SocketDatagrama *s) {
		char query[256]="No se encontro ningun servicio\0",ip[16];
		int i,r,espera,segundos,usegundos;
		unsigned char s_addr[4];
		struct timeval end,final,tiempo,tiempo2;
		PaqueteDatagrama recibe( sizeof(int) );
		string aux="";
		gettimeofday(&tiempo,NULL);
		while( espera < 5000 ){
			r = s->recibeTimeout(recibe,0,500000);
			gettimeofday(&end, NULL);
			if( r != -1 ){
				final.tv_sec = end.tv_sec - start.tv_sec;
				final.tv_usec = end.tv_usec - start.tv_usec;
				sprintf(query, "Servidor: %s tiempo de respuesta: %d.%d s </br>",
						recibe.obtieneDireccion() , final.tv_sec , final.tv_usec);
				aux += string(query);
			}
			gettimeofday(&tiempo2,NULL);
			segundos = tiempo2.tv_sec - tiempo.tv_sec;
			usegundos = tiempo2.tv_usec - tiempo.tv_usec;
			espera = ((segundos) * 1000 + usegundos/1000 );
		}
		mg_send_head( nc , 200 , aux.length(), "Content-Type: text/html");
		mg_printf( nc, "%s", aux.c_str() );
}

static void ev_handler(struct mg_connection *nc, int ev, void *p) {
	SocketDatagrama s(0);
	char query[256];
	int numeros[2]={5,5};
 	struct http_message *hm = (struct http_message *) p;

	if (ev == MG_EV_HTTP_REQUEST) {
		if (mg_vcmp(&hm->uri, "/search") == 0) {
			if( !s.setBroadcast() )
				printf("Socket configurado en Broadcast\n");
			mg_get_http_var(&hm->body, "query", query,sizeof(query));
			printf("IP Multicast: %s\n",query);
			PaqueteDatagrama enviar( (char*)numeros, sizeof(numeros) , query , 7200 );
			gettimeofday(&start, NULL);
			printf("Enviando mensaje\n");
			s.envia( enviar );
		    handle_search( nc, hm , &s );  
		}else{
			mg_serve_http(nc, (struct http_message *) p, s_http_server_opts);
		}
	}
}

int main(void) {
	struct mg_mgr mgr;
	struct mg_connection *nc;
	mg_mgr_init(&mgr, NULL);

	printf("Starting web server on port %s\n", s_http_port);
	nc = mg_bind(&mgr, s_http_port, ev_handler);
	if (nc == NULL) {
		printf("Failed to create listener\n");
		return 1;
	}
	// Set up HTTP server parameters
	mg_set_protocol_http_websocket(nc);
	s_http_server_opts.document_root = "www"; // Serve current directory
	s_http_server_opts.enable_directory_listing = "yes";
	for(;;){
		mg_mgr_poll(&mgr, 1000);
	}
	mg_mgr_free(&mgr);
	return 0;
}
