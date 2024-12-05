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
	virtual bool testUnitaire(std::string a);
	virtual void iteration(int n);
	virtual void afficher_Grille() const;
	virtual void lireFichier();
	virtual void ecrireFichier();
};

