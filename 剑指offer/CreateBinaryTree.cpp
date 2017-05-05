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
	//根节点-->前序遍历的第一个元素
	Node* root = new Node(*firstPrev);
	if (firstPrev == endPrev)//前序遍历只有一个节点
	{
		if ((firstIn==endIn) && (*firstIn = *endIn))//中序遍历只有一个节点
			return root;//只有根节点
		else
			assert(false);
	}
	//在中序遍历中找左子树--->前序遍历首元素的左边
	int* rootInOrder = firstPrev;
	if (rootInOrder <= endIn && *rootInOrder != *firstPrev)
		++rootInOrder;
	if (rootInOrder == endIn && *rootInOrder != *firstPrev)
		assert(false);//参数有误

	int leftLength = rootInOrder - firstIn;//左子树长度
	int* leftEnd = firstPrev + leftLength;//左子树树尾

	//构建左右子树
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