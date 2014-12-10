#include "ConfigurationInterne.h"
ConfigurationInterne ConfigurationInterne::m_instance=ConfigurationInterne();
ConfigurationInterne::ConfigurationInterne()
{
	sem_init(&mutex, 0, 10);
	std::list<string> ListeServeur();
}

ConfigurationInterne::~ConfigurationInterne()
{
	 cout<<"Creation"<<endl;
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

void ConfigurationInterne::addServeur(string *toadd)
{
	sem_wait(&mutex);
	ListeServeur.push_back(toadd);
	sem_post(&mutex);
}

void ConfigurationInterne::addFichier(Fichier f)
{
	sem_wait(&mutex);
	ListeFichier.push_back(f);
	sem_post(&mutex);
}