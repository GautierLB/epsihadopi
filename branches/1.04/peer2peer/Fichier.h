#pragma once
#include <string>
#include "Block.h"
using namespace std;

class Fichier
{
	public:
		Fichier(string p_NomFichier,int p_hash);
		~Fichier();
	private:
		string NomFichier;
		int EmpreinteNumerique;
		Block TableauBlocks[];
};

