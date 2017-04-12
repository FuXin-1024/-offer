#include<iostream>
using namespace std;

//0,1,1,2,3,5,8,13
//·ÇµÝ¹é
long long Fib(long long n)
{
	if (n <= 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;
	long long x1 = 1;
	long long x2 = 1;
	long long sum = 0;
	for (long long i = 3; i <= n; ++i)
	{
		sum = x1 + x2;
		x1 = x2;
		x2 = sum;
	}
	return sum;
}
//µÝ¹é
long long FibR(long long n)
{
	if (n <= 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;
	return FibR(n - 1) + FibR(n - 2);
}

void TestFib()
{
	for (size_t i = 0; i <= 10; ++i)
	{
		cout << Fib(i) << endl;
	}
	
}
void TestFibR()
{
	for (size_t i = 0; i <= 10; ++i)
	{
		cout << Fib(i) << endl;
	}

}
int main()
{
	TestFib();
	cout << "************" << endl;
	TestFibR();
	system("pause");
	return 0;
}