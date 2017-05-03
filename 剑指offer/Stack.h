#pragma once
#include<iostream>
#include<queue>
#include<assert.h>
using namespace std;

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
		assert(q1.size() || q2.size());
		//队1为空时，把队2出最后一个元素倒入队1
		if (q1.empty())
		{
			while (q2.size() > 1)
			{
				q1.push(q2.front());
				q2.pop();
			}
			q2.pop();
		}
		else
		{
			while (q1.size() > 1)
			{
				q2.push(q1.front());
				q1.pop();
			}
			q1.pop();
		}
	}
protected:
	queue<T> q1;
	queue<T> q2;
};

void StackTest()
{
	Stack<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Pop();

	s.Push(4);
	s.Push(5);
	s.Pop();
	s.Pop();

}