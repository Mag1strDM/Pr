//Вариант 14
//1 Найти сумму чисел на нечетных строках. +
//2. Найти сумму чисел, расположенных между первым и последним
//отрицательными числами. +
//3. Сжать файл, удалив из него все числа, модуль которого не превышает 10. Освободившиеся строки заполнить нулями. +

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>
#include "windows.h"
#include <math.h>

using namespace std;


vector<int> Arr() {
	vector <int> numbers;
	ifstream in("variant14.txt");
	int number;
	while (in >> number) {
		numbers.push_back(number);
	}
	in.close();
	return numbers;
}

void суммаНечетныхСтрок(vector<int>& numbers) {
	int sum = 0;
	for (int i = 0; i < numbers.size(); i += 2) {
		sum += numbers[i];
	}
	cout << "Сумма чисел на нечетных строках: " << sum << endl;
}


void суммаМежду(vector<int>& numbers) {
	int sum = 0;
	int first = -1;
	int last = -1;
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] < 0) {
			first = i;
			break;
		}
	}

	for (int j = numbers.size() - 1; j >= 0; j--) {
		if (numbers[j] < 0) {
			last = j;
			break;
		}
	}

	for (int k = first + 1; k < last; k++) {
		sum += numbers[k];
	}

	cout << "Сумма чисел между первым и последним отрицательными числами: " << sum << endl;
}

void сжатьФайл(vector<int>& numbers) {
	ofstream out("output__nums.txt");
	for (int i = 0; i < numbers.size(); i++) {
		if (fabs(numbers[i]) < 10) {
			numbers[i] = 0;
		}
		out << numbers[i] << endl;
	}
}


int main() {
	system("color F2");
	setlocale(LC_ALL, "Russian");
	vector<int> numbers = Arr();
	суммаНечетныхСтрок(numbers);
	суммаМежду(numbers);
	сжатьФайл(numbers);
}