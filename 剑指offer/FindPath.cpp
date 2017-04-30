#include<iostream>
#include<vector>
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

void FindPath(Node* root, int expectedSum, vector <int>& path, int& curSum)
{
	curSum += root->_value;
	path.push_back(root->_value);
	//如果是叶子结点并且路径的和等于输入的值，打印路径
	if ((curSum == expectedSum) && (root->_left == NULL && root->_right == NULL))
	{
		cout << " Path is found: ";
		vector <int> ::iterator it = path.begin();
		for (; it != path.end(); ++it)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	//如果不是叶子结点，遍历子节点
	if (root->_left)
		FindPath(root->_left, expectedSum, path, curSum);
	if (root->_right)
		FindPath(root->_right, expectedSum, path, curSum);

	//在返回父节点之前，在路径上删除当前结点，并在curSum中减去当前结点值
	curSum -= root->_value;
	path.pop_back();
}

void FindPath(Node* root, int expectedSum)
{
	if (root == NULL)
		return;
	vector <int> path;
	int curSum = 0;
	FindPath(root, expectedSum, path, curSum);
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
	int a[] = { 10, 5, 4, '#', '#', 7, '#', '#', 12, '#', '#' };
	size_t index = 0;
	Node* root = CreateTree(a, sizeof(a) / sizeof(a[0]), index);
	FindPath(root, 22);
}
int main()
{
	Test();
	system("pause");
	return 0;
}