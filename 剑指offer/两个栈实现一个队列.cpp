#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;
template<class T>
class Queue
{
public:
	void Push(const T& x)
	{
		s1.push(x);
	}
	void Pop()
	{
		if (s2.empty())
		{
			if (s1.empty())//队列为空
			{
				assert(false);
			}
			else
			{
				//把S1的数据导入s2；
				while (!s1.empty())
				{
					s2.push(s1.top());
					s1.pop();
				}
			}
			s2.pop();
		}
	}

	
protected:
	stack<T> s1;
	stack<T> s2;
};

void Test()
{
	Queue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);

	q.Pop();
}
int main()
{
	Test();
	system("pause");
	return 0;
}