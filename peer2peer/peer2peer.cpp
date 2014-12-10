#include "stdafx.h"
#include <iostream>

#include "DemoException.h"
#include "DemoSha224.h"
#include "DemoSocket.h"
#include "DemoThreads.h"
#include "DemoFiles.h"
#include "DemoDateTime.h"
#include "DemoSerialize.h"
#include "Configuration.h"
#include "Directorythread.h"

#include "CProtocolFrame.h"
#include "CProtocolFrameNotifyNewFileRequest.h"


void demos( int argc, char *argv[] ) {
	//
	// Display parameters received from command line
	std::cout << std::endl;
	std::cout << "** Parameters dump:" << std::endl;
	for (int i = 0; i < argc; i++) {
		std::cout << "argv[" << i << "] = \"" << argv[ i ] << "\"" << std::endl;
	}

	//
	// Test libraries
	std::cout << std::endl;
	testThreads();
	//testException();
	//testSha224();
	//testSocket();
	//testFile();
	//testDateTime();
	//testSerialize();

	return;
}


int main( int argc, char *argv[] ) {

	Configuration config = *Configuration::getInstance();


	std::cout << "** Welcome to this demo skeleton." << std::endl;
	int i=0;
	for (i = 0; i< 4; i++)
	{
		if (argv[i] != nullptr)
		{
			std::cout << "** Dump parameter :" << i << argv[i] << std::endl;
		} 
		else 
		{
			std::cout << "** Not enough parameters, using default values." << std::endl;
		}
	}
	
	if (argv[1] != nullptr)
	{
		config.setNbConnectionServeur(atoi(argv[1]));
		std::cout << "** Utilisation du parametre recu en ligne de commande pour le nombre de connections maximales serveur :" << argv[1] << std::endl;
	} 
	if (argv[2] != nullptr)
	{
		config.setNbEnvoieSimultane(atoi(argv[2]));
		std::cout << "** Utilisation du parametre recu en ligne de commande pour le nombre d'envois maximal serveur :" << argv[2] << std::endl;
	}
	if (argv[3] != nullptr)
	{
		config.setNbReceptionSimultane(atoi(argv[3]));
		std::cout << "** Utilisation du parametre recu en ligne de commande pour le nombre de receptions maximales simultanees serveur :" << argv[3] << std::endl;
	}

	//demos( argc, argv );

	//directoryBrowse();

	string s = "Initalisation du programme, parametres nombre de connections serveur : " + std::to_string(config.getNbConnectionServeur()) + " ,nombre d'envois simultanes : " + std::to_string(config.getNbEnvoieSimultane()) + " , nombre de receptions simultanees : " + std::to_string(config.getNbReceptionSimultane()); //A remplacer par la ligne à insérer dans le fichier de log
	LOG affiche; //Variable du type de la classe
    affiche.ecrire(s); //On appelle la méthode ecrire() avec le paramètre à mettre dans le fichier de log

	std::cout << "** Initialisation du programme" << std::endl;
	std::cout << "** Nombre de connection maximales serveur : " << config.getNbConnectionServeur() <<endl;
	std::cout << "** Nombre d'envois simultanes maximum : " << config.getNbEnvoieSimultane() <<endl;
	std::cout << "** Nombre receptions simultanees maximum : " << config.getNbReceptionSimultane() <<endl;
	std::cout << "** Temps entre chaque scan : " << config.getTimeOutScan() <<endl;
	testSocket();
	mainThread();
	
	std::cout << "** Goodbye" << std::endl;
	return 0;
}
