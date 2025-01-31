#pragma once
#include "Grille.h"

class GrilleTorique : public Grille
{
    public:
    void iteration(int n, bool choix) override;
    GrilleTorique(std::string lecture);

};
