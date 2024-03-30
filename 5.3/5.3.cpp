// 5.2
// Разбить текст на слова и записать их новую строку.
// Выполнить задание для введенной строки символов.
#define _CRT_SECURE_NO_WARNINGS

#include <iostream> 
#include <string>

using namespace std;
void enteringText(string*& ArrayPtr, string& arrayword, const int sizek, int& wordAmount);
void outputWords(string*& ArrayPtr, int& wordAmount);
void creatingNewString(string*& ArrayPtr, int& wordAmount, const int sizek);
int main()
{
	setlocale(LC_ALL, "ru");
	const int sizek = 50;
	int  num = 0, cntr = 2, queueCouner = 0, progCounter = 0, letterCounter = 0, wordAmount = 1;
	string* ArrayPtr = new string[sizek];
	string arrayword(100, '\0');

	enteringText(ArrayPtr, arrayword, sizek, wordAmount);
	outputWords(ArrayPtr, wordAmount);
	creatingNewString(ArrayPtr, wordAmount, sizek);

	delete[] ArrayPtr;

	return 0;
}

void enteringText(string*& ArrayPtr, string& arrayword, const int sizek, int& wordAmount)
{
	cout << "Введите текст: ";
	getline(cin, arrayword);

	int counter = 0;

	for (int i = 0; i < sizek; i++)
	{
		ArrayPtr[i].resize(50, '\0');
	}
	int j = 0;
	int StrlenArray = size(arrayword);
	cout << "StrlenArray = " << StrlenArray << endl;
	if (arrayword[StrlenArray - 1] == '.' || arrayword[StrlenArray - 1] == '!' || arrayword[StrlenArray - 1] == '?')
		wordAmount--;
	for (int counter = 0; counter < StrlenArray; counter++)
	{
		if (arrayword[counter] == ' ' || arrayword[counter] == '\0' || arrayword[counter] == ':' || arrayword[counter] == ';' || arrayword[counter] == '!' || arrayword[counter] == '?' || arrayword[counter] == '.' || arrayword[counter] == ',' || arrayword[counter] == '(' || arrayword[counter] == ')' || arrayword[counter] == '-')
		{
			wordAmount++;
			if (arrayword[counter + 1] == ' ' || arrayword[counter + 1] == ':' || arrayword[counter + 1] == ';' || arrayword[counter + 1] == '!' || arrayword[counter + 1] == '?' || arrayword[counter + 1] == '.' || arrayword[counter + 1] == ',' || arrayword[counter + 1] == '(' || arrayword[counter + 1] == ')' || arrayword[counter + 1] == '-')
			{
				counter++;
			}
		}
	}

	for (int i = 0; i < wordAmount; i++) // заполнение массива
	{
		while (arrayword[counter] != ' ' && arrayword[counter] != '\0' && arrayword[counter] != ':' && arrayword[counter] != ';' && arrayword[counter] != '!' && arrayword[counter] != '?' && arrayword[counter] != '.' && arrayword[counter] != ',' && arrayword[counter] != '(' && arrayword[counter] != ')' && arrayword[counter] != '-')

		{
			ArrayPtr[i][j] = arrayword[counter];
			j++;
			if (arrayword[counter + 1] == ':' || arrayword[counter + 1] == ';' || arrayword[counter + 1] == '!' || arrayword[counter + 1] == '?' || arrayword[counter + 1] == '.' || arrayword[counter + 1] == ',' || arrayword[counter + 1] == '(' || arrayword[counter + 1] == ')' || arrayword[counter + 1] == '-')
				counter++;
			counter++;
		}
		j = 0;
		counter++;
	}
}
void outputWords(string*& ArrayPtr, int& wordAmount)
{
	cout << "WordAmount = " << wordAmount << endl;
	for (int i = 0; i < wordAmount; i++) // Output Array
	{
		cout << endl << " Word: ";
		for (int j = 0; ArrayPtr[i][j] != '\0'; j++)
		{
			cout << ArrayPtr[i][j];
		}
		cout << " " << endl;
	}
}
void creatingNewString(string*& ArrayPtr, int& wordAmount, const int sizek)
{
	int  num = 0, cntr = 2, queueCouner = 0, progCounter = 0, letterCounter = 0;
	string newString(100, '\0');
	string stringus(100, '\0');
	for (int i = 0; i < wordAmount; i++)
	{
		string word(100, '\0');
		for (int j = 0; j < sizek; j++)
		{
			if ((int(ArrayPtr[i][j]) >= 65 && int(ArrayPtr[i][j]) <= 90) || (int(ArrayPtr[i][j]) >= 97 && int(ArrayPtr[i][j]) <= 122))
			{
				stringus[j] = ArrayPtr[i][j];
				stringus[j + 1] = '\0';
			}
		}

		for (int j = 0; j < sizek; j++)
		{
			word[j] = stringus[j];
		}

		for (int j = 0; word[j] != '\0'; j++)
		{
			num = j;
		}

		int wordLong = size(word);
		char wordus[] = { 'x','y','z' };

		if (num >= 3)
		{
			for (int j = num; j >= num - 3; j--)
			{
				if (word[j] == wordus[cntr])
				{
					cntr--;
					letterCounter++;
				}
			}
		}

		cntr = 2;

		if (letterCounter == 3)
		{
			progCounter++;
			newString += word;
			newString += " ";
		}
		letterCounter = 0;
	}

	if (progCounter < 1)
	{
		cout << "No such words";

	}
	cout << endl << "newString: " << newString << endl;
}