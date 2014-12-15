/*
Authors : CURTET Quentin, MORBOIS Antoine, LE BISSONNAIS Gautier, POUGET François.
Organisation : I4Initial EPSI Lyon
Année : 2014
*/
#include <stdio.h>
#include <sys/types.h>
#include "ConfigurationInterne.h"
#include "Fichier.h"
#include "Block.h"
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
	ConfigurationInterne* config= ConfigurationInterne::getInstance();
	struct dirent *lecture;
	DIR *rep;
	const char *path = ".\\Synchro";
	
	LOG log; 
	rep = opendir(path);
	unsigned int i=0;
	unsigned char buffer[] = "AZERTYUIOPLLKJHGFDSQX";

	while (lecture = readdir(rep))
	{

		std::vector<std::string> cnt;
		std::vector<Block> vb;
		std::string  pathfile = string(path) + '\\' + lecture->d_name;
		
		
		//we remove the directory + parent.
		if ( lecture->d_type == isDirectory) 
		{
			continue;
		}
		CLibSha224 hash = CLibSha224(pathfile);
		

		// découpage en blocs
		CFileBinary fin(pathfile);
		fin.open( EFileOpenMode::read );
		int nbBlock = floor(fin.getFileSize()/20);
		
		for(int a = 0;a<nbBlock;a++)
		{
		   memset( buffer, 0, sizeof( buffer ) );
		   fin.readData( 20, buffer, sizeof( buffer ) );

		   std::string temp="";
		   for(int j=0;j<21;j++){
			   temp += buffer[j];
		   }
		   Block b = Block(a,temp);
		   vb.push_back(b);
			
			
		}
		Fichier f =  Fichier(lecture->d_name, hash.getHash(),pathfile, vb);

		config->addFichier(f);
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
//	pthread_join( t1, &result );
	return;
}

void compareFile(string p_nom, string p_hash)
{
	ConfigurationInterne configInt = *ConfigurationInterne::getInstance();
	unsigned int i;
	for (i=0;i<configInt.getFichiers().size();i++)
	{
		if(configInt.getNomFichierId(i) == p_nom)
		{
			string p_name = p_nom + "(2)";
			configInt.setNomFichierId(i,p_name);
		}
		
	}

}