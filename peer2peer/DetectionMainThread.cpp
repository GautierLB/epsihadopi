#include "stdafx.h"
#include <iostream>
#include <pthread.h>
#include "DetectionMainThread.h"
#include "DetectionThread.h"

#include "windows.h" 
#include "VerificationThread.h"
#include "CSocketIp4.h"
#include "CException.h"
#include "ConfigurationInterne.h"

void *DetectionMainThreadFunc(void* ip) {
	
	while (true)
    {
   
	std::string* adressip=(std::string*)ip;
	BoucleRecherche(adressip);
	Sleep(20000);
	}
	return nullptr;
}

void DetectionMainThread() {
	pthread_t t1;
	void *result = nullptr;

	std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	std::cout << "** Creating thread..." << std::endl;
	std::string *adressip=new std::string("127.0.0.");
	//std::string *adressip=new std::string(getIp());
	if (pthread_create( &t1, 0, DetectionMainThreadFunc, ((void*)adressip)) != 0) {
		std::cerr << "** FAIL 1" << std::endl;
		return;
	}
	else {
		std::cout << "** Thread 1 creation OK" << std::endl;
	}

	std::cout << "** Waiting..." << std::endl;
	//pthread_join( t1, &result );
	std::cout << "** Fini..." << std::endl;
	
	
	std::cout << "** 20 SECONDE" << std::endl;
	return;
}
void BoucleRecherche(std::string* ip) {
	std::cout << "Coucou" << *ip<< std::endl;
	ConfigurationInterne* config= ConfigurationInterne::getInstance();
	list<string> serveur=config->getServeurs();
	for (std::list<string>::iterator it = serveur.begin(); it != serveur.end(); it++){
		
		VerificationThread(*it);
			}
	for (int i = 0; i < 50; i++){
		std:: string*adressiptemp =new std::string(*ip);

		*adressiptemp=*adressiptemp+std::to_string(i);
		std::cout << *adressiptemp<< std::endl;
		//testConnectGoogleAsHttpClient(adressiptemp);
		DetectionThread(adressiptemp);
	}	
}
string getIp() {
	std::vector<std::string> ipAddresses;
	CSocketIp4 s;

	// Get list of all local IPv4 addresses
	std::cout << std::endl;
	std::cout << "Getting local IP addresses..." << std::endl;
	ipAddresses = s.getLocalIpAddresses();
	std:: string adressip;

	for (size_t i = 0; i < ipAddresses.size(); i++) {
		std::cout << "- " << ipAddresses[ i ] << "   " << (s.isIpAddressPrivate( ipAddresses[ i ].c_str() ) ? "(private)" : "(public)") << std::endl;
		adressip=ipAddresses[ i ];
	}

	adressip=adressip.substr(0,adressip.rfind(".")+1);

	std::cout << adressip<< std::endl;
	

	return adressip;
}
