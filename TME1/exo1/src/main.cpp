#include "List.h"
#include <string>
#include <iostream>
#include <cstring>

int main () {

	std::string abc = "abc";
	// FAUTE: le tableau de char str nécessite un espace pour le terminateur null
	// char * str = new char[3];
	char * str = new char[4];
	str[3] = '\0'; // Mettre le terminateur null
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	size_t i = 0;

	if (! strcmp (str, abc.c_str())) {
		std::cout << "Equal !";
	}

	pr::List list;
	list.push_front(abc);

	std::cout << "Liste : " << list << std::endl;
	std::cout << "Taille : " << list.size() << std::endl;

	// FAUTE: Boucle infinie due à un débordement d'entier non signé
	// for (i = list.size() - 1; i >= 0; i--)
	for (i = list.size(); i-- > 0; ){
		std::cout << "elt " << i << ": " << list[i] << std::endl;
	}

	// FAUTE: Suppression des caractères individuels dans un tableau de char
	// for (char *cp = str; *cp; cp++) {
	//     delete cp;
	// }
	// La bonne façon de supprimer le tableau :
	delete[] str;


}
