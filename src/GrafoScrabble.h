#ifndef GRAFOSCRABBLE_H
#define GRAFOSCRABBLE_H

#include "NodoGrafo.h"
#include "Arista.h"
#include <unordered_map>
#include <vector>
#include <string>

class GrafoScrabble {
private:
    std::unordered_map<std::string, NodoGrafo*> nodos;
    bool esVecino(const std::string& palabra1, const std::string& palabra2);
    void limpiarGrafo();
    bool grafoConstruido;

public:
    GrafoScrabble();
    ~GrafoScrabble();
    void construirGrafo(const std::vector<std::string>& palabras);
    std::vector<std::string> posiblesPalabras(const std::string& letras);
    std::vector<std::string> obtenerPalabrasValidas(NodoGrafo* nodo, std::string palabraAcumulada, std::unordered_map<char, int> conteoLetras, bool comodin);
    bool isGrafoConstruido() const { return grafoConstruido; }
};

#endif // GRAFOSCRABBLE_H
