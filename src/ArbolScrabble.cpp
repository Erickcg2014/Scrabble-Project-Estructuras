#include "ArbolScrabble.h"
#include "NodoScrabble.h"
#include "Palabra.h"
#include <algorithm>
#include <fstream>
#include <iostream>

ArbolScrabble::ArbolScrabble() : raiz(nullptr), raizInversa(nullptr) {}

ArbolScrabble::~ArbolScrabble() {
}

int ArbolScrabble::inicializarArbol(const std::string& archivoDiccionario) {
    if (arbolDiccionarioInicializado) {
        return -1;
    }

    std::ifstream archivo(archivoDiccionario);
    if (!archivo.is_open()) {
        return 1;
    }

    std::string palabra;
    while (archivo >> palabra) {
        std::transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);

        if (Palabra::esPalabraValida(palabra)) {
            if (!insertarPalabra(&raiz, palabra)) {
                std::cerr << "Error al insertar la palabra '" << palabra << "' en el árbol." << std::endl;
            }
        } else {
            std::cerr << "La palabra '" << palabra << "' no es válida y no se inserta en el árbol." << std::endl << std::endl;
        }
    }

    archivo.close();
    arbolDiccionarioInicializado = true;
    return 0;
}


int ArbolScrabble::inicializarArbolInverso(const std::string& archivoDiccionario) {
    if (arbolDiccionarioInversoInicializado) {
        return -1;
    }

    std::ifstream archivo(archivoDiccionario);
    if (!archivo.is_open()) {
        return 1;
    }

    std::string palabra;
    while (archivo >> palabra) {
        std::transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);
        
        if (Palabra::esPalabraValida(palabra)) {
            std::reverse(palabra.begin(), palabra.end());
            if (!insertarPalabra(&raizInversa, palabra)) {
                std::cerr << "Error al insertar la palabra '" << palabra << "' en el árbol inverso." << std::endl;
            }
        } else {
            std::cerr << "La palabra '" << palabra << "' no es válida y no se inserta en el árbol inverso." << std::endl << std::endl;
        }
    }

    archivo.close();
    arbolDiccionarioInversoInicializado = true;
    return 0;
}


bool ArbolScrabble::insertarPalabra(NodoScrabble<char>** nodo, const std::string& palabra) {
    if (*nodo == nullptr) {
        *nodo = new NodoScrabble<char>(palabra[0]);  // Inicializa el nodo raíz si aún no existe
    }

    NodoScrabble<char>* ptr = *nodo;
    for (size_t i = 0; i < palabra.length(); ++i) {  // Comienza desde el primer caracter
        NodoScrabble<char>* hijo = ptr->buscarHijo(palabra[i]);
        if (hijo == nullptr) {
            hijo = new NodoScrabble<char>(palabra[i]);
            ptr->insertarHijo(hijo);
        }
        ptr = hijo;
    }
    ptr->marcarFinal();  // Marca el último nodo como el final de la palabra
    return true;
}

std::vector<std::string> ArbolScrabble::buscarPalabrasPorPrefijo(const std::string& prefijo) {
    std::vector<std::string> palabras;
    buscarPalabrasPorPrefijoRecursivo(raiz, prefijo, palabras, "");
    return palabras;
}

std::vector<std::string> ArbolScrabble::buscarPalabrasPorSufijo(const std::string& sufijo) {
    std::vector<std::string> palabras;
    buscarPalabrasPorSufijoRecursivo(raizInversa, sufijo, palabras, "");
    return palabras;
}

void ArbolScrabble::buscarPalabrasPorPrefijoRecursivo(NodoScrabble<char>* nodo, const std::string& prefijo, std::vector<std::string>& palabras, const std::string& palabraAcumulada) {
    if (nodo == nullptr) {
        return; 
    }

    if (prefijo.empty()) {
        // Cuando se consume el prefijo, recoge las palabras
        nodo->obtenerPalabrasPrefijo(palabraAcumulada, palabras);
        return; 
    }

    NodoScrabble<char>* siguiente = nodo->buscarHijo(prefijo[0]);
    if (siguiente) {
        buscarPalabrasPorPrefijoRecursivo(siguiente, prefijo.substr(1), palabras, palabraAcumulada + prefijo[0]);
    }
}

void ArbolScrabble::buscarPalabrasPorSufijoRecursivo(NodoScrabble<char>* nodo, const std::string& sufijo, std::vector<std::string>& palabras, const std::string& palabraAcumulada) {
    if (nodo == nullptr) {
        return;
    }

    if (sufijo.empty()) {
        // Cuando se consume el sufijo, recoge las palabras
        nodo->obtenerPalabrasSufijo(palabraAcumulada, palabras);
    } else {
        NodoScrabble<char>* siguiente = nodo->buscarHijo(sufijo.back());
        if (siguiente != nullptr) {
            buscarPalabrasPorSufijoRecursivo(siguiente, sufijo.substr(0, sufijo.length() - 1), palabras, sufijo.back() + palabraAcumulada);
        }
    }
}


