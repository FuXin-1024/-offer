#include<iostream>
#include<assert.h>
using namespace std;

struct Node
{
	int _value;
	Node* _left;
	Node* _right;

	Node(const int& x)
		:_value(x)
		, _left(NULL)
		, _right(NULL)
	{}
};

Node* Create(int* firstPrev, int* endPrev, int* firstIn, int* endIn)
{
	//���ڵ�-->ǰ������ĵ�һ��Ԫ��
	Node* root = new Node(*firstPrev);

}
Node* CreateBinaryTree(int* PrevOrder, int* InOrder,int n)
{
	assert(PrevOrder);
	assert(InOrder);
	assert(n);
	return Create(PrevOrder,PrevOrder+n-1,InOrder,InOrder+n-1);
}
int main()
{
	system("pause");
	return 0;
}