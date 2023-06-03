#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	setlocale(0, "rus");
	ofstream fout;
	ifstream fin;
	string file1 = "file1.txt", file2 = "file2.txt";

	fin.open(file1);
	if (!fin.is_open()) {
		cout << "error";
	}

	string str[20];
	int count = 0;
	while (!fin.eof()) {
		getline(fin, str[count]);
		count++;
	}

	fin.close();

	fout.open(file2);
	if (!fout.is_open()) {
		cout << "error";
	}

	string newStr[50];
	int size = 0;
	cout << "Количество слов: " << endl;
	for (int i = 0; i < count; i++) {
		if (str[i][0] == 'A' || str[i][0] == 'a') {
			fout << str[i] << endl;
			newStr[size] = str[i];
			size++;
		}
	}

	int count_word = 0;
	for (int i = 0; i < size; i++) {
		newStr[i] += " ";
		for (int j = 0; j < newStr[i].length(); j++) {
			if (newStr[i][j] == ' ' && newStr[i][j - 1] != ' ') {
				count_word++;
			}
		}
	}

	cout << count_word << endl;
	fout.close();
	return 0;
}