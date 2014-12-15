/*
Authors : CURTET Quentin, MORBOIS Antoine, LE BISSONNAIS Gautier, POUGET François.
Organisation : I4Initial EPSI Lyon
Année : 2014
*/
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
	ConfigurationInterne* config= ConfigurationInterne::getInstance();
	while (config->getContinu())
    {
   
	std::string* adressip=(std::string*)ip;
	BoucleRecherche(adressip);
	Sleep(20000);
	}
	std::cout<<"fin detection serveur"<<std::endl;
	return nullptr;
}

void DetectionMainThread() {
	pthread_t t1;
	void *result = nullptr;

	Configuration* config= Configuration::getInstance();
	std::string *adressip=new std::string(config->getIpReseau());
	//Fonction permettant d'obtenir son Ip mais vue qu'on ne teste que 255 possibilités on rentre son reseau en argument
	//std::string *adressip=new std::string(getIp());
	if (pthread_create( &t1, 0, DetectionMainThreadFunc, ((void*)adressip)) != 0) {
		
		return;
	}
	else {
	
	}


	return;
}
void BoucleRecherche(std::string* ip) {
	
	ConfigurationInterne* config= ConfigurationInterne::getInstance();
	list<string> serveur=config->getServeurs();
	for (std::list<string>::iterator it = serveur.begin(); it != serveur.end() ; it++){
		//Fonction permettant de verifier doublon (meme nom mais pas meme hash) mais probleme parcours liste
		//VerificationThread(*it)
			}
	for (int i = 0; i < 255; i++){
		std:: string*adressiptemp =new std::string(*ip);
		
		*adressiptemp=*adressiptemp+std::to_string(i);
		
		
		DetectionThread(adressiptemp);
	}	
}
string getIp() {
	std::vector<std::string> ipAddresses;
	CSocketIp4 s;

	// Get list of all local IPv4 addresses
	
	ipAddresses = s.getLocalIpAddresses();
	std:: string adressip;

	for (size_t i = 0; i < ipAddresses.size(); i++) {
		adressip=ipAddresses[ i ];
	}

	adressip=adressip.substr(0,adressip.rfind(".")+1);


	

	return adressip;
}
