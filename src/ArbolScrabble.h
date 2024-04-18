#ifndef ARBOL_SCRABBLE_H
#define ARBOL_SCRABBLE_H

#include "NodoScrabble.h"
#include <string>
#include <vector>
#include <iostream>

class ArbolScrabble {
private:
    NodoScrabble<char>* raiz;       // Nodo raíz para el árbol de prefijos 
    NodoScrabble<char>* raizInversa; // Nodo raíz para el árbol de sufijos
    bool arbolDiccionarioInicializado = false;
    bool arbolDiccionarioInversoInicializado = false;

public:
    ArbolScrabble();               
    ~ArbolScrabble();              
    int inicializarArbol(const std::string& archivoDiccionario);
    int inicializarArbolInverso(const std::string& archivoDiccionario);

    bool insertarPalabra(NodoScrabble<char>** nodo, const std::string& palabra);
    std::vector<std::string> buscarPalabrasPorPrefijo(const std::string& prefijo);
    std::vector<std::string> buscarPalabrasPorSufijo(const std::string& sufijo);


    void buscarPalabrasPorPrefijoRecursivo(NodoScrabble<char>* nodo, const std::string& prefijo, std::vector<std::string>& palabras, const std::string& palabraAcumulada);
    void buscarPalabrasPorSufijoRecursivo(NodoScrabble<char>* nodo, const std::string& sufijo, std::vector<std::string>& palabras, const std::string& palabraAcumulada);
    void mostrarPalabrasConDetalles(const std::vector<std::string>& palabras);
};

#endif // ARBOL_SCRABBLE_H


