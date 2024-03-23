﻿#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;

int create(char* s, int n);   // создание исходного файла чисел
int read_file(char* s);     // вывод на экран 
int create_file(char* s1, char* s, int n); // создание файла из файла исходного
int main()
{
    unsigned int n;
    cout << "Enter count of numbers " << endl;
    cin >> n;                   // количество чисел файла
    if (n % 2 != 0)
    {
        cout << "Error!";
        return 0;
    }

    char s[40] = "file.txt";   // имя файла   для записи 
    int error = create(s, n); // создание исходного файла 
    if (error != 0)
        return 1;
    cout << "Numbers in file1" << endl;
    error = read_file(s); // вывод на экран     
    if (error != 0)
        return 1;
    // имя нового файла для записи
    char s1[40] = "file1.txt";
    error = create_file(s1, s, n);  // создание  файла
    if (error != 0)
        return 1;
    cout << "Numbers in file2" << endl;
    error = read_file(s1);              // вывод на экран 
    if (error != 0)
        return 1;
    return 0;
}

// создание файла n cл. чисел
int create(char* s, int n)
{
    ofstream outfile(s);   // открываем файл для записи
    if (!outfile)
    {
        cout << "error1" << endl;
        return 1;
    }

    cout << "Enter numbers" << endl;
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        outfile << v << endl; // запись чисел в файл
    }
    outfile.close();
    return 0;
}

// вывод на экран файла чисел
int  read_file(char* s)
{
    ifstream infile(s); // открываем файл для чтения
    if (!infile)
    {
        cout << "error2" << endl;
        return 2;
    }

    int v;
    infile >> v;
    while (!infile.eof())
    {
        cout << v << " ";
        infile >> v;   // чтение чисел из файла   
    }
    cout << endl;

    infile.close();
    return 0;
}

// создание  файла 
int create_file(char* s1, char* s, int n)
{
    ofstream outfile(s1);   // открываем файл для записи
    if (!outfile)
    {
        cout << "error3" << endl;
        return 3;
    }
    ifstream infileChet(s);  // открыть файл для чтения 
    ifstream infileNeChet(s);


    int v, g, cntElements = 0, cntChet = 0, countofChet = 0, countofNeChet = 0, cntNeChet = 0;
    infileChet >> v;
    infileNeChet >> g;

    while (cntElements != n)
    {
        while (countofNeChet != n / 2 && cntNeChet != 1)
        {
            if (g % 2 != 0)
            {
                outfile << g << endl;
                cntElements++;
                cntNeChet++;
                countofNeChet++;
            }
            infileNeChet >> g;
        }

        while (countofChet != n / 2 && cntChet != 1)
        {
            if (v % 2 == 0)
            {
                outfile << v << endl;
                cntElements++;
                cntChet++;
                countofChet++;
            }
            infileChet >> v;
        }
        cntChet = 0;
        cntNeChet = 0;
    }

    infileChet.close();
    infileNeChet.close();
    outfile.close();

    return 0;
}