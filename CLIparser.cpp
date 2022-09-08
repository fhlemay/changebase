#include <iostream>
#include <algorithm>

#include "changebase.hpp"

const int POSITION_NOMBRE = 1;
const int POSITION_BASE = 2;
const int POSITION_BASE_CIBLE = 3;
const int NBR_MIN_ARG = 1+2 ; //le nom de l'application fait partie des arguments. 

int CLIparser (int argc, char const *argv[], std::string &nombre, int &base, int &base_cible) {

    if(argc < NBR_MIN_ARG) {
        std::cerr << "[Erreur] Il faut au moins deux arguments après l'appel du programme : le nombre et sa base d'origine." << std::endl;
        return 0;
    }

    nombre = argv[POSITION_NOMBRE];
    std::transform(nombre.begin(), nombre.end(), nombre.begin(), ::toupper);

    try {
        base = std::stoi(argv[POSITION_BASE], nullptr, 10); // convertir base d'origine en int
    }
    catch(const std::invalid_argument& e) {
        std::cerr << "Le nombre de la base d'origine n'est pas valide.\n";
        return 0;
    }

    if(argc > NBR_MIN_ARG) {
        try {
            base_cible = std::stoi(argv[POSITION_BASE_CIBLE], nullptr, 10); // convertir la base cible en int
        }
        catch(const std::exception& e) {
            std::cerr << "Le nombre de la base cible n'est pas valide.\n";
            return 0;
        }
    }

    if (!(base >= 2 && base <=16) || !(base_cible >= 2 && base_cible <=16)) {
        std::cerr << "Une ou les deux bases n'est pas valide. Il faut une base entre 2 et 16.\n";
        return 0;
    }

    // validation du nombre en fonction de sa base
    for(char const &char_nombre: nombre){
        bool valide = false;
        for(int i = 0 ; i < base ; i++){
            if (char_nombre == CHIFFRES[i]) {
                valide = true;
                break;
            }
        }
        if(valide == false) {
            std::cout << "Le nombre est invalide car le chiffre " << char_nombre << " n'est pas valide dans la base " << base <<".\n";
            return 0;
        }
    }

    return 1;
}