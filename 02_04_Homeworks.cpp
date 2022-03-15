#include "Header.h"


/*
Задание 4. Написать программу, которая заменяет все символы точки в строке, введённой 
пользователем, на символы восклицательного знака
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
	ReplaceDot(s);
	cout << s << endl;
	
	return 0;
}