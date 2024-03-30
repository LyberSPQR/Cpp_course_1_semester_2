// 5.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <string.h>
using namespace std;

void findingElements(string string0, string string1);
void findingString2(string& string0, string& string2, int lenght);
void findingLettersAlphabetOrder(string& string2);

int main()
{
    string string0 = "ahdh*dbhhh3y3f32fg2jsgw*7";
    string string1(30, '\0');
    string string2(30, '\0');

    int lenght = size(string0);

    findingElements(string0, string1);
    findingString2(string0, string2, lenght);
    findingLettersAlphabetOrder(string2);

    return 0;
}

void findingElements(string string0, string string1)
{
    int k = 0, lenght = size(string0), j = 0;
    cout << lenght << endl;
    cout << "String: " << string0 << endl;
    for (int i = 0; i < lenght; i++)
    {
        if (string0[i] == '*')
        {
            k = i;
            i++;
            cout << "Elements: ";
            for (; string0[i] != '*'; i++)
            {
                if (j < lenght - k && i < lenght)
                {
                    string1[j] = string0[i];
                    cout << string1[j] << " ";
                    j++;
                }
                else {
                    break;
                }
            }
        }
    }
}

void findingString2(string& string0, string& string2, int lenght)
{
    int j = 0;
    for (int i = 0; i < lenght; i++)
    {
        if ('a' <= string0[i] && string0[i] <= 'z'
            || 'A' <= string0[i] && string0[i] <= 'Z')
        {
            string2[j] = string0[i];
            j++;
        }
        string2[j] = '\0';
    }

    cout << endl;
    cout << "String2: " << string2 << endl << size(string2) << endl;

    for (int i = 0; i < size(string2) - 1; i++)
    {
        for (int j = size(string2) - 1; j > i; j--)
        {
            if (string2[j - 1] > string2[j])
            {
                int b = string2[j - 1];
                string2[j - 1] = string2[j];
                string2[j] = b;
            }
        }
    }
}

void findingLettersAlphabetOrder(string& string2)
{
    int counter = 0;
    cout << "Letters in alphabetical order, occurring once: ";
    for (int j = 0; j < size(string2); j++)
    {
        for (int i = 0; i < size(string2); i++)
        {
            if (string2[j] == string2[i])
            {
                counter++;
            }
        }
        if (counter == 1)
        {
            cout << string2[j] << " ";

        }
        counter = 0;
    }
}
