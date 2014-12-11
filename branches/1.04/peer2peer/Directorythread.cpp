#include <stdio.h>
#include <sys/types.h>
#include "ConfigurationInterne.h"
#include "Fichier.h"
#include <pthread.h>
#include <dirent.h>
#include <CLibSha224.h>
#include "Directorythread.h"
#include "CFileBinary.h"
#include "CFileText.h"

#include <string>
#include <iostream>
#include <ostream>

int isDirectory =16384;	//folder


void *directoryBrowseFunc(void *p_arg)
{

	ConfigurationInterne configInt = *ConfigurationInterne::getInstance();
	struct dirent *lecture;
	DIR *rep;
	//const char *path = ".\\";
	//const char *path = "C:\\Users\\quent_000\\Desktop\\test";
	const char *path = "C:\\Users\\Fran\\Desktop\\python";
	LOG log; 
	rep = opendir(path);

	while ((lecture = readdir(rep))) 
	{

		std::vector<std::string> cnt;
		std::string  pathfile = string(path) + '\\' + lecture->d_name;
		
		
		//we remove the directory + parent.
		if ( lecture->d_type == isDirectory) 
		{
			continue;
		}
		CLibSha224 hash = CLibSha224(pathfile);
		Fichier f =  Fichier(lecture->d_name, hash.getHash(),pathfile);
		configInt.addFichier(f);

	}
	
	unsigned int i=0;
	unsigned char buffer[] = "AZERTYUIOPLLKJHGFDSQX";
	
	while(i != configInt.ListeFichier.size())
	{
		//std::list<string> blocs = ls[i];

		std::cout << "fichier: " << i << " ~ " << configInt.ListeFichier[i].getNomFichier() <<std::endl;
		CFileBinary fin( configInt.ListeFichier[i].getPathFile());
		std::cout << "fichier: " << configInt.ListeFichier[i].getNomFichier() << "~" <<  fin.getFileSize() << " byte(s)." << std::endl;
		fin.open( EFileOpenMode::read );
		int nbBlock = floor(fin.getFileSize()/20);
		

		/*for(int a = 0;a<nbBlock;a++)
		{
		   memset( buffer, 0, sizeof( buffer ) );
		   fin.readData( 20, buffer, sizeof( buffer ) );

		   std::string temp="";
		   for(int j=0;j<21;j++){
			   temp += buffer[j];
		   }
		   
			string ligne="DirectoryThread :: fichier:"+ configInt.ListeFichier[i].getNomFichier() +"->"+"block N'" + std::to_string(a); 
			log.ecrire(ligne);
		    configInt.ListeFichier[i].listeBlocks.push_back(temp);
		}
	*/
		i++;
	}

/* 
affichage de debug qui liste les bloques
	
	i=0;/*
	while(i != config.ListeFichier.size())
	{
		int a=0;
		while(a != config.ListeFichier[i].getListeBlocks().size())
		{
			std::cout <<   "    block N:"<<  a << " => " <<  config.ListeFichier[i].listeBlocks[a] << std::endl;
			a++;
		}
		i++;

	}
*/
	closedir(rep);
	return nullptr;
}

void directoryThread() 
{
	pthread_t t1;

	void *result = nullptr;

	std::cout << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	std::cout << "** Creating Directory thread..." << std::endl;
	if (pthread_create( &t1, 0,directoryBrowseFunc,(void *) 1) != 0) 
	{
		std::cerr << "** FAIL Creation Directory Thread" << std::endl;
		return;
	}
	else 
	{
		std::cout << "** Directory Thread creation OK" << std::endl;
	}

	std::cout << "** Waiting..." << std::endl;
	pthread_join( t1, &result );
	return;
}

void compareFile(string p_nom, string p_hash)
{
	ConfigurationInterne configInt = *ConfigurationInterne::getInstance();
	unsigned int i;
	for (i=0;i<configInt.ListeFichier.size();i++)
	{
		if(configInt.ListeFichier[i].getNomFichier() == p_nom)
		{
			string p_name = p_nom + "(2)";
			configInt.ListeFichier[i].setNomFichier(p_name);
		}
		
	}

}