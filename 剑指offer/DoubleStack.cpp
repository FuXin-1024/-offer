#include<iostream>
using namespace std;

template<class T>
class DoubleStack
{
public:
	DoubleStack()
		:_a(NULL)
		, _top1(0)
		, _top2(0)
		, _capacity(0)
	{
		_CheckCapacity();
	}

protected:
	void _CheckCapacity()
	{
		if (_a == NULL)
		{
			_capacity += 3;
			_a = new T[_capacity];
			_top2 = _capacity - 1;
			return;
		}
		if (top1 == top2)
		{
			size_t oldCapacity = _capacity;
			_capacity *= 2;
			T* tmp = new T[_capacity];

			for (size_t i = 0; i < _top1; ++i)
			{
				tmp[i] = _a[i];
			}

			for (size_t j = oldCapacity - 1, i = _capacity - 1; j>_top2; j--, i--)
			{
				tmp[i] = _a[j];
			}
		}
	}
protected:
	T* _a;
	size_t _top1;
	size_t _top2;
	size_t _capacity;
};
int main()
{
	system("pause");
	return 0;
}