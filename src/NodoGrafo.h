#ifndef NODOGRAFO_H
#define NODOGRAFO_H

#include <string>
#include <vector>

class Arista;

class NodoGrafo {
public:
    std::string palabra;
    std::vector<Arista*> adyacentes; 

    NodoGrafo(const std::string& palabra);
    ~NodoGrafo();
};

#endif // NODOGRAFO_H
