#pragma once
#include <vector>
#include <iostream>
#include "Cellule.h"
class Grille
{
	private:
	int x=0;
	int y=0;
	std::string lecture;
	std::string ecriture;
	std::string ligne;
	public:
	Grille(std::string lecture, std::string ecriture);
	void iteration(int n);
	void afficher_Grille();
	void lireFichier();
	void ecrireFichier();
};

