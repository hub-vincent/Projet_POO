#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Grille.h"
#include "GrilleTorique.h"
#include "GrilleClassique.h"
#include "GrilleSFML.h"

int main()
{
   int a;
    bool choix;
    std::string fichierEntree = "Matrice.txt";
    std::cout << "Choisissez le fichier a consommer" << std::endl;
    std::cin >> fichierEntree;
    GrilleClassique existance(fichierEntree);
    std::cout << "Choissisez le mode 0(Console), 1(Graphique)" << std::endl;
    std::cin >> choix;
    std::cout << "Choissisez le nombre d'iterations (nombre entier)" << std::endl;
    std::cin >> a;
    if (choix == 0) {
        existance.lireFichier();
        existance.iteration(a, choix);
        std::cout << " " << std::endl;
        existance.afficher_Grille();
        std::string cheminSolution = "Matrice2.txt";
        existance.verifierSolution(cheminSolution);
    }
    else
    {
    //test model graphique
    GrilleSFML Existence("Matrice.txt");
    Existence.lireFichier();
    Existence.iteration(a,1);
    Existence.afficherGraphique();  // Lancement de l'affichage SFML
    Existence.afficher_Grille();
    }
    return 0;
}

    //GrilleTorique B("Matrice2.txt", "Matrice_out.txt");
    //B.lireFichier();
    //B.afficher_Grille();
    //B.iteration(2);
