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

		vector<Fichier> ConfigurationInterne::getFichiers();

		string ConfigurationInterne::getNomFichierId(int idFichier);
		string ConfigurationInterne::getPathFileId(int idFichier);
		
		void ConfigurationInterne::setNomFichierId(int idFichier, string filename);
		void ConfigurationInterne::addFichier(Fichier f);

		Fichier ConfigurationInterne::getFichierById(int idFichier);


	private:
		vector<Fichier> ListeFichier;
		
		list<string> ListeServeur;
		ConfigurationInterne();
		sem_t mutex;
		static ConfigurationInterne m_instance;
};
