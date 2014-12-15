/*
Authors : CURTET Quentin, MORBOIS Antoine, LE BISSONNAIS Gautier, POUGET François.
Organisation : I4Initial EPSI Lyon
Année : 2014
*/
#pragma once
#include "stdafx.h"
#include <list>
#include <pthread.h> 
#include <semaphore.h> 
#include "Fichier.h"
#include "CSocketIp4.h"




using namespace std;

class ConfigurationInterne
{
	public:
		~ConfigurationInterne();
		static ConfigurationInterne& getInstanceRef();
		static ConfigurationInterne* getInstance();
		void ConfigurationInterne::addServeur(string toadd);
		void ConfigurationInterne::delServeur(string todel);
		list<string> ConfigurationInterne::getServeurs();
		list<Fichier> ConfigurationInterne::getFichiers();
		void ConfigurationInterne::addFichier(Fichier f);
		Fichier ConfigurationInterne::getFichierById(int idFichier);


	private:
		list<Fichier> ListeFichier;	
		list<string> ListeServeur;
		ConfigurationInterne();
		sem_t mutex;
		static ConfigurationInterne m_instance;
};

