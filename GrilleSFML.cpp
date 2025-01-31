#include "GrilleSFML.h"
#include "Grille.h"
#include "Cellule.h"

GrilleSFML::GrilleSFML(std::string lecture) : Grille(lecture) {}

void GrilleSFML::afficherGraphique() {
    const int cellSize = 20;  // Taille des cellules
    sf::RenderWindow window(sf::VideoMode(x * cellSize, y * cellSize), "Jeu de la Vie et de la mort");
    
    //int iterations = 10;
    sf::Clock clock;  //temps entre itérations

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (clock.getElapsedTime().asSeconds() > 300) {
            iteration(1,1);
            clock.restart();
        }

        window.clear(sf::Color::Black);

        for (const auto& c : cellules) {
            sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));
            cell.setPosition(c.return_x() * cellSize, c.return_y() * cellSize);
            cell.setFillColor(c.return_state() ? sf::Color::White : sf::Color::Black);
            window.draw(cell);
        }

        window.display();
    }
}
