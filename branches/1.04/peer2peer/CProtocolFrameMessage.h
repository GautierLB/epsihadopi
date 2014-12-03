#pragma once

#include "CProtocolFrame.h"
#include "EProtocolCodeOp.h"

#pragma pack(push, 1)

class CProtocolFrameMessage : public CProtocolFrame {
public:
	char m_severity;
	unsigned short m_messageLength;

public:
	virtual unsigned int getClassSize() {
		return sizeof( CProtocolFrameMessage ) - static_cast<unsigned int>(reinterpret_cast<unsigned char *>(&this->m_versionMajor) - reinterpret_cast<unsigned char *>(this));
	}
};

#pragma pack(pop)
