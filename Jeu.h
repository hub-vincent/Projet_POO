#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "GrilleClassique.h"
#include "GrilleTorique.h"  // Assure-toi que cette classe est bien définie
#include <cassert>
#include <sstream>
#include "Cellule.h"
#include "Grille.h"


class Jeu {
private:
    std::string fichierEntree;
    int iterations;
    int delai;
    bool modeConsole;
    bool choixGrille;

public:
    Jeu();  
    void lancer();  
};