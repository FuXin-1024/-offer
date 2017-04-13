#include<iostream>
using namespace std;

//负数会引发死循环
int Count1(int n)
{
	int count = 0;
	while (n)
	{
		if (n & 1)
		{
			count++;
		}
		n = n >> 1;
	}
	return count;
}
//可能循环32次
int Count_1(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n  & flag)
			count++;
		flag = flag << 1;
	}
	return count;
}

int _Count_1(int n)
{
	int count = 0;
	while (n)
	{
		++count;
		n = n & (n - 1);
	}
	return count;
}
void Test()
{
	int n = 9;
	//cout << "1的个数：" << Count1(n) << endl;
	cout << "1的个数：" << Count_1(13) << endl;
	cout << "1的个数：" << _Count_1(13) << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}