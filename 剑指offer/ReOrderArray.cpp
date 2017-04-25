#include<iostream>
using namespace std;
//���������ֱ�ָ��ͷβ��ָ�룬firstָ��ָ�������һ��Ԫ�أ�end ָ��ָ����������һ��Ԫ��
// �ƶ�ָ�룬��firstָ������ż����endָ��ָ�������������������ƶ�������ֱ��end ��firstǰ��

void ReOrderArray(int* arr, int len)
{
	if (arr == NULL || len <= 0)
		return;
	int* first = &arr[0];
	int* end = &arr[len - 1];

	while (first < end)
	{
		while (first < end && *first % 2 != 0)//�ƶ���ֱ������ż��
		{
			first++;
		}
		while (first < end && *end % 2 == 0)
		{
			end--;
		}
		swap(*first, *end);
	}
}

void Test()
{
	int arr[] = { 1, 2, 3,4 ,3,4, 5, 6, 7, 8, 9 };
	ReOrderArray(arr, sizeof(arr) / sizeof(arr[0]));

	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}