#include <iostream> 
#include <string> 

using namespace std;

int main()
{
	string Text(100, '\0');
	getline(cin, Text);
	cout << "Text: " << Text << endl;
	int sizus = Text.length();
	cout << "Length: " << sizus << endl;

	string newString = "";
	string wordus = { 'x','y','z' };
	string word(20, '\0');

	int posic = 0;
	int j = 0, b = 0;

	while (Text.find(wordus, posic + 2) != std::string::npos)
	{
		posic = Text.find(wordus, posic + 2);
		for (int i = posic + 2; Text.at(i) != ' ' && Text.at(i) != ',' && Text.at(i) != '.' && Text.at(i) != '!' && Text.at(i) != '?' && Text.at(i) != ':'  && i > 0; i--)
		{
			b = i - 1;
		}
		for (int i = b; i <= posic + 2; i++)
		{
			word.at(j) = Text.at(i);
			j++;
		}
		j = 0;

		newString += word;
		newString += " ";
		word = string(20, '\0');
	}
	cout << endl << "newString: " << newString << endl;
}