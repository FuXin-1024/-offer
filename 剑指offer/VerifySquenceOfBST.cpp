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
	int root = arr[len - 1];//���ڵ�

	//�ڶ������������������Ľ��С�ڸ��ڵ�
	int i = 0;
	for (; i < len - 1; ++i)
	{
		if (arr[i]>root)
			break;
	}

	//�ڶ������������������Ľ����ڸ��ڵ�
	int j = i;
	for (; j < len - 1; ++j)
	{
		if (arr[j] < root)
			return false;//���������������������ȸ��ڵ��ֵ��
	}

	//�ж��������ǲ��Ƕ���������
	bool left = true;
	if (i > 0)
		left = VerifySquenceOfBST(arr, i);

	//�ж��������ǲ��Ƕ���������
	bool right = true;
	if (i < len - 1)
		right = VerifySquenceOfBST(arr + i, len - 1 - i);
	return (left && right);
}
int main()
{
	system("pause");
	return 0;
}