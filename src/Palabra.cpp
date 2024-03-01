#include "Palabra.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <map>
#include <algorithm>

using namespace std;

map<char, int> Palabra::valoresLetras;

void Palabra::inicializarValoresLetras() {
    valoresLetras['e'] = 1;
    valoresLetras['a'] = 1;
    valoresLetras['i'] = 1;
    valoresLetras['o'] = 1;
    valoresLetras['n'] = 1;
    valoresLetras['r'] = 1;
    valoresLetras['t'] = 1;
    valoresLetras['l'] = 1;
    valoresLetras['s'] = 1;
    valoresLetras['u'] = 1;

    valoresLetras['d'] = 2;
    valoresLetras['g'] = 2;

    valoresLetras['b'] = 3;
    valoresLetras['c'] = 3;
    valoresLetras['m'] = 3;
    valoresLetras['p'] = 3;
    
    
    valoresLetras['f'] = 4;
    valoresLetras['h'] = 4;
    valoresLetras['v'] = 4;
    valoresLetras['w'] = 4;
    valoresLetras['y'] = 4;
    valoresLetras['k'] = 5;

    valoresLetras['j'] = 8;
    valoresLetras['x'] = 8;
    
    valoresLetras['q'] = 10;
    
    valoresLetras['z'] = 10;
}

//VALIDAR PALABRA
bool Palabra::esPalabraValida(const string& palabra){
	for(char c : palabra){
		if(!isalpha(c)) return false;
	}
	return true;
}


//COMANDO: PUNTAJE PALABRA
int Palabra::calcularPuntaje(const string& palabra) {
	inicializarValoresLetras();
    int puntaje = 0;
    for (char c : palabra) {
        c = tolower(c);
        puntaje += valoresLetras[c];
    }
    return puntaje;
}

