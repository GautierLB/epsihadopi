#pragma once
#include <string>
#include "stdafx.h"
#include <list>
#include <vector>

using namespace std;

class Fichier
{
	public:
		Fichier(string p_NomFichier,string p_hash,string pathfile);
		~Fichier();

		string getNomFichier();
		string getPathFile();
		vector<std::string> getListeBlocks();
		void addBlock(string s);
		vector<string> listeBlocks;

	private:
		string NomFichier;
		string EmpreinteNumerique;
		string pathfile;
		
		
};

