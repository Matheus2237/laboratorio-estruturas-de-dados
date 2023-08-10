/**
 * @brief Implementação do "Tribonacci", método análogo ao Fibonacci, porém considerando 3 elementos para a soma.
 *
 * @author Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
 * @date 08/08/2023
 */

#include <iostream>

unsigned int le_qtde_elementos();
unsigned int* le_assinatura();
void valida_qtde_elementos(unsigned int qtde_elementos, unsigned int* assinatura);
unsigned int* tribonacci(unsigned int qtde_elementos, unsigned int* assinatura);
void imprime_vetor(unsigned int* vetor, unsigned int tamanho_vetor);

int main() {

    std::cout << std::endl << "Tribonacci" << std::endl;
    unsigned int qtde_elementos = le_qtde_elementos();
    unsigned int* assinatura = le_assinatura();
    valida_qtde_elementos(qtde_elementos, assinatura);

    unsigned int* resultado = tribonacci(qtde_elementos, assinatura);
    imprime_vetor(resultado, qtde_elementos);
    std::cout << std::endl;

    delete[] resultado;
    delete[] assinatura;
}

unsigned int le_qtde_elementos() {
    std::cout << std::endl << "Quantidade de elementos: ";
    int qtde;
    std::cin >> qtde;
    return qtde;
}

unsigned int* le_assinatura() {
    unsigned int* assinatura = new unsigned int[3];
    std::cout << "Digite os 3 valores da assinatura:" << std::endl;
    for(int i = 0; i < 3; i++) {
        std::cout << "  " << i+1 << "º Valor: ";
        std::cin >> assinatura[i];
    }
    return assinatura;
}

void valida_qtde_elementos(unsigned int qtde_elementos, unsigned int* assinatura) {
    switch (qtde_elementos) {
        case 0:
        case 1:
        case 2:
        case 3:
            imprime_vetor(assinatura, qtde_elementos);
            std::cout << std::endl;
            exit(0);
            break;
        default:
            break;
    }
}

unsigned int* tribonacci(unsigned int qtde_elementos, unsigned int* assinatura) {
    unsigned int antepenultimo = assinatura[0];
    unsigned int penultimo = assinatura[1];
    unsigned int ultimo = assinatura[2];

    unsigned int* resultado = new unsigned int[3];
    resultado[0] = antepenultimo;
    resultado[1] = penultimo;
    resultado[2] = ultimo;

    for(int i = 3; i < qtde_elementos; i++) {
        resultado[i] = ultimo + penultimo + antepenultimo;
        antepenultimo = penultimo;
        penultimo = ultimo;
        ultimo = resultado[i];
    }

    return resultado;
}

void imprime_vetor(unsigned int* vetor, unsigned int tamanho_vetor) {
    std::cout << std::endl << "Resultado:" << std::endl << "[ ";
    for (int i = 0; i < tamanho_vetor; i++)
        std::cout << vetor[i] << " ";
    std::cout << "]";
}