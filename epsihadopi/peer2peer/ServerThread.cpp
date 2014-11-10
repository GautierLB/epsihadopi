//#include "stdafx.h"
#include <iostream>


#include "..\libs\socket\include\CSocketIp4.h"
#include "..\libs\exception\include\CException.h"


void Server() {

	// On passe le pointeur null � notre variable s, et on d�finie les param�tres du serveur
	CSocketIp4 s, *remoteClient = nullptr;


	unsigned short maxConnexion = 5;
	unsigned short port = 666;

	std::cout << std::endl;
	std::cout << "Cr�ation du serveur sur le port 666" << std::endl;
	system("pause");

	// cr�ation du serveur, possibilit� de rajouter le protocole en param�tre
	s.server(port, maxConnexion);
	//s.server(5,666);
	

	for (;;) {
		std::string data, request;
		int recvCount = 0;
		char buffer[1024];


		std::cout << "En attente de connextion..." << std::endl;

		//si un client se connecte, on le r�cup�re
		remoteClient = dynamic_cast<CSocketIp4 *>(s.accept());

		std::cout << "Connection du client: " << remoteClient->getRemoteEndpointIp() << " on port " << remoteClient->getRemoteEndpointPort() << std::endl;

		// Receive whole response with 100ms timeout
		// !! WARNING !! a nicer way to handle this request is to check for end-of-request instead of foolishly wait for 100ms
		std::cout << "- r�cup�ration de la req�te" << std::endl;
		request = "";
		do {
			memset(buffer, 0, sizeof(buffer));
			std::cout << "wait" << std::endl;
			try {
				recvCount = remoteClient->recv(buffer, sizeof(buffer), NO_TIMEOUT);
				request += buffer;
			}

			// Si le client ne donne plus de signe de vie
			catch (CBrokenSocketException) {
				std::cout << "Connexion interrompu avec le client" << std::endl;
				recvCount = 0;
			}
		} while (recvCount > 0 && remoteClient->waitForRead(100) != SOCKET_TIMEOUT);


		// To Do

		// r�cup�rer bloc a envoyer


		remoteClient->send(data.c_str(), static_cast<unsigned short>(data.length()), NO_TIMEOUT);

		// l'envoie est termin�, d�connexion
		remoteClient->shutdown();
		delete remoteClient;
	}

	// Thread termin�, on "�teint" le serveur
	s.shutdown();

	return;
}