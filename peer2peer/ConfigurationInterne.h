#pragma once
#include <vector>
#include "Fichier.h"
#include "Block.h"
#include "CSocketIp4.h"
#include <pthread.h> 
#include <semaphore.h> 


using namespace std;

class ConfigurationInterne
{

	

public:
	~ConfigurationInterne();
	static ConfigurationInterne& getInstance();
	void ConfigurationInterne::addServeur(CSocketIp4 *toadd);
	vector<Fichier *> ListeFichier;
	vector<Block *>  ListeBlock;
	vector<CSocketIp4 *> ListeServeur;

private:
	ConfigurationInterne();
	sem_t mutex;
	static ConfigurationInterne m_instance;
	static ConfigurationInterne configInterne;
};

