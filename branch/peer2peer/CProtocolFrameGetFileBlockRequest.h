#pragma once

#include "CProtocolFrame.h"
#include "EProtocolCodeOp.h"

#pragma pack(push, 1)

class CProtocolFrameGetFileBlockRequest : public CProtocolFrame {
public:
	unsigned char m_padding1;
	unsigned char m_fileRawSha224 [ 28 ];
	unsigned long m_blockId;

public:
	virtual unsigned int getClassSize() {
		return sizeof( CProtocolFrameGetFileBlockRequest ) - static_cast<unsigned int>(reinterpret_cast<unsigned char *>(&this->m_versionMajor) - reinterpret_cast<unsigned char *>(this));
	}
};

#pragma pack(pop)
