/*
Authors : CURTET Quentin, MORBOIS Antoine, LE BISSONNAIS Gautier, POUGET Fran�ois.
Organisation : I4Initial EPSI Lyon
Ann�e : 2014
*/
#include "Configuration.h"

using namespace std;

// Cr�ation de l'instance
Configuration Configuration::m_instance=Configuration();

// Constructeur -- param�tres de base : 5 connections max serveurs, 5 envois simultan�s max, 5 r�c�ptions simultan�es max, 1000ms entre chaque scan de fichiers
Configuration::Configuration()
{
	nbConnectionServeur = 5;
	nbEnvoieSimultane = 5;
	nbReceptionSimultane = 5;
	ipReseau = "127.0.0.";
	timeOutScan = 1000;
	LOG log; 
	string s="Configuration :: Cr�ation du signleton, Nombre connections serveur = " + std::to_string(nbConnectionServeur) + " Nombre envois simultan�s " +
		std::to_string(nbEnvoieSimultane) + " Nombre receptions simultan�es " + std::to_string(nbReceptionSimultane)+ " timeoutscan " + std::to_string(timeOutScan) ;
    log.ecrire(s);
}

// Destructeur
Configuration::~Configuration()
{
	LOG log; 
	string s="Configuration :: Destruction du singleton";
    log.ecrire(s);
}

// Retourne l'adresse du singleton
Configuration& Configuration::getInstanceRef()
{
	static Configuration m_instance;
	return m_instance;
}

// Retourne l'adresse du singleton
Configuration* Configuration::getInstance()
{
	Configuration& config = Configuration::getInstanceRef();
	return &config;
}

// Modifie le nombre de connections max serveur
void Configuration::setNbConnectionServeur(int nb)
{
	nbConnectionServeur = nb;
	LOG log; 
	string s="Configuration :: Modification du nombre de connections serveur : " + std::to_string(nb);
    log.ecrire(s);
}

// Modifie le temps entre chaque scan des fichiers
void Configuration::setTimeOutScan(int time)
{
	timeOutScan = time;
	LOG log; 
	string s="Configuration :: Modification du timeout : " + std::to_string(time);
    log.ecrire(s);
}

// Modifie le nombre d'envois simultan�s
void Configuration::setNbEnvoieSimultane(int nb)
{
	nbEnvoieSimultane = nb;
	LOG log; 
	string s="Configuration :: Modification du nombre d'envois simultan�s : " + std::to_string(nb);
    log.ecrire(s);
}

// Modifie le nombre de r�c�ptions simultan�es
void Configuration::setNbReceptionSimultane(int nb)
{
	nbReceptionSimultane = nb;
	LOG log; 
	string s="Configuration :: Modification du nombre de r�c�ptions simultan�es : " + std::to_string(nb);
    log.ecrire(s);
}

// Renvoie le nombre de connexions serveurs
int Configuration::getNbConnectionServeur()
{
	return nbConnectionServeur;
}

// Renvoie le temps entre chaque scan de fichiers
int Configuration::getTimeOutScan()
{
	return timeOutScan;
}

// Renvoie le nombre d'envois simultan�s max
int Configuration::getNbEnvoieSimultane()
{
	return nbEnvoieSimultane;
}

// Renvoie le nombre de r�c�ptions simultan�es
int Configuration::getNbReceptionSimultane()
{
	return nbReceptionSimultane;
}

string Configuration::getIpReseau()
{
	return ipReseau;
}

// Renvoie le nombre de r�c�ptions simultan�es
void Configuration::setIpReseau(string ip)
{
	ipReseau =ip;
	
}

