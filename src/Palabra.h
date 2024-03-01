#ifndef PALABRA_H
#define PALABRA_H

#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <cctype> 

class Palabra {
private:
    static std::map<char, int> valoresLetras;
	std::string contenido; 
public:
	Palabra(const std::string& palabra) : contenido (palabra){}
	static void inicializarValoresLetras();
	
	const std::string& getContenido() const { return contenido; }
	
    static bool esPalabraValida(const std::string& palabra);
    static int calcularPuntaje(const std::string& palabra);

};

#endif // PALABRA_H

