/*
Authors : CURTET Quentin, MORBOIS Antoine, LE BISSONNAIS Gautier, POUGET François.
Organisation : I4Initial EPSI Lyon
Année : 2014
*/
#include "stdafx.h"
#include <iostream>
#include <pthread.h>
#include "DetectionThread.h"
#include "VerificationThread.h"
#include "CSocketIp4.h"
#include "CException.h"
#include "ConfigurationInterne.h"

void *DetectionThreadFunc(void* ip) {
	int c;
	std::string* ipfinal=(std::string*)ip;
	TestConnexion(*ipfinal);
	return nullptr;
}

void DetectionThread(std::string* ip) {
	pthread_t t1;
	void *result = nullptr;

	if (pthread_create( &t1, 0, DetectionThreadFunc, ((void*)ip)) != 0) {
		
		return;
	}
	else {
		
	}


	//pthread_join( t1, &result );
	return;
}
void TestConnexion(std::string ip) {
	CSocketIp4 s;
	s.initEngine();
	std::string data = "";
	int recvCount = 0;
	char buffer[ 1024 ];
	//const char* test=ip->c_str();
	ConfigurationInterne* config= ConfigurationInterne::getInstance();
	
	// Connect to remote host
	
	
	try{
		s.connect( ip.c_str(), 6699, 2500 );

		
		string chaine="114-EPSIHADOPY   100";
		char tt[22];

		for( int i=0;i<chaine.size();i++){
			tt[i]=chaine[i];

		}
		tt[chaine.size()]='\0';
	


		s.send( tt, static_cast<unsigned short>(strlen(tt)), NO_TIMEOUT );

		
		s.waitForRead( NO_TIMEOUT );

		// Receive whole response
		data = "";
		do {
			memset( buffer, 0, sizeof( buffer ) );
			
			// When Google has finished sending me its data, it closes the connection ; thus I'm getting an exception but it's okay
			try {
				recvCount = s.recv( buffer, sizeof( buffer ), NO_TIMEOUT );
				data += buffer;
			}
			catch (CBrokenSocketException) {
	
				recvCount = 0;
			}
		} while (recvCount > 0);
		
		if(data[2]=='5'){
			config->addServeur(ip);

		}
	
	}
	catch(CConnectionException){
		
	}
	catch(CException e){
		
	}
	s.uninitEngine();
	return;
}

