#include "Grille.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
std::vector<Cellule> cellules;



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


void Grille::lireFichier()
{
	std::ifstream chaine(this->lecture.c_str()); 
	chaine >> x;
	chaine >> y;
	int valCell;
	int index = -1;
	for (int i = 0; i < x * y;i++)
	{
		std::string nom_cellule;
		chaine >> valCell;
		if (valCell == 1 || valCell == 0) {
				index += 1;
				nom_cellule = "Cellule_" + std::to_string(index);
				std::cout << "Index:" << index << ".Charactere:" << valCell << std::endl;
				std::cout << nom_cellule << std::endl;
				cellules.emplace_back(index, valCell, this->x);
			}
	}
}



void Grille::ecrireFichier()
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
	std::cout << "Taille du tableau:" << cellules.size() << std::endl;
	for (const auto& c : cellules) {
		c.afficher();
		std::cout << " ";
	}
}
