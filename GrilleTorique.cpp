#include "GrilleTorique.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

GrilleTorique::GrilleTorique(std::string a) : Grille(a){}



void GrilleTorique::iteration(int n, bool choix) {
    for (int i = 0; i < n; i++) {
        std::vector<int> viv = {};
        std::vector<int> morts = {};
        
        // Analyser toutes les cellules
        for (const auto& c : cellules) {
            int cel_index = c.return_index();
            int cel_y = c.return_y();
            int cel_x = c.return_x();
            int vivantesvoisines = 0;
            
            // Compter les voisins vivants avec gestion torique
            for (const auto& f : cellules) {
                // Vérifier si c'est un voisin en calculant directement dans la condition
                if (((std::min(std::abs(cel_x - f.return_x()), x - std::abs(cel_x - f.return_x())) <= 1) && 
                     (std::min(std::abs(cel_y - f.return_y()), y - std::abs(cel_y - f.return_y())) <= 1) &&
                     !(cel_x == f.return_x() && cel_y == f.return_y())) && // Exclure la cellule elle-même
                     f.return_state() == 1) {
                    vivantesvoisines++;
                }
            }
            
            // Déterminer les cellules qui changent d'état
            if (c.return_state() == 1) {
                if (!(vivantesvoisines == 2 || vivantesvoisines == 3)) {
                    morts.push_back(cel_index);
                }
            }
            else {
                if (vivantesvoisines == 3) {
                    viv.push_back(cel_index);
                }
            }
        }
        
        // Appliquer les changements après avoir analysé toutes les cellules
        for (const auto& a : viv) {
            cellules[a].change_state(1);
        }
        for (const auto& b : morts) {
            cellules[b].change_state(0);
        }
        
        // Affichage et écriture
        if (choix == 0) {
            Grille::afficher_Grille();
        }
        ecrireFichier(i);
    }
}
