#include "Header.h"


/*
Задание 5. Пользователь вводит строку символов и искомый символ, посчитать сколько раз
он встречается в строке.
*/

void ReplaceDot(string& s) {
	while (s.find(".") != string::npos)
	{
		s.replace(s.find("."), 1, "!");
	}
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	cout << "Введите строку: ";
	string s; 
	getline(cin, s);
	cout << "Введите символ: ";
	char c; cin >> c;
	int count_c = 0;
	for (const char symb : s) {
		if (symb == c) {
			count_c++;
		}
	}
	cout << "Количество символов \"" << c << "\" равно: " << count_c << endl;
	
	return 0;
}