/*
Authors : CURTET Quentin, MORBOIS Antoine, LE BISSONNAIS Gautier, POUGET Fran�ois.
Organisation : I4Initial EPSI Lyon
Ann�e : 2014
*/
#include "Block.h"

//Constructeur de la classe Block
Block::Block(int p_numero,std::string p_content)
{
	content = p_content;
	numero = p_numero;
}

//Destructeur
Block::~Block()
{
}

//Obtenir le contenu des blocs
std::string Block::getContent(){
	return content;
}

//Obtenir le num�ro du bloc
int Block::getNumero(){
	return numero;
}