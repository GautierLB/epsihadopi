#include "stdafx.h"
#include <iostream>
#include "DemoException.h"
#include "DemoSha224.h"
#include "DemoSocket.h"
#include "DemoThreads.h"
#include "ServerThread.h"#include "Directorythread.h"
int main( int argc, char *argv[] ) {
	std::cout << "** Welcome to this demo skeleton." << std::endl;

	std::cout << "** Parameters dump:" << std::endl;
	for (int i = 0; i < argc; i++) {
		std::cout << "--> " << argv[ i ] << std::endl;
	}

	std::cout << "** Time to play now... enjoy!" << std::endl;
	//testThreads();
	//directoryBrowse();

	//testException();
	//testSha224();
	//testSocket();
	
		
	/*Server();*/
	system("pause");

	std::cout << "** Goodbye" << std::endl;
	system("PAUSE");
	return 0;
}
