#pragma once
#include <string>

using namespace std;


class Configuration
{
	public:
		~Configuration();
		static Configuration* getInstance( );
		static unsigned short nbConnectionServeur;  // nombre de client maximum
		static unsigned short timeOutScan;			// temps de recherche de client maximum 
		static unsigned short nbEnvoieSimultane;	// envoie max de bloc en simultané
		static unsigned short nbReceptionSimultane; //réception ~~
		static string logSimplifierName;
		static string logDebugName;

	private:
		Configuration();
		static Configuration* config;

};

