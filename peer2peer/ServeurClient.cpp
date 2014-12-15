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
#include "TabFichierThread.h"

void *LancementServeurClient( void *p_arg ) {
	//const char* test=ip->c_str();
	ConfigurationInterne* config= ConfigurationInterne::getInstance();
	list<string> serveur=config->getServeurs();
	
	for (std::list<string>::iterator it = serveur.begin(); it !=  serveur.end(); it++){
		string iptemp=*it;
		TabFichierThread(&iptemp);
	}
	return nullptr;
}


void LancementServeurClient() {
	pthread_t t1;
	void *result = nullptr;

	if (pthread_create( &t1, 0, LancementServeurClient, (void *) 1 ) != 0) {
		return;
	}
	else {
	
	}

	pthread_join( t1, &result );
	return;
}

