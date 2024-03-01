#include <iostream>
#include <cstdlib>
#include "Scrabble.h"
#include "Comandos.h"

using namespace std;

Comandos::Comandos(){};

void Comandos::ejecutarComandos(){
	
	Scrabble scrabble;
    string comando, archivoDiccionario;
    string palabra;
    
    cout << "Bienvenido al juego Scrabble!" << endl;
    cout << "Ingrese un comando ('ayuda' para ver la lista de comandos):" << endl;
    
    while (true) {
        cout << "$ ";
        cin >> comando;

        if (comando == "ayuda") {
            cout << "Lista de comandos:" << endl;
            cout << "  - inicializar <archivoDiccionario>: Inicializa el diccionario con el archivo especificado." << endl;
            cout << "  - iniciar_inverso <archivoDiccionario>: Inicializa el diccionario inverso con el archivo especificado." << endl;
            cout << "  - puntaje <palabra>: Obtiene el puntaje de la palabra dada." << endl;
            cout << "  - cls: Limpiar consola"<<endl;
			cout << "  - salir: Termina la ejecucion del programa." << endl;
			
            // Funciones componente 2
            // cout << "  - iniciar_arbol <archivoDiccionario>: Inicializa el arbol de palabras con el archivo especificado." << endl;
            // cout << "  - iniciar_arbol_inverso <archivoDiccionario>: Inicializa el arbol de palabras inverso con el archivo especificado." << endl;
            // cout << "  - palabras_por_prefijo <prefijo>: Muestra las palabras que comienzan con el prefijo dado." << endl;
            // cout << "  - palabras_por_sufijo <sufijo>: Muestra las palabras que terminan con el sufijo dado." << endl;
            
        } else if (comando == "inicializar") {
            cin >> archivoDiccionario;
            scrabble.inicializarDiccionario(archivoDiccionario);
        } else if (comando == "iniciar_inverso") {
            cin >> archivoDiccionario;
            scrabble.iniciarDiccionarioInverso(archivoDiccionario);
        } else if (comando == "puntaje") {
            cin >> palabra;
            scrabble.obtenerPuntaje(palabra);
        } else if (comando == "salir" || comando == "exit") {
            cout << "Gracias por usar nuestra herramienta de Scrabble. Que tengas un buen dia" << endl;
            scrabble.salir();
        } else if(comando == "cls"){
			system("cls");
			cout << "Ingrese un comando ('ayuda' para ver la lista de comandos):" << endl;
		}else {
            cout << "Comando no reconocido. Ingrese 'ayuda' para ver la lista de comandos disponibles." << endl;
        }
    }
}

