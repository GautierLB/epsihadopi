#include <stdio.h>
#include <sys/types.h>
#include "ConfigurationInterne.h"
#include "Fichier.h"
#include <pthread.h>
#include <dirent.h>
#include <CLibSha224.h>
#include "Directorythread.h"
#include "CFileBinary.h"

#include <string>
#include <iostream>
#include <ostream>

int isDirectory =16384;	//folder


void *DirectoryBrowseFunc(void *p_arg)
{

	ConfigurationInterne config = *ConfigurationInterne::getInstance();
	struct dirent *lecture;
	DIR *rep;
	//const char *path = ".\\";
	const char *path = "C:\\Users\\quent_000\\Desktop\\test";
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
		config.addFichier(f);

	}
	
	unsigned int i=0;
	unsigned char buffer[] = "AZERTYUIOPLLKJHGFDSQX";
	
	while(i != config.ListeFichier.size())
	{
		//std::list<string> blocs = ls[i];

		std::cout << "fichier: " << i << " ~ " << config.ListeFichier[i].getNomFichier() <<std::endl;
		CFileBinary fin( config.ListeFichier[i].getPathFile());
		std::cout << "fichier: " << config.ListeFichier[i].getNomFichier() << "~" <<  fin.getFileSize() << " byte(s)." << std::endl;
		fin.open( EFileOpenMode::read );
		int nbBlock = floor(fin.getFileSize()/20);
		

		for(int a = 0;a<nbBlock;a++)
		{
		   memset( buffer, 0, sizeof( buffer ) );
		   unsigned char r = fin.readData( 20, buffer, sizeof( buffer ) ) ;	
		/*   std::string str( r, r + sizeof r / sizeof r );
		   config.ListeFichier[i].listeBlocks.push_back(str);*/
		}
		
		i++;
	}


	
	i=0;
	while(i != config.ListeFichier.size())
	{
		int a=0;
		while(a != config.ListeFichier[i].getListeBlocks().size())
		{
			std::cout <<   "    block N:"<<  a << " => " <<  config.ListeFichier[i].listeBlocks[a] << std::endl;
			//std::cout << "block:  " << ls[i].listeBlocks[a] << std::endl;
			a++;
		}

	}
	
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
	if (pthread_create( &t1, 0,DirectoryBrowseFunc,(void *) 1) != 0) 
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