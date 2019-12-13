// Seminar1_Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	const int YearsLimit = 20;
	const int RequiredSickPeopleCountFactor = 2;

	int sickPeopleCount = 0,
		recoveredPeoplePercentYearly = 0,
		recoveredPeopleCountYearly = 0,
		sickPeopleCountBuffer = 0,
		requiredSickPeopleCount = 0,
		yearsElapsed = 0;

	cout << "Введите количество больных людей A: " << endl;
	cin >> sickPeopleCount;

	cout << "Введите ежегодный процент снижения больных людей p: " << endl;
	cin >> recoveredPeoplePercentYearly;

	cout << "Введите ежегодное снижение количества больных людей Q: " << endl;
	cin >> recoveredPeopleCountYearly;

	requiredSickPeopleCount = sickPeopleCount / RequiredSickPeopleCountFactor;
	sickPeopleCountBuffer = sickPeopleCount;

	while (sickPeopleCountBuffer > requiredSickPeopleCount)
	{
		yearsElapsed++;
		sickPeopleCountBuffer = sickPeopleCountBuffer - (sickPeopleCountBuffer / 100) * recoveredPeoplePercentYearly;
		sickPeopleCountBuffer -= recoveredPeopleCountYearly;
	}

	if (yearsElapsed > YearsLimit)
	{
		cout << "Число больных уменьшится в 2 раза более чем через " << YearsLimit << " лет. (через " << yearsElapsed << " лет.)"<< endl;
		return 0;
	}

	cout << "Число больных уменьшится в 2 раза через " << yearsElapsed << " лет." << endl;
	cin;
}

