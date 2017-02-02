#include <iostream>

using namespace std;

int main()
{
	const int sizeX = 7;
	const int sizeY = 5;

	int **ary = new int*[sizeY];
	for (int i = 0; i < sizeY; ++i) {
		ary[i] = new int[sizeX];
	}

	for (int i = 0; i < sizeY; i++)
		for (int j = 0; j < sizeX; j++)
			ary[i][j] = i + j;

	for (int i = 0; i < sizeY; ++i) {
		delete[] ary[i];
	}
	delete[] ary;

	system("pause");
	return 0;
}