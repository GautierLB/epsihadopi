/*
Authors : CURTET Quentin, MORBOIS Antoine, LE BISSONNAIS Gautier, POUGET Fran�ois.
Organisation : I4Initial EPSI Lyon
Ann�e : 2014
*/
#pragma once
#include <string>
#include "stdafx.h"
using namespace std;


class Configuration
{
	public:
		~Configuration(); //Destructeur
		void setNbConnectionServeur(int nb); //D�finir le nombre de connection serveur
		void setTimeOutScan(int time); //D�finir le temps de recherche de client maximum
		void setNbEnvoieSimultane(int nb); //D�finir le nombre d'envois simultan�s
		void setNbReceptionSimultane(int nb); //D�finir le nombre de r�ceptions simultan�es
		int getNbConnectionServeur(); //Obtenir le nombre de connexions serveurs
		int getTimeOutScan(); //Obtenir le temps de recherche de client maximum
		int getNbEnvoieSimultane(); //Obtenir le nombre d'envois simultan�s
		int getNbReceptionSimultane(); //Obtenir le nombre de r�ceptions simultan�es
		static Configuration* getInstance(); // Retourne l'adresse du singleton
		static Configuration& getInstanceRef(); // Retourne l'adresse du singleton

	private:
		Configuration(); //Constructeur
		static Configuration m_instance;
		unsigned short nbConnectionServeur;  // nombre de client maximum
		unsigned short timeOutScan;			// temps de recherche de client maximum 
		unsigned short nbEnvoieSimultane;	// envoie max de bloc en simultan�
		unsigned short nbReceptionSimultane; //r�ception ~~
		string logSimplifierName;
		string logDebugName;
};

