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
		void setNomFichier(string p_name);
		string getPathFile();
		string getEmpreinteNumerique();
		vector<string> getListeBlocks();
		void addBlock(string);
		void compare(string p_nom,string p_hash);


	private:
		vector<string> listeBlocks;
		string NomFichier;
		string EmpreinteNumerique;
		string pathfile;
		
		
};

