#include <iostream>
#include <cstdlib>
using namespace std;
const int N = 10;  // константа N, она определяет количество элементов в массиве.
int main()
{
	int mass[N], max;

	cout << "Elements: ";
	for (int r = 0; r < N; r++)  // заполним массив случайными числами.
	{
		mass[r] = rand() % 99;  // случайное значение от 0 до 98.
		cout << mass[r] << " ";
	}
	cout << endl;

	max = mass[0];
	for (int r = 1; r < N; r++)
	{
		if (max < mass[r]) max = mass[r];
	}
	cout << "Max: " << max << endl;

	return 0;
}