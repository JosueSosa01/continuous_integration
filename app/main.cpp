#include <iostream>
#include <string>
#include "functions.h"

using namespace std;

int main()
{
    string transmission1 = readFile("transmission1.txt");
    string transmission2 = readFile("transmission2.txt");
    string mcode1 = readFile("mcode1.txt");
    string mcode2 = readFile("mcode2.txt");
    string mcode3 = readFile("mcode3.txt");

    cout << "Parte 1" << endl;
    size_t position;
    cout << (contains(transmission1, mcode1, position) ? "true " + to_string(position) : "false") << endl;
    cout << (contains(transmission1, mcode2, position) ? "true " + to_string(position) : "false") << endl;
    cout << (contains(transmission1, mcode3, position) ? "true " + to_string(position) : "false") << endl;
    cout << (contains(transmission2, mcode1, position) ? "true " + to_string(position) : "false") << endl;
    cout << (contains(transmission2, mcode2, position) ? "true " + to_string(position) : "false") << endl;
    cout << (contains(transmission2, mcode3, position) ? "true " + to_string(position) : "false") << endl;

    cout << "\n"
         << "Parte 2" << endl;
    pair<pair<int, int>, string> palindromeTransmission1 = findLongestPalindrome(transmission1);
    pair<pair<int, int>, string> palindromeTransmission2 = findLongestPalindrome(transmission2);

    cout << palindromeTransmission1.first.first << " " << palindromeTransmission1.first.second << " " << palindromeTransmission1.second << endl;
    cout << palindromeTransmission2.first.first << " " << palindromeTransmission2.first.second << " " << palindromeTransmission2.second << endl;

    cout << "Parte 3" << endl;
    pair<int, int> longestCommonSubstring = findLongestCommonSubstring(transmission1, transmission2);
    cout << longestCommonSubstring.first << " " << longestCommonSubstring.second << " ";
    cout << transmission1.substr(longestCommonSubstring.first - 1, longestCommonSubstring.second - longestCommonSubstring.first + 1) << endl;

    return 0;
}
