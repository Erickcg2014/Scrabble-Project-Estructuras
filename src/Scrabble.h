#ifndef SCRABBLE_H
#define SCRABBLE_H

#include <string>

class Scrabble {
public:
    // Métodos públicos de la clase Scrabble
    void inicializarDiccionario(const std::string& archivoDiccionario);
    void iniciarDiccionarioInverso(const std::string& archivoDiccionario);
    void obtenerPuntaje(const std::string& palabra);
    void salir();
    void iniciarArbol(const std::string& archivoDiccionario);
    void iniciarArbolInverso(const std::string& archivoDiccionario);
    void palabrasPorPrefijo(const std::string& prefijo);
    void palabrasPorSufijo(const std::string& sufijo);
    void grafoDePalabras();
    void posiblesPalabras(const std::string& letras);

private:
    // Declaraciones privadas de la clase Scrabble
    // Puedes agregar variables miembro aquí si es necesario
};

#endif // SCRABBLE_H


