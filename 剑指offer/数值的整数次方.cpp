#include<iostream>
using namespace std;

bool g_invalidInput = false;

//判断double类型数据是否相等。
bool Equal(int num1, int num2)
{
	if ((num1 - num2 > -0.00000000001) 
		&& (num1 - num2 < 0.00000000001))
		return true;
	else 
		return false;
}

//求数值的n次方
double Power(double base, double exponent)
{
	g_invalidInput = false;
	
	//0 没有倒数  -->返回0；
	if (Equal(base, 0.0) && exponent < 0)
	{
		g_invalidInput = true;
		return 0.0;
	}
	//获取n次方
	unsigned int absExponent = (unsigned int)exponent;
	if (exponent < 0)
	{
		absExponent = (unsigned int)(-exponent);
	}
	//开始计算
	double ret = 1.0;
	for (int i = 0; i < absExponent; ++i)
	{
		ret *= base;
	}
	//如果exponent为负，取倒数
	if (exponent < 0)
		ret = 1.0 / ret;
	return ret;
}

void Test()
{
	cout << Power(0, 0) << endl;//0的0次方没意义，返回1
	cout << Power(0, -1) << endl;//0
	cout << Power(0, 2) << endl;//0
	cout << Power(2, 0) << endl;//1
	cout << Power(2, 2) << endl;//4
	cout << Power(2, -1) << endl;//0.5
	cout << Power(2, 5) << endl;//32
	cout << Power(-1, 0) << endl;//1
	cout << Power(-2, -1) << endl;//-0.5
	cout << Power(-2, 5) << endl;//-32
}
int main()
{
	Test();
	system("pause");
	return 0;
}