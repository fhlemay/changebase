const char CHIFFRES[16] =   {'0','1','2','3',
                             '4','5','6','7',
                             '8','9','A','B',
                             'C','D','E','F'};

int CLIparser (int argc, char const *argv[], std::string &nombre, int &base, int &base_cible);
void convertBaseXtoBase10(std::string &nombre, int base);