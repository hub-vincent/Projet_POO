#pragma once

#include "Grille.h"
#include <SFML/Graphics.hpp>

class GrilleSFML : public Grille {
public:
    GrilleSFML(std::string lecture);
    void afficherGraphique();
};
