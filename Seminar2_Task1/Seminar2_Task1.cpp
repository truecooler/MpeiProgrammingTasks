// Seminar2_Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>

using namespace std;

int** CreateMatrix(int matrixHeigth, int matrixWeigth)
{
	int** matrix = new int* [matrixHeigth];

	for (int i = 0; i < matrixHeigth; i++)
	{
		matrix[i] = new int[matrixWeigth];
	}

	return matrix;
}

void PrintMatrix(int** matrix, int matrixHeigth, int matrixWeigth)
{
	for (int i = 0; i < matrixHeigth; i++)
	{
		for (int j = 0; j < matrixWeigth; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

void FillMatrix(int** matrix, int matrixHeigth, int matrixWeigth)
{
	for (int i = 0; i < matrixHeigth; i++)
	{
		for (int j = 0; j < matrixWeigth; j++)
		{
			matrix[i][j] = rand() % 20 - 10;
		}
	}
}

bool CalcRowSum(int** matrix, int matrixHeigth, int matrixWeigth, int conditional, int* rowSumOut)
{
	bool isRowExists = false;
	for (int i = 0; i < matrixHeigth; i++)
	{
		for (int j = 0; j < matrixWeigth; j++)
		{
			if (matrix[i][0] > conditional)
			{
				*rowSumOut += matrix[i][j];
				isRowExists = true;
			}
		}
	}
	return isRowExists;
}


int main()
{
	const int FirstMatrixConditional = 0;
	const int SecondMatrixConditional = 1;

	int firstMatrixHeight = 7;
	int firstMatrixWight = 3;
	int** firstMatrix = NULL;
	int firstSum = 0;

	int secondMatrixHeight = 6;
	int secondMatrixWight = 4;
	int** secondMatrix = NULL;
	int secondSum = 0;

	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	firstMatrix = CreateMatrix(firstMatrixHeight, firstMatrixWight);
	FillMatrix(firstMatrix, firstMatrixHeight, firstMatrixWight);

	secondMatrix = CreateMatrix(secondMatrixHeight, secondMatrixWight);
	FillMatrix(secondMatrix, secondMatrixHeight, secondMatrixWight);

	cout << "Первая сгенерированная матрица: " << endl;
	PrintMatrix(firstMatrix, firstMatrixHeight, firstMatrixWight);

	if (!CalcRowSum(firstMatrix, firstMatrixHeight, firstMatrixWight, FirstMatrixConditional, &firstSum))
	{
		cout << "В сгенерированной матрице нет строк, начинающихся с нулевого элемента. Сгенерируйте матрицу заного." << endl;
	}
	else
	{
		cout << "Сумма элементов строк первой матрицы, первые элементы строк которой являются положительными: " << firstSum << endl;
	}

	cout << "Вторая сгенерированная матрица: " << endl;
	PrintMatrix(secondMatrix, secondMatrixHeight, secondMatrixWight);

	if (!CalcRowSum(secondMatrix, secondMatrixHeight, secondMatrixWight, SecondMatrixConditional, &secondSum))
	{
		cout << "В сгенерированной матрице нет строк, начинающихся с положительного элемента. Сгенерируйте матрицу заного." << endl;
	}
	else
	{
		cout << "Сумма элементов строк второй матрицы, первые элементы строк которой больше единицы: " << secondSum << endl;
	}

	cin;
}


