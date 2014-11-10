#include "Configuration.h"
#include <string>

using namespace std;

Configuration::Configuration()
{

}


Configuration::~Configuration()
{
}

Configuration* Configuration::getInstance()
{
	if (NULL == config){
		config = new Configuration();
	}
	return config;
}
