#include<iostream>
using namespace std;

bool g_invalidInput = false;

//�ж�double���������Ƿ���ȡ�
bool Equal(int num1, int num2)
{
	if ((num1 - num2 > -0.00000000001) 
		&& (num1 - num2 < 0.00000000001))
		return true;
	else 
		return false;
}

//����ֵ��n�η�
double Power(double base, double exponent)
{
	g_invalidInput = false;
	
	//0 û�е���  -->����0��
	if (Equal(base, 0.0) && exponent < 0)
	{
		g_invalidInput = true;
		return 0.0;
	}
	//��ȡn�η�
	unsigned int absExponent = (unsigned int)exponent;
	if (exponent < 0)
	{
		absExponent = (unsigned int)(-exponent);
	}
	//��ʼ����
	double ret = 1.0;
	for (int i = 0; i < absExponent; ++i)
	{
		ret *= base;
	}
	//���exponentΪ����ȡ����
	if (exponent < 0)
		ret = 1.0 / ret;
	return ret;
}

void Test()
{
	cout << Power(0, 0) << endl;//0��0�η�û���壬����1
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