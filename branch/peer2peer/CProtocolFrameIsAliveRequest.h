#pragma once

#include "CProtocolFrame.h"
#include "EProtocolCodeOp.h"

#pragma pack(push, 1)

class CProtocolFrameIsAliveRequest : public CProtocolFrame {
public:
	char m_padding1;
	char m_softwareName [ 20 ];
	unsigned long m_requesterUptimeSeconds;


public:
	virtual unsigned int getClassSize() {
		return sizeof( CProtocolFrameIsAliveRequest ) - static_cast<unsigned int>(reinterpret_cast<unsigned char *>(&this->m_versionMajor) - reinterpret_cast<unsigned char *>(this));
	}
};

#pragma pack(pop)
