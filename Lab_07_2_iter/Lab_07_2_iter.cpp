// Lab_7_2_1.cpp
// < Данилюк Максим >
// Лабораторна робота № 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 18

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Change(int** a, const int rowCount, const int colCount);
int IMinEven(int** a, const int rowCount, const int colNo);
int IMaxOdd(int** a, const int rowCount, const int colNo);

int main()
{
	srand((unsigned)time(NULL));

	int Low = 7;
	int High = 65;

	int rowCount;
	int colCount;

	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	
	cout << "Original array" << endl;
	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);

	cout << "Changed array" << endl;
	Change(a, rowCount, colCount);
	Print(a, rowCount, colCount);

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;

	system("pause");
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void Change(int** a, const int rowCount, const int colCount)
{
	int imin, imax, min, max;
	for (int j = 1; j < colCount; j += 2)
	{
		imin = IMinEven(a, rowCount, j);
		min = a[imin][j];
		imax = IMaxOdd(a, rowCount, j - 1);
		max = a[imax][j - 1];

		a[imin][j] = max;
		a[imax][j - 1] = min;
	}
}

int IMinEven(int** a, const int rowCount, const int colNo)
{
	int min = a[0][colNo];
	int imin = 0;
	for (int r = 1; r < rowCount; r++)
	{
		if (a[r][colNo] < min)
		{
			min = a[r][colNo];
			imin = r;
		}
	}
	return imin;
}

int IMaxOdd(int** a, const int rowCount, const int colNo)
{
	int max = a[0][colNo];
	int imax = 0;
	for (int r = 1; r < rowCount; r++)
	{
		if (a[r][colNo] > max)
		{
			max = a[r][colNo];
			imax = r;
		}
	}
	return imax;
}
