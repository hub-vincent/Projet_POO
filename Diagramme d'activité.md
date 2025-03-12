graph TD
    A(Début) --> B(Demander fichier d'entrée)
    B --> C{Fichier valide ?}
    C -- Oui --> D(Demander type de grille : Classique :0: ou Torique :1:)
    C -- Non --> X(Erreur : Fichier invalide) --> Z(Fin)

    D --> E(Demander mode d'affichage : Console :0: ou Graphique :1:)
    E --> F(Demander nombre d'itérations)
    F -->|Si mode Graphique| G(Demander délai entre itérations)
    F -->|Si mode Console| H(Lire fichier et initialiser grille)
    G --> H

    H --> I{Mode choisi ?}
    I -- Console --> J(Afficher grille initiale dans la console)
    I -- Graphique --> K(Ouvrir fenêtre SFML)

    subgraph Mode Console
        J --> L(Loop : Effectuer les itérations)
        L --> M(Mettre à jour et afficher la grille après chaque itération)
        M --> N(Enregistrer état dans .txt)
        N -->|Itérations restantes ?| L
        N -->|Fin des itérations| Y(Affichage final de la grille)
    end

    subgraph Mode Graphique
        K --> P(Loop : Effectuer les itérations)
        P --> Q(Mettre à jour affichage SFML)
        Q --> R(Attendre délai entre itérations)
        R -->|Itérations restantes ?| P
        R -->|Fin des itérations ou Escape pressée| S(Fermer la fenêtre SFML)
        S --> Y
    end

    Y --> Z(Fin)
