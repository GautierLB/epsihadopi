/*
Authors : CURTET Quentin, MORBOIS Antoine, LE BISSONNAIS Gautier, POUGET François.
Organisation : I4Initial EPSI Lyon
Année : 2014
*/
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




	if (pthread_create( &t1, 0, LancementServeur, ((void*)0)) != 0) {
		
		return;
	}
	else {
		
	}


	//pthread_join( t1, &result );
	return;
}
void Serveur() {
		CSocket::initEngine();
		CSocketIp4 s, *remoteClient = nullptr;


	ConfigurationInterne* config= ConfigurationInterne::getInstance();
	s.server( 6699, 5 );
	for (;;) {
		std::string data, request;

		int recvCount = 0;
		char buffer[ 2048 ];

		remoteClient = dynamic_cast<CSocketIp4 *>(s.accept());

	
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
			
			
			int size=config->getFichiers().size();
		string chaine="117-"+to_string(size);
		
	
			
			const list<Fichier> myCopy = config->getFichiers();
			list<Fichier>::const_iterator i = myCopy.begin();
			while(i != myCopy.end())
			{
				Fichier fichiertemp=*i;
				chaine=chaine+fichiertemp.getNomFichier()+";";
				chaine=chaine+fichiertemp.getEmpreinteNumerique()+";";
			++i;
			}
			
		
		
		int temp=chaine.size()+1;
		char tt[1000];
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
		
		// Disconnect
		remoteClient->shutdown();
		delete remoteClient;
	}
	s.shutdown();

	return;
}
