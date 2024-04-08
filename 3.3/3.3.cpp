// 3.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;
struct Students
{
	char fio[6] = "";
	unsigned int age;
	unsigned int course;
	unsigned int gender;
	double grade;
};

void creatingDatabase(Students& student,int cntStudents)
{
	ofstream fout("data_base.bin", ios::binary);
	for (int i = 0; i < cntStudents; i++)
	{
		strcpy(student.fio, "Вася");
		student.age = rand() % 4 + 18;
		student.course = rand() % 3 + 1;
		student.gender = rand() % 2 + 1;
		student.grade = rand() % 3 + 7;

		fout.write(reinterpret_cast<const char*>(&student),sizeof(Students));

		cout << "ФИО: " << student.fio << endl;
		cout << "Возраст: " << student.age << endl;
		cout << " Курс: " << student.course << endl;
		cout << "Пол: (1 - муж 2 - жен) " << student.gender << endl;
		cout << "Успеваемость: " << student.grade << endl << endl << endl << endl;
	}
	fout.close();
}

void findingCntOfGoodStudents(Students& student, int cntStudents)
{
	int course, counter = 0;
	cout << "Enter course to search: " << endl;
	cin >> course;
	ifstream fin("data_base.bin", ios::binary);
	for (int i = 0; i < cntStudents; i++)
	{
		fin.read(reinterpret_cast<char*>(&student), sizeof(Students));
		if (student.course == course && student.grade >= 8)
			counter++;
	}
	cout << "Count of good students: " << counter;
	fin.close();
}

int main()
{
	setlocale(LC_ALL, "ru");
	Students student;
	int cntStudents;
	cout << "Enter count of students: " << endl;
	cin >> cntStudents;
	creatingDatabase(student, cntStudents);
	findingCntOfGoodStudents(student, cntStudents);
	return 0;
}