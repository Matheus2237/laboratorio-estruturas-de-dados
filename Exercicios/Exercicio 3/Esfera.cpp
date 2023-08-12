#include <cmath>
#include "Esfera.h"

Esfera::Esfera(double raio):
    raio(raio)
{}

double Esfera::getRaio() {
    return this->raio;
}

double Esfera::calculaArea() {
    return 4 * PI * pow(this->raio, 2);
}

double Esfera::calculaVolume() {
    return 4 / 3.0 * PI * pow(this->raio, 3);
}