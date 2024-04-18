#ifndef SCRABBLE_H
#define SCRABBLE_H

#include "ArbolScrabble.h"
#include "Comandos.h"
#include "Diccionario.h"
#include <string>
#include <iostream>

class Scrabble {
private:
    Diccionario diccionario;
    ArbolScrabble arbolDiccionario;
    ArbolScrabble arbolDiccionarioInverso;

public:
    Scrabble();
    
    void inicializarDiccionario(const std::string& archivoDiccionario);
    void iniciarDiccionarioInverso(const std::string& archivoDiccionario);
    void obtenerPuntaje(const std::string& palabra);
    void salir();

	// Nuevas funciones para inicializar los árboles
    int inicializarArbol(const std::string& archivoDiccionario);
    int inicializarArbolInverso(const std::string& archivoDiccionario);

    void buscarPalabrasPorPrefijo(const std::string& prefijo);
    void buscarPalabrasPorSufijo(const std::string& sufijo);
};

#endif // SCRABBLE_H



