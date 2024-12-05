#include "Cellule.h"

Cellule::Cellule(int index, bool b, int max_x) {
	x = index % max_x;
	y = (index - x) / max_x;
	val = b;
}

int Cellule::reveal_coordonates_y()
{
	return y;
}

int Cellule::reveal_coordonates_x()
{
	return x;
}

void Cellule::reveal_xy() {
	std::cout << x << " " << y << " " << val << std::endl;
}