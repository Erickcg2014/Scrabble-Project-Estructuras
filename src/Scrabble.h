#ifndef SCRABBLE_H
#define SCRABBLE_H

#include "ArbolScrabble.h"
#include "Comandos.h"
#include "Diccionario.h"
#include "GrafoScrabble.h"
#include <string>
#include <iostream>

class Scrabble {
private:
    Diccionario diccionario;
    ArbolScrabble arbolDiccionario;
    ArbolScrabble arbolDiccionarioInverso;
    GrafoScrabble grafoPalabras;

public:
    Scrabble();
    
    void inicializarDiccionario(const std::string& archivoDiccionario);
    void iniciarDiccionarioInverso(const std::string& archivoDiccionario);
    void obtenerPuntaje(const std::string& palabra);
    void salir();

	// Funciones para inicializar los árboles
    int inicializarArbol(const std::string& archivoDiccionario);
    int inicializarArbolInverso(const std::string& archivoDiccionario);

    void buscarPalabrasPorPrefijo(const std::string& prefijo);
    void buscarPalabrasPorSufijo(const std::string& sufijo);

    void posiblesPalabrasLetras(const std::string& letras);

    Diccionario& getDiccionario() { return diccionario; }
    GrafoScrabble& getGrafo() { return grafoPalabras; }
};

#endif // SCRABBLE_H


