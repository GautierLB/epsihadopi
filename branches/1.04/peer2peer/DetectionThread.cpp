#include "stdafx.h"
#include <iostream>
#include <pthread.h>
#include "DetectionThread.h"
#include "DemoSocket.h"

void *DetectionThreadFunc(void* ip) {
	int c;
	std::string* ipfinal=(std::string*)ip;
	sem_t smutex;
	sem_init(&smutex, 0, 10);
	testConnectGoogleAsHttpClient(*ipfinal);
	return nullptr;
}

void DetectionThread(std::string* ip) {
	pthread_t t1;
	void *result = nullptr;

	std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	std::cout << "** Creating thread..." << std::endl;
	if (pthread_create( &t1, 0, DetectionThreadFunc, ((void*)ip)) != 0) {
		std::cerr << "** FAIL 1" << std::endl;
		return;
	}
	else {
		std::cout << "** Thread 1 creation OK" << std::endl;
	}

	std::cout << "** Waiting..." << std::endl;
	//pthread_join( t1, &result );
	return;
}
