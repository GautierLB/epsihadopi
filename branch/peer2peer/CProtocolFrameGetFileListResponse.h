#pragma once

#include "CProtocolFrame.h"
#include "EProtocolCodeOp.h"

#pragma pack(push, 1)

class CProtocolFrameGetFileListResponse : public CProtocolFrame {
public:
	unsigned char m_padding1;
	unsigned long m_fileCount;

public:
	virtual unsigned int getClassSize() {
		return sizeof( CProtocolFrameGetFileListResponse ) - static_cast<unsigned int>(reinterpret_cast<unsigned char *>(&this->m_versionMajor) - reinterpret_cast<unsigned char *>(this));
	}
};

#pragma pack(pop)
