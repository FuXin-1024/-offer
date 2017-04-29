#include<iostream>
#include<queue>
using namespace std;

//²ãÐò±éÀú¶þ²æÊ÷
struct Node
{
	int _value;
	Node* _left;
	Node* _right;

	Node(const int x)
		:_value(x)
		, _left(NULL)
		,_right(NULL)
	{}
};

void PrintFromTopToBottom(Node* root)
{
	if (root == NULL)
		return;
	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		Node* front = q.front();
		cout << front->_value << " ";
		q.pop();
		if (front->_left)
			q.push(front->_left);
		if (front->_right)
			q.push(front->_right);
	}
	cout << endl;
}
int main()
{
	system("pause");
	return 0;
}