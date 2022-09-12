// =========================================================
// File: main.cpp
// Authors:
// Ariann Fernando A01703556
// Jaime López Hernández A00571842
//
// Date: 21/ 09 / 2022
// =========================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

// function to read file
string readFile(string fileName)
{
    string line;
    string text;
    ifstream file(fileName);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            text += line;
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file";
    }
    return text;
}

// function to check if substring is in string
int isSubstring(string text, string substring)
{
    auto isFound = text.find(substring);
    if (isFound != string::npos)
    {
        return isFound;
    }
    else
    {
        return -1;
    }
}

// find palindrome in string
vector<int> findPalindrome(string text)
{
    vector<int> palindrome;
    int initialIndex = 0;
    int finalIndex = 0;
    int length = 0;
    for (int i = 0; i < text.size(); i++)
    {
        for (int j = i + 1; j < text.size(); j++)
        {
            string substring = text.substr(i, j - i + 1);
            string reverseSubstring = substring;
            reverse(reverseSubstring.begin(), reverseSubstring.end());
            if (substring == reverseSubstring)
            {
                if (substring.size() > length)
                {
                    length = substring.size();
                    initialIndex = i;
                    finalIndex = j;
                }
            }
        }
    }
    palindrome.push_back(initialIndex);
    palindrome.push_back(finalIndex + 1);
    return palindrome;
}

// function longest substring of two strings
string longestSubstring(string text1, string text2)
{
    string longestSubstring;
    int length = 0;
    for (int i = 0; i < text1.size(); i++)
    {
        for (int j = i + 1; j < text1.size(); j++)
        {
            string substring = text1.substr(i, j - i + 1);
            int isSubstring = text2.find(substring);
            if (isSubstring != string::npos)
            {
                if (substring.size() > length)
                {
                    length = substring.size();
                    longestSubstring = substring;
                }
            }
        }
    }
    return longestSubstring;
}

// function to check is substring is in string
void positionSubstring(string text, string substring, vector<int> &vec)
{
    for (int i = 0; text[i] != '\n'; i++)
    {
        for (int j = 0; substring[j] != '\n'; j++)
        {
            if (text[i + j] != substring[j])
            {
                break;
            }
            if (j == 1)
            {
                vec.push_back(i);
            }
        }
    }
}

// function to print vector
template <typename T>
void printVector(vector<T> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()
{
    string fileName = "transmission1.txt";
    string fileName2 = "transmission2.txt";
    string malicious1 = "mcode1.txt";
    string malicious2 = "mcode2.txt";
    string malicious3 = "mcode3.txt";

    // string example = "test.txt";
    // string example2 = "test2.txt";
    // string example3 = "test3.txt";

    string text = readFile(fileName);
    string text2 = readFile(fileName2);
    string code1 = readFile(malicious1);
    string code2 = readFile(malicious2);
    string code3 = readFile(malicious3);

    // string text2 = readFile(example);
    // string text3 = readFile(example2);
    // string text4 = readFile(example3);

    // cout << text2 << endl;
    // cout << text3 << endl;

    // cout << text << endl;
    cout << "==========================" << endl;
    vector<int> vecPositions;
    vector<int> vecPositions2;

    // positionSubstring(text2, text3, vecPositions);
    // printVector(vecPositions);

    int resultText1Code1 = isSubstring(text, code1);
    int resultText1Code2 = isSubstring(text, code2);
    int resultText1Code3 = isSubstring(text, code3);

    int resultText2Code1 = isSubstring(text2, code1);
    int resultText2Code2 = isSubstring(text2, code2);
    int resultText2Code3 = isSubstring(text2, code3);

    // ======1st part of the code======
    // transmission 1.txt
    cout << "transmission1.txt: " << endl;
    cout << "mcode1.txt - ";
    if (resultText1Code1 == -1)
    {
        cout << "false" << endl;
    }
    else
    {
        cout << "true, start at position: " << resultText1Code1 << endl;
    }
    cout << "mcode2.txt - ";
    if (resultText1Code2 == -1)
    {
        cout << "false" << endl;
    }
    else
    {
        cout << "true, start at position: " << resultText1Code2 << endl;
    }
    cout << "mcode3.txt - ";
    if (resultText1Code3 == -1)
    {
        cout << "false" << endl;
    }
    else
    {
        cout << "true, start at position: " << resultText1Code3 << endl;
    }
    cout << endl;
    // transmission2.txt
    cout << "transmission2.txt: " << endl;
    cout << "mcode1.txt - ";
    if (resultText2Code1 == -1)
    {
        cout << "false" << endl;
    }
    else
    {
        cout << "true, start at position: " << resultText2Code1 << endl;
    }
    cout << "mcode2.txt - ";
    if (resultText2Code2 == -1)
    {
        cout << "false" << endl;
    }
    else
    {
        cout << "true, start at position: " << resultText2Code2 << endl;
    }
    cout << "mcode3.txt - ";
    if (resultText2Code3 == -1)
    {
        cout << "false" << endl;
    }
    else
    {
        cout << "true, start at position: " << resultText2Code3 << endl;
    }
    cout << endl;

    // ======2nd part of the code======

    cout << "transmission1.txt: " << endl;
    vector<int> palindrome1 = findPalindrome(text);
    cout << "mirrored code found, start at " << palindrome1[0] << " ended at " << palindrome1[1] << endl;
    vector<int> palindrome2 = findPalindrome(text2);
    cout << "transmission2.txt: " << endl;
    cout << "mirrored code found, start at " << palindrome2[0] << " ended at " << palindrome2[1] << endl;
    cout << endl;
    //======3rd part of the code======
    string longestSubstring1 = longestSubstring(text, text2);
    cout << "the longest common substring between transmission1.txt and transmission2.txt is " << longestSubstring1.length() << " characters long" << endl;

    return 0;
}
