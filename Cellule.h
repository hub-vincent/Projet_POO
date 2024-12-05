#pragma once
#include "Grille.h"
class Cellule
{
private:
	int x;
	int y;
	bool val;
public:
	Cellule(int index, bool val, int X_max);
	int reveal_coordonates_x();
	int reveal_coordonates_y();
};

