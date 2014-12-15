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

void LancementServeurClient() {
	
	//const char* test=ip->c_str();

	ConfigurationInterne* config= ConfigurationInterne::getInstance();
	
	for(;;){
	list<string> serveur=config->getServeurs();

	std::list<string>::iterator itdebut = serveur.begin();
	std::list<string>::iterator itfin = serveur.end();
	for (std::list<string>::iterator it = itdebut; it != itfin; it++){
		string iptemp=*it;
		TabFichierThread(&iptemp);
	}
	}
	return;
}
