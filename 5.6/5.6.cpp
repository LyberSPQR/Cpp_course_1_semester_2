// 5.6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() 
{
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Не удалось открыть файл." << endl;
        return 0;
    }
    vector<string> words;
    string word;

    while (inputFile >> word)
        words.push_back(word);

    inputFile.close();

    for (auto iterator = words.rbegin(); iterator != words.rend(); ++iterator) {
        outputFile << *iterator << " ";
    }
    outputFile.close();
    return 0;
}