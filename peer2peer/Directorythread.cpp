#include <stdio.h>
#include <sys/types.h>
#include "ConfigurationInterne.h"
#include "Fichier.h"
#include <dirent.h>
#include <CLibSha224.h>
unsigned char isFile =0x8;


void directoryBrowse() {

	ConfigurationInterne config = ConfigurationInterne::getInstance();
    struct dirent *lecture;
    DIR *rep;
    rep = opendir(".");
    while ((lecture = readdir(rep))) {
        printf("%s\n", lecture->d_name);

		if (lecture->d_name == "." || lecture->d_name == ".." ) 
		{
			continue;
		}

		if (lecture->d_type == isFile)
		{
			continue;
		}
		CLibSha224 hash = CLibSha224(lecture->d_name);
		Fichier f =  Fichier(lecture->d_name, hash.getHash());
		config.addFichier(f);

    }
	
    closedir(rep);
}