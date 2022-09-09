#include <iostream>
#include <cmath>
#include "changebase.hpp"

const char CHIFFRES[16] =   {'0','1','2','3',
                             '4','5','6','7',
                             '8','9','A','B',
                             'C','D','E','F'};

// TODO Comment faire si le nombre est binaire et négatif?
int convertBaseXtoBase10(std::string &nombre, int base){

    std::cout << "----------------------" << "--" << "----------------\n";
    std::cout << "Conversion de la base " << base << " à la base 10 : \n";
    std::cout << "----------------------" << "--" << "----------------\n";

    int puissance = nombre.size() - 1;
    int somme = 0;
    int somme_totale = 0;
    int negatif = 1;
    int position = 0;

    // si signe néatif présent
    if (nombre[position] == '-') {
        position = 1; // on saute le premier chiffre (qui est le signe)
        puissance--; // diminue la puissance car elle est basée sur le nombre de caractères
        negatif = -1; // coefficient négatif
    }

    for(int i = position ; i < nombre.size() ; i++, puissance--){

        int valeur_chiffre = 0;

        for (int j = 0; j < base ; j++){
            if (nombre[i] == CHIFFRES[j]){
                valeur_chiffre = j;
                break;
            }
        }

        // somme des (chiffre * base^(position-1))
        somme = negatif * valeur_chiffre * pow(base, puissance);
        somme_totale += somme;

        std::cout << negatif * valeur_chiffre << " * " << base << "^" << puissance << " = " << somme << std::endl;
    }
    std::cout << " Total : " << somme_totale << std::endl;
    return somme_totale;
}

void convertBase10toBaseY(std::string &nombre, int base_cible){

    std::cout << "-----------------------------------" << "--\n";
    std::cout << "Conversion de la base 10 à la base " << base_cible <<"\n";
    std::cout << "-----------------------------------" << "--\n";

}

// validation du nombre en fonction de sa base.
bool validerNombreBase(std::string nombre, int base){
    
    for(char const &char_nombre: nombre){

        for(int i = 0 ; i < base ; i++){

            if (char_nombre == '-') break; // si le nombre est négatif, on conserve le signe.
            if (char_nombre == CHIFFRES[i]) break;
        }
        return false; // le chiffre est invalide, donc le nombre l'est.
    }
    return true; // tous les chiffres sont valides, donc le nombre est valide.
}