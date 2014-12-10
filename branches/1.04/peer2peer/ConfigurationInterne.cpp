#include "ConfigurationInterne.h"
ConfigurationInterne ConfigurationInterne::m_instance=ConfigurationInterne();
ConfigurationInterne::ConfigurationInterne()
{
	sem_init(&mutex, 0, 10);
	std::list<string> ListeServeur();
}

ConfigurationInterne::~ConfigurationInterne()
{
	 cout<<"** Configurationintrne:Destruction Singleton"<<endl;
}

ConfigurationInterne& ConfigurationInterne::getInstanceRef()
{
	static ConfigurationInterne m_instance;
	return m_instance;
}
ConfigurationInterne* ConfigurationInterne::getInstance()
{
	ConfigurationInterne& interne = ConfigurationInterne::getInstanceRef();
	return &interne;
}

list<string *> ConfigurationInterne::getServeurs()
{
	return ListeServeur;
}
void ConfigurationInterne::addServeur(string *toadd)
{
	sem_wait(&mutex);
	LOG log; 
	string s="Ajout du serveur " + *toadd + " à la liste de serveurs";
    log.ecrire(s);
	ListeServeur.push_back(toadd);
	sem_post(&mutex);
}

void ConfigurationInterne::delServeur(string *todel)
{
	sem_wait(&mutex);
	ListeServeur.remove(todel);
	sem_post(&mutex);
}


void ConfigurationInterne::addFichier(Fichier f)
{
	sem_wait(&mutex);
	ListeFichier.push_back(f);
	sem_post(&mutex);
}