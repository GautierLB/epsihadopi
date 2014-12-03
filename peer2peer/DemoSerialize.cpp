#include "stdafx.h"
#include <iostream>
#include <string>

#include "DemoSerialize.h"

#include "CProtocolFrame.h"
#include "CProtocolFrameNotifyNewFileRequest.h"


void testSerialize() {
	// Test class serialization, especially getClassSize() virtual method
	CProtocolFrame f1;
	CProtocolFrameNotifyNewFileRequest f2;
	std::string targetFolder = "d:\\";

	std::cout << "Serializing CProtocolFrame object to directory " << targetFolder << "..." << std::endl;
	f1.m_versionMajor = 1;
	f1.m_versionMinor = 1;
	f1.m_codeOp = 64;
	f1.serialize( targetFolder + std::string( "CProtocolFrame.bin" ) );

	std::cout << "Serializing CProtocolFrameNotifyNewFileRequest object to directory " << targetFolder << "..." << std::endl;
	f2.m_versionMajor = 1;
	f2.m_versionMinor = 1;
	f2.m_codeOp = 68;
	f2.m_padding1 = 0;
	f2.m_fineNameLength = 12;
	memset( &f2.m_fileRawSha224, 0xAA, sizeof( f2.m_fileRawSha224 ) );
	f2.serialize( targetFolder + std::string( "CProtocolFrameGetFileListRequest.bin" ) );

	std::cout << "End of serialization demo" << std::endl;
	return;
}
