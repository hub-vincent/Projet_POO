#include "GrilleTorique.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>


GrilleTorique::GrilleTorique(std::string a, std::string b) : Grille(a,b){}

void GrilleTorique::afficher_Grille()
{
	Grille::afficher_Grille();
}


void GrilleTorique::iteration(int n)
{
	/*/for (int i = 0; i < n; i++) {
		std::vector<int> viv = {};
		std::vector<int> morts = {};
		int vivantesvoisines = 0;
		for (auto& c : return_cellules()) {
			int cel_index = c.return_index();
			int cel_x = c.return_x();
			int cel_y = c.return_y();
			bool cel_state = c.return_state();
			for (auto& f : return_cellules())
			{
				if ((((cel_x - f.return_x()) % x) <= 1) && (((cel_x - f.return_x()) % x) >= -1) && 
					(((cel_y - f.return_y()) % y) <= 1) && (((cel_y - f.return_y()) % y) >= -1) &&
					!(cel_y == f.return_y() && cel_x == f.return_x()) && //Exclusion de la cellule même.
					f.return_state() == 1)	
					{
					vivantesvoisines = +1;
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
			for (const auto& a : viv) {
				return_cellules()[a].change_state(1);
			}

			for (const auto& b : morts) {
				return_cellules()[b].change_state(0);
			}
			Grille::afficher_Grille();
		}
	}/*/
}

void GrilleTorique::ecrireFichier()
{
	Grille::ecrireFichier();
}

void GrilleTorique::lireFichier()
{
	Grille::lireFichier();
}


