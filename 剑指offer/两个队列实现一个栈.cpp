//˼·��
//���Ƚ��ȳ���Ҫ��ʵ��ջ�ĺ���ȳ�������ʱ��Ҫ���ڲ�Ϊ�յĶ��������һ������Ϊ��
//ɾ��ʱ��Ҫ�Ѷ��в�Ϊ�յĶ��� �����һ��Ԫ�طŵ���һ��Ϊ�յĶ����У�Ȼ��pop�����һ��Ԫ��
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
		//ջûԪ��ʱ��ɾ������
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