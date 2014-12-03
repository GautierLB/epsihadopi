#include "stdafx.h"
#include <iostream>
#include "DemoException.h"

#include "CException.h"


void testException() {
	std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	std::cout << "Using exception library v" << CException::getVersion() << " as of " << CException::getBuildDate() << "." << std::endl;

	// Use RTII to get default exception type
	std::cout << CException::CLASS_TYPE << std::endl;

	try {
		std::cout << std::endl;
		std::cout << "Trying impossible..." << std::endl;
		throw _CException( "Wow! something went wrong.", 1212 );
		std::cout << "Failed, of course" << std::endl;
	}
	catch (CException &e) {			// & is IMPORTANT
		std::cerr << "** --- EXCEPTION THROWN ---" << std::endl;
		std::cerr << "** Type: " << e.getType() << std::endl;
		std::cerr << "** Message: " << e.getMessage() << std::endl;
		std::cerr << "** Error code: " << e.getErrorCode() << std::endl;
		std::cerr << "** Fault location: " << e.getFaultLocation() << std::endl;
	}
	return;
}
