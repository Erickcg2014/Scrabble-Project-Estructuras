#include "NodoGrafo.h"
#include "Arista.h"

NodoGrafo::NodoGrafo(const std::string& palabra) : palabra(palabra) {}

NodoGrafo::~NodoGrafo() {
    // Eliminar todas las aristas asociadas con este nodo
    for (Arista* arista : adyacentes) {
        delete arista;
    }
}
