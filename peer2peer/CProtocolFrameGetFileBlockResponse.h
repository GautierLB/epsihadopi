#pragma once

#include "CProtocolFrame.h"
#include "EProtocolCodeOp.h"

#pragma pack(push, 1)

class CProtocolFrameGetFileBlockResponse : public CProtocolFrame {
public:
	unsigned char m_padding1;
	unsigned char m_blockRawSha224 [ 28 ];

public:
	virtual unsigned int getClassSize() {
		return sizeof( CProtocolFrameGetFileBlockResponse ) - static_cast<unsigned int>(reinterpret_cast<unsigned char *>(&this->m_versionMajor) - reinterpret_cast<unsigned char *>(this));
	}
};

#pragma pack(pop)
