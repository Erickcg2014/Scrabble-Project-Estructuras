#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "Palabra.h"
#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype> // Para std::isalpha y std::tolower

class Diccionario {
private:
    std::list<Palabra> diccionario;
    std::list<Palabra> diccionarioInverso;
    bool diccionarioInicializado = false;
    bool diccionarioInversoInicializado = false;

public:
    enum class Resultado;
    Diccionario();
    bool inicializarDiccionario(const std::string& archivoDiccionario);
    bool iniciarDiccionarioInverso(const std::string& archivoDiccionario);
    bool contienePalabra(const std::string& palabra) const;
    void buscarPuntaje(const std::string& palabra);
};

#endif // DICCIONARIO_H
