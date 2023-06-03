#include <iostream>		
#include <fstream>
#include <string>
using namespace std;

int count_words(string str)
{
	str += " ";
	int count = 0;
	for (int i = 1; i <= str.length(); i++)
	{
		if (str[i] == ' ' && str[i - 1] != ' ')
		{
			count++;
		}
	}
	return count;
}

int main()
{
	setlocale(0, "rus");
	ofstream fout;
	ifstream fin;
	string file1 = "file1.txt", file2 = "file2.txt";

	fin.open(file1);
	if (!fin.is_open())
	{
		cout << "error";
	}

	string str[20];
	int count = 0;
	while (!fin.eof())
	{
		getline(fin, str[count]);
		count++;
	}
	fin.close();

	fout.open(file2);
	if (!fout.is_open())
	{
		cout << "error";
	}

	cout << "Слова из 5 букв: " << endl;
	for (int i = 0; i < count; i++)
	{
		if (count_words(str[i]) == 1)
		{
			fout << str[i] << endl;
			if (str[i].length() == 5)
			{
				cout << str[i] << endl;
			}
		}
	}
	fout.close();
}