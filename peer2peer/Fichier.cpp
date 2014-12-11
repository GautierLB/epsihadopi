#include "Fichier.h"


Fichier::Fichier(string p_NomFichier, string p_hash, string p_pathfile)
{
	NomFichier = p_NomFichier;
	EmpreinteNumerique = p_hash;
	pathfile = p_pathfile;
}


Fichier::~Fichier()
{

}

std::string Fichier::getNomFichier()
{
	return NomFichier;
}
std::string Fichier::getPathFile()
{
	return pathfile;
}
