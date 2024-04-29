// 5.7.cpp
//

#include <iostream>
#include <list>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	list<string> Text;
 
        ifstream inputFile("input.txt");
        ofstream outputFile("output.txt");

        if (!inputFile.is_open() || !outputFile.is_open()) {
            cout << "Не удалось открыть файл." << endl;
            return 0;
        }
        string word;
        string temp;

        while (inputFile >> word)
            Text.push_back(word);

        inputFile.close();

        for (auto iterator = Text.begin(); iterator != Text.end(); iterator++)
        {
            temp = *iterator;
            if (temp[0] == 'a')
            {
                for (int i = 0; i < temp.length(); i++)
                {
                    if ((97 <= temp[i] && temp[i] <= 122) || (65 <= temp[i] && temp[i] <= 90))
                    {
                        outputFile << temp[i];
                    }
                }
                outputFile << " ";
            } 
        }
        outputFile.close();
        return 0;
}