#include "ConfigurationInterne.h"

/*/
void ConfigurationInterne::DeclarationListeFichier(int nbFichier)
{
	static  liste_fichier[nbFichier];

}*/

ConfigurationInterne ConfigurationInterne::m_instance=ConfigurationInterne();

ConfigurationInterne::ConfigurationInterne()
{
}

ConfigurationInterne::~ConfigurationInterne()
{

}

ConfigurationInterne& ConfigurationInterne::getInstance()
{
    return m_instance;
}