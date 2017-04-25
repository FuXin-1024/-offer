
//��O(1)ʱ��ɾ��������
//˼·��
//�ҵ�Ҫɾ���Ľ��i ����һ�����j ���Ѻ���Ľ��j �����ݸ��Ƶ�Ҫɾ�����i��
//i->next = j->next, delete j;
//ע�⣺ ɾ��β��㣬 ��ֻ��һ���ڵ�����
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
	if (del->_next == NULL)//ɾ��Ϊ�ڵ㣬ֻ���ñ�����ʽɾ��
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
	else if (del == pHead)//ֻ��һ���ڵ㣬ɾ��ͷ���
	{
		delete del;
		del = NULL;
		pHead = del = NULL;
	}
	else//����ڵ㣬ɾ������һ��
	{
		Node* next = del->_next;
		del->_value = next->_value;//�Ѻ���Ľ�㸴�Ƶ�Ҫ��ɾ���Ľ��
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