#include <iostream>
#include <fstream>
#include <string>

const int n = 40;
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	ifstream file1("FILE1.txt");
	ofstream file2("FILE2.txt");
	if (!file1.is_open())
		cout << "Файл не может быть открыт!\n";
	else
	{
		string str; int counter = 0; bool num_exist = false;
		cout << "Файл открыт успешно!\n\n";
		while (getline(file1, str)) {
			cout << str << endl;
			for (int i = 0; i < str.size(); i++) {
				if (str[i] >= '0' && str[i] <= '9') {
					num_exist = true;
					continue;
				}
			}
			if (!num_exist) {
				file2 << str << endl;
				if (str[0] == 'A') {
					counter++;
				}
			}
			num_exist = false;
		}
		file2 << "Количество 'А' в начале строк " << counter;
	}
	file1.close();
	file2.close();
	return 0;
}