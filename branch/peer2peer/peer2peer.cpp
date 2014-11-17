#include "stdafx.h"
#include <iostream>

#include "DemoException.h"
#include "DemoSha224.h"
#include "DemoSocket.h"
#include "DemoThreads.h"
#include "DemoFiles.h"
#include "DemoDateTime.h"
#include "Directorythread.h"
#include "../libs/core/include/CDateTime.h"
#include "Configuration.h"
#include "MainThread.h"
#include "ecriture.h"

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
	//testThreads();
	//testException();
	//testSha224();
	//testSocket();
	//testFile();
	//testDateTime();

	//
	// Test class serialization, especially getClassSize() virtual method
	CProtocolFrame f1;
	CProtocolFrameNotifyNewFileRequest f2;

	f1.m_versionMajor = 1;
	f1.m_versionMinor = 1;
	f1.m_codeOp = 64;
	f1.serialize( std::string( "C:\\Users\Gautier\Dropbox\Perso\Multithreading C++\StarterKitUpdated\peer2peer\CProtocolFrame.bin" ) );

	f2.m_versionMajor = 1;
	f2.m_versionMinor = 1;
	f2.m_codeOp = 68;
	f2.m_padding1 = 0;
	f2.m_fineNameLength = 12;
	memset( &f2.m_fileRawSha224, 0xAA, sizeof( f2.m_fileRawSha224 ) );
	f2.serialize( std::string( "C:\\Users\Gautier\Dropbox\Perso\Multithreading C++\StarterKitUpdated\peer2peer\CProtocolFrameGetFileListRequest.bin" ) );
	return;
}


int main( int argc, char *argv[] ) {
	std::cout << "** Welcome to this demo skeleton." << std::endl;

	//demos( argc, argv );

	string s = "Thread numero 1000"; //A remplacer par la ligne à insérer dans le fichier de log
	LOG affiche; //Variable du type de la classe
    affiche.ecrire(s); //On appelle la méthode ecrire() avec le paramètre à mettre dans le fichier de log

	Configuration config = Configuration::getInstance();
	std::cout << "** Initialisation du programme" << std::endl;
	std::cout << "** Nombre de connection maximales serveur : " << config.getNbConnectionServeur() <<endl;
	std::cout << "** Nombre d'envois simultanes maximum : " << config.getNbEnvoieSimultane() <<endl;
	std::cout << "** Nombre receptions simultanees maximum : " << config.getNbReceptionSimultane() <<endl;
	std::cout << "** Temps entre chaque scan : " << config.getTimeOutScan() <<endl;
	mainThread();
	std::cout << "** Goodbye" << std::endl;
	return 0;
}
