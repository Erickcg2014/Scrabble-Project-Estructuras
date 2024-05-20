#ifndef ARISTA_H
#define ARISTA_H

#include "NodoGrafo.h"

class Arista {
public:
    NodoGrafo* origen;
    NodoGrafo* destino;

    Arista(NodoGrafo* origen, NodoGrafo* destino);
};

#endif // ARISTA_H
