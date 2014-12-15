/*
Authors : CURTET Quentin, MORBOIS Antoine, LE BISSONNAIS Gautier, POUGET François.
Organisation : I4Initial EPSI Lyon
Année : 2014
*/
#ifndef POINT_H
#define POINT_H
#include <iostream>



using namespace std;

//Classe qui définit les méthodes et variables pour écrire dans les fichiers de log

class LOG
{
	public:
		LOG(); //Constructeur
		string ecrire(const string &s); //Méthode pour écrire dans le fichier de log simple
		sem_t mutex; //Mutex du fichier de log simple
		sem_t mutex_complexe; //Mutex du fichier de log complexe
		string ecrire_complexe(const string &s_complexe); //Méthode pour écrire dans le fichier de log complexe
		~LOG(); //Destructeur

	private:
		string s; //Variable qui reçoit les données à écrire dans le fichier de log simple
		string s_complexe; //Variable qui reçoit les données à écrire dans le fichier de log complexe
};
#endif