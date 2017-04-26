#include<iostream>
using namespace std;

//反转链表并输出反转后链表的头结点

struct Node
{
	int _value;
	Node* _next;

	Node(const int x)
		:_value(x)
		, _next(NULL)
	{}
};
Node* ReverseList(Node* head)
{
	if (head == NULL)
		return NULL;
	
	Node* ReverseNode = NULL;
	Node* cur = head;
	Node* prev = NULL;
	while (cur)
	{
		Node* next = cur->_next;
		if (next == NULL)
			ReverseNode = cur;
		cur->_next = prev;

		prev = cur;
		cur = next;
	}
	return ReverseNode;
}

void Print(Node* head)
{
	if (head == NULL)
		return;
	while (head)
	{
		cout << head->_value << " ";
		head = head->_next;
	}
	cout << endl;
}
void ReverseListTest()
{
	Node* head1 = NULL;

	Node* head = new Node(1);
	Node* n1 = new Node(2);
	head->_next = n1;
	Node* n2 = new Node(3);
	n1->_next = n2;
	Node* n3 = new Node(4);
	n2->_next = n3;
	Node* n4 = new Node(5);
	n3->_next = n4;
	n4->_next = NULL;

	cout << " before reverse: ";
	Print(head);

	Node* ReverseNode = ReverseList(head);
	cout << " after reverse: ";
	Print(ReverseNode);
}


int main()
{
	ReverseListTest();
	system("pause");
	return 0;
}