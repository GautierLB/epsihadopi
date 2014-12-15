/*
Authors : CURTET Quentin, MORBOIS Antoine, LE BISSONNAIS Gautier, POUGET François.
Organisation : I4Initial EPSI Lyon
Année : 2014
*/
#pragma once
#include <string>
#include "stdafx.h"


class Block
{
	public:
		Block(int p_numero,std::string p_content);
		~Block();

		std::string getContent();
		int getNumero();


	private:
		std::string content;
		int numero;
};

