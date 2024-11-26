#include "functions.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

string readFile(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    return content;
}

bool contains(const string &haystack, const string &needle, size_t &position)
{
    size_t pos = haystack.find(needle);
    if (pos != string::npos)
    {
        position = pos + 1; // Convertir a 1-indexado
        return true;
    }
    return false;
}

pair<pair<int, int>, string> findLongestPalindrome(const string &s)
{
    int n = s.length();
    int start = 0, maxLength = 1;
    vector<vector<bool>> table(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i)
    {
        table[i][i] = true;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] == s[i + 1])
        {
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    for (int len = 3; len <= n; ++len)
    {
        for (int i = 0; i < n - len + 1; ++i)
        {
            int j = i + len - 1;
            if (s[i] == s[j] && table[i + 1][j - 1])
            {
                table[i][j] = true;
                if (len > maxLength)
                {
                    start = i;
                    maxLength = len;
                }
            }
        }
    }

    string palindrome = s.substr(start, maxLength);
    return {{start + 1, start + maxLength}, palindrome};
}

pair<int, int> findLongestCommonSubstring(const string &s1, const string &s2)
{
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    int maxLength = 0;
    int endPos = 0;

    for (int i = 1; i <= n1; ++i)
    {
        for (int j = 1; j <= n2; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength)
                {
                    maxLength = dp[i][j];
                    endPos = i - 1;
                }
            }
        }
    }

    int startPos = endPos - maxLength + 1;
    return {startPos + 1, endPos + 1};
}
