#include "Grille.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

Grille::Grille(std::string lecture) : lecture(lecture)
{
    std::ifstream Lecture(this->lecture.c_str());
    //std::ofstream Ecriture(this->ecriture.c_str());
}


void Grille::iteration(int n, bool choix)
{

    for (int i = 0; i < n; i++) {
        std::vector<int> viv = {};
        std::vector<int> morts = {};
        for (const auto& c : cellules) {
            int cel_index = c.return_index();
            int y_co = c.return_y();
            int x_co = c.return_x();
            int vivantesvoisines = 0;
            for (const auto& e : cellules) {
                if ((y_co - e.return_y() >= -1 && y_co - e.return_y() <= 1) &&
                    (x_co - e.return_x() >= -1 && x_co - e.return_x() <= 1) &&
                    !(y_co == e.return_y() && x_co == e.return_x()) && //Exclusion de la cellule même.
                    e.return_state() == 1) {
                    vivantesvoisines++;
                }
            }

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
        for (const auto& a : viv) {
            cellules[a].change_state(1);
        }

        for (const auto& b : morts) {
            cellules[b].change_state(0);
        }
        if (choix==0) {
        Grille::afficher_Grille();
        }
        ecrireFichier(i);
    }

}


void Grille::lireFichier()
{
    Grille::clear();
    std::ifstream chaine(this->lecture.c_str()); 
    chaine >> x;
    chaine >> y;
    int valCell;
    int index = -1;
    for (int i = 0; i < x * y;i++)
    {
        chaine >> valCell;
        if (valCell == 1 || valCell == 0) {
                index += 1;
                cellules.emplace_back(index, valCell, this->x);
        }
    }
}

void Grille::ecrireFichier(int a) 
{
    ecriture = lecture.substr(0, lecture.size() - 4) + "_out" + std::to_string(a) + ".txt";
    std::ofstream Ecrire(ecriture.c_str());
    if (Ecrire)
    {
        Ecrire << "Fichier ecriture:" << std::endl;
        for (const auto& c : cellules) {
            Ecrire << c.return_state() << " ";
            if (c.return_x() == (x - 1))
            {
                Ecrire << "" << std::endl;
            }
        }
    }
    
    Ecrire.close();
}

void Grille::clear()
{
    cellules.clear();
}

//std::vector<Cellule>& Grille::return_cellules() {return cellules; }

void Grille::afficher_Grille()
{
    std::cout << "Taille du tableau : " << cellules.size() << std::endl;
    for (const auto& c : cellules) {
        std::cout << c.return_state();
        std::cout << " ";
        if (c.return_x() == (x-1))
        {
            std::cout << "" << std::endl;
        }
    }
}

bool Grille::verifierSolution(const std::string& cheminSolution)
{
    //ouverture
    std::ifstream fichierSolution(cheminSolution.c_str());
    if (!fichierSolution) {
        std::cerr << "Pas de fichier." << std::endl;
        return false;
    }
    //lecture
    std::vector<int> solutionEtats;
    int valCell;
    while (fichierSolution >> valCell) {
        solutionEtats.push_back(valCell);
    }
    
    // Verification
    for (size_t i = 0; i < cellules.size(); ++i) {
        if (cellules[i].return_state() != solutionEtats[i]) {
            std::cerr << "Erreur" << std::endl;
            return false;
        }
    }

    std::cout << "Les matrices sont identiques !" << std::endl;
    return true;

    
}



int Grille::afficherGraphique(int max_it,int clock/*temps entre itérations*/) {
    const int cellSize = 20;  // Taille des cellules
    sf::RenderWindow window(sf::VideoMode(x * cellSize, y * cellSize), "Jeu de la Vie");
    sf::Event event;

    int c=0; //compteur
    Grille* grille = this;

    while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && (c < max_it)) {
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
                return 0;
            }
        }

        sf::sleep(sf::milliseconds(clock));
        grille->iteration(1, 1);
        c++;

        window.clear(sf::Color::Black);

        for (const auto& c : cellules) {
            sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));
            cell.setPosition(c.return_x() * cellSize, c.return_y() * cellSize);
            cell.setFillColor(c.return_state() ? sf::Color::White : sf::Color::Black);
            window.draw(cell);
        }

        window.display();
    }
    while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
                return 0;
            }
        }
    }
    return 0;
}
