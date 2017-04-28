#include<iostream>
using namespace std;

struct Node
{
	int _value;
	Node* _left;
	Node* _right;

	Node(const int x)
		:_value(x)
		, _left(NULL)
		, _right(NULL)
	{}
};

void MirrorImage(Node* node)
{
	if ((node == NULL) || (node->_left==NULL && node->_right==NULL))
		return;
	Node* tmp = node->_left;
	node->_left = node->_right;
	node->_right = tmp;

	if (node->_left)
		MirrorImage(node->_left);
	if (node->_right)
		MirrorImage(node->_right);
}

Node* CreateTree(int* a, size_t n, size_t& index)
{
	if (index < n && a[index] != '#')
	{
		Node* root = new Node(a[index]);
		root->_left = CreateTree(a, n, ++index);
		root->_right = CreateTree(a, n, ++index);
		return root;
	}
	return NULL;
}

void Test()
{
	int a[] = { 8, 6, 5, '#', '#', 7, '#', '#', 10, 9, '#', '#', 11, '#', '#' };
	size_t index = 0;
	Node* root = CreateTree(a, sizeof(a) / sizeof(a[0]), index);
	MirrorImage(root);
}
int main()
{
	Test();
	system("pause");
	return 0;
}
