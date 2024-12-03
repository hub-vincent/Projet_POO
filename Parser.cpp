#include "Parser.h"
#include "Cellule.h"

Parser::Parser(std::string lecture, std::string ecriture) : lecture(lecture), ecriture(ecriture)
{
	std::ifstream Lecture(this->lecture.c_str());
	std::ofstream Ecriture(this->ecriture.c_str());

	if (!Lecture)
	{
		std::cout << "LECTURE : fichier INVALIDE" << std::endl;
	}
	
	if (!Ecriture) 
	{
		std::cout << "ECRITURE : fichier INVALIDE" << std::endl;
	}

}

void Parser::lire()
{
	int grille_x;
	int grille_y;
	std::ifstream chaine(this->lecture.c_str());
	char character{}; //Initialisation de variables.
	chaine >> grille_x;
	chaine >> grille_y;
	std::cout << grille_x << std::endl;
	std::cout << grille_y << std::endl;
	Grille::grille_set(grille_x,grille_y);
	for (int i = 0; i < 50;i++)
	{

		chaine.get(character);
		std::cout << character << std::endl;
		if (character=='1' || character=='0') {
			std::cout << "1/0 :" << character << std::endl;
		}
	}
}

void Parser::ecrire()
{
	std::ofstream Ecrire(ecriture.c_str());
	if (Ecrire)  
	{
		Ecrire << "Bonjour, je suis une phrase écrite dans un fichier." << std::endl;
		Ecrire << 42.1337 << std::endl;
		Ecrire << "J'ai 32 ans." << std::endl;
	}
	Ecrire.close();  
}
