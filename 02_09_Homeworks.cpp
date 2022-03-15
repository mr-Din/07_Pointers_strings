#include "Header.h"


/*
Задание 9. Подсчитать количество слов во введенном предложении.
*/

void ReplaceSpace(string& s) {
	while (s.find(" ") != string::npos)
	{
		s.replace(s.find(" "), 1, "\t");
	}
}

int GetCountWords(string& s) {
	int c = 0;
	bool is_space = true;
	for (const char symbol : s) {
		if (symbol == ' ' && !is_space) {
			c++;
			is_space = true;
		}
		else if (symbol != ' ') {
			is_space = false;
		}
	}
	if (!is_space) {
		c++;
	}
	return c;
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	cout << "Введите строку: ";
	string s;
	getline(cin, s);
	int count = GetCountWords(s);
	cout << "Количество слов в строке: " << count << endl;

	return 0;
}