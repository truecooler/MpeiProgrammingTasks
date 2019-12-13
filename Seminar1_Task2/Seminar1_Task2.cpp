// Seminar1_Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int* vector = NULL;
	int vectorSize = 0;
	int zerosCount = 0;

	cout << "Введите размер одномерного массива: " << endl;
	cin >> vectorSize;
	vector = new int[vectorSize];
	
	cout << "Вводите элементы массива: " << endl;
	for (int i = 0; i < vectorSize; i++)
	{
		cin >> vector[i];
	}

	for (int i = 0; i < vectorSize; i++)
	{
		if (vector[i] == 0)
		{
			zerosCount++;
		}

		if (vector[i] < 0)
		{
			vector[i] = abs(vector[i]);
		}
	}

	cout << "Количество нулевых элементов: " << zerosCount << endl;
	cout << "Состояние массива после замены отрицательных значений абсолютными:" << endl;
	for (int i = 0; i < vectorSize; i++)
	{
		cout << vector[i] << " ";
	}
	cout << endl;
	cin;
}

