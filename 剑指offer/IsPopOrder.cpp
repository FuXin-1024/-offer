#include<iostream>
#include<stack>
using namespace std;

bool IsPopOrder(int* push, int* pop, int len)
{
	if (push && pop && len > 0)
	{
		stack<int> s;
		const int* p1 = push;
		const int* p2 = pop;
		while (p2 - pop < len)//pop序列 没完时
		{
			while (s.empty() || s.top() != *p2) //栈为空或栈顶元素不等于pop序列的值
			{
				if (p1 - push == len) //push序列，全部压栈了
					break;
				s.push(*p1);
				++p1;
			}
			if (*p2 != s.top()) //栈顶元素不等于pop序列值
				break;
			s.pop();
			++p2;
		}
		if (s.empty() && p2 - pop == len)
			return true;
	}
	return false;
}

void IsPopOrderTest()
{
	int a[] = { 1, 2, 3, 4, 5 };
	int a1[] = { 4, 5, 3, 2, 1 };
	int a2[] = { 4, 3, 5, 1, 2 };
	cout << IsPopOrder(a, a1, sizeof(a) / sizeof(a[0])) << endl;
	cout << IsPopOrder(a, a2, sizeof(a) / sizeof(a[0])) << endl;

}
int main()
{
	IsPopOrderTest();
	system("pause");
	return 0;
}