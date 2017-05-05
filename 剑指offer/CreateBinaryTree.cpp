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
	if (firstPrev == endPrev)//ǰ�����ֻ��һ���ڵ�
	{
		if ((firstIn==endIn) && (*firstIn = *endIn))//�������ֻ��һ���ڵ�
			return root;//ֻ�и��ڵ�
		else
			assert(false);
	}
	//�������������������--->ǰ�������Ԫ�ص����
	int* rootInOrder = firstPrev;
	if (rootInOrder <= endIn && *rootInOrder != *firstPrev)
		++rootInOrder;
	if (rootInOrder == endIn && *rootInOrder != *firstPrev)
		assert(false);//��������

	int leftLength = rootInOrder - firstIn;//����������
	int* leftEnd = firstPrev + leftLength;//��������β

	//������������
	if (leftLength > 0)
		root->_left = Create(firstPrev+1, leftEnd,firstIn,rootInOrder-1);
	if (leftLength < endPrev - firstPrev)
		root->_right = Create(leftEnd + 1, endPrev, rootInOrder + 1, endIn);
	return root;
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