#include "Header.h"

/*
Задание 1. Написать функцию, которая удаляет из строки символ с заданным номером.
*/





int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	cout << "Введите строку: ";
	string s;// cin >> s;
	getline(cin, s);
	cout << "Введите индекс символа в строке для удаления: ";
	int pos; cin >> pos;
	if (pos > s.size()-1) {
		cout << "Индекс выходит за границы строки!\n";
	}
	else{
		s.erase(s.begin() + pos);
		cout << "Результирующая строка:\n" << s << endl;
	}
	

	
	return 0;
}