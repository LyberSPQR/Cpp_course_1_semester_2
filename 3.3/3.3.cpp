// 3.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;
struct Students
{
	char fio[40];
	unsigned int age;
	unsigned int course;
	unsigned int gender;
	double grade;
};

int main()
{
	setlocale(LC_ALL, "ru");
	Students student;
	ofstream fout("data_base.bin", ios::binary);
	int cntStudents, course, counter = 0;
	cout << "Enter count of students: " << endl;
	cin >> cntStudents;
	for (int i = 0; i < cntStudents; i++)
	{
		strcpy(student.fio, "Зубенко_Михаил_Петрович");
		student.age = rand() % 4 + 18;
		student.course = rand() % 3 + 1;
		student.gender = rand() % 2 + 1;
		student.grade = rand() % 3 + 7;

		fout << student.fio << " " << student.age << " " << student.course << " " << student.gender << " " << student.grade << endl;

		cout << "ФИО: " << student.fio << endl;
		cout << "Возраст: " << student.age << endl;
		cout << " Курс: " << student.course << endl;
		cout << "Пол: (1 - муж 2 - жен) " << student.gender << endl;
		cout << "Успеваемость: " << student.grade << endl << endl << endl << endl;
	}
	fout.close();

	cout << "Enter course to search: " << endl;
	cin >> course;
	ifstream fin("data_base.bin", ios::binary);
	for (int i = 0; i < cntStudents; i++)
	{
		fin >> student.fio >> student.age >> student.course >> student.gender >> student.grade;
		if (student.course == course && student.grade >= 8)
			counter++;
	}
	cout << "Count of good students: " << counter;
	fin.close();
}