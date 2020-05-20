#define MG_ENABLE_HTTP_STREAMING_MULTIPART 1
#include "mongoose.h"
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


static void handle_search(struct mg_connection *nc, struct http_message *hm) {
		char query[256],ip[16];
		unsigned char s_addr[4];
		struct sockaddr_in msg_to_server_addr, client_addr;
   		int s, num[2], res,i;
		struct timeval start,end,final;

		mg_get_http_var(&hm->body, "query", ip, sizeof(ip));
		
		s = socket(AF_INET, SOCK_DGRAM, 0);
   		/* rellena la dirección del servidor */
   		bzero( (char *)&msg_to_server_addr, sizeof(msg_to_server_addr) );
   		msg_to_server_addr.sin_family = AF_INET;
   		msg_to_server_addr.sin_addr.s_addr = inet_addr( ip );
		msg_to_server_addr.sin_port = htons( 7200 );
		/* rellena la direcciòn del cliente*/
		bzero((char *)&client_addr, sizeof(client_addr));
   		client_addr.sin_family = AF_INET;
   		client_addr.sin_addr.s_addr = INADDR_ANY;
		client_addr.sin_port = htons(0); //El sistema asigna el puerto
   		bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));

		num[0] = 2;
   		num[1] = 5; /*rellena el mensaje */
		gettimeofday(&start, NULL);
   		sendto(s, (char *)num, 2*sizeof(int), 0, (struct sockaddr*)&msg_to_server_addr, sizeof(msg_to_server_addr));
   
   		/* se bloquea esperando respuesta */
   		recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);
		gettimeofday(&end, NULL);
		memcpy(s_addr,&msg_to_server_addr.sin_addr.s_addr,4);
		final.tv_sec = end.tv_sec - start.tv_sec;
		final.tv_usec = end.tv_usec - start.tv_usec;
		sprintf(query, "Servidor: %d.%d.%d.%d tiempo de respuesta: %d.%d s ",
		         s_addr[0],s_addr[1],s_addr[2],s_addr[3],final.tv_sec,final.tv_usec );
		printf("Cadena enviada: %s\n", query);

		mg_send_head(nc,200,strlen(query), "Content-Type: text/plain");
		mg_printf(nc, "%s", query);
}

static void ev_handler(struct mg_connection *nc, int ev, void *p) {
	char query[256];
 	struct http_message *hm = (struct http_message *) p;

	if (ev == MG_EV_HTTP_REQUEST) {
		if (mg_vcmp(&hm->uri, "/search") == 0) { 
			mg_get_http_var(&hm->body, "query", query,sizeof(query));
			printf("IP Multicast: %s\n",query);

		    handle_search(nc, hm);  
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
