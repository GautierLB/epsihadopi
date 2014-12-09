#pragma once
#include <vector>
#include "Fichier.h"
#include "Block.h"
#include <pthread.h> 
#include <semaphore.h> 


using namespace std;

class ConfigurationInterne
{

	

public:
	~ConfigurationInterne();
	static ConfigurationInterne& getInstance();
	void ConfigurationInterne::addServeur(Fichier *toadd);
	vector<Fichier *> ListeFichier;
	vector<Block *>  ListeBlock;

private:
	ConfigurationInterne();
	sem_t mutex;
	static ConfigurationInterne m_instance;
	static ConfigurationInterne configInterne;
};

