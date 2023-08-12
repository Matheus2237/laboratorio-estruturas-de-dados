/**
 * @brief Desenvolvimento de um TAD de uma esfera.
 *
 * @author Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
 * @date 12/08/2023
 */

#include <iostream>
#include "Esfera.h"

namespace Exibicao {
    const std::string tab = "  ";
    void imprime_informacoes(Esfera esfera);
}

int main() {
    Esfera esfera(15);
    Exibicao::imprime_informacoes(esfera);
}

void Exibicao::imprime_informacoes(Esfera esfera) {
    std::cout << std::endl << "Informacoes da esfera:" << std::endl;
    std::cout << Exibicao::tab << "raio: " << esfera.getRaio() << " U.C." << std::endl;
    std::cout << Exibicao::tab << "area: " << esfera.calculaArea() << " U.A." << std::endl;
    std::cout << Exibicao::tab << "volume: " << esfera.calculaVolume() << " U.V." << std::endl;
}