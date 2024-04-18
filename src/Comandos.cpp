#include <iostream>
#include <cstdlib>
#include "Scrabble.h"
#include "Comandos.h"
#include "Diccionario.h"

using namespace std;

Comandos::Comandos(){};

void Comandos::ejecutarComandos(){
	
	Scrabble scrabble;
    Diccionario diccionario;
    string comando, archivoDiccionario;
    string prefijo,sufijo;
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
            cout << "  - iniciar_arbol <archivoDiccionario>: Inicializa el arbol de palabras con el archivo especificado." << endl;
            cout << "  - iniciar_arbol_inverso <archivoDiccionario>: Inicializa el arbol de palabras inverso con el archivo especificado." << endl;
            cout << "  - palabras_por_prefijo <prefijo>: Muestra las palabras que comienzan con el prefijo dado." << endl;
            cout << "  - palabras_por_sufijo <sufijo>: Muestra las palabras que terminan con el sufijo dado." << endl;
            
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
		} else if (comando == "iniciar_arbol"){
            cin>>archivoDiccionario;
            int result = scrabble.inicializarArbol(archivoDiccionario);
            bool tipoArbol=true;
            manejarResultado(result,tipoArbol);
        } else if (comando == "iniciar_arbol_inverso"){
            cin>>archivoDiccionario;
            int result2 = scrabble.inicializarArbolInverso(archivoDiccionario);
            bool tipoArbol=false;
            manejarResultado(result2,tipoArbol);
        } else if (comando == "palabras_por_prefijo"){
            cin>>prefijo;
            scrabble.buscarPalabrasPorPrefijo(prefijo);
        } else if (comando == "palabras_por_sufijo"){
            cin>>sufijo; 
            scrabble.buscarPalabrasPorSufijo(sufijo);
        }
        else {
            cout << "Comando no reconocido. Ingrese 'ayuda' para ver la lista de comandos disponibles." << endl;
        }
    }
}

void Comandos::manejarResultado(int codigo, bool tipo) {
        if(tipo == true){
            switch (codigo) {
                case 0:
                    std::cout << "(Resultado exitoso) El arbol del diccionario se ha inicializado correctamente." << std::endl;
                    break;
                case 1:
                    std::cout << "(Archivo no existe) El archivo no existe o no puede ser leido." << std::endl;
                    break;
                case -1:
                    std::cout <<"(Diccionario ya inicializado) El diccionario ya ha sido inicializado." << std::endl;
                    break;
                default:
                    std::cout << "Error desconocido." << std::endl;
                    break;
        }
        }else {
            switch (codigo) {
                case 0:
                    std::cout << "(Resultado exitoso) El arbol inverso del diccionario se ha inicializado correctamente." << std::endl;
                    break;
                case 1:
                    std::cout << "(Archivo no existe) El archivo no existe o no puede ser leido." << std::endl;
                    break;
                case -1:
                    std::cout <<"(Diccionario ya inicializado) El diccionario inverso ya ha sido inicializado." << std::endl;
                    break;
                default:
                    std::cout << "Error desconocido." << std::endl;
                    break;
        }
        }
        
}

void Comandos::mostrarResultadosPrefijo(const std::string& prefijo, const std::vector<std::string>& palabras) {
        if (palabras.empty()) {
            std::cout << "No se encontraron palabras que comiencen con el prefijo \"" << prefijo << "\"." << std::endl;
        } else {
            std::cout << "Palabras que inician con el prefijo \"" << prefijo << "\":" << std::endl;
            for (const auto& palabra : palabras) {
                int puntuacion = Palabra::calcularPuntaje(palabra);
                std::cout << palabra << " (Longitud: " << palabra.length() << ", Puntuacion: " << puntuacion << ")" << std::endl;
            }
        }
    }


void Comandos::mostrarResultadosSufijo(const std::string& sufijo, const std::vector<std::string>& palabras) {
        if (palabras.empty()) {
            std::cout << "No se encontraron palabras que terminen con el sufijo \"" << sufijo << "\"." << std::endl;
        } else {
            std::cout << "Palabras que terminan con el sufijo \"" << sufijo << "\":" << std::endl;
            for (auto palabra : palabras) {
                int puntuacion = Palabra::calcularPuntaje(palabra);
                //std::reverse(palabra.begin(), palabra.end());
                std::cout << palabra << " (Longitud: " << palabra.length() << ", Puntuacion: " << puntuacion << ")" << std::endl;
            }
        }
    }