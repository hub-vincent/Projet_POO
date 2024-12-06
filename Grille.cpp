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
}



void Grille::iteration(int n)
{
	for (int i = 0; i < n; i++) {
		std::vector<int> viv = {};
		std::vector<int> morts = {};
		for (const auto& c : cellules) {
			int cel_index = c.return_index();
			int y_co = c.return_y();
			int x_co = c.return_x();
			int vivantesvoisines = 0;
			for (const auto& e : cellules) {
				if ((y_co - e.return_y() >= -1 && y_co - e.return_y() <= 1) &&
					(x_co - e.return_x() >= -1 && x_co - e.return_x() <= 1) &&
					!(y_co == e.return_y() && x_co == e.return_x()) && //Exclusion de la cellule même.
					e.return_state() == 1) {
					vivantesvoisines++;
				}
			}

			if (c.return_state() == 1) {
				if (!(vivantesvoisines == 2 || vivantesvoisines == 3)) {
					morts.push_back(cel_index);
				}
			}
			else {
				if (vivantesvoisines == 3) {
					viv.push_back(cel_index);
				}
			}
		}
		for (const auto& a : viv) {
			cellules[a].change_state(1);
		}

		for (const auto& b : morts) {
			cellules[b].change_state(0);
		}
		Grille::afficher_Grille();
	}
}


void Grille::lireFichier()
{
	Grille::clear();
	std::ifstream chaine(this->lecture.c_str()); 
	chaine >> x;
	chaine >> y;
	int valCell;
	int index = -1;
	for (int i = 0; i < x * y;i++)
	{
		chaine >> valCell;
		if (valCell == 1 || valCell == 0) {
				index += 1;
				cellules.emplace_back(index, valCell, this->x);
		}
	}
}


void Grille::ecrireFichier() 
{
	std::ofstream Ecrire(ecriture.c_str());
	if (Ecrire)
	{
		Ecrire << "Fichier ecriture:" << std::endl;
		for (const auto& c : cellules) {
			Ecrire << c.return_state() << " ";
			if (c.return_x() == (x - 1))
			{
				Ecrire << "" << std::endl;
			}
		}
	}
	Ecrire.close();
}

void Grille::clear()
{
	cellules.clear();
}

//std::vector<Cellule>& Grille::return_cellules() {return cellules; }


void Grille::afficher_Grille() const
{
	std::cout << "Taille du tableau : " << cellules.size() << std::endl;
	for (const auto& c : cellules) {
		std::cout << c.return_state();
		std::cout << " ";
		if (c.return_x() == (x-1))
		{
			std::cout << "" << std::endl;
		}
	}
}
