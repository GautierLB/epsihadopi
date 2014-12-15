/*
Authors : CURTET Quentin, MORBOIS Antoine, LE BISSONNAIS Gautier, POUGET Fran�ois.
Organisation : I4Initial EPSI Lyon
Ann�e : 2014
*/
#pragma once
#include <string>
#include "stdafx.h"


class Block
{
	public:
		Block(int p_numero,std::string p_content); //Constructeur
		~Block(); //Destructeur

		std::string getContent(); //Contenu du bloc
		int getNumero(); //Num�ro du bloc


	private:
		std::string content;
		int numero;
};

