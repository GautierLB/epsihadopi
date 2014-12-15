/*
Authors : CURTET Quentin, MORBOIS Antoine, LE BISSONNAIS Gautier, POUGET Fran�ois.
Organisation : I4Initial EPSI Lyon
Ann�e : 2014
*/
#include "stdafx.h"
#include "Directorythread.h"
#include "DetectionMainThread.h"
#include "ServeurClient.h"
#include "Serveur.h"
#include "ConfigurationInterne.h"

void *MainThreadFunc( void *p_arg ) {
	int c;
	ConfigurationInterne* config= ConfigurationInterne::getInstance();
	std::cout << "Press Esc to quit.\n";
	directoryThread();
	DetectionMainThread();
	LancementServeur();
	LancementServeurClient();
	do
    {
		
		c = _getch();
    }while (c != 27);
	config->setContinu(false);
	return nullptr;
}

void mainThread() {
	pthread_t t1;
	//pthread_t t_directory;
	void *result = nullptr;

	

	if (pthread_create( &t1, 0, MainThreadFunc, (void *) 1 ) != 0) {
		std::cerr << "** FAIL Creation Main Thread" << std::endl;
		return;
	}
	else {
		
	}

	pthread_join( t1, &result );
	return;
}
