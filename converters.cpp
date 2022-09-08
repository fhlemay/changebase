#include <iostream>
#include <cmath>
#include "changebase.hpp"

void convertBaseXtoBase10(std::string &nombre, int base){

    // somme des (chiffre * base^(position-1))
    std::cout << "Conversion de la base " << base << " à la base 10 : \n";
    std::cout << "On additionne la multiplication des chiffres avec la base à la puissance de leur position.\n";
    std::cout << "somme des (chiffre * base^position)\n";

    int puissance = nombre.size() - 1;
    int somme = 0;
    int somme_totale = 0;

    for(int position = 0; position < nombre.size() ; position++, puissance--){

        int valeur_chiffre = 0;

        for (int j = 0; j < base ; j++){
            if (nombre[position] == CHIFFRES[j]){
                valeur_chiffre = j;
                break;
            }
        }

        somme = valeur_chiffre * pow(base, puissance);
        somme_totale += somme;

        std::cout << nombre[position] << " (" << valeur_chiffre << ") " << " * " << base << "^" << puissance << " = " << somme << " (total : " << somme_totale << ")" << std::endl;
    }
}

void convertBaseXtoBaseY(std::string &nombre, int base, int base_cible){

}