/**
 * @brief Encontra, dentro de um vetor, o número inteiro que possui ocorrência 
 *      ímpar.
 * 
 * @author Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
 * @date 02/08/2023
 */

#include <iostream>

unsigned int encontra_incidencia_impar(int*, unsigned int);
bool eh_impar(int);
void formata_resultado(int*, unsigned int, unsigned int);
void imprime_vetor(int*, unsigned int);

int main() {
    int tamanho_vetor_a = 1;
    int vetor_a[tamanho_vetor_a] = {7};
 
    int tamanho_vetor_b = 1;
    int vetor_b[tamanho_vetor_b] = {0};
 
    int tamanho_vetor_c = 3;
    int vetor_c[tamanho_vetor_c] = {1, 1, 2};
 
    int tamanho_vetor_d = 5;
    int vetor_d[tamanho_vetor_d] = {0, 1, 0, 1, 0};
 
    int tamanho_vetor_e = 13;
    int vetor_e[tamanho_vetor_e] = {1, 2, 2, 3, 3, 3, 4, 3, 3, 3, 2, 2, 1};

    formata_resultado(vetor_a, tamanho_vetor_a, encontra_incidencia_impar(vetor_a, tamanho_vetor_a));
    formata_resultado(vetor_b, tamanho_vetor_b, encontra_incidencia_impar(vetor_b, tamanho_vetor_b));
    formata_resultado(vetor_c, tamanho_vetor_c, encontra_incidencia_impar(vetor_c, tamanho_vetor_c));
    formata_resultado(vetor_d, tamanho_vetor_d, encontra_incidencia_impar(vetor_d, tamanho_vetor_d));
    formata_resultado(vetor_e, tamanho_vetor_e, encontra_incidencia_impar(vetor_e, tamanho_vetor_e));

    return 0;
}

unsigned int encontra_incidencia_impar(int* vetor, unsigned int tamanho_vetor) {
    int incidencia_impar = 0;
    for (int i = 0; i < tamanho_vetor; i++) {
        int incidencia = 0;
        for (int j = 0; j < tamanho_vetor; j++)
            if(vetor[i] == vetor[j])
                incidencia++;
        if(eh_impar(incidencia)) {
            incidencia_impar = vetor[i];
            break;
        }
    }
    return incidencia_impar;
}

bool eh_impar(int numero) {
    return numero % 2 == 1;
}

void formata_resultado(int* vetor, unsigned int tamanho_vetor, unsigned int incidencia_impar) {
    imprime_vetor(vetor, tamanho_vetor);
    std::cout << " --> " << incidencia_impar << std::endl;
}

void imprime_vetor(int* vetor, unsigned int tamanho_vetor) {
    std::cout << "[ ";
    for (int i = 0; i < tamanho_vetor; i++)
        std::cout << vetor[i] << " ";
    std::cout << "]";
}