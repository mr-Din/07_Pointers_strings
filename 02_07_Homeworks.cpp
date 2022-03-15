#include "Header.h"


/*
Задание 7. Дана строка символов. Заменить в ней все пробелы на табуляции.
*/

void ReplaceSpace(string& s) {
	while (s.find(" ") != string::npos)
	{
		s.replace(s.find(" "), 1, "\t");
	}
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	cout << "Введите строку: ";
	string s;
	getline(cin, s);
	ReplaceSpace(s);
	cout << s << endl;

	return 0;
}