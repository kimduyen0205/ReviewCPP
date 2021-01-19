#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node* pNext;
};
typedef struct node NODE;
struct list
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct list LIST;
void CreateListEmpty(LIST &l) {
	l.pHead = NULL;
	l.pTail = NULL;
}
NODE *CreateNode(int x) {
	NODE* p = new NODE;
	p->data = x;
	p->pNext = NULL;
	return p;
}
int main() {
	LIST l;
	CreateListEmpty(l); 
	int x;
	cout << "Nhap gia tri so nguyen: ";
	cin >> x;
	NODE* p = CreateNode(x);
	system("pause");
	return 0;
}