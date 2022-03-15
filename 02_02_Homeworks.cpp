#include "Header.h"

/*
Задание 2. Написать функцию, которая удаляет из строки все вхождения в нее заданного символа.
*/

// встроенные методы
void DelSymbol(string& s, char symbol) {
	while (s.find(symbol) != string::npos)
	{
		s.erase(s.find(symbol), 1);
	}
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	cout << "Введите строку: ";
	string s;// cin >> s;
	getline(cin, s);
	cout << "Введите символ для удаления: ";
	char symbol; cin >> symbol;
	DelSymbol(s, symbol);
	cout << s << endl;

	
	return 0;
}