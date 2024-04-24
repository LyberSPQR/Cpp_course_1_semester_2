// 5.4 Из двух массивов разной длины сформировать общий массив и поменять местами его максимальный и минимальный элементы.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector <int> vector1 = { 1,10 ,2,3,4 };
	vector <int> vector2 = { 5,6,7,8,9 };
	vector <int> vector3;
	auto iter = vector3.cbegin();
	vector3.insert(iter, begin(vector1), end(vector1));
	auto iter3 = vector3.end();
	vector3.insert(iter3, vector2.begin(), vector2.end());

	for (int n : vector3)
		cout << n << "   ";
	cout << endl;
	iter_swap(min_element(vector3.begin(), vector3.end()), max_element(vector3.begin(), vector3.end()));
	for (int n : vector3)
		cout << n << "   ";
}