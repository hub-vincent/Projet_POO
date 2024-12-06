#pragma once
#include <vector>
#include <iostream>

#include "Cellule.h"

class Grille
{
	protected:
	int x=0;
	int y=0;
	std::string lecture;
	std::string ecriture;
	std::string ligne;
	public:
	Grille() = default;
	Grille(std::string lecture, std::string ecriture);
	virtual void iteration(int n);
	virtual void afficher_Grille() const;
	virtual void lireFichier();
	virtual void ecrireFichier();
	virtual void clear();
	//std::vector<Cellule>& return_cellules();
};




