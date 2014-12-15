#include "Fichier.h"


Fichier::Fichier(string p_NomFichier, string p_hash, string p_pathfile,vector<Block> p_vb)
{
	
	NomFichier = p_NomFichier;
	EmpreinteNumerique = p_hash;
	pathfile = p_pathfile;
	listeBlock = p_vb;
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

vector<Block>Fichier::getListeBlock()
{
	return listeBlock;
}

void Fichier::addBlock(Block p_block)
{
	
	listeBlock.push_back(p_block);
	
}
