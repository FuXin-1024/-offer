#include<iostream>
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

bool VerifySquenceOfBST(int* arr, int len)
{
	if (arr == NULL || len < 0)
		return false;
	int root = arr[len - 1];//根节点

	//在二叉搜索树中左子树的结点小于根节点
	int i = 0;
	for (; i < len - 1; ++i)
	{
		if (arr[i]>root)
			break;
	}

	//在二叉搜索树中右子树的结点大于根节点
	int j = i;
	for (; j < len - 1; ++j)
	{
		if (arr[j] < root)
			return false;//二叉搜索树的右子树都比根节点的值大
	}

	//判断左子树是不是二叉搜索树
	bool left = true;
	if (i > 0)
		left = VerifySquenceOfBST(arr, i);

	//判断右子树是不是二叉搜索树
	bool right = true;
	if (i < len - 1)
		right = VerifySquenceOfBST(arr + i, len - 1 - i);
	return (left && right);
}

void Test()
{
	int arr1[] = { 5, 7, 6, 9, 11, 10 };
	cout <<"arr1??  "<< VerifySquenceOfBST(arr1, sizeof(arr1) / sizeof(arr1[0])) << endl;
	int arr2[] = { 7, 4, 6, 5 };
	cout << "arr2??  " << VerifySquenceOfBST(arr2, sizeof(arr2) / sizeof(arr2[0])) << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}