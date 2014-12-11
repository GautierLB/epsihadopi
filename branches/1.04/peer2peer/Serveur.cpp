#include "stdafx.h"
#include <iostream>
#include "CSocketIp4.h"
#include "CException.h"
#include "ConfigurationInterne.h"
#include "Serveur.h"

void *LancementServeur(void* ip) {
	int c;
	std::string* ipfinal=(std::string*)ip;
	Serveur();
	return nullptr;
}

void LancementServeur() {
	pthread_t t1;
	void *result = nullptr;

	std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	std::cout << "** Creating thread..." << std::endl;
	if (pthread_create( &t1, 0, LancementServeur, ((void*)0)) != 0) {
		std::cerr << "** FAIL 1" << std::endl;
		return;
	}
	else {
		std::cout << "** Thread 1 creation OK" << std::endl;
	}

	std::cout << "** Waiting..." << std::endl;
	//pthread_join( t1, &result );
	return;
}
void Serveur() {
		CSocket::initEngine();
		CSocketIp4 s, *remoteClient = nullptr;

	std::cout << std::endl;
	std::cout << "Creating HTTP server on port 666..." << std::endl;
	ConfigurationInterne* config= ConfigurationInterne::getInstance();
	s.server( 6699, 5 );
	for (;;) {
		std::string data, request;
		int recvCount = 0;
		char buffer[ 1024 ];


		std::cout << "Waiting for connections..." << std::endl;
		remoteClient = dynamic_cast<CSocketIp4 *>(s.accept());

		std::cout << "Accepted incoming connection from " << remoteClient->getRemoteEndpointIp() << " on port " << remoteClient->getRemoteEndpointPort() << std::endl;

		// Receive whole response with 100ms timeout
		// !! WARNING !! a nicer way to handle this request is to check for end-of-request instead of foolishly wait for 100ms
		std::cout << "- receiving its request..." << std::endl;
		request = "";
		do {
			memset( buffer, 0, sizeof( buffer ) );
			try {
				recvCount = remoteClient->recv( buffer, sizeof( buffer ), NO_TIMEOUT );
				request += buffer;
			}
			catch (CBrokenSocketException) {
				std::cout << "Connection closed by remote host..." << std::endl;
				recvCount = 0;
			}
		} while (recvCount > 0 && remoteClient->waitForRead( 100 ) != SOCKET_TIMEOUT);
		std::cout << "Requete:" <<request << std::endl;
		// Send him the same information everytime
		// Oww! crap! No doctype ... and crappy headers too. but it works, so enjoy.
		std::cout << "- sending fake page..." << std::endl;

		data = "HTTP/1.1 200 OK\r\n"
			"Host: hello.it.s.me\r\n"
			"Server: my-server\r\n"
			"Content-type: text/html\r\n"
			"Connection: close\r\n"
			"\r\n"
			"<html>"
			"  <head>"
			"    <title>Hello from local HTTP server</title>"
			"    <style type='text/css'>h1 { color: navy; font-variant: small-caps; }</style>"
			"  </head>"
			"  <body>"
			"    <h1>You should know that ...</h1>"
			"    <ul>"
			"      <li>you just created your first HTTP server</li>"
			"      <li>your client uses IP address " + remoteClient->getRemoteEndpointIp() + "</li>"
			"    </ul>"
			"    <h1>Your client sends those headers</h1>"
			"    <pre>" + request + "</pre>"
			"  </body>"
			"</html>";
		
		
		if(request[2]=='4'){
			string chaine="115-EPSIHADOPY   100";
		char tt[22];

		for( int i=0;i<chaine.size();i++){
			tt[i]=chaine[i];

		}
		tt[chaine.size()]='\0';
		
		remoteClient->send( tt, static_cast<unsigned short>(strlen(tt)), NO_TIMEOUT );
		}
		//Renvoie tableau Fichier
		else if(request[2]=='6'){
			
			char tt[22];
		string chaine="117-"+config->getFichiers().size();
		if(config->getFichiers().size()!=0){
			string nomtemp=config->getNomFichierId(0);
			
		chaine+="Coucouc"+nomtemp;
		}
		

		for( int i=0;i<chaine.size();i++){
			tt[i]=chaine[i];

		}
		tt[chaine.size()]='\0';
		remoteClient->send( tt, static_cast<unsigned short>(strlen(tt)), NO_TIMEOUT );
		}
		else{
			
		char tt[22];
		tt[0] = 'F';
		tt[1] = 'A';
		tt[2] = 'K';
		tt[3] = 'E';
		tt[4] = '\0';
		remoteClient->send( tt, static_cast<unsigned short>(strlen(tt)), NO_TIMEOUT );
		}
		std::cout << "CARAC:" << request[2] << std::endl;
		// Disconnect
		remoteClient->shutdown();
		delete remoteClient;
	}
	s.shutdown();

	return;
}
