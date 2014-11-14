#include "stdafx.h"
#include <iostream>
#include "DemoSha224.h"

#include "CLibSha224.h"
#include "CException.h"

void testSha224() {
	std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	std::cout << "Using SHA-224 library v" << CLibSha224::getVersion() << " as of " << CLibSha224::getBuildDate() << "." << std::endl;
	std::cout << std::endl;

	// From file
	std::cout << "- From file..." << std::endl;
	try {
		CLibSha224 shaFile( "D:\\Games\\Doom3\\install.log" );
		std::cout << "Hash is " << shaFile.getHash() << std::endl;
	}
	catch (CException &e) {
		std::cerr << "** --- EXCEPTION THROWN ---" << std::endl;
		std::cerr << "** Type: " << e.getType() << std::endl;
		std::cerr << "** Message: " << e.getMessage() << std::endl;
		std::cerr << "** Error code: " << e.getErrorCode() << std::endl;
		std::cerr << "** Fault location: " << e.getFaultLocation() << std::endl;
	}
	std::cout << std::endl;

	// From buffer
	std::cout << "- From buffer..." << std::endl;
	std::string s = "I'm a string ready to be hashed";
	try {
		unsigned char rawHash[ 28 ];

		CLibSha224 shaBuffer( reinterpret_cast<const unsigned char *>(s.c_str()), static_cast<const int>(s.length()) );
		std::cout << "- Hash is " << shaBuffer.getHash() << std::endl;
		shaBuffer.getRawHash( &rawHash[ 0 ] );
	}
	catch (CException &e) {
		std::cerr << "** --- EXCEPTION THROWN ---" << std::endl;
		std::cerr << "** Type: " << e.getType() << std::endl;
		std::cerr << "** Message: " << e.getMessage() << std::endl;
		std::cerr << "** Error code: " << e.getErrorCode() << std::endl;
		std::cerr << "** Fault location: " << e.getFaultLocation() << std::endl;
	}
	std::cout << std::endl;
	return;
}
