/*
Authors : CURTET Quentin, MORBOIS Antoine, LE BISSONNAIS Gautier, POUGET Fran�ois.
Organisation : I4Initial EPSI Lyon
Ann�e : 2014
*/
#pragma once
#include "stdafx.h"
#include <list>
#include <pthread.h> 
#include <semaphore.h> 
#include "Fichier.h"
#include "CSocketIp4.h"




using namespace std;

class ConfigurationInterne
{
	public:
		~ConfigurationInterne(); //Destructeur
		static ConfigurationInterne& getInstanceRef(); // Retourne l'adresse du singleton
		static ConfigurationInterne* getInstance(); // Retourne l'adresse du singleton
		void ConfigurationInterne::addServeur(string toadd); //Ajout d'un serveur � la liste
		void ConfigurationInterne::delServeur(string todel); //Suppression d'un serveur de la liste
		list<string> ConfigurationInterne::getServeurs(); //Obtenir la liste des serveurs
		list<Fichier> ConfigurationInterne::getFichiers(); //Obtenir la liste des fichiers
		void ConfigurationInterne::addFichier(Fichier f); //Ajouter un fichier � la liste des fichiers
		Fichier ConfigurationInterne::getFichierById(int idFichier); //Obtenir un fichier par son ID


	private:
		list<Fichier> ListeFichier;	//Liste des fichiers
		list<string> ListeServeur; //Liste des serveurs
		ConfigurationInterne(); //Constructeur
		sem_t mutex; //S�maphore
		static ConfigurationInterne m_instance;
};

