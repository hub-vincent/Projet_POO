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
	void reveal_xy();
};

