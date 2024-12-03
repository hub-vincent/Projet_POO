#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Grille.h"
#include "Cellule.h"

class Parser
{
private:
	std::string lecture;
	std::string ecriture;
	std::string ligne; 

public:

	Parser() = default;
	Parser(std::string lecture,std::string ecriture);
	void lire();
	void ecrire();

/*"C:\Users\Vincent\OneDrive - Association Cesi Viacesi mail\Documents\Test_POO.txt"*/
};

