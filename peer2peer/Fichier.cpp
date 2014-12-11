#include "Fichier.h"


Fichier::Fichier(string p_NomFichier, string p_hash, string p_pathfile)
{
	std::list<string>listeBlocks();
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
vector<string>Fichier::getListeBlocks()
{
	return listeBlocks;
}


void Fichier::addBlock(std::string s)
{
	
	listeBlocks.push_back(s);
	
}