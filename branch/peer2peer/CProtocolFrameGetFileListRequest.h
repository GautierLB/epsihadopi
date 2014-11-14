#pragma once

#include "CProtocolFrame.h"
#include "EProtocolCodeOp.h"

#pragma pack(push, 1)

class CProtocolFrameGetFileListRequest : public CProtocolFrame {
public:

public:
	virtual unsigned int getClassSize() {
		return sizeof( CProtocolFrameGetFileListRequest ) - static_cast<unsigned int>(reinterpret_cast<unsigned char *>(&this->m_versionMajor) - reinterpret_cast<unsigned char *>(this));
	}
};

#pragma pack(pop)
