#include "stdafx.h"
#include <iostream>
#include "DemoSocket.h"

#include "..\libs\socket\include\CSocketIp4.h"
#include "..\libs\exception\include\CException.h"


void testNameResolution() {
	std::vector<std::string> ipAddresses;
	CSocketIp4 s;

	// Get list of all local IPv4 addresses
	std::cout << std::endl;
	std::cout << "Getting local IP addresses..." << std::endl;
	ipAddresses = s.getLocalIpAddresses();
	for (size_t i = 0; i < ipAddresses.size(); i++) {
		std::cout << "- " << ipAddresses[ i ] << "   " << (s.isIpAddressPrivate( ipAddresses[ i ].c_str() ) ? "(private)" : "(public)") << std::endl;
	}

	// Get list of all Google IPv4 addresses on host "www"
	std::cout << std::endl;
	std::cout << "Resolving www.google.com..." << std::endl;
	ipAddresses = s.dnsResolve( "www.google.com" );
	for (size_t i = 0; i < ipAddresses.size(); i++) {
		std::cout << "- " << ipAddresses[ i ] << std::endl;
	}
	return;
}


// This procedure connects to Google, asks it to send us its home page and displays result as raw text
void testConnectGoogleAsHttpClient() {
	CSocketIp4 s;
	std::string data = "";
	int recvCount = 0;
	char buffer[ 1024 ];


	// Connect to remote host
	std::cout << std::endl;
	std::cout << "Connecting to www.google.com..." << std::endl;
	s.connect( "www.google.com", 80, 2500 );

	// Show information about endpoints
	std::cout << "Getting endpoints information..." << std::endl;
	std::cout << "- local socket is bound to IPv4 " << s.getLocalEndpointIp() << " on port " << s.getLocalEndpointPort() << std::endl;
	std::cout << "- remote socket is bound to IPv4 " << s.getRemoteEndpointIp() << " on port " << s.getRemoteEndpointPort() << std::endl;

	// Send HTTP request
	data = "GET / HTTP/1.1\r\n"
		"Host: www.google.com\r\n"
		"Connection: close\r\n"
		"\r\n";
	std::cout << "Sending request..." << std::endl;
	s.send( data.c_str(), static_cast<unsigned short>(data.length()), NO_TIMEOUT );

	// Wait for response
	std::cout << "Waiting for response..." << std::endl;
	s.waitForRead( NO_TIMEOUT );

	// Receive whole response
	data = "";
	do {
		memset( buffer, 0, sizeof( buffer ) );
		std::cout << "Receiving response part..." << std::endl;
		// When Google has finished sending me its data, it closes the connection ; thus I'm getting an exception but it's okay
		try {
			recvCount = s.recv( buffer, sizeof( buffer ), NO_TIMEOUT );
			data += buffer;
		}
		catch (CBrokenSocketException) {
			std::cout << "Connection closed by remote host..." << std::endl;
			recvCount = 0;
		}
	} while (recvCount > 0);

	// Cleanly close the connection
	std::cout << "Disconnecting..." << std::endl;
	s.shutdown();

	// Display result
	std::cout << "And the response is..." << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << data << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	return;
}


void testHttpServer() {
	CSocketIp4 s, *remoteClient = nullptr;

	std::cout << std::endl;
	std::cout << "Creating HTTP server on port 666..." << std::endl;

	s.server( 666, 5 );
	for (;;) {
		std::string data, request;
		int recvCount = 0;
		char buffer[ 1024 ];


		std::cout << "Waiting for connections..." << std::endl;
		remoteClient = dynamic_cast<CSocketIp4 *>(s.accept());

		std::cout << "Accepted incoming connection from " << remoteClient->getRemoteEndpointIp() << " on port " << remoteClient->getRemoteEndpointPort() << std::endl;

		// Receive whole response with 100ms timeout
		// !! WARNING !! a nicer way to handle this request is to check for end-of-request instead of foolishly wait for 100ms
		std::cout << "- receiving its request..." << std::endl;
		request = "";
		do {
			memset( buffer, 0, sizeof( buffer ) );
			try {
				recvCount = remoteClient->recv( buffer, sizeof( buffer ), NO_TIMEOUT );
				request += buffer;
			}
			catch (CBrokenSocketException) {
				std::cout << "Connection closed by remote host..." << std::endl;
				recvCount = 0;
			}
		} while (recvCount > 0 && remoteClient->waitForRead( 100 ) != SOCKET_TIMEOUT);

		// Send him the same information everytime
		// Oww! crap! No doctype ... and crappy headers too. but it works, so enjoy.
		std::cout << "- sending fake page..." << std::endl;
		data = "HTTP/1.1 200 OK\r\n"
			"Host: hello.it.s.me\r\n"
			"Server: my-server\r\n"
			"Content-type: text/html\r\n"
			"Connection: close\r\n"
			"\r\n"
			"<html>"
			"  <head>"
			"    <title>Hello from local HTTP server</title>"
			"    <style type='text/css'>h1 { color: navy; font-variant: small-caps; }</style>"
			"  </head>"
			"  <body>"
			"    <h1>You should know that ...</h1>"
			"    <ul>"
			"      <li>you just created your first HTTP server</li>"
			"      <li>your client uses IP address " + remoteClient->getRemoteEndpointIp() + "</li>"
			"    </ul>"
			"    <h1>Your client sends those headers</h1>"
			"    <pre>" + request + "</pre>"
			"  </body>"
			"</html>";
		remoteClient->send( data.c_str(), static_cast<unsigned short>(data.length()), NO_TIMEOUT );

		// Disconnect
		remoteClient->shutdown();
		delete remoteClient;
	}
	s.shutdown();

	return;
}


void testSocket() {
	std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	std::cout << "Using socket library version " << CSocket::getVersion() << " as of " << CSocket::geBuildDate() << std::endl;

	try {
		CSocket::initEngine();
		testNameResolution();
		testConnectGoogleAsHttpClient();
		testHttpServer();
	}
	//	catch (CBrokenSocketException &e) { }
	//	catch (CConnectionException &e) { }
	//	catch (CDnsResolutionException &e) { }
	//	catch (CServerSocketException &e) { }
	//	catch (CSocketIOException &e) { }
	catch (CException &e) {
		std::cerr << "** --- EXCEPTION THROWN ---" << std::endl;
		std::cerr << "** Type: " << e.getType() << std::endl;
		std::cerr << "** Message: " << e.getMessage() << std::endl;
		std::cerr << "** Error code: " << e.getErrorCode() << std::endl;
		std::cerr << "** Fault location: " << e.getFaultLocation() << std::endl;
	}

	CSocket::uninitEngine();

	std::cout << std::endl;
	return;
}
