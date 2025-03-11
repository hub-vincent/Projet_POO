#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Grille.h"
#include "GrilleTorique.h"
#include "GrilleClassique.h"

int main()
{
    int a;
    int b = 300;
    bool choix;
    std::string fichierEntree = "Matrice2.txt";
    std::cout << "Choisissez le fichier a consommer" << std::endl;
    std::cin >> fichierEntree;
    if (std::ifstream(fichierEntree).is_open() == false){
        std::cout << "LECTURE : fichier INVALIDE" << std::endl;
        return 0;
    }
    GrilleTorique existance(fichierEntree);
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
    std::cout << "Choissisez le nombre de temps entre itérations en milliseconde" << std::endl;
    std::cin >> b;
    existance.lireFichier();
    existance.afficherGraphique(a,b);  // Lancement de l'affichage SFML
    existance.afficher_Grille();
    }
    return 0;
}

    //GrilleTorique B("Matrice2.txt", "Matrice_out.txt");
    //B.lireFichier();
    //B.afficher_Grille();
    //B.iteration(2);
