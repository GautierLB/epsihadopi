/*
Authors : CURTET Quentin, MORBOIS Antoine, LE BISSONNAIS Gautier, POUGET François.
Organisation : I4Initial EPSI Lyon
Année : 2014
*/
#ifndef POINT_H
#define POINT_H
#include <iostream>



using namespace std;

class LOG
{
	public:
		LOG();
		string ecrire(const string &s);
		sem_t mutex;
		sem_t mutex_complexe;
		string ecrire_complexe(const string &s_complexe);
		~LOG();

	private:
		string s;
};
#endif