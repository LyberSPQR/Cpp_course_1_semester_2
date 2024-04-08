// 5.2
#include <iostream>
#include <string.h>
using namespace std;
void findingNumber(string& str);
int main()
{
	setlocale(LC_ALL, "Russian");
	string str(100,'\0');
	findingNumber(str);
	
	return 0;
}
void findingNumber(string& str)
{
	int m, r, j, i = 0, n;
	cout << "Введите натуральное число m " << endl;
	cin >> m;
	do
	{
		int r = m % 2;
		m = m / 2;
		str.at(i) = char('0' + r);
		i++;
	} while (m > 0);

	cout << str;
	long int dec = 0;
	int v = 1;
	dec = 0;
	int sizik = i;
	for (int i = sizik; i >= 0; i--)
	{
		if (str.at(i) == '1')
		{
			dec += v;
		}
		v *= 2;
	}
	cout << endl << "n = " << dec / 2 << endl;
}