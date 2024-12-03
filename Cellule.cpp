#include "Cellule.h"

Cellule::Cellule(int index, bool b, int max_x) {
	x = index % max_x;
	y = (index - x) / max_x;
	val = b;
}

void Cellule::reveal_xy() {
	std::cout << x << " " << y << " " << val << std::endl;
}