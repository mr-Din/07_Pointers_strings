#include "Header.h"


/*
Задание 6. Пользователь вводит строку. Определить количество букв, количество цифр и
количество остальных символов, присутствующих в строке.
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
	int letters = 0;
	int digits = 0;
	int symbols = 0;
	for (const char symb : s) {
		if (symb > 47 && symb < 58) {
			digits++;
		}
		else if ((symb > 64 && symb < 91) || (symb > 96 && symb < 123)) {
			letters++;
		}
		else {
			symbols++;
		}

	}
	cout << "Количество цифр: " << digits << endl;
	cout << "Количество букв (англ.): " << letters << endl;
	cout << "Количество других символов: " << symbols << endl;
	
	/*cout << static_cast<int>('a') << endl << static_cast<int>('z') << endl;
	cout << static_cast<int>('A') << endl << static_cast<int>('Z') << endl;
	for (int i = 65; i < 200; i++)
	{
		cout << i << "\t" << static_cast<char>(i) << endl;
	}*/
	return 0;
}