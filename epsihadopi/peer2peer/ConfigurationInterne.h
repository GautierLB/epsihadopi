#pragma once
#include <vector>
#include "Fichier.h"
#include "Block.h"


using namespace std;

class ConfigurationInterne
{

	

public:
	ConfigurationInterne();
	~ConfigurationInterne();
	ConfigurationInterne* getConfig();
	static vector<Fichier *> ListeFichier;
	static vector<Block *>  ListeBlock;

private:
		static ConfigurationInterne configInterne;
};

