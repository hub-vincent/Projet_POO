// Projet_POO.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Grille.h"
#include "GrilleTorique.h"

int main()
{
    Grille Existance("C:/Users/Vincent/source/repos/Projet_POO/Matrice.txt", "C:/Users/Vincent/source/repos/Projet_POO/Tests.txt");
    Existance.lireFichier();
    Existance.iteration(4);
    Existance.ecrireFichier();
    std::cout << " " << std::endl;
    GrilleTorique B("C:/Users/Vincent/source/repos/Projet_POO/Matrice2.txt", "C:/Users/Vincent/source/repos/Projet_POO/Matrice_out.txt");
    B.lireFichier();
    B.afficher_Grille();
    Existance.afficher_Grille();
    B.iteration(2);
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
