#include "Cellule.h"

Cellule::Cellule(int index, bool b, int max_x) {
	x = index % max_x;
	y = (index - x) / max_x;
	val = b;
}