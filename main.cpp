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
// check if vector is empty
bool isEmpty(vector<int> vec)
{
    if (vec.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string fileName = "transmission1.txt";
    string fileName2 = "transmission2.txt";
    string malicious1 = "mcode1.txt";
    string malicious2 = "mcode2.txt";
    string malicious3 = "mcode3.txt";

    string example = "test.txt";
    string example2 = "test2.txt";
    string example3 = "test3.txt";

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
    // print for transmission2.txt
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

    // cout<<"\t Malicious 1"<<endl;
    // int index = isSubstring(text, malicious1);
    // cout << text << endl;
    // cout<<"\t Malicious 2"<<endl;
    // index = isSubstring(text, malicious1);
    // cout<<"\t Malicious 3"<<endl;
    // cout << text << endl;
    // index = isSubstring(text, malicious1);

    return 0;
}
