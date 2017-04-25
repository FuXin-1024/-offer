
//在O(1)时间删除链表结点
//思路：
//找到要删除的结点i 的下一个结点j ，把后面的结点j 的内容复制到要删除结点i，
//i->next = j->next, delete j;
//注意： 删除尾结点， 和只有一个节点的情况
#include<iostream>
using namespace std;

struct Node
{
	int _value;
	Node* _next;

	Node(int value)
		: _value(value)
		, _next(NULL)
	{}
};


void DeleteNode(Node* pHead, Node* del)
{
	if (pHead == NULL || del == NULL)
		return;
	if (del->_next == NULL)//删除为节点，只能用遍历方式删除
	{
		Node* cur = pHead;
		while (cur->_next != del)
		{
			cur = cur->_next;
		}
		cur->_next = NULL;
		delete del;
		del = NULL;
	}
	else if (del == pHead)//只有一个节点，删除头结点
	{
		delete del;
		del = NULL;
		pHead = del = NULL;
	}
	else//多个节点，删除其中一个
	{
		Node* next = del->_next;
		del->_value = next->_value;//把后面的结点复制到要被删除的结点
		del->_next = next->_next;
		delete next;
		next = NULL;
	}
}

void testDelete()
{
	Node* head = new Node(0);
	Node* n1 = new Node(1);
	head->_next = n1;
	Node* n2 = new Node(2);
	n1->_next = n2;
	Node* n3 = new Node(3);
	n2->_next = n3;
	Node* n4 = new Node(4);
	n3->_next = n4;
	n4->_next = NULL;

	DeleteNode(head, n2);

}

int main()
{
	testDelete();
	system("pause");
	return 0;
}