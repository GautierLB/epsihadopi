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
		Fichier(string p_NomFichier,string p_hash,string pathfile,list<Block> p_vb); //Constructeur
		~Fichier(); //Destructeur

		string getNomFichier(); //Récupère le nom du fichier
		void setNomFichier(string p_name); //Définir le nom du fichier
		string getPathFile(); //Obtenir le chemin vers le fichier
		string getEmpreinteNumerique(); //Obtenir l'empreinte numérique du fichier
		list<Block> getListeBlock(); //Obtenir la liste des blocs

		void addBlock(Block p_block); //Ajouter un bloc à la liste
		void compare(string p_nom,string p_hash); //Comparer les fichiers lors de la synchronisation


	private:
		list<Block> listeBlock;
		string NomFichier;
		string EmpreinteNumerique;
		string pathfile;
};

