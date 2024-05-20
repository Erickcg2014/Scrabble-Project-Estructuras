#include <iostream>
#include <cstdlib>
#include "Scrabble.h"
#include "Comandos.h"
#include "Diccionario.h"

using namespace std;

Comandos::Comandos() {
    scrabble = new Scrabble();
}

Comandos::~Comandos() {
    delete scrabble;
}


void Comandos::ejecutarComandos(){
	
	Scrabble scrabble;
    Diccionario diccionario;
    string comando, archivoDiccionario;
    string prefijo, sufijo;
    string palabra;
    std::string letras;
    
    cout << "Bienvenido al juego Scrabble!" << endl;
    cout << "Ingrese un comando ('ayuda' para ver la lista de comandos):" << endl;
    
    while (true) {
        cout << "$ ";
        cin >> comando;


        if (comando == "ayuda") {
            std::cout << "Lista de comandos:" << std::endl;
            std::cout << "  - inicializar <archivoDiccionario>: Inicializa el diccionario con el archivo especificado." << std::endl;
            std::cout << "  - iniciar_inverso <archivoDiccionario>: Inicializa el diccionario inverso con el archivo especificado." << std::endl;
            std::cout << "  - puntaje <palabra>: Obtiene el puntaje de la palabra dada." << std::endl;
            std::cout << "  - cls: Limpiar consola" << std::endl;
            std::cout << "  - salir: Termina la ejecucion del programa." << std::endl;
            // Funciones componente 2
            std::cout << "  - iniciar_arbol <archivoDiccionario>: Inicializa el arbol de palabras con el archivo especificado." << std::endl;
            std::cout << "  - iniciar_arbol_inverso <archivoDiccionario>: Inicializa el arbol de palabras inverso con el archivo especificado." << std::endl;
            std::cout << "  - palabras_por_prefijo <prefijo>: Muestra las palabras que comienzan con el prefijo dado." << std::endl;
            std::cout << "  - palabras_por_sufijo <sufijo>: Muestra las palabras que terminan con el sufijo dado." << std::endl;
            // Funciones componente 3
            std::cout << "  - grafo_de_palabras: Construye el grafo de palabras." << std::endl;
            std::cout << "  - posibles_palabras_letras <letras>: Muestra las posibles palabras a construir con las letras dadas." << std::endl;

        } else if (comando == "inicializar") {
            cin >> archivoDiccionario;
            if (scrabble.inicializarDiccionario(archivoDiccionario)) {
                cout << "(Resultado exitoso) El Diccionario se ha inicializado correctamente." << endl;
            } else {
                cout << "Error al inicializar el diccionario." << endl;
            }
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
        } else if (comando == "palabras_por_prefijo") {
            cin >> prefijo;
            std::transform(prefijo.begin(), prefijo.end(), prefijo.begin(), ::tolower);
            scrabble.buscarPalabrasPorPrefijo(prefijo);
        } else if (comando == "palabras_por_sufijo") {
            cin >> sufijo; 
            std::transform(sufijo.begin(), sufijo.end(), sufijo.begin(), ::tolower);
            scrabble.buscarPalabrasPorSufijo(sufijo);
        } else if (comando == "grafo_de_palabras") {
            if (!scrabble.isDiccionarioInicializado()) {
                cout << "Error: El diccionario no ha sido inicializado." << endl;
            } else if (scrabble.getGrafo().isGrafoConstruido()) {
                cout << "Error: El grafo ya ha sido construido." << endl;
            } else {
                vector<string> palabras = scrabble.getDiccionario().obtenerPalabras();
                scrabble.getGrafo().construirGrafo(palabras);
                cout << "(Resultado exitoso) Grafo construido correctamente." << endl;
            }
        } else if (comando == "posibles_palabras") {
            std::cin >> letras;
             std::transform(letras.begin(), letras.end(), letras.begin(), ::tolower);
            scrabble.posiblesPalabrasLetras(letras);
        } else {
            std::cout << "Comando no reconocido. Ingrese 'ayuda' para ver la lista de comandos disponibles." << std::endl;
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
            std::cout << "(Prefijo invalido) Prefijo \"" << prefijo << "\" " <<"no pudo encontrarse en el diccionario."<< std::endl;
        } else {
            std::cout << "(Resultado exitoso) Las palabras que inician con el prefijo \"" << prefijo << "\":"<<std::endl;
            for (const auto& palabra : palabras) {
                int puntuacion = Palabra::calcularPuntaje(palabra);
                std::cout << palabra << " (Longitud: " << palabra.length() << ", Puntuacion: " << puntuacion << ")" << std::endl;
            }
        }
    }


void Comandos::mostrarResultadosSufijo(const std::string& sufijo, const std::vector<std::string>& palabras) {
        if (palabras.empty()) {
            std::cout << "(Sufijo invalido) Sufijo \"" << sufijo << "\" " << "no pudo encontrarse en el diccionario."<<std::endl;
        } else {
            std::cout << "(Resultado exitoso) Palabras que terminan con el sufijo \"" << sufijo << "\":" << std::endl;
            for (auto palabra : palabras) {
                int puntuacion = Palabra::calcularPuntaje(palabra);
                //std::reverse(palabra.begin(), palabra.end());
                std::cout << palabra << " (Longitud: " << palabra.length() << ", Puntuacion: " << puntuacion << ")" << std::endl;
            }
        }
    }