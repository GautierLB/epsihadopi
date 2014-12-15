/*
Authors : CURTET Quentin, MORBOIS Antoine, LE BISSONNAIS Gautier, POUGET François.
Organisation : I4Initial EPSI Lyon
Année : 2014
*/
#include <iostream>
#include <fstream>
#include <string>
#include <semaphore.h> 
#include "Log.h"
#include "../libs/core/include/CDateTime.h"
#include "stdafx.h"

using namespace std;

LOG::LOG(){}; //Instanciation du constructeur

//Comptage des lignes de fichiers
int CountLines(std::ifstream& File) 
{ 
    int Count = 0; 
    while (File.ignore(std::numeric_limits<int>::max(), '\n')) {
        ++Count;  
	}
  
    return Count; 
}

//ecriture dans le fichier de log simple
string LOG::ecrire(const string &s)
{
	sem_init(&mutex, 0, 10);
	sem_wait(&mutex);
	// Ouvre le fichier de données :
	fstream f("log.txt",ios_base::in | ios_base::out | ios::ate);
	if (f.is_open())
	{
		CDateTime now;
		now.Now();
		// Écrit les données :
		string chaine;
		f << now.m_wYear << "-" << now.m_wMonth << "-" << now.m_wDay << " : " << now.m_wHour << "-" << now.m_wMinute << "-" << now.m_wSecond << "-" << now.m_wMilliseconds << " Infos : " << s << endl;
		// Lit les données :
		f >> chaine ;
		_int64 lines = std::count( 
			std::istreambuf_iterator<char>( f ), 
			std::istreambuf_iterator<char>(), '\n' );
		std::cout << s << std::endl;
		// Ferme le fichier :
		f.close();
	}

	std::ifstream File("log.txt"); 
    File.clear(); 
    File.seekg(0, std::ios::beg); 
	
	return "";
	sem_post(&mutex);
}

//ecriture dans le fichier de log complexe
string LOG::ecrire_complexe(const string &s_complexe)
{
	sem_init(&mutex_complexe, 0, 10);
	sem_wait(&mutex_complexe);
	// Ouvre le fichier de données :
	fstream f("log_complexe.txt",ios_base::in | ios_base::out | ios::ate);
	if (f.is_open())
	{
		CDateTime now;
		now.Now();
		// Écrit les données :
		string chaine;
		f << now.m_wYear << "-" << now.m_wMonth << "-" << now.m_wDay << " : " << now.m_wHour << "-" << now.m_wMinute << "-" << now.m_wSecond << "-" << now.m_wMilliseconds << " Infos : " << s_complexe << endl;
		// Lit les données :
		f >> chaine ;
		_int64 lines = std::count( 
			std::istreambuf_iterator<char>( f ), 
			std::istreambuf_iterator<char>(), '\n' );
		std::cout << s_complexe << std::endl;
		// Ferme le fichier :
		f.close();
	}

	std::ifstream File("log_complexe.txt"); 
    File.clear(); 
    File.seekg(0, std::ios::beg); 

	return "";
	sem_post(&mutex_complexe);
}


LOG::~LOG(){}; //Instanciation du destructeur