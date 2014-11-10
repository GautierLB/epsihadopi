#include "Configuration.h"
#include <string>

using namespace std;

Configuration::Configuration()
{

}


Configuration::~Configuration()
{
}

Configuration* Configuration::getConfig()
{
	if (config != NULL){
		return config;
	} else {
		Configuration *toCreate = new Configuration();
		config = toCreate;
		return config;
	}
}
