#pragma once

#include "CProtocolFrame.h"
#include "EProtocolCodeOp.h"

#pragma pack(push, 1)

class CProtocolFrameGetFileListResponseOneFile : public CProtocolFrame {
public:
	unsigned long m_fileSize;
	unsigned char m_fileDateYear;
	unsigned char m_fileDateMonth;
	unsigned char m_fileDateDay;
	unsigned char m_fileTimeHour;
	unsigned char m_fileTimeMinute;
	unsigned char m_fileTimeSecond;
	unsigned short m_fileTimeMillisecond;
	unsigned char m_fileRawSha224 [ 28 ];
	unsigned short m_fineNameLength;

public:
	virtual unsigned int getClassSize() {
		return sizeof( CProtocolFrameGetFileListResponseOneFile ) - static_cast<unsigned int>(reinterpret_cast<unsigned char *>(&this->m_versionMajor) - reinterpret_cast<unsigned char *>(this));
	}
};

#pragma pack(pop)
