#include "Jeu.h"

Jeu::Jeu() {
    std::cout << "Choisissez le fichier a consommer: ";
    std::cin >> fichierEntree;

    if (!std::ifstream(fichierEntree).is_open()) {
        std::cout << "LECTURE : fichier INVALIDE" << std::endl;
        exit(0);
    }

    std::cout<< "Choisissez la grille 0(Classique), 1(Torique): ";
    std::cin >> choixGrille;


    std::cout << "Choisissez le mode 0(Console), 1(Graphique): ";
    std::cin >> modeConsole;

    std::cout << "Choisissez le nombre d'iterations (nombre entier): ";
    std::cin >> iterations;

    if (modeConsole) {
        std::cout << "Choisissez le temps entre iterations en millisecondes: ";
        std::cin >> delai;
    }
}

void Jeu::lancer() {
    GrilleClassique existance(fichierEntree);
    GrilleTorique Existance(fichierEntree);
    existance.lireFichier();
    if (!choixGrille){
        std::cout << "Classique" << std::endl;
        existance.lireFichier();
        if (!modeConsole){
            existance.iteration(iterations, modeConsole);
            std::cout << std::endl;
            // existance.verifierSolution(fichierEntree);
        } else{
            existance.afficherGraphique(iterations, delai);
        }
    }
    else{
        //std::cout<<"Torique" << std::endl;
        Existance.lireFichier();
        if (!modeConsole){
            Existance.iteration(iterations, modeConsole);
            std::cout << std::endl;
            // Existance.verifierSolution(fichierEntree);
        } else{
            Existance.afficherGraphique(iterations, delai);
        }

    }
}
