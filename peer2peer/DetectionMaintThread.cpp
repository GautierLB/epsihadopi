#include "stdafx.h"
#include <iostream>
#include <pthread.h>
#include "DetectionThread.h"
#include "DemoSocket.h"

void *DetectionMainThreadFunc(void* ip) {
	
	
	std::string* adressip=(std::string*)ip;
	testfonction(adressip);
	/*for (int i = 80; i < 255; i++){
			std:: string*adressiptemp =new std::string(adressip);

			*adressiptemp=*adressiptemp+std::to_string(i);
			std::cout << *adressiptemp<< std::endl;
			//testConnectGoogleAsHttpClient(adressiptemp);
			DetectionThread(adressiptemp);
		}*/
	return nullptr;
}

void DetectionMainThread() {
	pthread_t t1;
	void *result = nullptr;

	std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	std::cout << "** Creating thread..." << std::endl;
	std::string *adressip=new std::string("127.0.0.");
	if (pthread_create( &t1, 0, DetectionMainThreadFunc, ((void*)adressip)) != 0) {
		std::cerr << "** FAIL 1" << std::endl;
		return;
	}
	else {
		std::cout << "** Thread 1 creation OK" << std::endl;
	}

	std::cout << "** Waiting..." << std::endl;
	pthread_join( t1, &result );
	std::cout << "** Fini..." << std::endl;
	return;
}
