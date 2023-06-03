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

int main() {
	setlocale(0, "rus");
	ofstream fout;
	ifstream fin;
	string file = "file.txt";

	string str;
	cout << "Введите строку: ";
	getline(cin, str);

	fout.open(file);
	write(fout, str);

	fin.open(file);
	read(fin, str);

	int count = 0;
	int arr[50];
	int size = 0;

	int index = 0;
	str += " ";

	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ') {
			count++;
		}
		else {
			arr[size] = count;
			size++;
			count = 0;
		}
	}

	int min = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
			index = i;
		}
	}
	string group;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ' && str[i - 1] != ' ') {
			count++;
		}
		else if (count == index) {
			group += str[i];
		}
	}

	cout << "Самая короткая группа: " << group << endl;

	return 0;
}