/*
Authors : CURTET Quentin, MORBOIS Antoine, LE BISSONNAIS Gautier, POUGET Fran�ois.
Organisation : I4Initial EPSI Lyon
Ann�e : 2014
*/
#include "Configuration.h"

using namespace std;

//Configuration Configuration::m_instance=Configuration();

Configuration::Configuration()
{
	nbConnectionServeur = 5;
	nbEnvoieSimultane = 5;
	nbReceptionSimultane = 5;
	timeOutScan = 1000;
	LOG log; 
	string s="Configuration :: Cr�ation du signleton, Nombre connections serveur = " + std::to_string(nbConnectionServeur) + " Nombre envois simultan�s " +
		std::to_string(nbEnvoieSimultane) + " Nombre receptions simultan�es " + std::to_string(nbReceptionSimultane)+ " timeoutscan " + std::to_string(timeOutScan) ;
    log.ecrire(s);
}

Configuration::~Configuration()
{
	LOG log; 
	string s="Configuration :: Destruction du singleton";
    log.ecrire(s);
}

Configuration& Configuration::getInstanceRef()
{
	static Configuration m_instance;
	return m_instance;
}
Configuration* Configuration::getInstance()
{
	Configuration& config = Configuration::getInstanceRef();
	return &config;
}


// Setters
void Configuration::setNbConnectionServeur(int nb)
{
	nbConnectionServeur = nb;
	LOG log; 
	string s="Configuration :: Modification du nombre de connections serveur : " + std::to_string(nb);
    log.ecrire(s);
}

void Configuration::setTimeOutScan(int time)
{
	timeOutScan = time;
	LOG log; 
	string s="Configuration :: Modification du timeout : " + std::to_string(time);
    log.ecrire(s);
}

void Configuration::setNbEnvoieSimultane(int nb)
{
	nbEnvoieSimultane = nb;
	LOG log; 
	string s="Configuration :: Modification du nombre d'envois simultan�s : " + std::to_string(nb);
    log.ecrire(s);
}

void Configuration::setNbReceptionSimultane(int nb)
{
	nbReceptionSimultane = nb;
	LOG log; 
	string s="Configuration :: Modification du nombre de r�c�ptions simultan�es : " + std::to_string(nb);
    log.ecrire(s);
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
