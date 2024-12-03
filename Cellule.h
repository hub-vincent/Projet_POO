#pragma once
#include "Grille.h"
class Cellule
{
	int x;
	int y;
	bool val;
	std::vector<int> a = {};
	void ajouter_cellule();
};

