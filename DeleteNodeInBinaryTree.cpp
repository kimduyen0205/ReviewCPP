#include<iostream>
using namespace std;

struct node
{
	int data; 
	struct node* pLeft; 
	struct node* pRight; 
};
typedef struct node NODE;
typedef NODE* TREE;

void createtree(TREE &root){
	root = NULL;
}

void insertnode(TREE &root, int x){
	if (root == NULL){
		NODE* p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		root = p;
	}else{
		if (x < root->data){
			insertnode(root->pLeft, x);
		}else if (x > root->data){
			insertnode(root->pRight, x);
		}
	}
}

void Duyet_NLR(TREE root){
	if (root != NULL){
		cout << root->data << "  ";
		Duyet_NLR(root->pLeft);
		Duyet_NLR(root->pRight);
	}
}

void Duyet_LNR(TREE root) {
	if (root != NULL) {
		Duyet_LNR(root->pLeft);
		cout << root->data << " ";
		Duyet_LNR(root->pRight);
	}
}

void Duyet_LRN(TREE root) {
	if (root != NULL) {
		Duyet_LRN(root->pLeft);
		Duyet_LRN(root->pRight);
		cout << root->data << " ";
	}
}

NODE* FindAnElementInBinaryTree(TREE root, int key){
	if (root == NULL){
		return NULL;
	}
	else
	{
		if (key < root->data){
			FindAnElementInBinaryTree(root->pLeft, key);
		}else if (key > root->data) {
			FindAnElementInBinaryTree(root->pRight, key);
		}else {
			return root; 
		}
	}

}

void FindNodeLeftOfNodeRight(TREE& X, TREE& Y) {
	if (Y->pLeft != NULL){
		FindNodeLeftOfNodeRight(X, Y->pLeft);
	}
	else {
		X->data = Y->data;
		X = Y;
		Y = Y->pRight;
	}
}

void DeleteNodeInBinaryTree(TREE &root, int data) {
	if (root == NULL){
		return; 
	}else{
		if (data < root->data){
			DeleteNodeInBinaryTree(root->pLeft, data);
		}else if (data > root->data){
			DeleteNodeInBinaryTree(root->pRight, data);
		}else {
			NODE* x = root;
			if (root->pLeft == NULL){
				root = root->pRight;
			}else if (root->pRight == NULL){
				root = root->pLeft;
			}else {
				FindNodeLeftOfNodeRight(x, root->pRight);
			}
			delete x; 
		}
	}
}

void Menu(TREE &root){
	int luachon;
	while (true){
		system("cls");
		cout << "\n\n\t\t======Menu======";
		cout << "\n1.Nhap du lieu";
		cout << "\n2.duyet cay theo NLR";
		cout << "\n3.duyet cay theo LNR";
		cout << "\n4.duyet cay theo LRN";
		cout << "\n5.Tim kiem 1 phan tu trong cay";
		cout << "\n6.Xoa node la hoac node bac 1 hoac node bac 2 trong cay";
		cout << "\n0. Thoat";
		cout << "\n\n\t\t================";

		int luachon;
		cout << "Moi nhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon > 6){
			cout << "Su lua chon khong phu hop";
			system("pause");
		}else if (luachon == 1){
			int x;
			cout << "\nNhap gia tri: ";
			cin >> x;
			insertnode(root, x);
		}else if (luachon == 2){
			Duyet_NLR(root);
			system("pause");
		}else if (luachon == 3) {
			Duyet_LNR(root);
			system("pause");
		}else if (luachon == 4){
			Duyet_LRN(root);
			system("pause");
		}else if (luachon == 5){
			int key;
			cout << "Nhap gia tri can tim trong cay: ";
			cin >> key;
			NODE *p = FindAnElementInBinaryTree(root, key);
			if (p == NULL){
				cout << "Khong tim thay phan tu trong cay" << endl;
			}else{
				cout << "Tim thay phan tu " << key << " trong cay" << endl;
			}
			system("pause");
		}else if (luachon == 6){
			int x;
			cout << "Nhap gia tri can xoa: ";
			cin >> x;
			DeleteNodeInBinaryTree(root, x);
		}else{
			break;
		}
	}
}

int main()
{
	TREE root;
	createtree(root);
	Menu(root);
	system("pause");
	return 0;
}