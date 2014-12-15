#include "ConfigurationInterne.h"
ConfigurationInterne ConfigurationInterne::m_instance=ConfigurationInterne();
ConfigurationInterne::ConfigurationInterne()
{
	sem_init(&mutex, 0, 10);
	std::list<string> ListeServeur();
	LOG log; 
	string s="Configurationinterne :: cr�ation du singleton";
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
	string s="ConfigurationInterne :: Ajout du serveur " + toadd + " � la liste de serveurs";
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

vector<Fichier> ConfigurationInterne::getFichiers()
{
	return ListeFichier;
}

Fichier ConfigurationInterne::getFichierById(int idFichier)
{
	 
	return ListeFichier[idFichier];
}

string ConfigurationInterne::getNomFichierId(int idFichier)
{ 
	return ListeFichier[idFichier].getNomFichier();
}

void ConfigurationInterne::setNomFichierId(int idFichier, string filename)
{
	ListeFichier[idFichier].setNomFichier(filename);
}


string ConfigurationInterne::getPathFileId(int idFichier)
{
	return ListeFichier[idFichier].getPathFile();
}
