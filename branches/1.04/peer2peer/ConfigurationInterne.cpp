/*
Authors : CURTET Quentin, MORBOIS Antoine, LE BISSONNAIS Gautier, POUGET François.
Organisation : I4Initial EPSI Lyon
Année : 2014
*/
#include "ConfigurationInterne.h"
ConfigurationInterne ConfigurationInterne::m_instance=ConfigurationInterne();
ConfigurationInterne::ConfigurationInterne()
{
	sem_init(&mutex, 0, 10);
	list<string> ListeServeur();
	list<string> ListeFichier();
	LOG log; 
	string s="Configurationinterne :: création du singleton";
    log.ecrire(s);
}

ConfigurationInterne::~ConfigurationInterne()
{
	LOG log; 
	string s="Configurationinterne :: destruction du singleton";
    log.ecrire(s);
}

ConfigurationInterne& ConfigurationInterne::getInstanceRef()
{
	return m_instance;
}
ConfigurationInterne* ConfigurationInterne::getInstance()
{
	ConfigurationInterne& interne = ConfigurationInterne::getInstanceRef();
	return &interne;
}

list<string> ConfigurationInterne::getServeurs()
{
	return ListeServeur;
}
void ConfigurationInterne::addServeur(string toadd)
{
	sem_wait(&mutex);
	ListeServeur.push_back(toadd);
	LOG log; 
	string s="ConfigurationInterne :: Ajout du serveur " + toadd + " à la liste de serveurs";
    log.ecrire(s);
	sem_post(&mutex);
}

void ConfigurationInterne::delServeur(string todel)
{
	sem_wait(&mutex);
	ListeServeur.remove(todel);
	LOG log; 
	string s="ConfigurationInterne :: Suppression du serveur " + todel + " de la liste de serveurs";
    log.ecrire(s);
	sem_post(&mutex);
}


void ConfigurationInterne::addFichier(Fichier f)
{
	sem_wait(&mutex);
	ListeFichier.push_back(f);
	sem_post(&mutex);
}

list<Fichier> ConfigurationInterne::getFichiers()
{
	return ListeFichier;
}
/*
Fichier ConfigurationInterne::getFichierById(int idFichier)
{
	 //return ListeFichier.find_element(idFichier);
	//return ListeFichier[idFichier];
	Fichier f = Fichier();
	return f;
}*/

string ConfigurationInterne::getNomFichierId(int idFichier)
{ 
	//return ListeFichier[idFichier].getNomFichier();
	return "";
}

void ConfigurationInterne::setNomFichierId(int idFichier, string filename)
{
	//ListeFichier[idFichier].setNomFichier(filename);
}


string ConfigurationInterne::getPathFileId(int idFichier)
{
	//return ListeFichier[idFichier].getPathFile();
	return "";
}

