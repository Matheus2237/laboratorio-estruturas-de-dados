#ifndef ESFERA_H
#define ESFERA_H

#define PI 3.14159265359

class Esfera {
private:
    double raio;

public:
    Esfera(double raio);
    double getRaio();
    double calculaArea();
    double calculaVolume();
};

#endif