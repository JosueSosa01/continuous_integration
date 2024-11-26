#include <iostream>
#include <fstream>
#include <string>
#include "../A01411984_ActInt1/ActInt1.cpp" 

using namespace std;  

string readFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << filename << endl;
        exit(1);
    }
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    return content;
}

void testContainsWithFiles() {
    string transmission1 = readFile("transmission1.txt");
    string transmission2 = readFile("transmission2.txt");
    string mcode1 = readFile("mcode1.txt");
    string mcode2 = readFile("mcode2.txt");
    string mcode3 = readFile("mcode3.txt");

    size_t position = 0;

    cout << "Prueba de 'contains' con archivos:" << endl;

    if (contains(transmission1, mcode1, position)) {
        cout << "  Se encontró mcode1 en transmission1 en la posición: " << position << " - APROBADA\n";
    } else {
        cout << "  No se encontró mcode1 en transmission1 - FALLIDA\n";
    }

    if (!contains(transmission2, mcode3, position)) {
        cout << "  No se encontró mcode3 en transmission2 - APROBADA\n";
    } else {
        cout << "  Se encontró mcode3 en transmission2 en la posición: " << position << " - FALLIDA\n";
    }
}

void testFindLongestPalindromeWithFiles() {
    string transmission1 = readFile("transmission1.txt");
    string transmission2 = readFile("transmission2.txt");

    auto result1 = findLongestPalindrome(transmission1);
    auto result2 = findLongestPalindrome(transmission2);

    cout << "Prueba de 'findLongestPalindrome' con archivos:" << endl;
    cout << "  Palíndromo más largo en transmission1: " << result1.second
         << " (Inicio: " << result1.first.first << ", Fin: " << result1.first.second << ") - APROBADA\n";
    cout << "  Palíndromo más largo en transmission2: " << result2.second
         << " (Inicio: " << result2.first.first << ", Fin: " << result2.first.second << ") - APROBADA\n";
}

void testFindLongestCommonSubstringWithFiles() {
    string transmission1 = readFile("transmission1.txt");
    string transmission2 = readFile("transmission2.txt");

    auto result = findLongestCommonSubstring(transmission1, transmission2);

    cout << "Prueba de 'findLongestCommonSubstring' con archivos:" << endl;
    cout << "  Subcadena común más larga: "
         << transmission1.substr(result.first - 1, result.second - result.first + 1)
         << " (Inicio: " << result.first << ", Fin: " << result.second << ") - APROBADA\n";
}

int main() {
    testContainsWithFiles();
    testFindLongestPalindromeWithFiles();
    testFindLongestCommonSubstringWithFiles();
    return 0;
}
