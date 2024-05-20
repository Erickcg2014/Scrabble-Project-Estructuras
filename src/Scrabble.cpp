#include "Scrabble.h"
#include "Comandos.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

Scrabble::Scrabble(){}

void Scrabble::inicializarDiccionario(const string& archivoDiccionario) {
    diccionario.inicializarDiccionario(archivoDiccionario);
    grafoPalabras.construirGrafo(diccionario.obtenerPalabras());
}

void Scrabble::iniciarDiccionarioInverso(const string& archivoDiccionario) {
    diccionario.iniciarDiccionarioInverso(archivoDiccionario);
}

void Scrabble::obtenerPuntaje(const string& palabraOriginal) {
    if (!Palabra(palabraOriginal).esPalabraValida(palabraOriginal)) {
        cout << "(Letras invalidas) La palabra contiene simbolos invalidos." << endl;
        return;
    }
    
    if (!diccionario.contienePalabra(palabraOriginal)) {
        cout << "(Palabra no existe) La palabra no existe en el diccionario." << endl;
        return;
    }

    diccionario.buscarPuntaje(palabraOriginal);
}

//Funciones componente 2
int Scrabble::inicializarArbol(const std::string& archivoDiccionario) {
    return arbolDiccionario.inicializarArbol(archivoDiccionario); 
}

int Scrabble::inicializarArbolInverso(const std::string& archivoDiccionario) {
    return arbolDiccionarioInverso.inicializarArbolInverso(archivoDiccionario); 
}

void Scrabble::buscarPalabrasPorPrefijo(const std::string& prefijo) {
    Comandos comandos;
    std::vector<std::string> palabras = arbolDiccionario.buscarPalabrasPorPrefijo(prefijo);
    comandos.mostrarResultadosPrefijo(prefijo, palabras);
}


void Scrabble::buscarPalabrasPorSufijo(const std::string& sufijo) {
    Comandos comandos;
    std::vector<std::string> palabras = arbolDiccionarioInverso.buscarPalabrasPorSufijo(sufijo);
    comandos.mostrarResultadosSufijo(sufijo, palabras);
}

void Scrabble::posiblesPalabrasLetras(const std::string& letras) {
    auto palabras = grafoPalabras.posiblesPalabras(letras);
    if (palabras.empty()) {
        std::cout << "No se encontraron palabras posibles con las letras \"" << letras << "\"." << std::endl;
    } else {
        std::cout << "Las posibles palabras a construir con las letras \"" << letras << "\" son:" << std::endl;
        for (const auto& palabra : palabras) {
            int puntuacion = Palabra::calcularPuntaje(palabra);
            std::cout << palabra << " (Longitud: " << palabra.length() << ", Puntuacion: " << puntuacion << ")" << std::endl;
        }
    }
}


//COMANDO: SALIR 
void Scrabble::salir() {
    exit(0);
}
