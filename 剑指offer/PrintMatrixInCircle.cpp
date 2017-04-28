#include<iostream>
using namespace std;

void PrintMatrixInCircle(int arr[][4], int rows, int cols, int start)
{
	int endX = cols - 1 - start;
	int endY = rows - 1 - start;

	//从左到右打印一行
	for (int i = start; i <= endX; ++i)
	{
		cout << arr[start][i] << " ";
	}

	//从上到下打印一列
	if (start < endY)//终止行号 > 起始行号(只有一行就不用打印)
	{
		for (int i = start + 1; i <= endY; ++i)
		{
			cout << arr[i][endX] << " ";
		}
	}

	//从右到左打印一行
	if (start < endX && start < endY)//至少有两行两列
	{
		for (int i = endX - 1; i >= start; --i)
		{
			cout << arr[endY][i] << " ";
		}
	}

	//从下到上打印一列
	if (start < endX && start < endY - 1)//至少三行两列
	{
		for (int i = endY - 1; i >= start + 1; --i)
		{
			cout << arr[i][start] << " ";
		}
	}
}

void PrintMatrix(int arr[][4], int rows,int cols)
{
	if (arr == NULL || rows < 0 || cols < 0)
		return;
	int start = 0;
	while (rows>start * 2 && cols>start * 2)
	{
		PrintMatrixInCircle(arr, rows, cols, start);
		++start;
	}
	cout << endl;
}

void TestPrint()
 {
	int a[][4] = 
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16} };
	
		PrintMatrix(a, 4, 4);
	}
int main()
{
	TestPrint();
	system("pause");
	return 0;
}