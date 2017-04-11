//思路：
//队先进先出，要想实现栈的后进先出，插入时，要插在不为空的队列里，保持一个队列为空
//删除时，要把队列不为空的队列 除最后一个元素放到另一个为空的队列中，然后pop出最后一个元素
#include<iostream>
using namespace std;
#include<queue>
#include<assert.h>

template<class T>
class Stack
{
public:
	void Push(const T& x)
	{
		if (!q1.empty())
			q1.push(x);
		else
			q2.push(x);
	}
	void Pop()
	{
		//栈没元素时，删除报错
		assert(q1.size() || q2.size());
		if (q1.empty())
		{
			int size = q2.size();
			while (size > 1)
			{
				q1.push(q2.front());
				q2.pop();
				--size;
			}
			q2.pop();
		}
		else
		{
			int size = q1.size();
			while (size > 1)
			{
				q2.push(q1.front());
				q1.pop();
				--size;
			}
			q1.pop();
		}
			
	}
private:
	queue <T> q1;
	queue <T> q2;
};

void TestStack()
{
	Stack <int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	s.Push(5);
	s.Pop();
	s.Pop();
	s.Pop();
	s.Pop();
	s.Pop();
	//s.Pop();
}
int main()
{
	TestStack();
	system("pause");
	return 0;
}