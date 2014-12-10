#include <iostream>
#include <fstream>
#include <string>
#include "Log.h"
#include "../libs/core/include/CDateTime.h"
#include "stdafx.h"

using namespace std;

LOG::LOG(){}; //Instanciation du constructeur

int CountLines(std::ifstream& File) 
{ 
    int Count = 0; 
    while (File.ignore(std::numeric_limits<int>::max(), '\n')) {
        ++Count;  
	}
  
    return Count; 
}

string LOG::ecrire(const string &s)
{
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
		std::cout << lines << std::endl;
		std::cout << s << std::endl;
		// Ferme le fichier :
		f.close();
	}

	std::ifstream File("log.txt"); 
  
    std::cout << CountLines(File) << std::endl; 
  
    File.clear(); 
    File.seekg(0, std::ios::beg); 
  
    std::cout << CountLines(File) << std::endl; 
	
	return "";
}

string LOG::ecrire_complexe(const string &s_complexe)
{
	// Ouvre le fichier de données :
	fstream f("log_complexe.txt",ios_base::in | ios_base::out | ios::ate);
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
		std::cout << lines << std::endl;
		std::cout << s << std::endl;
		// Ferme le fichier :
		f.close();
	}

	std::ifstream File("log_complexe.txt"); 
  
    std::cout << CountLines(File) << std::endl; 
  
    File.clear(); 
    File.seekg(0, std::ios::beg); 
  
    std::cout << CountLines(File) << std::endl; 
	
	return "";
}


LOG::~LOG(){}; //Instanciation du destructeur