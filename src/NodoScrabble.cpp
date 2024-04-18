#include "NodoScrabble.h"
#include <algorithm>

template<typename T>
NodoScrabble<T>::NodoScrabble(T valor) : valor(valor), esFinal(false) {}

template<typename T>
NodoScrabble<T>::~NodoScrabble() {
    for (auto& par : hijos) {
        delete par.second;
    }
}

template<typename T>
T NodoScrabble<T>::getValor() const {
    return valor;
}

template<typename T>
void NodoScrabble<T>::insertarHijo(NodoScrabble<T>* hijo) {
    hijos[hijo->getValor()] = hijo;
}

template<typename T>
NodoScrabble<T>* NodoScrabble<T>::buscarHijo(T valor) const {
    auto it = hijos.find(valor);
    return it != hijos.end() ? it->second : nullptr;
}

template<typename T>
bool NodoScrabble<T>::esFinalDePalabra() const {
    return esFinal;
}

template<typename T>
void NodoScrabble<T>::marcarFinal() {
    esFinal = true;
}

template<typename T>
void NodoScrabble<T>::obtenerPalabrasPrefijo(const std::string& prefijo, std::vector<std::string>& palabras) const {
    if (esFinalDePalabra()) {
        palabras.push_back(prefijo);
    }

    for (const auto& par : hijos) {
        par.second->obtenerPalabrasPrefijo(prefijo + par.second->getValor(), palabras);
    }
}

template<typename T>
void NodoScrabble<T>::obtenerPalabrasSufijo(const std::string& palabraAcumulada, std::vector<std::string>& palabras) const {
    if (esFinalDePalabra()) {
        palabras.push_back(palabraAcumulada);  
    }
    for (auto& hijo : hijos) {
        hijo.second->obtenerPalabrasSufijo(hijo.first + palabraAcumulada, palabras);
    }
}


template class NodoScrabble<char>;

