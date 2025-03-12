#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "GrilleClassique.h"
#include "GrilleTorique.h"  // Assure-toi que cette classe est bien définie

class Jeu {
private:
    std::string fichierEntree;
    int iterations;
    int delai;
    bool modeConsole;
    bool choixGrille;

public:
    Jeu();  // Constructeur
    void lancer();  // Démarrer le jeu
};