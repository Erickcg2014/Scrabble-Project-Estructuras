#include "Scrabble.h"
#include "Comandos.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

Scrabble::Scrabble(){}

void Scrabble::inicializarDiccionario(const string& archivoDiccionario) {
    diccionario.inicializarDiccionario(archivoDiccionario);
}

void Scrabble::iniciarDiccionarioInverso(const string& archivoDiccionario) {
    diccionario.iniciarDiccionarioInverso(archivoDiccionario);
}

void Scrabble::obtenerPuntaje(const string& palabraOriginal) {
    if (!Palabra(palabraOriginal).esPalabraValida(palabraOriginal)) {
        cout << "(Letras invalidas) La palabra contiene simbolos invalidos." << endl;
        return;
    }
    
    if (!diccionario.contienePalabra(palabraOriginal)) {
        cout << "(Palabra no existe) La palabra no existe en el diccionario." << endl;
        return;
    }

    diccionario.buscarPuntaje(palabraOriginal);
}

//Funciones componente 2
int Scrabble::inicializarArbol(const std::string& archivoDiccionario) {
    return arbolDiccionario.inicializarArbol(archivoDiccionario); 
}

int Scrabble::inicializarArbolInverso(const std::string& archivoDiccionario) {
    return arbolDiccionarioInverso.inicializarArbolInverso(archivoDiccionario); 
}

void Scrabble::buscarPalabrasPorPrefijo(const std::string& prefijo) {
    Comandos comandos;
    std::vector<std::string> palabras = arbolDiccionario.buscarPalabrasPorPrefijo(prefijo);
    comandos.mostrarResultadosPrefijo(prefijo, palabras);
}


void Scrabble::buscarPalabrasPorSufijo(const std::string& sufijo) {
    Comandos comandos;
    std::vector<std::string> palabras = arbolDiccionarioInverso.buscarPalabrasPorSufijo(sufijo);
    comandos.mostrarResultadosSufijo(sufijo, palabras);
}


//COMANDO: SALIR 
void Scrabble::salir() {
    exit(0);
}
































/*
//COMPONENTE 2

void Scrabble::iniciarArbol(const std::string& archivoDiccionario) {
    // inicializar el arbol de palabras desde el archivo
    if (arbolInicializado){
        cout <<"(Arbol ya inicializado)"<<endl<<"El arbol del diccionario ya ha sido inicializado."<<endl;
        return; 
    }
    ifstream archivo(archivoDiccionario);
    if (!archivo.is_open()){
        cout << "(Archivo no existe)"<<endl<<" El archivo "<< archivoDiccionario << "no existte o no puede ser leido."<<endl;
        return;
    }

    //en caso de que el archivo sea aceptado
    archivo.close();
    arbolInicializado = true; 
    cout <<"(Resultado exitoso) El arbol del diccionario se ha inicializado correctamente."<<endl;
}

void Scrabble::iniciarArbolInverso(const std::string& archivoDiccionario) {
    if (arbolInversoInicializado){
        cout<< "(Arbol ya inicializado)"<<endl<<"El arbol del diccionario inverso ya ha sido inicializado."<<endl;
        return;
    }
    ifstream archivo(archivoDiccionario);
    if(!archivo.is_open()){
        cout<<"(Archivo no existe) El archivo "<<archivoDiccionario <<" no existe o no pudo ser leido."<<endl;
        return;
    }

    //leer el archivo y almacenar las palabras en un arbol

    archivo.close();
    arbolInversoInicializado = true;
    cout <<"(Resultado exitoso)"<<endl<<" El arbol del diccionario inverso se ha inicializado."<<endl;
}

void Scrabble::palabrasPorPrefijo(const std::string& prefijo) {
    if (!arbolInicializado){
        cout<<"(Arbol no inicializado) El arbol del diccionario no ha sido inicializado. Por favor, inicialicelo primero."<<endl;
        return;
    } else {
        cout<<"(Resultado exitoso)"<<endl;
        cout<<"Aca se dira las palabras que inician con el prefijo";
    }
    return;
}

void Scrabble::palabrasPorSufijo(const std::string& sufijo){ 
    if (!arbolInicializado){
        cout<<"(Arbol no inicializado) El arbol del diccionario no ha sido inicializado. Por favor, inicialicelo primero."<<endl;
        return;
    } else {
        cout<<"(Resultado exitoso)"<<endl;
        cout<<"Aca se dira las palabras que inician con el sufijo";
    }
}

void Scrabble::grafoDePalabras() {
    if (!diccionarioInicializado) {
        cout << "(Diccionario no inicializado)" << endl;
        return;
    }

    cout << "Comando 'grafoDePalabras' ejecutado." << endl;
}

void Scrabble::posiblesPalabras(const std::string& letras) {
    if (!diccionarioInicializado) {
        cout << "(Diccionario no inicializado)" << endl;
        return;
    }

    cout << "Comando 'posiblesPalabras' ejecutado con par�metro: " << letras << endl;
}*/

