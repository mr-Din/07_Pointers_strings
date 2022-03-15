#include "Header.h"

/*
Задание 1. Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры).
Необходимо создать третий массив минимально возможного размера, в котором
нужно собрать элементы массива A, которые не включаются в массив B, без повторений.
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
	// Массив размером n1 (максимально возможный размер)
	int* arr3 = new int[n1];
	// Ключ. Если элемент первого массива содержится во втором, то false
	// И этот элемент не добавится в результирующий
	int k = 0;
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
	cout << "Массив №3: ";
	ShowArr(arr3, n1);
	// создаём массив нужного размера
	int* arr4 = new int[k];
	for (int i = 0; i < k; i++)
	{
		arr4[i] = arr3[i];
	}
	cout << "Массив №4: ";
	ShowArr(arr4, k);


	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	
	return 0;
}

