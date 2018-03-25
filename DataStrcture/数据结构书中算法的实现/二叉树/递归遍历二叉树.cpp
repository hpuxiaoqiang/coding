#include <iostream>
#include <cstdio>
using namespace std;
#define OK 1
#define ERROR 0
typedef char ElemType;
/*二叉树的储存结构*/ 
typedef struct BiTNode{
	struct BiTNode *lchild,*rchild;
	ElemType data;
}BiTNode,*BiTree;
/*先序遍历创建二叉树*/ 
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
/*中序递归遍历二叉树*/
void InOrderTraverse(BiTree &T)
{
	if(T)
	{
		InOrderTraverse(T->lchild);
		cout<<T->data;
		InOrderTraverse(T->rchild);
	}
}
/*先序递归遍历二叉树*/
void PriorOrderTraverse(BiTree &T)
{
	if(T)
	{
		cout<<T->data;
		InOrderTraverse(T->lchild);
		InOrderTraverse(T->rchild);
	}
}
/*后序递归遍历二叉树*/
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
	cout<<"中序递归遍历二叉树："; 
	InOrderTraverse(T);
	cout<<endl;
	cout<<"先序递归遍历二叉树："; 
	PriorOrderTraverse(T);
	cout<<endl;
	cout<<"后序递归遍历二叉树："; 
	ReraOrderTraverse(T);
	cout<<endl;
	return 0;
}
