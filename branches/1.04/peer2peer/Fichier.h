#pragma once
#include <string>
#include "Block.h"
using namespace std;

class Fichier
{
	public:
		Fichier(string p_NomFichier,string p_hash,string pathfile);
		~Fichier();

		string getNomFichier();
	private:
		string NomFichier;
		string EmpreinteNumerique;
		string pathfile;
		Block TableauBlocks[];
};

