#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <utility>

using namespace std;

// Función para leer un archivo y devolver su contenido como una cadena de texto
string readFile(const string &filename);

// Función para verificar si un código malicioso está contenido en una transmisión
bool contains(const string &haystack, const string &needle, size_t &position);

// Función para encontrar el palíndromo más largo en una cadena
pair<pair<int, int>, string> findLongestPalindrome(const string &s);

// Función para encontrar la subcadena más larga común entre dos cadenas
pair<int, int> findLongestCommonSubstring(const string &s1, const string &s2);

#endif // FUNCTIONS_H
