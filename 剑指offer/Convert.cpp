#include<iostream>
using namespace std;
//二叉搜索树与双向链表
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

Node* CreateTree(int* a, int n, int& index)
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

void _Convert(Node* root, Node** prev)
{
	if (root == NULL)
		return;
	if (root->_left)
		_Convert(root->_left, prev);

	//left指针指向上一个结点
	root->_left = *prev;
	//right指向下一个结点
	if (*prev != NULL)
		(*prev)->_right = root;
	*prev = root;

	if (root->_right)
		_Convert(root->_right, prev);
}
Node* Convert(Node* root)
{
	if (root == NULL)
		return NULL;

	//找到最左边的结点-->转换后链表的头结点
	Node* head = root;
	while (head->_left)
	{
		head = head->_left;
	}
	Node* prev = NULL;
	_Convert(root, &prev);
	return head;
}

void Test()
{
	int a[] = { 10, 6, 4, '#', '#', 8,'#', '#', 14, 12, '#', '#', 16, '#', '#' };
	int index = 0;
	Node* root = CreateTree(a, sizeof(a) / sizeof(a[0]), index);
	Convert(root);
}
int main()
{
	Test();
	system("pause");
	return 0;
}