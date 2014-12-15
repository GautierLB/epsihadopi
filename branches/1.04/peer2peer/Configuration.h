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
		~Configuration();
		void setNbConnectionServeur(int nb);
		void setTimeOutScan(int time);
		void setNbEnvoieSimultane(int nb);
		void setNbReceptionSimultane(int nb);
		int getNbConnectionServeur();
		int getTimeOutScan();
		int getNbEnvoieSimultane();
		int getNbReceptionSimultane();
		static Configuration* getInstance();
		static Configuration& getInstanceRef();

	private:
		Configuration();
		static Configuration m_instance;
		unsigned short nbConnectionServeur;  // nombre de client maximum
		unsigned short timeOutScan;			// temps de recherche de client maximum 
		unsigned short nbEnvoieSimultane;	// envoie max de bloc en simultan�
		unsigned short nbReceptionSimultane; //r�ception ~~
		string logSimplifierName;
		string logDebugName;

};

