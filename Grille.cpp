#include "Grille.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>


Grille::Grille(std::string lecture, std::string ecriture) : lecture(lecture), ecriture(ecriture)
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


void Grille::lire()
{
	std::ifstream chaine(this->lecture.c_str());
	char character{}; //Initialisation de variables.
	chaine >> x;
	chaine >> y;
	int index = -1;
	for (int i = 0; i < 50;i++)
	{
		chaine.get(character);
		std::string nom_cellule = "Cellule_";
		if (character == '1' || character == '0') {
			index +=1;
			nom_cellule += std::to_string(index);
			std::cout << "Index:" << index << ".Charactere:" << character << std::endl;
			std::cout << nom_cellule << std::endl;
			Cellule nom_cellule(index,character,this->x);
		}
	}
}



void Grille::ecrire()
{
	std::ofstream Ecrire(ecriture.c_str());
	if (Ecrire)
	{
		Ecrire << "Bonjour, je suis une phrase écrite dans un fichier." << std::endl;
		Ecrire << x << std::endl;
		Ecrire << "J'ai 32 ans." << std::endl;
	}
	Ecrire.close();
}

void Grille::generer_Grille()
{
	for (int i = 0; i <= x; i++)
	{
		for (int j = 0; j <= y;j++)
		{
			a.push_back(i);
			a.push_back(j);
		}
	}
}

void Grille::afficher_Grille()
{
	for (int val : a) {
		std::cout << val << " ";
	}
}

void Grille::set_Grille(int a, int b)
{
	x = a;
	y = b;
}
