/*
Authors : CURTET Quentin, MORBOIS Antoine, LE BISSONNAIS Gautier, POUGET François.
Organisation : I4Initial EPSI Lyon
Année : 2014
*/
#include "Block.h"

Block::Block(int p_numero,std::string p_content)
{
	content = p_content;
	numero = p_numero;
}

Block::~Block()
{
}

std::string Block::getContent(){
	return content;
}
int Block::getNumero(){
	return numero;
}