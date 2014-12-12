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

