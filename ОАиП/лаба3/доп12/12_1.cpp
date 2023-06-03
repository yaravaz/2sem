
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void main() {

	setlocale(LC_ALL, "ru");

	ofstream fout;
	ifstream fin;
	string str, file1 = "FILE1.txt", file2 = "FILE2.txt";
	string word;
	int count = 0, size = 0;

	fin.open(file1);
	fin >> word;
	fin.close();

	for (int i = 0; word[i] != '\0'; i++) {
		size++;
	}

	fin.open(file1);
	fout.open(file2);
	while (!fin.eof()) {
		str = "";
		getline(fin, str);
		int i = 0;
		while (i < str.length()) {
			int j = 0;
			while (str[i] == word[j] && j < word.length()) {

				i++;
				j++;
			}
			if (j == word.length()) {
				fout << str << endl;
				break;
			}
			else {
				i++;
			}
		}
	}
	fin.close();
	fout.close();


	int a = 0;
	count = 0;
	fin.open(file2);
	string buf;
	while (!fin.eof()) {
		getline(fin, buf);
		count++;
	}
	fin.close();
	fin.open(file2);
	while (!fin.eof()) {
		getline(fin, buf);
		a++;
		if (a == count - 1) {
			count = 0;
			for (int i = 0; i <= buf.length(); i++) {
				if (((buf[i] >= 'b' && buf[i] <= 'd') || (buf[i] >= 'f' && buf[i] <= 'h') || (buf[i] >= 'j' && buf[i] <= 'n') || (buf[i] >= 'p' && buf[i] <= 't') || (buf[i] >= 'v' && buf[i] <= 'x') || buf[i] == 'z') || ((buf[i] >= 'B' && buf[i] <= 'D') || (buf[i] >= 'F' && buf[i] <= 'H') || (buf[i] >= 'J' && buf[i] <= 'N') || (buf[i] >= 'P' && buf[i] <= 'T') || (buf[i] >= 'V' && buf[i] <= 'X') || buf[i] == 'Z')) {
					count++;
				}
			}
		}
	}
	cout << count;
	fin.close();
}


