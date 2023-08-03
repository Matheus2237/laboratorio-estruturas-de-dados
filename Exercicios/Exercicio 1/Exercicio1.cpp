/**
 * @brief Calcula a persistência multiplicativa de um número.
 * 
 * @author Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
 * @date 02/08/2023
 */

#include <cstdlib>
#include <iostream>
#include <string>

unsigned int persistencia(unsigned int);
std::string multiplica_algarismos(std::string);
void formata_resultado(unsigned int, unsigned int);

int main() {
    int numero_a = 39;
    int numero_b = 999;
    int numero_c = 4;

    std::cout << std::endl << "Valor --> Persistencia" << std::endl;
    formata_resultado(numero_a, persistencia(numero_a));
    formata_resultado(numero_b, persistencia(numero_b));
    formata_resultado(numero_c, persistencia(numero_c));

    return 0;
}

unsigned int persistencia(unsigned int num) {
    std::string s_num = std::to_string(num);
    if (s_num.length() == 1) return 0;
    
    unsigned int persistencia = 0;
    do {
        s_num = multiplica_algarismos(s_num);
        persistencia++;
    } while (s_num.length() != 1);
    
    return persistencia;
}

std::string multiplica_algarismos(std::string num) {
    unsigned int multiplicacao = 1;
    for (char algarismo : num) {
        multiplicacao *= atoi(&algarismo);
    }
    return std::to_string(multiplicacao);
}

void formata_resultado(unsigned int numero, unsigned int persistencia) {
    std::cout << numero << " --> " << persistencia << std::endl;
}