#include <stdio.h>
#include <sys/types.h>
#include "ConfigurationInterne.h"
#include "Fichier.h"
#include <dirent.h>
#include <CLibSha224.h>


void directoryBrowse() {

	ConfigurationInterne config = ConfigurationInterne::getInstance();
    struct dirent *lecture;
    DIR *rep;
    rep = opendir(".");
    while ((lecture = readdir(rep))) {
        printf("%s\n", lecture->d_name);

		if (*lecture->d_name == "." || *lecture->d_name == "." ) {
			continue;
		}
		if (lecture->d_type == isFile()){
			continue;
		}
		std::string hash = CLibSha224(lecture->d_name);
		Fichier f =  Fichier(lecture->d_name, hash);
		config.ListeFichier.push_back(f);

    }
	
    closedir(rep);
}