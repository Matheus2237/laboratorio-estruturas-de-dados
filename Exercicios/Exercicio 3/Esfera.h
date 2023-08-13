#ifndef ESFERA_H
#define ESFERA_H

#define PI 3.14159265359

/**
 * @brief Representação de uma esfera.
 * 
 */
class Esfera {
private:
    double raio;

public:

    /**
     * @brief Constroi um novo objeto do tipo Esfera.
     * 
     * @param raio Raio da esfera
     */
    Esfera(double raio);

    /**
     * @brief Recupera o raio do objeto.
     * 
     * @return double Valor do raio do objeto
     */
    double getRaio();

    /**
     * @brief Calcula a área da esfera.
     * 
     * @return double Valor da área da esfera
     */
    double calculaArea();

    /**
     * @brief Calcula o volume da esfera.
     * 
     * @return double Valor do volume da esfera.
     */
    double calculaVolume();
};

#endif