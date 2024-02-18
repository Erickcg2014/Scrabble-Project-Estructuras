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
	bool diccionarioInicializado = false;
	bool diccionarioInversoInicializado = false;
	bool arbolInicializado = false;
	bool arbolInversoInicializado = false;
	
};

#endif // SCRABBLE_H


