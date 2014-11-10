#pragma once
class Configuration
{
	public:
		Configuration();
		~Configuration();
		Configuration* getConfig();
		static unsigned short nbConnectionServeur; // nombre de client maximum
		static unsigned short timeOutScan;			// temps de recherche de client maximum 
		static unsigned short nbEnvoieSimultane;	// envoie max de bloc en simultané
		static unsigned short nbReceptionSimultane;//réception ~~
		static  string logSimplifierName;
		static  string logDebugName;

	private:
		static Configuration config;

};

