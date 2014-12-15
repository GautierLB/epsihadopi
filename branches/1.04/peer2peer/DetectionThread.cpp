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

	std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	std::cout << "** Creating thread..." << std::endl;
	if (pthread_create( &t1, 0, DetectionThreadFunc, ((void*)ip)) != 0) {
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
void TestConnexion(std::string ip) {
	CSocketIp4 s;
	s.initEngine();
	std::string data = "";
	int recvCount = 0;
	char buffer[ 1024 ];
	//const char* test=ip->c_str();
	ConfigurationInterne* config= ConfigurationInterne::getInstance();
	
	// Connect to remote host
	std::cout << std::endl;
	std::cout << "Connecting to " << ip << std::endl;
	try{
		s.connect( ip.c_str(), 6699, 2500 );

		// Show information about endpoints
		std::cout << "Getting endpoints information..." << std::endl;
		std::cout << "- local socket is bound to IPv4 " << s.getLocalEndpointIp() << " on port " << s.getLocalEndpointPort() << std::endl;
		std::cout << "- remote socket is bound to IPv4 " << s.getRemoteEndpointIp() << " on port " << s.getRemoteEndpointPort() << std::endl;

		// Send HTTP request
		string chaine="114-EPSIHADOPY   100";
		char tt[22];

		for( int i=0;i<chaine.size();i++){
			tt[i]=chaine[i];

		}
		tt[chaine.size()]='\0';
		/*	tt[0] = '1';
		tt[1] = '1';
		tt[2] = '4';
		tt[3] = '-';
		tt[4] = 'E';
		tt[5] = 'P';
		tt[6] = 'S';
		tt[7] = 'I';
		tt[8] = 'H';
		tt[9] = 'A';
		tt[10] = 'D';
		tt[11] = 'O';
		tt[12] = 'D';
		tt[13] = 'P';
		tt[14] = 'Y';
		tt[15] = ' ';
		tt[16] = ' ';
		tt[17] = ' ';
		tt[18] = '1';
		tt[19] = '0';
		tt[20] = '0';
		tt[21] = '\0';*/

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
		std::cout << "COUCOU:" << data[2] << std::endl;
		if(data[2]=='5'){
			config->addServeur(ip);

		}
		/*if(data[2]=='5'){
		std::cout << "TEST:" << data[2] << std::endl;
		string chaine="116-EPSIHADOPY   100";
		char tt[22];

		for( int i=0;i<chaine.size();i++){
		tt[i]=chaine[i];

		}
		/*tt[0] = '1';
		tt[1] = '1';
		tt[2] = '6';
		tt[3] = '-';
		tt[4] = 'E';
		tt[5] = 'P';
		tt[6] = 'S';
		tt[7] = 'I';
		tt[8] = 'H';
		tt[9] = 'A';
		tt[10] = 'D';
		tt[11] = 'O';
		tt[12] = 'D';
		tt[13] = 'P';
		tt[14] = 'Y';
		tt[15] = ' ';
		tt[16] = ' ';
		tt[17] = ' ';
		tt[18] = '1';
		tt[19] = '0';
		tt[20] = '0';
		tt[21] = '\0';
		s.connect( ip.c_str(), 6699, 2500 );	
		data = "Coucouc";
		std::cout << "Sending request..." << std::endl;
		s.send( tt, static_cast<unsigned short>(strlen(tt)), NO_TIMEOUT );
		}
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
		// Cleanly close the connection
		std::cout << "Disconnecting..." << std::endl;
		s.shutdown();

		// Display result
		std::cout << "And the response is..." << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		std::cout << data << std::endl;
		std::cout << "----------------------------------------" << std::endl;*/
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

