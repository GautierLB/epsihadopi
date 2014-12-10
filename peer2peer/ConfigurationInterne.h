#pragma once
#include "stdafx.h"
#include <list>
#include <pthread.h> 
#include <semaphore.h> 
#include "Fichier.h"
#include "Block.h"
#include "CSocketIp4.h"




using namespace std;

class ConfigurationInterne
{

	

public:
	~ConfigurationInterne();
	static ConfigurationInterne& getInstanceRef();
	static ConfigurationInterne* getInstance();
	void ConfigurationInterne::addServeur(string *toadd);
	void ConfigurationInterne::delServeur(string *todel);
	list<string *> ConfigurationInterne::getServeurs();
	void ConfigurationInterne::addFichier(Fichier f);
	vector<Fichier> ListeFichier;
	vector<Block *>  ListeBlock;
	list<string *> ListeServeur;

private:
	ConfigurationInterne();
	sem_t mutex;
	static ConfigurationInterne m_instance;
};
