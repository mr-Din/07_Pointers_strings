#include "Header.h"

/*
Задание 3. Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). Необходимо
создать третий массив минимально возможного размера, в котором нужно собрать
элементы обоих массивов.
*/


// Одномерный массив
int* ArrOneDim(int size) {
	int* arr = new int[size];
	for (int i = 0; i < size; ++i) {
		//arr[i] = rand() % (100 - (-100)) - 100;
		arr[i] = rand() % 10;
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

void MakeArr(int* arr1, int* arr2, int* arr3, int n1, int n2, int& k) {
	bool key = true;
	for (int i = 0; i < n1; i++)
	{
		// Сравниваем текущий элемент с элементами второго массива
		for (int j = 0; j < n2; j++)
		{
			if (arr1[i] == arr2[j]) {
				key = false;
				break;
			}
		}
		// Сравниваем текущий элемент с элементами в новом массиве
		for (int j = 0; j < k; j++)
		{
			if (arr1[i] == arr3[j]) {
				key = false;
				break;
			}
		}

		// Если элемент не найден во втором массиве и в новом
		if (key) {
			arr3[k] = arr1[i];
			k++;	// текущая позиция в новом массиве увеличивается на 1
		}
		key = true;
	}
}

int* MakeArr(int* arr1, int* arr2, int n1, int n2) {
	int* arr3 = new int[n1 + n2];

	for (int i = 0; i < n1; i++)
	{
		arr3[i] = arr1[i];
	}
	for (int i = 0; i < n2; i++)
	{
		arr3[n1 + i] = arr2[i];
	}
	return arr3;
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	cout << "Введите размер массива 1: ";
	int n1; cin >> n1;
	cout << "Введите размер массива 2: ";
	int n2; cin >> n2;
	int* arr1 = ArrOneDim(n1);
	int* arr2 = ArrOneDim(n2);
	cout << "Массив №1: ";
	ShowArr(arr1, n1);
	cout << "Массив №2: ";
	ShowArr(arr2, n2);

	int* arr3 = MakeArr(arr1, arr2, n1, n2);

	cout << "Массив №3: ";

	ShowArr(arr3, n1+n2);


	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	
	return 0;
}

