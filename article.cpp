#include <iostream>
#include <iomanip>
#include <vector>
#include "header.h"
#include <chrono>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	int size, num;
	char x;
	cout << "Введите размер массива: ";
	cin >> size;
	int* array = new int[size];
	for (int i = 0; i < size; i++) {
		array[i] = -1000 + rand() % 2000;
	}
	cout << "Вывести массив? Y/N -> ";
	cin >> x;
	if (x == 'Y') {
		for (int i = 0; i < size; i++) {
			cout << setw(6) << array[i];
		}
		cout << endl;
	}
	cout << "Какой метод сортировки использовать? (1 - BubbleSort, 2 - BucketSort): ";
	cin >> num;
	switch (num) {
	case 1: {
		auto start = std::chrono::high_resolution_clock::now();
		BubbleSort(array, size);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;
		cout << "Время выполнения: " << duration.count() << " сек.\n";
		break;
	}
	case 2: {
		auto start = std::chrono::high_resolution_clock::now();
		BucketSort(array, size);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;
		cout << "Время выполнения: " << duration.count() << " сек.\n";
		break;
	}
	}
	cout << "Вывести отсортированный массив? Y/N -> ";
	cin >> x;
	if (x == 'Y') {
		for (int i = 0; i < size; i++) {
			cout << setw(6) << array[i];
		}
	}
	delete[] array;
}

