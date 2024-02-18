#include <iostream>
#include "Scrabble.h"

using namespace std;

int main() {
    Scrabble scrabble;
    string comando;
    
    cout << "Bienvenido al juego Scrabble!" << endl;
    cout << "Ingrese un comando ('ayuda' para ver la lista de comandos):" << endl;
    
    while (true) {
        cout << "$ ";
        cin >> comando;

        if (comando == "ayuda") {
            // Mostrar lista de comandos disponibles
            cout << "Lista de comandos:" << endl;
            cout << "  - inicializar <archivoDiccionario>: Inicializa el diccionario con el archivo especificado." << endl;
            cout << "  - iniciar_inverso <archivoDiccionario>: Inicializa el diccionario inverso con el archivo especificado." << endl;
            cout << "  - puntaje <palabra>: Obtiene el puntaje de la palabra dada." << endl;
            cout << "  - salir: Termina la ejecución del programa." << endl;
            cout << "  - iniciar_arbol <archivoDiccionario>: Inicializa el árbol de palabras con el archivo especificado." << endl;
            cout << "  - iniciar_arbol_inverso <archivoDiccionario>: Inicializa el árbol de palabras inverso con el archivo especificado." << endl;
            cout << "  - palabras_por_prefijo <prefijo>: Muestra las palabras que comienzan con el prefijo dado." << endl;
            cout << "  - palabras_por_sufijo <sufijo>: Muestra las palabras que terminan con el sufijo dado." << endl;
        } else if (comando == "inicializar") {
            string archivoDiccionario;
            cin >> archivoDiccionario;

            scrabble.inicializarDiccionario(archivoDiccionario);
        } else if (comando == "iniciar_inverso") {
            string archivoDiccionario;
            cin >> archivoDiccionario;
            scrabble.iniciarDiccionarioInverso(archivoDiccionario);
        } else if (comando == "puntaje") {
            string palabra;
            cin >> palabra;
            scrabble.obtenerPuntaje(palabra);
        } else if (comando == "salir") {
            cout << "¡Have a nice day!" << endl;
            break;
        } else if (comando == "iniciar_arbol") {
            string archivoDiccionario;
            cin >> archivoDiccionario;
            scrabble.iniciarArbol(archivoDiccionario);
        } else if (comando == "iniciar_arbol_inverso") {
            string archivoDiccionario;
            cin >> archivoDiccionario;
            scrabble.iniciarArbolInverso(archivoDiccionario);
        } else if (comando == "palabras_por_prefijo") {
            string prefijo;
            cin >> prefijo;
            scrabble.palabrasPorPrefijo(prefijo);
        } else if (comando == "palabras_por_sufijo") {
            string sufijo;
            cin >> sufijo;
            scrabble.palabrasPorSufijo(sufijo);
        } else {
            cout << "Comando no reconocido. Ingrese 'ayuda' para ver la lista de comandos disponibles." << endl;
        }
    }

    return 0;  
}

