#include <stdio.h>
#include <sys/types.h>
#include "ConfigurationInterne.h"
#include "Fichier.h"
#include <dirent.h>
#include <CLibSha224.h>


unsigned int isDirectory =16384;	//folder


void directoryBrowse() {

	ConfigurationInterne config = ConfigurationInterne::getInstance();
    struct dirent *lecture;
    DIR *rep;
	const char *path = "C:\\Users\\NEWBIE\\Desktop\\test";
    rep = opendir(path);
    while ((lecture = readdir(rep))) 
	{
        std::cout<< "nom fichier:  " << lecture->d_name <<std::endl;

		//we remove the directory + parent.
		if ( lecture->d_type == isDirectory) 
		{
			continue;
		}

		std::string  pathfile = string(path) + '\\' + lecture->d_name;
		CLibSha224 hash = CLibSha224(pathfile);
		Fichier f =  Fichier(lecture->d_name, hash.getHash());
		config.addFichier(f);

    }
	vector<Fichier> ls = config.ListeFichier;
	for(int i=0;ls.size();i++)
	{
		if (i == ls.size())
		{
			break;
		}
		std::cout << "liste fichier:" << i << "~" << config.ListeFichier[i].getNomFichier() <<std::endl;

		// ToDo => découper en bloc les fichiers
	}
	
    closedir(rep);
}