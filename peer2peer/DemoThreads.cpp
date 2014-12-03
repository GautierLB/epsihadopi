#include "stdafx.h"
#include <iostream>
#include <pthread.h>
#include "DemoThreads.h"


void *threadFunc( void *p_arg ) {
	int number = reinterpret_cast<int>(p_arg);
	for (int i = 0; i < 5000; i++) {
		std::cout << number;
	}
	return nullptr;
}


void testThreads() {
	pthread_t t1, t2;
	void *result = nullptr;

	std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	std::cout << "** Creating thread..." << std::endl;
	if (pthread_create( &t1, 0, threadFunc, (void *) 1 ) != 0) {
		std::cerr << "** FAIL 1" << std::endl;
		return;
	}
	else {
		std::cout << "** Thread 1 creation OK" << std::endl;
	}

	if (pthread_create( &t2, 0, threadFunc, (void *) 2 ) != 0) {
		std::cerr << "** FAIL 2" << std::endl;
		return;
	}
	else {
		std::cout << "** Thread 2 creation OK" << std::endl;
	}

	std::cout << "** Waiting..." << std::endl;
	pthread_join( t1, &result );
	pthread_join( t2, &result );

	return;
}
