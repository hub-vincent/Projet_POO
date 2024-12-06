#pragma once
#include "Grille.h"


class GrilleTorique : public Grille
{
	public:
	void iteration(int n) override;
	void ecrireFichier();
	void lireFichier();
	GrilleTorique(std::string lecture, std::string ecriture);
	void afficher_Grille();

};

