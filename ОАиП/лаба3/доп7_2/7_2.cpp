#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void read(ifstream& f, string str) {
	if (!f.is_open())
	{
		cout << "error";
	}

	getline(f, str);
	f.close();
}

void write(ofstream& f, string str) {
	if (!f.is_open())
	{
		cout << "error";
	}

	f << str;
	f.close();
}

int main()
{
	setlocale(0, "rus");
	ofstream fout;
	ifstream fin;
	string file = "file.txt";

	string str;
	cout << "¬ведите строку: ";
	getline(cin, str);

	fout.open(file);
	write(fout, str);

	fin.open(file);
	read(fin, str);

	int k;
	cout << "¬ведите k: ";
	cin >> k;

	int count = 1;
	int k_st = k - 1;

	for (int i = 1; i <= k; i++)
	{
		if (str[i] == ' ' && str[i - 1] != ' ')
		{
			count++;
		}
	}

	if (str[k_st] == ' ')
	{
		cout << count - 1;
	}
	else cout << count;
}