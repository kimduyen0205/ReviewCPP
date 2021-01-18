#include<iostream>
using namespace std;

struct node {
	int data;
	struct node *pLeft;
	struct node *pRight;
};
typedef struct node NODE;
typedef NODE* TREE;
void createtree(TREE &root) {
	root = NULL;
}
void insertnode(TREE &root, int x) {
	if (root == NULL){
		NODE* p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		root = p;
	}
	else {
		if (x < root->data ){
			insertnode(root->pLeft, x);
		}else if (x > root->data){
			insertnode(root->pRight, x);
		}
	}
}
void Duyet_NLR(TREE root) {
	if (root != NULL){
		cout << root->data << " ";
		Duyet_NLR(root->pLeft);
		Duyet_NLR(root->pRight);
	}
}
void Duyet_LNR(TREE root) {
	if (root != NULL){
		Duyet_LNR(root->pLeft);
		cout << root->data << " ";
		Duyet_LNR(root->pRight);
	}
}
void Duyet_LRN(TREE root) {
	if (root != NULL){
		Duyet_LRN(root->pLeft);
		Duyet_LRN(root->pRight);
		cout << root->data << " ";
	}
}
void Menu(TREE& root) {
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t======Menu======";
		cout << "\n1.Nhap du lieu";
		cout << "\n2.Duyet cay theo NLR";
		cout << "\n3.Duyet cay theo LNR";
		cout << "\n4.Duyet cay theo LRN";
		cout << "\n0.Thoat";
		cout << "\n\n\t\t================";
		int luachon;
		cout << "Moi nhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon > 4) 
		{
			cout << "Su lua chon khong phu hop";
			system("pause");
		}
		else if (luachon == 1)
		{
			int x;
			cout << "Nhap so nguyen: ";
			cin >> x;
			insertnode(root, x);
		}
		else if (luachon == 2) {
			Duyet_NLR(root);
			system("pause");
		}
		else if (luachon == 3) {
			Duyet_LNR(root);
			system("pause");
		}
		else if (luachon == 4)
		{
			Duyet_LRN(root);
			system("pause");
		}
		else {
			break;
		}
	}
}
int main() {
	TREE root;
	createtree(root);
	Menu(root);
	system("pause");
	return 0;
}