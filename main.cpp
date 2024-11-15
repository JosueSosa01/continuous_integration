// E1. Actividad Integradora 1

// Alejandro Charles Gonzalez        A00835903
// Josue Eduardo Sosa Martinez       A01411984
// Alba Suárez Tapia                 A01764346

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Función para leer un archivo y devolver su contenido como una cadena de texto
string readFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    return content;
}

// Función para verificar si un código malicioso está contenido en una transmisión
bool contains(const string& haystack, const string& needle, size_t& position) {
    size_t pos = haystack.find(needle);
    if (pos != string::npos) {
        position = pos + 1;  // Convertir a 1-indexado
        return true;
    }
    return false;
}

// Función para encontrar el palíndromo más largo en una cadena
pair<pair<int, int>, string> findLongestPalindrome(const string& s) {
    int n = s.length();
    int start = 0, maxLength = 1;
    vector<vector<bool>> table(n, vector<bool>(n, false));

    // Cada carácter individual es un palíndromo
    for (int i = 0; i < n; ++i) {
        table[i][i] = true;
    }

    // Buscar palíndromos de longitud 2
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Buscar palíndromos de longitud mayor
    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j] && table[i + 1][j - 1]) {
                table[i][j] = true;
                if (len > maxLength) {
                    start = i;
                    maxLength = len;
                }
            }
        }
    }

    string palindrome = s.substr(start, maxLength);
    return {{start + 1, start + maxLength}, palindrome};  // Convertir a 1-indexado
}

// Función para encontrar la subcadena más larga común entre dos cadenas
pair<int, int> findLongestCommonSubstring(const string& s1, const string& s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    int maxLength = 0;
    int endPos = 0;

    // Llenar la tabla DP
    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endPos = i - 1;
                }
            }
        }
    }

    int startPos = endPos - maxLength + 1;
    return {startPos + 1, endPos + 1};  // Convertir a 1-indexado
}

int main() {
    string transmission1 = readFile("transmission1.txt");
    string transmission2 = readFile("transmission2.txt");
    string mcode1 = readFile("mcode1.txt");
    string mcode2 = readFile("mcode2.txt");
    string mcode3 = readFile("mcode3.txt");

    // Parte 1: Verificar si el código malicioso está en las transmisiones
    cout << "Parte 1" << endl;
    size_t position;
    cout << (contains(transmission1, mcode1, position) ? "true " + to_string(position) : "false") << endl;
    cout << (contains(transmission1, mcode2, position) ? "true " + to_string(position) : "false") << endl;
    cout << (contains(transmission1, mcode3, position) ? "true " + to_string(position) : "false") << endl;
    cout << (contains(transmission2, mcode1, position) ? "true " + to_string(position) : "false") << endl;
    cout << (contains(transmission2, mcode2, position) ? "true " + to_string(position) : "false") << endl;
    cout << (contains(transmission2, mcode3, position) ? "true " + to_string(position) : "false") << endl;

    // Parte 2: Encontrar el palíndromo más  largo en los archivos de transmisión
    cout << "\n" <<  "Parte 2" << endl;
    pair<pair<int, int>, string> palindromeTransmission1 = findLongestPalindrome(transmission1);
    pair<pair<int, int>, string> palindromeTransmission2 = findLongestPalindrome(transmission2);

    cout << palindromeTransmission1.first.first << " " << palindromeTransmission1.first.second << " " << palindromeTransmission1.second << endl;
    cout << palindromeTransmission2.first.first << " " << palindromeTransmission2.first.second << " " << palindromeTransmission2.second << endl;

    // Parte 3: Encontrar la subcadena común más larga entre las transmisiones
    cout << "Parte 3" << endl;
    pair<int, int> longestCommonSubstring = findLongestCommonSubstring(transmission1, transmission2);
    cout << longestCommonSubstring.first << " " << longestCommonSubstring.second << " ";
    cout << transmission1.substr(longestCommonSubstring.first - 1, longestCommonSubstring.second - longestCommonSubstring.first + 1) << endl;


    return 0;
}
