#include "ConfigurationInterne.h"

/*/
void ConfigurationInterne::DeclarationListeFichier(int nbFichier)
{
	static  liste_fichier[nbFichier];

}*/

ConfigurationInterne ConfigurationInterne::m_instance=ConfigurationInterne();

ConfigurationInterne::ConfigurationInterne()
{
	sem_init(&mutex, 0, 1);
}

ConfigurationInterne::~ConfigurationInterne()
{

}

ConfigurationInterne& ConfigurationInterne::getInstance()
{
    return m_instance;
}

void ConfigurationInterne::addServeur()
{
	sem_wait(&mutex);
	ListeFichier;
	sem_post(&mutex);
}