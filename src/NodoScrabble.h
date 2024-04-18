#ifndef NODO_SCRABBLE_H
#define NODO_SCRABBLE_H

#include <string>
#include <vector>
#include <map>

template<typename T>
class NodoScrabble {
public:
    NodoScrabble(T valor);
    ~NodoScrabble();

    T getValor() const;
    void insertarHijo(NodoScrabble<T>* hijo);
    NodoScrabble<T>* buscarHijo(T valor) const;
    bool esFinalDePalabra() const;
    void marcarFinal();
    void obtenerPalabrasPrefijo(const std::string& prefijo, std::vector<std::string>& palabras) const;
    void obtenerPalabrasSufijo(const std::string& palabraAcumulada, std::vector<std::string>& palabras) const;

private:
    T valor;
    bool esFinal;
    std::map<T, NodoScrabble<T>*> hijos;
};

#endif // NODO_SCRABBLE_H
