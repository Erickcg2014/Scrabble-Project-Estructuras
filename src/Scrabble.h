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
    
    bool inicializarDiccionario(const std::string& archivoDiccionario);
    void iniciarDiccionarioInverso(const std::string& archivoDiccionario);
    void obtenerPuntaje(const std::string& palabra);
    void salir();

	// Funciones para inicializar los árboles
    int inicializarArbol(const std::string& archivoDiccionario);
    int inicializarArbolInverso(const std::string& archivoDiccionario);

    void buscarPalabrasPorPrefijo(const std::string& prefijo);
    void buscarPalabrasPorSufijo(const std::string& sufijo);

    bool construirGrafoDePalabras();
    void posiblesPalabrasLetras(const std::string& letras);

    Diccionario& getDiccionario() { return diccionario; }
    GrafoScrabble& getGrafo() { return grafoPalabras; }
    bool isDiccionarioInicializado() const { return diccionario.isInicializado(); }
    bool isDiccionarioInversoInicializado() const { return diccionario.isInversoInicializado(); }
    bool isGrafoConstruido() const { return grafoPalabras.isGrafoConstruido(); }
};

#endif // SCRABBLE_H


