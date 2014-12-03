#ifndef POINT_H
#define POINT_H
#include <iostream>



using namespace std;

class LOG
{
	public:
		LOG();
		string ecrire(const string &s);
		~LOG();

	private:
		string s;
};
#endif