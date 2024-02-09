<<<<<<< HEAD

#ifndef SCRABBLE_H
#define SCRABBLE_H

#include <string>
#include <vector>

using namespace std;

class Scrabble {
public:
    // Comandos para la configuración del juego
    void inicializarDiccionario(const string& archivoDiccionario);
    void iniciarDiccionarioInverso(const string& archivoDiccionario);
    void obtenerPuntaje(const string& palabra);
    void salir();

    // Comandos para la búsqueda de palabras
    void iniciarArbol(const string& archivoDiccionario);
    void iniciarArbolInverso(const string& archivoDiccionario);
    void palabrasPorPrefijo(const string& prefijo);
    void palabrasPorSufijo(const string& sufijo);

    // Comandos para la generación de combinaciones de letras
    void grafoDePalabras();
    void posiblesPalabras(const string& letras);

private:
    // Variables para verificaciones, se utiliza solo como prueba
    bool diccionarioInicializado = false;
    bool diccionarioInversoInicializado = false;
    bool arbolInicializado = false; 
    bool arbolInversoInicializado = false; 
};

#endif // SCRABBLE_H
=======

#ifndef SCRABBLE_H
#define SCRABBLE_H

#include <string>
#include <vector>

using namespace std;

class Scrabble {
public:
    // Comandos para la configuración del juego
    void inicializarDiccionario(const string& archivoDiccionario);
    void iniciarDiccionarioInverso(const string& archivoDiccionario);
    void obtenerPuntaje(const string& palabra);
    void salir();

    // Comandos para la búsqueda de palabras
    void iniciarArbol(const string& archivoDiccionario);
    void iniciarArbolInverso(const string& archivoDiccionario);
    void palabrasPorPrefijo(const string& prefijo);
    void palabrasPorSufijo(const string& sufijo);

    // Comandos para la generación de combinaciones de letras
    void grafoDePalabras();
    void posiblesPalabras(const string& letras);

private:
    // Variables para verificaciones, se utiliza solo como prueba
    bool diccionarioInicializado = false;
    bool diccionarioInversoInicializado = false;
    bool arbolInicializado = false; 
    bool arbolInversoInicializado = false; 
};

#endif // SCRABBLE_H
>>>>>>> 3ff178c64278b8a684b0510e46dc48a363786a34
