#include "stdafx.h"
#include <iostream>
#include <pthread.h>
#include "MainThread.h"

void *MainThreadFunc( void *p_arg ) {
	int c;
	std::cout << "Press Esc to quit.\n";
	do
    {
		c = std::getchar();
		std::cout << c << std::endl;
    }while (c != 27);
	return nullptr;
}

void mainThread() {
	pthread_t t1;
	void *result = nullptr;

	std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	std::cout << "** Creating thread..." << std::endl;
	if (pthread_create( &t1, 0, MainThreadFunc, (void *) 1 ) != 0) {
		std::cerr << "** FAIL 1" << std::endl;
		return;
	}
	else {
		std::cout << "** Thread 1 creation OK" << std::endl;
	}

	std::cout << "** Waiting..." << std::endl;
	pthread_join( t1, &result );
	return;
}
