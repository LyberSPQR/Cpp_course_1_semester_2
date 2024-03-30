// 3.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;

void create(char* s, int n);   // создание исходного файла чисел
void read_file(ifstream& infile);     // вывод на экран 
int create_file(char* s1, char* s); // создание файла из файла исходного

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

    char s[40] = "file.bin";   // имя файла   для записи 
     create(s, n); // создание исходного файла 

    ifstream infile(s, ios::binary | ios::_Nocreate); // открываем файл для чтения
    if (!infile)
    {
        cout << "error2" << endl;
        return 2;
    }
    cout << "Numbers in file1" << endl;
     read_file(infile); // вывод на экран     
 
    // имя нового файла для записи
    char s1[40] = "file1.bin";
    create_file(s1, s);  // создание  файла
    infile.close();
    cout << "Numbers in file2" << endl;
    ifstream infileS1(s1, ios::binary | ios::_Nocreate); // открываем файл для чтения
    if (!infileS1)
    {
        cout << "error2" << endl;
    }
    read_file(infileS1);              // вывод на экран 
    infileS1.close();

    return 0;
}

// создание файла n cл. чисел
void create(char* s, int n)
{
    ofstream outfile(s, ios::binary);
    if (!outfile)
    {
        cout << "error1" << endl;
    }

    cout << "Enter numbers" << endl;
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        outfile.write(reinterpret_cast<char*>(&v), sizeof(int));

    }
    outfile.close();
    
}

// вывод на экран файла чисел
void read_file(ifstream& infile)
{
    int v;
    infile.read(reinterpret_cast<char*>(&v), sizeof(int));
    while (!infile.eof())   //  до достижения конца файла
    {
        cout << v << " " << "\n";
        //  чтение элемента из файла  infile.read
        infile.read(reinterpret_cast<char*>(&v), sizeof(int));
    }

  
    cout << endl;

    infile.clear();
    infile.close();
   
}

// создание  файла 
int create_file(char* s1, char* s)
{
    ifstream infile(s, ios::binary | ios::_Nocreate);
    // открываем файл для чтения
    unsigned long size = 0, h;

    while (!infile.eof())
    {
        infile.read(reinterpret_cast<char*>(&h), sizeof(int));
        size++;
    }
    size -= 1;
    infile.close();

    cout << "Size = " << size << endl;

    ofstream outfileS(s1, ios::binary);   // открываем файл для записи
    if (!outfileS)
    {
        cout << "error3" << endl;
    }
    ifstream infileChet(s, ios::binary | ios::_Nocreate);  // открыть файл для чтения 
    ifstream infileNeChet(s, ios::binary | ios::_Nocreate);


    int v, g, cntElements = 0, cntChet = 0, countofChet = 0, countofNeChet = 0, cntNeChet = 0;
    infileChet.read(reinterpret_cast<char*>(&v), sizeof(int));
    infileNeChet.read(reinterpret_cast<char*>(&g), sizeof(int));
    
    while (cntElements != size)
    {
        while (countofNeChet != size / 2 && cntNeChet != 1)
        {
            if (g % 2 != 0)
            {
                outfileS.write(reinterpret_cast<char*>(&g), sizeof(int));
                cntElements++;
                cntNeChet++;
                countofNeChet++;
            }
            infileNeChet.read(reinterpret_cast<char*>(&g), sizeof(int));
        }

        while (countofChet != size / 2 && cntChet != 1)
        {
            if (v % 2 == 0)
            {
                outfileS.write(reinterpret_cast<char*>(&v), sizeof(int));
                cntElements++;
                cntChet++;
                countofChet++;
            }
            infileChet.read(reinterpret_cast<char*>(&v), sizeof(int));
        }
        cntChet = 0;
        cntNeChet = 0;
    }

    infileChet.close();
    infileNeChet.close();
    outfileS.close();

    return 0;
}