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
		unsigned short nbEnvoieSimultane;	// envoie max de bloc en simultané
		unsigned short nbReceptionSimultane; //réception ~~
		string logSimplifierName;
		string logDebugName;

};

