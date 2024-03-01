#include "Scrabble.h"
#include "Diccionario.h"
#include "Palabra.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

Diccionario::Diccionario(){};


//COMANDO INICIALIZAR DICCIONARIO
bool Diccionario::inicializarDiccionario(const string& archivoDiccionario) {
    if (diccionarioInicializado) {
        cout << "(Diccionario ya inicializado) El diccionario ya ha sido inicializado." << endl;
        return false;
    }

    ifstream archivo(archivoDiccionario);
    if (!archivo.is_open()) {
        cout << "(Archivo no existe) El archivo " << archivoDiccionario << " no existe o no puede ser leido." << endl;
        return false;
    }

    string palabra;
    while (archivo >> palabra) {
        if (Palabra(palabra).esPalabraValida(palabra)) {
            diccionario.push_back(Palabra(palabra));
        }
    }

    archivo.close();
    diccionarioInicializado = true;
    cout << "(Resultado exitoso) El diccionario se ha inicializado correctamente." << endl;
    return true;
}


//INICIAR_INVERSO DICCIONARIO

bool Diccionario::iniciarDiccionarioInverso(const string& archivoDiccionario) {
    if (diccionarioInversoInicializado) {
        cout << "(Diccionario ya inicializado) El diccionario inverso ya ha sido inicializado." << endl;
        return false;
    }

    ifstream archivo(archivoDiccionario);
    if (!archivo.is_open()) {
        cout << "(Archivo no existe) El archivo " << archivoDiccionario << " no existe o no puede ser leido." << endl;
        return false;
    }

    string palabra;
    while (archivo >> palabra) {
        if (Palabra(palabra).esPalabraValida(palabra)) {
            reverse(palabra.begin(), palabra.end()); 
            diccionarioInverso.push_back(Palabra(palabra));
        }
    }

    archivo.close();
    diccionarioInversoInicializado = true;
    cout << "(Resultado exitoso) El diccionario inverso se ha inicializado correctamente." << endl;
    return true;
}

//DICCIONARIO COMPROBAR PALABRA

bool Diccionario::contienePalabra(const string& palabraBusqueda) const {
    for (const auto& palabra : diccionario) {
        if (palabra.getContenido() == palabraBusqueda) return true;
    }

    for (const auto& palabra : diccionarioInverso) {
        if (palabra.getContenido() == palabraBusqueda) return true;
    }

    return false;
}


void Diccionario::buscarPuntaje(const std::string& palabraOri) {
    string palabraInvertida = palabraOri;


    // Buscar en el diccionario normal
    for (const auto& palabra : diccionario) {
        if (palabra.getContenido() == palabraOri) {
            cout << "(Resultado exitoso) La palabra tiene un puntaje de " << palabra.calcularPuntaje(palabraOri) << "." << endl;
            return;
        }
    }

    // Buscar en el diccionario inverso
    for (const auto& palabra : diccionarioInverso) {
        if (palabra.getContenido() == palabraInvertida) {
            cout << "(Resultado exitoso) La palabra inversa tiene un puntaje de " << palabra.calcularPuntaje(palabraInvertida) << "." << endl;
            return;
        }
    }

    cout << "(Palabra no encontrada) La palabra no existe en el diccionario." << endl;
}
