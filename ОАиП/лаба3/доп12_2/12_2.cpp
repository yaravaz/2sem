#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void inFile(ifstream& f, string& text, string& file) 
{
	f.open(file);
	if (f.fail()) {
		cout << "\n Error";
		exit(1);
	}
	f >> text;
	f.close();
}
void fromFile(ofstream& f, string& text, string& file)
{
	f.open(file);
	if (f.fail())
	{
		cout << "\nError";
		exit(1);
	}
	f << text;
	f.close();
}

void main() {
	setlocale(0, "rus");
	string str, file = "text.txt";
	cout << "¬ведите строку: " << endl;
	cin.ignore();
	getline(cin, str);
	ofstream fout;
	fromFile(fout, str, file);

	string buf;
	int count = 0;
	ifstream fin;
	inFile(fin, buf, file);

	for (int i = 0; buf[i] != '\0'; i++) {
		if (buf[i] == ',') {
			count++;
		}
	}
	cout << count;
}