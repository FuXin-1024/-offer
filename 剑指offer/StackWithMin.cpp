#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

template <class T>
class StackWithMin
{
public:
	void push(const T& x)
	{
		s.push(x);
		if (min.size() == 0 || x <= min.top()) //辅助栈插入的是，当前数据栈的最小值
			min.push(x);
		else
			min.push(min.top());
	}

	void pop()
	{
		assert(s.size() > 0 && min.size() > 0);
		s.pop();
		min.pop();
	}

	const T& Min()
	{
		assert(s.size() > 0 && min.size() > 0);
		return min.top();
	}

protected:
	stack<T> s;//数据栈
	stack<T> min;//辅助栈->存放最小值
};

void StackWithMinTest()
{
	StackWithMin<int> s;
	s.push(3);
	s.push(7);
	cout <<"Min: "<< s.Min() << endl;

	s.push(1);
	cout << "Min: " << s.Min() << endl;
	s.pop();
	s.push(9);
	cout << "Min: " << s.Min() << endl;
	s.push(5);
	cout << "Min: " << s.Min() << endl;
}
int main()
{
	StackWithMinTest();
	system("pause");
	return 0;
}