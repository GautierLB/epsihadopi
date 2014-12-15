/*
Authors : CURTET Quentin, MORBOIS Antoine, LE BISSONNAIS Gautier, POUGET François.
Organisation : I4Initial EPSI Lyon
Année : 2014
*/
#pragma once
#include <string>
#include "stdafx.h"
using namespace std;


class Configuration
{
	public:
		~Configuration(); //Destructeur
		void setNbConnectionServeur(int nb); //Définir le nombre de connection serveur
		void setTimeOutScan(int time); //Définir le temps de recherche de client maximum
		void setNbEnvoieSimultane(int nb); //Définir le nombre d'envois simultanés
		void setNbReceptionSimultane(int nb); //Définir le nombre de réceptions simultanées
		int getNbConnectionServeur(); //Obtenir le nombre de connexions serveurs
		int getTimeOutScan(); //Obtenir le temps de recherche de client maximum
		int getNbEnvoieSimultane(); //Obtenir le nombre d'envois simultanés
		int getNbReceptionSimultane(); //Obtenir le nombre de réceptions simultanées
		static Configuration* getInstance(); // Retourne l'adresse du singleton
		static Configuration& getInstanceRef(); // Retourne l'adresse du singleton

	private:
		Configuration(); //Constructeur
		static Configuration m_instance;
		unsigned short nbConnectionServeur;  // nombre de client maximum
		unsigned short timeOutScan;			// temps de recherche de client maximum 
		unsigned short nbEnvoieSimultane;	// envoie max de bloc en simultané
		unsigned short nbReceptionSimultane; //réception ~~
		string logSimplifierName;
		string logDebugName;
};

