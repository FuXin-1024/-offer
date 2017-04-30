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
	//�����Ҷ�ӽ�㲢��·���ĺ͵��������ֵ����ӡ·��
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
	//�������Ҷ�ӽ�㣬�����ӽڵ�
	if (root->_left)
		FindPath(root->_left, expectedSum, path, curSum);
	if (root->_right)
		FindPath(root->_right, expectedSum, path, curSum);

	//�ڷ��ظ��ڵ�֮ǰ����·����ɾ����ǰ��㣬����curSum�м�ȥ��ǰ���ֵ
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