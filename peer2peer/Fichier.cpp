#include "Fichier.h"


Fichier::Fichier(string p_NomFichier, string p_hash)
{
	NomFichier = p_NomFichier;
	EmpreinteNumerique = p_hash;
}


Fichier::~Fichier()
{
}
