#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <thread>
#include <sys/time.h>
#include "mongoose.h"
#include "Respuesta.h"
#include "Solicitud.h"
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include "registro.h"
#include "trie.h"

using namespace std;

static const char *s_http_port = "8000";
static struct mg_serve_http_opts s_http_server_opts;
int ptoBroad;
char *ipBroad;
//PRI,PAN,PRD P_T,VDE,MVC,MOR,PES,PNL
int votos_partidos[9]={0,0,0,0,0,0,0,0,0};

void voto( char v );
void web_embedded( void );
static void ev_handler( struct mg_connection *nc, int ev, void *ev_data );
static void handle_info_votes(struct mg_connection *nc,SocketDatagrama *sd);
void info_votos( void );

int main( int argc , char *argv[] ){
    if( argc != 7 ){
        printf("Uso: %s ptoLocal IpTiempo PtoTiempo IpBroadcast PtoBroadcast  Nombre_Archivo \n" , argv[0]);
        exit(0);
    }
    int pto = atoi( argv[1] );
    ptoBroad = atoi( argv[5] );
    ipBroad = argv[4];
    Respuesta res( pto );
    Solicitud tiempo;
    struct mensaje datos;
    struct registro reg;
    struct timeval timestamp;
    struct TrieNode *trie = getNode();
    int archivo,ptoTime = atoi( argv[3] );
    string aux;
    thread th1( info_votos ), th2( web_embedded );

    printf("\n********** Servidor iniciado **********");
    printf("\nEsperando mensajes en el puerto: %d\n",pto);

    while(1){
        memcpy( &datos,res.getRequest( ),sizeof(datos) );
        if( res.getError() == 0 ){
            memcpy( &timestamp , tiempo.doOperation(argv[2],ptoTime,0,(char*)&timestamp) , sizeof(timestamp) );
            memcpy( &reg , datos.arguments , sizeof(datos.arguments) );
            if ( !search( trie , string(reg.celular) ) ){
                insert( trie , string(reg.celular) );
                printf("Registro exitoso  \nCel: %s\n",reg.celular);
                printf("CURP: %s\n",reg.CURP);
                printf("Partido: %s\n",reg.partido);
                printf("timestamp: %ld - %ld \n\n",timestamp.tv_sec,timestamp.tv_usec);
                voto( reg.partido[2]  );
                aux = reg.toString() + " " 
                    + to_string(timestamp.tv_sec) + "-" 
                    + to_string(timestamp.tv_usec) +  "\n";
                if( ( archivo = open(argv[6], O_WRONLY|O_CREAT|O_APPEND,0666) ) == -1 )
                    perror(argv[6]);
	            write( archivo , aux.c_str() , aux.length() );
	            fsync( archivo );
                close( archivo );
            }
            else{
                timestamp.tv_sec = 0;
                timestamp.tv_usec = 0;
            }
        }
        res.sendReply( (char*)&timestamp );
    }
    th1.join(); th2.join();
    return 0;
}

void voto( char v ){
    switch( v ){
        case 'I': //PRI
            votos_partidos[0]++;
            break; 
        case 'N': //PAN
            votos_partidos[1]++;
            break;
        case 'D': //PRD 
            votos_partidos[2]++;
            break;
        case 'T': //P_T
            votos_partidos[3]++;
            break;
        case 'E': //VDE
            votos_partidos[4]++;
            break;
        case 'C': //MVC
            votos_partidos[5]++;
            break;
        case 'R': //MOR
            votos_partidos[6]++;
            break;
        case 'S': //PES
            votos_partidos[7]++;
            break; 
        case 'L': //PNL
            votos_partidos[8]++;
            break;
        default:   
            break;
    }   
}

void web_embedded( void ){
    struct mg_mgr mgr;          //Event manager
    struct mg_connection *nc;   //Mongoose conection
    cs_stat_t st;

	mg_mgr_init(&mgr, NULL);

	printf("Starting web server on port %s\n", s_http_port);
	nc = mg_bind(&mgr, s_http_port, ev_handler);
	if (nc == NULL) {
		printf("Failed to create listener\n");
		exit(1);
	}
	// Set up HTTP server parameters
	mg_set_protocol_http_websocket( nc );
	s_http_server_opts.document_root = "web_root"; // Serve current directory
	s_http_server_opts.enable_directory_listing = "yes";
	while( 1 ){
        mg_mgr_poll(&mgr, 1000);
    }
	mg_mgr_free(&mgr);
}

static void ev_handler(struct mg_connection *nc, int ev, void *ev_data) {
    struct http_message *hm = (struct http_message *) ev_data;
    if( ev == MG_EV_HTTP_REQUEST ){
        SocketDatagrama sd(0);
        if( sd.setBroadcast() == -1 )
            printf("Error configurando el socket en Broadcast\n");
        if (mg_vcmp(&hm->uri, "/get_votes") == 0)
            handle_info_votes(nc,&sd);
        else
            mg_serve_http(nc, hm, s_http_server_opts);  // Server static content
    }
}

static void handle_info_votes(struct mg_connection *nc,SocketDatagrama *sd) {
    int votos[9]={0,0,0,0,0,0,0,0,0},aux[9],i,s=0,c=0;
    char a = 1 , json[250];
    PaqueteDatagrama env( &a , sizeof(a) , ipBroad , ptoBroad );
    PaqueteDatagrama recibe( sizeof(votos) );
    string servidores = "";
    sd->envia(env);
    while ( s < 10 ){    
        if( sd->recibeTimeout( recibe , 0 , 200000 ) != -1 ){
            c++;
            memcpy( aux , recibe.obtieneDatos() , sizeof(aux) );
            for( i = 0 ; i < 9 ; i++)
                votos[i] += aux[i];
            servidores += string( recibe.obtieneDireccion() ) + "</br>";
        }
        s++;
    }
    // Use chunked encoding in order to avoid calculating Content-Length
    mg_printf(nc, "%s", "HTTP/1.1 200 OK\r\nTransfer-Encoding: chunked\r\n\r\n");
    mg_printf_http_chunk( nc, "{\"votos\":{\"PRI\":%d,\"PAN\":%d,\"PRD\":%d,\"P_T\":%d,\"VDE\":%d,\"MVC\":%d,\"MOR\":%d,\"PES\":%d,\"PNL\":%d,\"IPS\":\"%s\"}}", 
                          votos[0],votos[1],votos[2],votos[3],votos[4],votos[5],votos[6],votos[7],votos[8] , servidores.c_str() );
    // Send empty chunk, the end of response
    mg_send_http_chunk(nc, "", 0);
}

void info_votos( void ){
    int i;
    SocketDatagrama sock( ptoBroad );
    PaqueteDatagrama recibe( sizeof(char) );
    while( 1 ){
        sock.recibe( recibe );
        PaqueteDatagrama envia( (char*)votos_partidos , sizeof(votos_partidos) , recibe.obtieneDireccion() , recibe.obtienePuerto() );
        sock.envia( envia );
    }
}
