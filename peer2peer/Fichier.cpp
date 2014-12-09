#include "Fichier.h"


Fichier::Fichier(string p_NomFichier, int p_hash)
{
	NomFichier = p_NomFichier;
	EmpreinteNumerique = p_hash;
}


Fichier::~Fichier()
{
}
