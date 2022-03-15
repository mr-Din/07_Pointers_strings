#include "Header.h"


/*
Задание 3. Написать функцию, которая вставляет в строку в указанную позицию заданный символ.
*/



void AppendSymbol(char* s, char symbol, int pos) {
	
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	cout << "Введите строку: ";
	string s; 
	getline(cin, s);
	cout << "Введите позицию: ";
	int p; cin >> p;
	cout << "Введите символ (несколько символов): ";
	string s_ins;
	//getline(cin, s_append);
	cin >> s_ins;
	s.insert(p, s_ins);
	cout << s << endl;

	
	return 0;
}