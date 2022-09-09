/*
 * Changer la base d'un nombre, en expliquant les étapes.
 * Utilisation : changebase <nombre> <base origine> <base cible>.
 * Outil pour le cours INF1427 Architecture des ordinateurs.
 * par flemay@gmail.com
 */
#include <iostream>
#include "changebase.hpp"

//int convertBaseXtoBase10(std::string &nombre, int base);

int main(int argc, char const *argv[]) // les espaces inutiles sont enlevés entre les arguments.
{
    std::string nombre;
    int base;
    int base_cible = 10; // par défaut si non spécifiée.

    if(!CLIparser(argc, argv, nombre, base, base_cible)){ // données cli non valides
        return 1;
    }

    std::cout << "nombre : " << nombre << " base : " << base << " base cible : " << base_cible << std::endl;

    if(base != 10) { //on converti en premier lieu le nombre d'origine en base 10. nombre_origine est modifié. 

        int tmp = convertBaseXtoBase10(nombre, base);
    }

    // if(base_cible != 10) on converti le nombre_origine, maintenant en base 10, vers la base cible.

    return 0;
}