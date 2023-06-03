#include <iostream>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	string str1 = "The House sits on the outskirts of town.", 
		str2 = "They call it Gray House.";
	[](auto s1, auto s2) { (size(s1) > size(s2)) ? cout << s1 : cout << s2; }
	(str1, str2);
}