// Seminar1_Task3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <time.h>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(NULL));
	int** matrix = NULL;
	int matrixHeight = 0;
	int matrixWight = 0;
	int firstPositiveItemMaxtrixRowIndex = -1;
	int rowSum = 0;

	cout << "Введите высоту матрицы: " << endl;
	cin >> matrixHeight;

	cout << "Введите ширину матрицы: " << endl;
	cin >> matrixWight;
	matrix = new int*[matrixHeight];

	cout << "Сгенерированная матрица: " << endl;

	for (int i = 0; i < matrixHeight; i++)
	{
		matrix[i] = new int[matrixWight];
		for (int j = 0; j < matrixWight; j++)
		{
			matrix[i][j] = rand() % 20 - 10;
			cout << matrix[i][j] << "\t";
		}
		if (firstPositiveItemMaxtrixRowIndex == -1 && matrix[i][0] > 0)
		{
			firstPositiveItemMaxtrixRowIndex = i;
		}
		cout << endl;
	}

	if (firstPositiveItemMaxtrixRowIndex == -1)
	{
		cout << "В сгенерированной матрице нет строк с первым положительным элементом." << endl;
		return 0;
	}

	cout << "Индекс строки с первым положительным элементом: " << firstPositiveItemMaxtrixRowIndex << endl;

	for (int i = 0; i < matrixWight; i++)
	{
		rowSum += matrix[firstPositiveItemMaxtrixRowIndex][i];
	}

	cout << "Сумма элементов этой строки: " << rowSum << endl;

	cin;
}


