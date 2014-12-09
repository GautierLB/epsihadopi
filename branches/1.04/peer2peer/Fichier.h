#pragma once
#include <string>
#include "Block.h"
using namespace std;

class Fichier
{
	public:
		Fichier(string p_NomFichier,string p_hash);
		~Fichier();

		string getNomFichier();
	private:
		string NomFichier;
		string EmpreinteNumerique;
		Block TableauBlocks[];
};

