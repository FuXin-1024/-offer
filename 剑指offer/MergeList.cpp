#include<iostream>
using namespace std;

struct Node
{
	int _value;
	Node* _next;

	Node(const int x)
		:_value(x)
		, _next(NULL)
	{}
};

Node* MergeList(Node* head1, Node* head2)
{
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	Node* MergeNode = NULL;
	if ((head1->_value) < (head2->_value))
	{
		MergeNode = head1;
		head1 = head1->_next;
		MergeNode->_next = MergeList(head1, head2);
	}
	else
	{
		MergeNode = head2;
		head2 = head2->_next;
		MergeNode->_next = MergeList(head1, head2);
	}
	return MergeNode;
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
}

void MergeListLest()
{
	Node* head = NULL;
	Node* head1 = new Node(1);
	Node* n1 = new Node(3);
	head1->_next = n1;
	Node* n2 = new Node(5);
	n1->_next = n2;
	Node* n3 = new Node(7);
	n2->_next = n3;
	Node* n4 = new Node(9);
	n3->_next = n4;
	n4->_next = NULL;

	Node* head2 = new Node(0);
	Node* n11 = new Node(2);
	head2->_next = n11;
	Node* n12 = new Node(4);
	n11->_next = n12;
	Node* n13 = new Node(6);
	n12->_next = n13;
	Node* n14 = new Node(8);
	n13->_next = n14;
	n14->_next = NULL;

	Node* MergeNode = MergeList(head1, head2);
	Print(MergeNode);
}
int main()
{
	MergeListLest();
	system("pause");
	return 0;
}