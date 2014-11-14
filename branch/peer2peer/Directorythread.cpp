#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include "ConfigurationInterne.h"

void directoryBrowse() {

    struct dirent *lecture;
    DIR *rep;
    rep = opendir(".");
    while ((lecture = readdir(rep))) {
        printf("%s\n", lecture->d_name);
    }
	
    closedir(rep);
}