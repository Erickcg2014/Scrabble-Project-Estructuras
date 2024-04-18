#include "Letra.h"
#include <iostream>
#include <cctype>
#include <fstream>
#include <string>


using namespace std;

Letra::Letra() {
}

std::map<char, int> Letra::valoresLetras;


void Letra::inicializarValoresLetras(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    char letra;
    int puntaje;
    while (archivo >> letra >> puntaje) {
        valoresLetras[letra] = puntaje;
    }

    archivo.close();
}


bool Letra::esLetraValida(char letra) {
    return isalpha(letra);
}

int Letra::getPuntaje(char letra) {
    letra = tolower(letra);
    return valoresLetras[letra];
}