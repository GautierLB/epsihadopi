/*
Authors : CURTET Quentin, MORBOIS Antoine, LE BISSONNAIS Gautier, POUGET Fran�ois.
Organisation : I4Initial EPSI Lyon
Ann�e : 2014
*/
#ifndef POINT_H
#define POINT_H
#include <iostream>



using namespace std;

//Classe qui d�finit les m�thodes et variables pour �crire dans les fichiers de log

class LOG
{
	public:
		LOG(); //Constructeur
		string ecrire(const string &s); //M�thode pour �crire dans le fichier de log simple
		sem_t mutex; //Mutex du fichier de log simple
		sem_t mutex_complexe; //Mutex du fichier de log complexe
		string ecrire_complexe(const string &s_complexe); //M�thode pour �crire dans le fichier de log complexe
		~LOG(); //Destructeur

	private:
		string s; //Variable qui re�oit les donn�es � �crire dans le fichier de log simple
		string s_complexe; //Variable qui re�oit les donn�es � �crire dans le fichier de log complexe
};
#endif