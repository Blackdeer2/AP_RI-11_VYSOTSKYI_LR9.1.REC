#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void Create(int** mas, const int rowCount, const int  colCount, const int A, const int B, int i, int j);
void Print(int** mas, const int rowCount, const int  colCount, int i, int j);

void Change(int** mas, int row1, int row2, int colCount, int tmp, int j);

void Sort(int** mas, int rowCount, int  colCount, int j, int i0, int i1);

void Numbers(int** mas, int rowCount, int colCount, int& num, int i, int j);
void Suma(int** mas, int rowCount, int colCount, int& sum, int i, int j);

void Zamina_0(int** mas, int rowCount, int colCount, int i, int j);

int main()
{
	srand((unsigned)time(NULL));

	int rowCount = 8;
	int colCount = 5;

	int** T = new int* [rowCount];
	for (int i = 0; i < rowCount; i++) {

		T[i] = new int[colCount];
	}

	Create(T, rowCount, colCount, -17, 14, 0, 0);
	cout << "T = { " << endl;
	Print(T, rowCount, colCount, 0, 0);
	cout << "    }" << endl;

	Sort(T, rowCount, colCount, 0, 1, 1);
	cout << " Sort T = { " << endl;
	Print(T, rowCount, colCount, 0, 0);
	cout << "    }" << endl;

	int num = 0;
	Numbers(T, rowCount, colCount, num, 0, 0);
	cout << "Numbers = " << num << endl;

	int sum = 0;
	Suma(T, rowCount, colCount, sum, 0, 0);
	cout << "Suma = " << sum << endl;

	Zamina_0(T, rowCount, colCount, 0, 0);
	cout << " Zamina_0 T = { " << endl;
	Print(T, rowCount, colCount, 0, 0);
	cout << "    }" << endl;


	for (int i = 0; i < rowCount; i++)
		delete[]T[i];
	delete[]T;

	return 0;
}
void Create(int** mas, const int rowCount, const int  colCount, const int A, const int B, int i, int j) {

	mas[i][j] = A + rand() % (B - A + 1);

	if (j < colCount - 1) {
		Create(mas, rowCount, colCount, A, B, i, j + 1);
	}
	else {
		if (i < rowCount - 1) {
			Create(mas, rowCount, colCount, A, B, i + 1, 0);
		}
	}
}
void Print(int** mas, const int rowCount, const int  colCount, int i, int j) {
	cout << setw(4) << mas[i][j];

	if (j < colCount - 1) {
		Print(mas, rowCount, colCount, i, j + 1);
	}
	else {
		if (i < rowCount - 1) {
			cout << endl;
			Print(mas, rowCount, colCount, i + 1, 0);
		}
	}
}

void Change(int** mas, int row1, int row2, int colCount, int tmp, int j) {

	tmp = mas[row1][j];
	mas[row1][j] = mas[row2][j];
	mas[row2][j] = tmp;
	if (j < colCount) {
		Change(mas, row1, row2, colCount, tmp, j + 1);
	}
}

void Sort(int** mas, int rowCount, int  colCount, int j, int i0, int i1) {

	if (mas[i1][0] > mas[i1 + 1][0] ||

		(mas[i1][0] == mas[i1 + 1][0] && mas[i1][1] > mas[i1 + 1][1]) ||

		(mas[i1][0] == mas[i1 + 1][0] && mas[i1][1] == mas[i1 + 1][1] && mas[i1][2] > mas[i1 + 1][2]))
	{
		Change(mas, i1, i1 + 1, colCount, 0, 0);
	}
	if (i1 < rowCount - i0 - 1)
		Sort(mas, rowCount, colCount, j, i0, i1 + 1);
	else
		if (i0 < rowCount - 1)
			Sort(mas, rowCount, colCount, j, i0 + 1, 0);
}

void Numbers(int** mas, int rowCount, int colCount, int& num, int i, int j) {

	if (mas[i][j] < 0 && !(mas[i][j] % 4 == 0)) {
		num++;
	}
	if (j < colCount - 1) {
		Numbers(mas, rowCount, colCount, num, i, j + 1);
	}
	else if (i < rowCount - 1) {
		Numbers(mas, rowCount, colCount, num, i + 1, 0);
	}
}
void Suma(int** mas, int rowCount, int colCount, int& sum, int i, int j) {
	if (mas[i][j] < 0 && !(mas[i][j] % 4 == 0)) {

		sum += mas[i][j];

	}
	if (j < colCount - 1) {
		Suma(mas, rowCount, colCount, sum, i, j + 1);
	}
	else if (i < rowCount - 1) {
		Suma(mas, rowCount, colCount, sum, i + 1, 0);
	}
}

void Zamina_0(int** mas, int rowCount, int colCount, int i, int j) {
	if (mas[i][j] < 0 && !(mas[i][j] % 4 == 0)) {

		mas[i][j] = 0;
	}
	if (j < colCount - 1) {
		Zamina_0(mas, rowCount, colCount, i, j + 1);
	}
	else if (i < rowCount - 1) {
		Zamina_0(mas, rowCount, colCount, i + 1, 0);
	}
}