#include "Header.h"

/*
Задание 4. Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). Необходимо создать
третий массив минимально возможного размера, в котором нужно собрать общие элементы двух
массивов без повторений.
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

// массив из двух без общих элементов
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

// массив из двух с общими элементами
pair<int*, int> MakeArrWithCommon(int* arr1, int* arr2, int n1, int n2) {
	bool key = false;
	int k = 0;
	int* arr3 = new int[n1 + n2];
	for (int i = 0; i < n1; i++)
	{
		// Сравниваем текущий элемент с элементами второго массива
		for (int j = 0; j < n2; j++)
		{
			// Если такой элемент есть во втором массиве, добавляем его
			if (arr1[i] == arr2[j]) {
				key = true;
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
		key = false;
	}
	int* arr4 = new int[k];
	for (int i = 0; i < k; i++)
	{
		arr4[i] = arr3[i];
	}
	delete[] arr3;
	return { arr4, k };
}


// массив из двух 
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

	auto arr3_with_size = MakeArrWithCommon(arr1, arr2, n1, n2);

	cout << "Массив №3: ";

	ShowArr(arr3_with_size.first, arr3_with_size.second);


	delete[] arr1;
	delete[] arr2;
	delete[] arr3_with_size.first;

	
	return 0;
}

