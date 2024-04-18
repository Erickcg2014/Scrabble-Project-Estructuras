#include <iostream>
#include <cstdlib>
#include "Comandos.h"
#include "Letra.h"

using namespace std;

int main() {
    Comandos juego;
    Letra letra;

    letra.inicializarValoresLetras("valoresLetras.txt");
    juego.ejecutarComandos();

    return 0;  
}

