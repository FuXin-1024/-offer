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

bool DoesTree1HaveTree2(Node* root1, Node* root2)
{
	if (root2 == NULL)
		return true;
	if (root1 == NULL)
		return false;

	if (root1->_value != root2->_value)
		return false;

	return DoesTree1HaveTree2(root1->_left, root2->_left) &&
		DoesTree1HaveTree2(root1->_right, root2->_right);
}

bool HasSubtree(Node* root1, Node* root2)
{
	bool result = false;
	if (root1 != NULL && root2 != NULL)
	{
		if (root1->_value==root2->_value)
			result = DoesTree1HaveTree2(root1, root2);
		if (!result)
			HasSubtree(root1->_left, root2);
		if (!result)
			HasSubtree(root1->_right, root2);
	}
	return result;
}
int main()
{

	system("pause");
	return 0;
}