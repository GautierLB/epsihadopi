#include "stdafx.h"
#include "Directorythread.h"
#include "DetectionMainThread.h"
#include "ServeurClient.h"
#include "Serveur.h"
#include "ConfigurationInterne.h"



void *MainThreadFunc( void *p_arg ) {
	int c;
	
	std::cout << "Press Esc to quit.\n";
	directoryThread();
	ConfigurationInterne* config= ConfigurationInterne::getInstance();
	DetectionMainThread();
	LancementServeur();
	LancementServeurClient();
	do
    {
		
		c = _getch();
    }while (c != 27);
	return nullptr;
}

void mainThread() {
	pthread_t t1;
	//pthread_t t_directory;
	void *result = nullptr;

	std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	std::cout << "** Creating Main thread..." << std::endl;
	if (pthread_create( &t1, 0, MainThreadFunc, (void *) 1 ) != 0) {
		std::cerr << "** FAIL Creation Main Thread" << std::endl;
		return;
	}
	else {
		std::cout << "** Main Thread creation OK" << std::endl;
	}

	std::cout << "** Waiting..." << std::endl;
	pthread_join( t1, &result );
	return;
}
