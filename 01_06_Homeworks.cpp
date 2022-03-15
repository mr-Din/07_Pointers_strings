#include "Header.h"

/*
Задание 6. Написать функцию, которая получает указатель на динамический массив и его размер.
Функция должна удалить из массива все простые числа и вернуть указатель на новый
динамический массив.
*/


// Одномерный массив
int* ArrOneDim(int size) {
	int* arr = new int[size];
	for (int i = 0; i < size; ++i) {
		//arr[i] = rand() % (100 - (-100)) - 100;
		arr[i] = rand() % 100;
	}
	return arr;
}

void ShowArr(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		/*cout << *arr << " ";
		arr++;*/
		cout << "[" << i << "]=" << arr[i] << " ";
	}
	cout << endl;
}

bool SimpleNumber(int num) {
	if (num < 2) {
		return false;
	}
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int* DelSimple(int* arr, int n1, int& n2) {
	
	int* tmp = new int[n1];
	n2 = 0;
	for (int i = 0; i < n1; i++)
	{
		if (!SimpleNumber(arr[i])) {
			tmp[n2] = arr[i];
			n2++;
		}
	}
	delete[] arr;
	arr = new int[n2];
	for (int i = 0; i < n2; i++)
	{
		arr[i] = tmp[i];
	}
	return arr;

}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	cout << "Введите размер массива 1: ";
	int n1; cin >> n1;
	int* arr1 = ArrOneDim(n1);
	cout << "Массив №1: ";
	ShowArr(arr1, n1);
	int n2 = 0; // новый размер
	cout << "Массив №2: ";

	arr1 = DelSimple(arr1, n1, n2);	
	
	ShowArr(arr1, n2);

	delete[] arr1;


	return 0;
}