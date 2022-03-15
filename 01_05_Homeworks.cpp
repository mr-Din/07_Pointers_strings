#include "Header.h"

/*
Задание 5. Дан массив: А[M] (M вводится с клавиатуры). Необходимо удалить из массива четные
или нечетные значения. Пользователь вводит данные в массив, а также с помощью меню решает,
что нужно удалить.
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


int* DelNegative(int* arr, int n1, int& n2, bool negative) {
	
	int* tmp = new int[n1];
	n2 = 0;
	for (int i = 0; i < n1; i++)
	{
		if (arr[i] % 2 == 0 && negative) {
			tmp[n2] = arr[i];
			n2++;
		}
		else if (arr[i] % 2 != 0 && !negative) {
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
	int operation;
	do
	{
		cout << "Введите:\n1 - удалить нечётные элементы из массива\n"
			"2 - удалить чётные элементы из массива\n";
		cin >> operation;
		switch (operation)
		{
		case 1:
			arr1 = DelNegative(arr1, n1, n2, true);
			break;
		case 2:
			arr1 = DelNegative(arr1, n1, n2, false);
			break;
		default:
			cout << "Некорректный ввод!\n";
			break;
		}
	} while (operation != 1 && operation != 2);
	
	ShowArr(arr1, n2);

	delete[] arr1;


	return 0;
}