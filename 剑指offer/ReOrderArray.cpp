#include<iostream>
using namespace std;
//利用两个分别指向头尾的指针，first指针指向数组第一个元素，end 指针指向数组的最后一个元素
// 移动指针，当first指针遇到偶数，end指针指向奇数，交换。继续移动，交换直到end 在first前面

void ReOrderArray(int* arr, int len)
{
	if (arr == NULL || len <= 0)
		return;
	int* first = &arr[0];
	int* end = &arr[len - 1];

	while (first < end)
	{
		while (first < end && *first % 2 != 0)//移动，直到遇到偶数
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