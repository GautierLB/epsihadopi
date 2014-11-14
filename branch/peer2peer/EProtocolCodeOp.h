#pragma once

typedef enum {
	isAliveRequest = 64,
	isAliveResponse = 65,
	getFileListRequest = 66,
	getFileListResponse = 67,
	notifiNewFileRequest = 68,
	getBlockListOfFileRequest = 70,
	getBlockListOfFileResponse = 71,
	getFileBlockRequest = 72,
	getFileBlockResponse = 73,
	error = 0
} EProtocolCodeOp;
