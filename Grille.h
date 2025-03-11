#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>//ajout
#include "Cellule.h"

class Grille
{
    protected:
    int x=0;
    int y=0;
    std::string lecture;
    std::string ecriture;
    std::string ligne;
    public:
    
    std::vector<Cellule> cellules;

    Grille() = default;
    Grille(std::string lecture);
    virtual void iteration(int n, bool choix);
    virtual void afficher_Grille();
    virtual int afficherGraphique(int max_it, int clock);//ajout
    virtual void lireFichier();
    virtual void ecrireFichier(int a);
    virtual void clear();
    //std::vector<Cellule>& return_cellules();
    virtual bool verifierSolution(const std::string& cheminSolution);// testUnitaire
};
