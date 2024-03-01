#ifndef SCRABBLE_H
#define SCRABBLE_H

#include "Diccionario.h"
#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype> 

class Scrabble {
	private:
		Diccionario diccionario;
	public:
    	Scrabble();
    	void inicializarDiccionario(const std::string& archivoDiccionario);
    	void iniciarDiccionarioInverso(const std::string& archivoDiccionario);
    	void obtenerPuntaje(const std::string& palabra);
    	void salir();
};

#endif // SCRABBLE_H


