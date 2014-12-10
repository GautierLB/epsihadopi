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