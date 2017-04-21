#include<iostream>
#include<assert.h>
using namespace std;

 //打印1到最大的n位数
bool Increment(char* num)
{
	bool IsOverflow = false;
	int len = strlen(num) - 1;
	int TakeOver = 0;
	for (size_t i = len; i >= 0; i--)
	{
		int sum = num[i] - '0' + TakeOver;
		if (i == len)
			sum++;
		if (sum >= 10)
		{
			if (i == 0)
				IsOverflow = true;
			else
			{
				sum -= 10;
				TakeOver = 1;
				num[i] = '0' + sum;
			}
		}
		else
		{
			num[i] = '0' + sum;
			break;
		}
	}
	return IsOverflow;
}

void PrintNum(char* num)
{
	bool IsBeginning0 = true;
	int len = strlen(num);
	for (size_t i = 0; i<len; ++i)
	{
		if (IsBeginning0 && num[i] != '0')
			IsBeginning0 = false;
		if (!IsBeginning0)
			cout << num[i];
	}
	cout << " ";
}
void PrintToMaxNum(int n)
{
	assert(n > 0);
	char* num = new char[n + 1];
	memset(num, '0', n);
	num[n] = '\0';

	while (!Increment(num))
	{
		PrintNum(num);
	}
	cout << endl;

	//delete[] num;
}

void TestPrintToMaxNum()
{
	int n = 2;
	PrintToMaxNum(n);
}

int main()
{
	TestPrintToMaxNum();
	system("pause");
	return 0;
}
