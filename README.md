# Projet Jeu De La Vie

Ceci est un projet académique basé sur le **Jeu de la Vie de Conway**, implémenté en **C++** sous **Linux Ubuntu** en utilisant **Visual Studio Code**. Il propose une simulation du célèbre automate cellulaire avec un affichage en console et une version graphique grâce à la bibliothèque **SFML**.

## Dépendances
Avant de compiler et d'exécuter le projet, assurez-vous d'installer les dépendances nécessaires sur votre environnement Linux Ubuntu :

### Installation de Clang++ (compilateur)
Le projet est compilé avec `clang++`, assurez-vous qu'il est installé :
```bash
sudo apt-get install clang
```

### Installation de SFML (affichage graphique)
Le programme utilise la bibliothèque **SFML** pour le rendu graphique :
```bash
sudo apt-get install libsfml-dev
```

## Lancement du jeu
### Compilation via terminal
Placez-vous dans le répertoire du projet et compilez avec **Makefile** :
```bash
make
```
Cela génère un exécutable nommé `main`.

### Exécution
Lancez ensuite l'exécutable en ligne de commande :
```bash
./main
```
Suivez ensuite les instructions pour choisir :
1. Le fichier de configuration (matrice de départ).
2. Le type de grille (**classique** ou **torique**).
3. Le mode d'affichage (**console** ou **graphique**).
4. Le nombre d'itérations.

## Compatibilité avec Visual Studio Code
Le projet est conçu pour être utilisé sous **Visual Studio Code** sur **Linux Ubuntu**. Il vous suffit d'ouvrir le dossier contenant le projet avec **VS Code** et d'utiliser le **Makefile** pour compiler et exécuter.

