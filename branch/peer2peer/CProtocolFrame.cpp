#include "stdafx.h"
#include <iostream>

#include "CProtocolFrame.h"

#include "CException.h"
#include "CFileBinary.h"


void CProtocolFrame::serialize( std::string p_fileName ) {
	try {
		CFileBinary fout( p_fileName );

		fout.open( EFileOpenMode::write );
		fout.writeData( reinterpret_cast<unsigned char *>(&this->m_versionMajor), this->getClassSize() );
		fout.close();
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

void CProtocolFrame::deserialize( std::string p_fileName ) {
	try {
		CFileBinary fin( p_fileName );

		fin.open( EFileOpenMode::read );
		fin.readData( this->getClassSize(), reinterpret_cast<unsigned char *>(&this->m_versionMajor), this->getClassSize() );
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
