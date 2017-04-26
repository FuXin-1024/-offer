#include<iostream>
using namespace std;
//˼·����������ָ�룬Front,Behind.Front����k-1����Behind������
//�ӵ�K����ʼ���ڶ���ָ�������ͷ��ʼ������������ָ��ľ��벻����
// ��Frontָ���ߵ�����βʱ��Behindָ��ǡ���ǵ�����K���ڵ�
struct Node
{
	int  _value;
	Node* _next;
	
	Node(const int x)
		:_value(x)
		, _next(NULL)
	{}
};

Node* FindKthToTail(Node* pHead, size_t k)
{
	if (pHead == NULL || k <= 0)
		return NULL;
	Node* Front = pHead;
	Node* Behind = NULL;
	for (int i = 0; i < k - 1; ++i)
	{
		if (Front->_next != NULL)
			Front = Front->_next;
		else
			return NULL;
	}
	Behind = pHead;
	while (Front->_next != NULL)
	{
		Front = Front->_next;
		Behind = Behind->_next;
	}
	return Behind;
}

//��������м�ڵ�
Node* FindListMid(Node* head)
{
	if (head == NULL)
		return NULL;
	Node* front = head;
	Node* behind = head;
	while (front->_next != NULL && front->_next->_next !=NULL)
	{
		front = front->_next->_next;
		behind = behind->_next;
	}
	return behind;
}

// �ж�һ�����������Ƿ��γ��˻��νṹ
bool IsRing(Node* head)//�ǻ� ���� ��
{
	if (head == NULL)
		return false;
	Node* front = head;
	Node* behind = head;
	while (front->_next != NULL && front->_next->_next != NULL)
	{
		front = front->_next->_next;
		behind = behind->_next;
		if (front < behind)
			return true;
	}
	return false;
}

void Print(Node* head)
{
	Node* cur = head;
	if (cur == NULL)
		return;
	while (cur)
	{
		cout << cur->_value << " ";
		cur = cur->_next;
		if (cur == head)
			break;
	}
	cout << endl;
}

void FindKthToTailTest()
{
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

	Print(head);

	Node* find = FindKthToTail(head, 1);
	if (find)
		cout << "Find: " << find->_value << endl;
}

void FindListMidTest()
{
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
	Print(head);

	Node* find = FindListMid(head);
	if (find)
		cout << "Find: " << find->_value << endl;
}

void IsRing()
{
	Node* head = new Node(1);
	Node* n1 = new Node(2);
	head->_next = n1;
	Node* n2 = new Node(3);
	n1->_next = n2;
	Node* n3 = new Node(4);
	n2->_next = n3;
	Node* n4 = new Node(5);
	n3->_next = n4;
	n4->_next = head;

	Print(head);
	cout<<"IsRing??" << IsRing(head) << endl;;
}

int main()
{
	FindListMidTest();
	FindKthToTailTest();
	IsRing();
	system("pause");
	return 0;
}