/*
Authors : CURTET Quentin, MORBOIS Antoine, LE BISSONNAIS Gautier, POUGET Fran�ois.
Organisation : I4Initial EPSI Lyon
Ann�e : 2014
*/
#include "ConfigurationInterne.h"

// Cr�ation de l'instance 
ConfigurationInterne ConfigurationInterne::m_instance=ConfigurationInterne();

// Constructeur -- Initialisation des listes, de la section critique et du log.
ConfigurationInterne::ConfigurationInterne()
{
	sem_init(&mutex, 0, 10);
	list<string> ListeServeur();
	list<string> ListeFichier();
	continu = true;
	LOG log; 
	string s="Configurationinterne :: cr�ation du singleton";
    log.ecrire(s);
}

// Destructeur
ConfigurationInterne::~ConfigurationInterne()
{
	LOG log; 
	string s="Configurationinterne :: destruction du singleton";
    log.ecrire(s);
}

// Retourne l'adresse du singleton
ConfigurationInterne& ConfigurationInterne::getInstanceRef()
{
	return m_instance;
}

// Retourne l'adresse du singleton
ConfigurationInterne* ConfigurationInterne::getInstance()
{
	ConfigurationInterne& interne = ConfigurationInterne::getInstanceRef();
	return &interne;
}

// Renvoie la liste de serveurs
list<string> ConfigurationInterne::getServeurs()
{
	return ListeServeur;
}

// Ajoute un serveur � la liste des serveurs : prot�g� par une section critique pour conserver l'int�grit� des donn�es
void ConfigurationInterne::addServeur(string toadd)
{
	sem_wait(&mutex);
	ListeServeur.push_back(toadd);
	LOG log; 
	string s="ConfigurationInterne :: Ajout du serveur " + toadd + " � la liste de serveurs";
    log.ecrire(s);
	sem_post(&mutex);
}

// Suppression d'un serveur, prot�g� par une section critique aussi.
void ConfigurationInterne::delServeur(string todel)
{
	sem_wait(&mutex);
	ListeServeur.remove(todel);
	LOG log; 
	string s="ConfigurationInterne :: Suppression du serveur " + todel + " de la liste de serveurs";
    log.ecrire(s);
	sem_post(&mutex);
}

// Ajout d'un fichier � la liste des fichiers, pas besoin d'�tre prot�g� par une s�maphore puisque tous les ajouts sont g�r�s dans un seul thread
void ConfigurationInterne::addFichier(Fichier f)
{
	ListeFichier.push_back(f);
	LOG log; 
	string s="ConfigurationInterne :: Ajout du fichier: " + f.getNomFichier() + "  � la liste de fichiers";
    log.ecrire(s);
}

// Renvoie la liste des fichiers
list<Fichier> ConfigurationInterne::getFichiers()
{
	return ListeFichier;
}

void ConfigurationInterne::setContinu(boolean p_b){
		continu = p_b;
}
boolean ConfigurationInterne::getContinu(){
		return continu;
}