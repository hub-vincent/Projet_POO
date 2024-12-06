#pragma once
#include "Grille.h"


class GrilleTorique : public Grille
{
	public:
	void iteration(int n) override;
	void ecrireFichier() override;
	void lireFichier() override;
	GrilleTorique(std::string lecture, std::string ecriture);
	void afficher_Grille() override;

};

