#ifndef LETRA_H
#define LETRA_H

#include <map>
#include <string>

class Letra {
private:
    char letra;
public:
    static std::map<char, int> valoresLetras;
    Letra();
    Letra(char l) : letra(l) {}

    char getLetra() const { return letra; }

    static void inicializarValoresLetras(const std::string& nombreArchivo);

    static int getPuntaje(char letra);

    static bool esLetraValida(char letra);
};

#endif // LETRA_H