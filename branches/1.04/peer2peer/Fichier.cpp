#include "Fichier.h"


Fichier::Fichier(string p_NomFichier, string p_hash, string p_pathfile)
{
	vector<string>listeBlocks();
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

void Fichier::setNomFichier(string p_name)
{
	NomFichier = p_name;
}

std::string Fichier::getPathFile()
{
	return pathfile;
}

std::string Fichier::getEmpreinteNumerique()
{
	return EmpreinteNumerique;
}

vector<string>Fichier::getListeBlocks()
{
	return listeBlocks;
}

void Fichier::addBlock(string s)
{
	
	listeBlocks.push_back(s);
	
}

