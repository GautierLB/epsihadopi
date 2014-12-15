/*
Authors : CURTET Quentin, MORBOIS Antoine, LE BISSONNAIS Gautier, POUGET François.
Organisation : I4Initial EPSI Lyon
Année : 2014
*/
#include "stdafx.h"
#include <iostream>
#include <pthread.h>
#include "DetectionThread.h"
#include "TabFichierThread.h"
#include "CSocketIp4.h"
#include "CException.h"
#include "ConfigurationInterne.h"

void *TabFichierThread(void* ip) {
	int c;
	std::string* ipfinal=(std::string*)ip;
	DemandeTab(*ipfinal);
	return nullptr;
}

void TabFichierThread(std::string* ip) {
	pthread_t t1;
	void *result = nullptr;

	std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	std::cout << "** Creating thread..." << std::endl;
	if (pthread_create( &t1, 0, TabFichierThread, ((void*)ip)) != 0) {
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
void DemandeTab(std::string ip) {
			CSocketIp4 s;
	s.initEngine();
	std::string data = "";
	int recvCount = 0;
	char buffer[ 2048 ];
		ConfigurationInterne* config= ConfigurationInterne::getInstance();	
		
	
	try{
		
		s.connect(ip.c_str(), 6699, 2500 );

		// Show information about endpoints
		std::cout << "Getting endpoints information..." << std::endl;
		std::cout << "- local socket is bound to IPv4 " << s.getLocalEndpointIp() << " on port " << s.getLocalEndpointPort() << std::endl;
		std::cout << "- remote socket is bound to IPv4 " << s.getRemoteEndpointIp() << " on port " << s.getRemoteEndpointPort() << std::endl;

		// Send HTTP request
		string chaine="116-EPSIHADOPY   100";
		char tt[22];

		for( int i=0;i<chaine.size();i++){
			tt[i]=chaine[i];

		}
		tt[chaine.size()]='\0';


		data = "Coucouc";
		std::cout << "Sending request..." << std::endl;
		s.send( tt, static_cast<unsigned short>(strlen(tt)), NO_TIMEOUT );

		// Wait for response
		std::cout << "Waiting for response..." << std::endl;
		s.waitForRead( NO_TIMEOUT );

		// Receive whole response
		data = "";
		do {
			memset( buffer, 0, sizeof( buffer ) );
			std::cout << "Receiving response part..." << std::endl;
			// When Google has finished sending me its data, it closes the connection ; thus I'm getting an exception but it's okay
			try {
				recvCount = s.recv( buffer, sizeof( buffer ), NO_TIMEOUT );
				data += buffer;
			}
			catch (CBrokenSocketException) {
				std::cout << "Connection closed by remote host..." << std::endl;
				recvCount = 0;
			}
		} while (recvCount > 0);
		std::cout << "ICI:" << data << std::endl;
		string fichier="";
		string hash="";
		boolean testfichier=false;
		for(int i=7;i<data.size();i++){
			if(data[i]!=';'){
				if(testfichier==false){
					 fichier=fichier+data[i];
				}
				else{
					hash=hash+data[i];
				}
			}
			else{
				if(testfichier==false){
					testfichier=true;
				}
				else{
				std::cout << fichier << " "<< hash <<std::endl;
				if(config->getFichiers().size()!=0){
					//Recherche si fichier de même nom
					std::cout <<"Recherche "<< fichier << " "<< hash <<std::endl;
					//Telechargement fichier apres test hash Fonction de recherche


				}
				
				
		
		
				fichier="";
				hash="";
				}
			}
		}
	}
	catch(CConnectionException){
		std::cout << "ECHEC:"<<ip << std::endl;
	}
	catch(CException e){
		std::cout << "ECHEC:"<<e.getMessage() << std::endl;
	}
	
	s.uninitEngine();
	return;
}



