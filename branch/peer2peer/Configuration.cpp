#include "Configuration.h"
#include <string>

using namespace std;

Configuration Configuration::m_instance=Configuration();

Configuration::Configuration()
{
   nbConnectionServeur = 5;
   nbEnvoieSimultane = 5;
   nbReceptionSimultane = 5;
   timeOutScan = 1000;
}

Configuration::~Configuration()
{

}

Configuration& Configuration::getInstance()
{
    return m_instance;
}

// Setters
void Configuration::setNbConnectionServeur(int nb)
{
	nbConnectionServeur = nb;
}

void Configuration::setTimeOutScan(int time)
{
	timeOutScan = time;
}

void Configuration::setNbEnvoieSimultane(int nb)
{
	nbEnvoieSimultane = nb;
}

void Configuration::setNbReceptionSimultane(int nb)
{
	nbReceptionSimultane = nb;
}

//Getters

int Configuration::getNbConnectionServeur()
{
	return nbConnectionServeur;
}

int Configuration::getTimeOutScan()
{
	return timeOutScan;
}

int Configuration::getNbEnvoieSimultane()
{
	return nbEnvoieSimultane;
}

int Configuration::getNbReceptionSimultane()
{
	return nbReceptionSimultane;
}
