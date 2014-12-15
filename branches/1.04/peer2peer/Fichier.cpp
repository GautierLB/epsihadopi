/*
Authors : CURTET Quentin, MORBOIS Antoine, LE BISSONNAIS Gautier, POUGET François.
Organisation : I4Initial EPSI Lyon
Année : 2014
*/
#include "Fichier.h"

Fichier::Fichier(string p_NomFichier, string p_hash, string p_pathfile,list<Block> p_vb)
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

list<Block>Fichier::getListeBlock()
{
	return listeBlock;
}

void Fichier::addBlock(Block p_block)
{
	listeBlock.push_back(p_block);
	
}

