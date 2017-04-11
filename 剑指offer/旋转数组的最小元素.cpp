#include<iostream>

using namespace std;
#include<assert.h>
int MinInorder(int* arr, int first, int end);
int Min(int* arr, int len)
{
	assert(arr);
	assert(len > 0);
	int first = 0;
	int end = len - 1;
	int mid = first;//第一个元素就是最小值，直接返回
	while (arr[first] >= arr[end])
	{
		if (end - first == 1)
		{
			mid = end;
			break;
		}
		mid = (first + end) / 2;
		// 如果 下标first ,end,mid 的值相同
		if (arr[first] == arr[end] && arr[first] == arr[mid])
			return MinInorder(arr, first, end);
		if (arr[mid] >= arr[first])
			first = mid;
		else if (arr[mid] <= arr[end])
			end = mid;
	}
	return arr[mid];
}
int MinInorder(int* arr, int first, int end)
{
	int ret = arr[first];
	for (int i = first + 1; i <= end; ++i)
	{
		if (ret > arr[i])
			ret = arr[i];
	}
	return ret;
}
void Test()
{
	int arr[] = { 1,0,1,1,1,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int ret = Min(arr, len);
	cout << ret << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}