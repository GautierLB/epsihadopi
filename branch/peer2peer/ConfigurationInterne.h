#pragma once
#include <vector>
#include "Fichier.h"
#include "Block.h"


using namespace std;

class ConfigurationInterne
{

	

public:
	~ConfigurationInterne();
	static ConfigurationInterne& getInstance();
	vector<Fichier *> ListeFichier;
	vector<Block *>  ListeBlock;

private:
	ConfigurationInterne();
	static ConfigurationInterne m_instance;
	static ConfigurationInterne configInterne;
};

