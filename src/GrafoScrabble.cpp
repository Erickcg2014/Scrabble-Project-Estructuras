#include "GrafoScrabble.h"
#include <algorithm>
#include <queue>
#include <unordered_set>

GrafoScrabble::GrafoScrabble() {}

GrafoScrabble::~GrafoScrabble() {
    limpiarGrafo();
}

void GrafoScrabble::limpiarGrafo() {
    for (auto& par : nodos) {
        delete par.second;
    }
    nodos.clear();
}

bool GrafoScrabble::esVecino(const std::string& palabra1, const std::string& palabra2) {
    if (palabra1.length() != palabra2.length()) return false;
    int diferencias = 0;
    for (size_t i = 0; i < palabra1.length(); ++i) {
        if (palabra1[i] != palabra2[i]) {
            diferencias++;
            if (diferencias > 1) return false;
        }
    }
    return diferencias == 1;
}

void GrafoScrabble::construirGrafo(const std::vector<std::string>& palabras) {
    limpiarGrafo();

    // Crear nodos para cada palabra
    for (const auto& palabra : palabras) {
        nodos[palabra] = new NodoGrafo(palabra);
    }

    // Conectar los nodos vecinos
    for (const auto& palabra1 : palabras) {
        for (const auto& palabra2 : palabras) {
            if (esVecino(palabra1, palabra2)) {
                NodoGrafo* nodo1 = nodos[palabra1];
                NodoGrafo* nodo2 = nodos[palabra2];
                Arista* arista = new Arista(nodo1, nodo2);
                nodo1->adyacentes.push_back(arista);
            }
        }
    }
}

std::vector<std::string> GrafoScrabble::posiblesPalabras(const std::string& letras) {
    std::unordered_map<char, int> conteoLetras;
    for (char letra : letras) {
        conteoLetras[letra]++;
    }

    std::vector<std::string> resultados;
    for (const auto& par : nodos) {
        auto nuevasPalabras = obtenerPalabrasValidas(par.second, "", conteoLetras, true);
        resultados.insert(resultados.end(), nuevasPalabras.begin(), nuevasPalabras.end());
    }
    return resultados;
}

std::vector<std::string> GrafoScrabble::obtenerPalabrasValidas(NodoGrafo* nodo, std::string palabraAcumulada, std::unordered_map<char, int> conteoLetras, bool comodin) {
    std::vector<std::string> palabrasValidas;

    // Verificar si la palabra puede formarse con las letras disponibles
    for (char c : nodo->palabra) {
        if (conteoLetras[c] > 0) {
            conteoLetras[c]--;
        } else if (comodin) {
            comodin = false;
        } else {
            return palabrasValidas;  // No se puede formar la palabra
        }
    }

    palabrasValidas.push_back(nodo->palabra);

    // Verificar las palabras adyacentes
    for (Arista* arista : nodo->adyacentes) {
        NodoGrafo* adyacente = arista->destino;
        auto nuevasPalabras = obtenerPalabrasValidas(adyacente, palabraAcumulada + adyacente->palabra, conteoLetras, comodin);
        palabrasValidas.insert(palabrasValidas.end(), nuevasPalabras.begin(), nuevasPalabras.end());
    }

    return palabrasValidas;
}
