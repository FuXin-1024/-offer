#include<iostream>
using namespace std;
//������������˫������
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

	//leftָ��ָ����һ�����
	root->_left = *prev;
	//rightָ����һ�����
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

	//�ҵ�����ߵĽ��-->ת���������ͷ���
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