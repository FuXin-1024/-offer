#include<iostream>
using namespace std;

void Permutation(char* str, char* begin)
{
	if (*begin == '\0')
		cout << str << endl;
	else
	{
		for (char* ch = begin; *ch != '\0'; ++ch)
		{
			char temp = *ch;
			*ch = *begin;
			*begin = temp;

			Permutation(str, begin + 1);
			temp = *ch;
			*ch = *begin;
			*begin = temp;
		}
	}
}
void Permutation(char* str)
{
	if (str == NULL)
		return;
	Permutation(str, str);
}

void Test()
{
	char str[] = { "abc" };
	Permutation(str);
}
int main()
{
	Test();
	system("pause");
	return 0;
}