/*
Authors : CURTET Quentin, MORBOIS Antoine, LE BISSONNAIS Gautier, POUGET François.
Organisation : I4Initial EPSI Lyon
Année : 2014
*/
#pragma once
#include <string>
#include "stdafx.h"
#include <list>
#include <vector>
#include "Block.h"



class Fichier
{
	public:
		Fichier(string p_NomFichier,string p_hash,string pathfile,vector<Block> p_vb);
		~Fichier();

		string getNomFichier();
		void setNomFichier(string p_name);
		string getPathFile();
		string getEmpreinteNumerique();
		vector<Block> getListeBlock();

		void addBlock(Block p_block);
		void compare(string p_nom,string p_hash);


	private:
		 vector<Block> listeBlock;
		string NomFichier;
		string EmpreinteNumerique;
		string pathfile;
		
		
};

