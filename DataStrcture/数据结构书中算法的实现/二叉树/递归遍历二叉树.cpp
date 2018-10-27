#include <iostream>
#include <cstdio>
using namespace std;
#define OK 1
#define ERROR 0
typedef char ElemType;
/*�������Ĵ���ṹ*/ 
typedef struct BiTNode{
	struct BiTNode *lchild,*rchild;
	ElemType data;
}BiTNode,*BiTree;
/*�����������������*/ 
void Creat_BiTree(BiTree &T)
{
	char ch;
	cin>>ch;
	if(ch == '#') T=NULL;
	else
	{
		T = new BiTNode;
		T->data = ch;
		Creat_BiTree(T->lchild);
		Creat_BiTree(T->rchild);
	}
}
/*����ݹ����������*/
void InOrderTraverse(BiTree &T)
{
	if(T)
	{
		InOrderTraverse(T->lchild);
		cout<<T->data;
		InOrderTraverse(T->rchild);
	}
}
/*����ݹ����������*/
void PriorOrderTraverse(BiTree &T)
{
	if(T)
	{
		cout<<T->data;
		InOrderTraverse(T->lchild);
		InOrderTraverse(T->rchild);
	}
}
/*����ݹ����������*/
void ReraOrderTraverse(BiTree &T)
{
	if(T)
	{
		InOrderTraverse(T->lchild);
		InOrderTraverse(T->rchild);
		cout<<T->data;
	}
}
int main()
{
	BiTNode *T;
	Creat_BiTree(T);
	cout<<"����ݹ������������"; 
	InOrderTraverse(T);
	cout<<endl;
	cout<<"����ݹ������������"; 
	PriorOrderTraverse(T);
	cout<<endl;
	cout<<"����ݹ������������"; 
	ReraOrderTraverse(T);
	cout<<endl;
	return 0;
}
