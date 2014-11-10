//#include "stdafx.h"
#include <iostream>


#include "..\libs\socket\include\CSocketIp4.h"
#include "..\libs\exception\include\CException.h"


void Server() {

	// On passe le pointeur null à notre variable s, et on définie les paramètres du serveur
	CSocketIp4 s, *remoteClient = nullptr;


	unsigned short maxConnexion = 5;
	unsigned short port = 666;

	std::cout << std::endl;
	std::cout << "Création du serveur sur le port 666" << std::endl;
	system("pause");

	// création du serveur, possibilité de rajouter le protocole en paramètre
	s.server(port, maxConnexion);
	//s.server(5,666);
	

	for (;;) {
		std::string data, request;
		int recvCount = 0;
		char buffer[1024];


		std::cout << "En attente de connextion..." << std::endl;

		//si un client se connecte, on le récupère
		remoteClient = dynamic_cast<CSocketIp4 *>(s.accept());

		std::cout << "Connection du client: " << remoteClient->getRemoteEndpointIp() << " on port " << remoteClient->getRemoteEndpointPort() << std::endl;

		// Receive whole response with 100ms timeout
		// !! WARNING !! a nicer way to handle this request is to check for end-of-request instead of foolishly wait for 100ms
		std::cout << "- récupération de la reqête" << std::endl;
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

		// récupérer bloc a envoyer


		remoteClient->send(data.c_str(), static_cast<unsigned short>(data.length()), NO_TIMEOUT);

		// l'envoie est terminé, déconnexion
		remoteClient->shutdown();
		delete remoteClient;
	}

	// Thread terminé, on "éteint" le serveur
	s.shutdown();

	return;
}