#include "Palabra.h"
#include "Letra.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <map>
#include <algorithm>

using namespace std;

bool Palabra::esPalabraValida(const string& palabra){
	for(char c : palabra){
		if(!isalpha(c)) return false;
	}
	return true;
}

//COMANDO: PUNTAJE PALABRA
int Palabra::calcularPuntaje(const string& palabra) {
	Letra::inicializarValoresLetras("valoresLetras.txt");
    int puntaje = 0;
    for (char c : palabra) {
        c = tolower(c);
        puntaje += Letra::valoresLetras[c]; // Utiliza la definición de valoresLetras de Letra
    }
    return puntaje;
}
