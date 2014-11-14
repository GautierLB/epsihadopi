#pragma once

#include "EProtocolCodeOp.h"

#pragma pack(push, 1)

class CProtocolFrame {
public:
	unsigned char m_versionMajor;
	unsigned char m_versionMinor;
	unsigned char m_codeOp;

public:
	virtual unsigned int getClassSize() {
		return sizeof( CProtocolFrame ) - static_cast<unsigned int>(reinterpret_cast<unsigned char *>(&this->m_versionMajor) - reinterpret_cast<unsigned char *>(this));
	}

	void serialize( std::string p_fileName );
	void deserialize( std::string p_fileName );
};

#pragma pack(pop)
