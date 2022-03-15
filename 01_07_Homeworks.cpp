#include "Header.h"

/*
Задание 7. Написать функцию, которая получает указатель на статический массив и его размер.
Функция распределяет положительные, отрицательные и нулевые элементы в отдельные
динамические массивы.
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


tuple <int*, int*, int*> SplitArr(int* arr, int n, int& n1, int& n2, int& n3) {
	
	int* arr_null = new int[n];
	int* arr_positive = new int[n];
	int* arr_negative = new int[n];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0) {
			arr_null[n1] = arr[i];
			n1++;
		}
		else if (arr[i] % 2 == 0) {
			arr_positive[n2] = arr[i];
			n2++;
		}
		else {
			arr_negative[n3] = arr[i];
			n3++;
		}
	}
	return { arr_null, arr_positive, arr_negative };
}

struct ArrPositNegatNull
{
	int* arr_null = nullptr;
	int* arr_positive = nullptr;
	int* arr_negative = nullptr;
	int n1=0;
	int n2=0;
	int n3=0;
};

ArrPositNegatNull SplitArr(int* arr, int n) {
	ArrPositNegatNull arrays;
	arrays.arr_null = new int[n];
	arrays.arr_positive = new int[n];
	arrays.arr_negative = new int[n];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0) {
			arrays.arr_null[arrays.n1] = arr[i];
			arrays.n1++;
		}
		else if (arr[i] % 2 == 0) {
			arrays.arr_positive[arrays.n2] = arr[i];
			arrays.n2++;
		}
		else {
			arrays.arr_negative[arrays.n3] = arr[i];
			arrays.n3++;
		}
	}
	return arrays;
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
	int n; cin >> n;
	int* arr = ArrOneDim(n);
	cout << "Массив №1: ";
	ShowArr(arr, n);
	int n1 = 0; // новый размер
	int n2 = 0;
	int n3 = 0;
	
	// ! Размер результирующих массивов равен n.
	auto arrays = SplitArr(arr, n, n1, n2, n3);
	cout << "Массив с нулями:\n";
	ShowArr(get<0>(arrays), n1);
	cout << "Массив положительный:\n";
	ShowArr(get<1>(arrays), n2);
	cout << "Массив отрицательный:\n";
	ShowArr(get<2>(arrays), n3);
	cout << endl;

	// ! Размер результирующих массивов равен n.
	auto arr_2 = SplitArr(arr, n);
	cout << "Массив с нулями:\n";
	ShowArr(arr_2.arr_null, arr_2.n1);
	cout << "Массив положительный:\n";
	ShowArr(arr_2.arr_positive, arr_2.n2);
	cout << "Массив отрицательный:\n";
	ShowArr(arr_2.arr_negative, arr_2.n3);

	
	return 0;
}