#ifndef COMANDOS_H
#define COMANDOS_H

#include <vector>
#include <string>

class Scrabble;

class Comandos {
    
private:
    Scrabble* scrabble;

public:
    Comandos();
     ~Comandos();
    void ejecutarComandos();
    void manejarResultado(int codigo, bool tipo);
    void mostrarResultadosPrefijo(const std::string& prefijo, const std::vector<std::string>& palabras);
    void mostrarResultadosSufijo(const std::string& sufijo, const std::vector<std::string>& palabras);

};

#endif // COMANDOS_H

