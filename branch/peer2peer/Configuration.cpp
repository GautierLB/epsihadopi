#include "Configuration.h"
#include <string>

using namespace std;

Configuration Configuration::m_instance=Configuration();

Configuration::Configuration()
{
   
}

Configuration::~Configuration()
{

}

Configuration& Configuration::getInstance()
{
    return m_instance;
}
