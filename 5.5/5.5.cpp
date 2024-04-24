// 5.5.cpp  . Для заданной матрицы А найти значение min(j)SUM(|aij|)

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
int main()
{
	srand(time(NULL));
	int Row,cntMin, Col,sum = 0;
	vector<vector<int>> Matrix;
	cout << "Enter count of Rows" << endl;
	cin >> Row;
	cout << "Enter count of Columns" << endl;
	cin >> Col;

	for (int i = 0; i < Row; i++)
	{
		vector <int> temp;    
		for (int j = 0; j < Col; j++) 
			temp.push_back(rand() % 10 - 5);
		Matrix.push_back(temp);
	}

	for (int i = 0; i < Matrix.size(); i++)
	{               
		for (int j = 0; j < Matrix[i].size(); j++)
			cout << "  " << Matrix[i][j] << "\t";
			cout << endl;
	}
	cout << endl;

	int min = INT_MAX;
	for (int j = 0; j < Col; j++)
	{
		for (int i = 0; i < Row; i++)
		{
			sum += abs(Matrix[i][j]);
		}
		if (sum < min)
		{
			min = sum;
			cntMin = j + 1;
		}
		sum = 0;
	}
	cout << "Number of column with min sum: " << cntMin << endl;
	cout << "Min sum in Column: " << min << endl;
	return 0;
}