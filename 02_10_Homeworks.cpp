#include "Header.h"


/*
Задание 10. Дана строка символов. Необходимо проверить является ли эта строка палиндромом.
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

bool IsPalindrome(string& s) {
	for (int i = 0; i < s.size()/2; i++)
	{
		if (s[i] != s[s.size() - 1 - i]) {
			return false;
		}
	}
	return true;
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	cout << "Введите строку: ";
	string s;
	getline(cin, s);
	/*int count = GetCountWords(s);
	cout << "Количество слов в строке: " << count << endl;*/
	if (IsPalindrome(s)) {
		cout << "Строка: " << s << " палиндром!\n";
	}
	else {
		cout << "Строка: " << s << " не палиндром!\n";
	}
	

	return 0;
}