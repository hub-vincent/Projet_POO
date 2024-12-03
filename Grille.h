#pragma once
#include <vector>
#include <iostream>
class Grille
{
	private:
	int x=0;
	int y=0;
	std::string lecture;
	std::string ecriture;
	std::string ligne;
	std::vector<int> a{};
	public:
	Grille(std::string lecture, std::string ecriture);
	void generer_Grille();
	void afficher_Grille();
	void lire();
	void ecrire();
	void set_Grille(int a, int b);
};

