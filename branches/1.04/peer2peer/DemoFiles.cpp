#include "stdafx.h"
#include <iostream>
#include "DemoFiles.h"

#include "CFileBinary.h"
#include "CFileText.h"
#include "CException.h"


void testFileText() {
	std::cout << "Starting text-file library tests" << std::endl;
	std::cout << std::endl;
	std::cout << "Using text-file library v" << CFileText::getVersion() << " as of " << CFileText::getBuildDate() << "." << std::endl;

	try {
		std::vector<std::string> cnt;

		CFileText fin( "d:\\txt_lf.txt" );
		fin.open( EFileOpenMode::read );
		cnt = fin.readAll();
		std::cout << "----------" << std::endl;
		for (size_t i = 0; i < cnt.size(); i++) {
			std::cout << cnt[ i ] << "~" << std::endl;
		}
		std::cout << "----------" << std::endl;
		fin.close();

		CFileText fout( "d:\\txt2.txt", EFileOpenMode::write );
		fout.writeAll( cnt, EFileEOL::UNIX );
		fin.close();
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


void testFileBinary() {
	std::cout << "Starting binary-file library tests" << std::endl;
	std::cout << std::endl;
	std::cout << "Using binary-file library v" << CFileBinary::getVersion() << " as of " << CFileBinary::getBuildDate() << "." << std::endl;

	try {
		unsigned char buffer[] = "AZERTYUIOPQSDFGHJKLMWXCVBN";

		// Write 15 bytes to file
		CFileBinary fout( "d:\\test.bin" );
		fout.open( EFileOpenMode::write );
		std::cout << "Written " << fout.writeData( buffer, 15 ) << " byte(s)." << std::endl;
		fout.close();

		// Get file size
		CFileBinary fin( "d:\\test.bin" );
		std::cout << "File size is " << fin.getFileSize() << " byte(s)." << std::endl;
		fin.open( EFileOpenMode::read );

		// Read 10 bytes from file
		memset( buffer, 0, sizeof( buffer ) );
		std::cout << "Read " << fin.readData( 10, buffer, sizeof( buffer ) ) << " byte(s)." << std::endl;
		std::cout << "Data: \"" << buffer << "\"" << std::endl;

		// Try to read 10 bytes from file (only 5 will be OK)
		memset( buffer, 0, sizeof( buffer ) );
		std::cout << "Read " << fin.readData( 10, buffer, sizeof( buffer ) ) << " byte(s)." << std::endl;
		std::cout << "Data: \"" << buffer << "\"" << std::endl;
		fin.close();
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


void testFile() {
	testFileText();
	testFileBinary();
	return;
}

