#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

#define OK 1
#define ERROR 0
#define ENDFLAG  0
typedef int ElemType;
typedef struct BSTNode{
	ElemType data;
	BSTNode *Rchild,*Lchild; 
}BSTNode,*BSTree;

int Insert_BSTree(BSTree &T,ElemType e)
{
	BSTNode *S;
	if(!T)
	{
		S = new BSTNode;
		S->Lchild = S->Rchild = NULL;
		S->data = e;
		T=S; 
	}
	else if(e > T->data){
		Insert_BSTree(T->Rchild,e);
	}else if(e < T->data){
		Insert_BSTree(T->Lchild,e);
	} 
} 

int Creat_BSTree(BSTree &T)
{
	cout<<"��������������!"<<endl;
	T = NULL;
	int num;
	cout<<"����ڵ�����(������\'0\'����)"<<endl; 
	cin>>num;
	while(num!=ENDFLAG)
	{
		Insert_BSTree(T,num);
		cout<<"����ڵ�����(������\'0\'����)"<<endl;
		cin>>num;
	}
	return OK; 
}

int InOrderTraverse(BSTree T)
{
	if(T==NULL) return ERROR;
	else
	{
		InOrderTraverse(T->Lchild);
		cout<<T->data<<" ";
		InOrderTraverse(T->Rchild);
	}
}

BSTree BSTree_Search(BSTree T,ElemType e)
{
	if(!T || T->data == e) return T;
	else if(e>T->data)   return BSTree_Search(T->Rchild,e);
	else if(e < T->data) return BSTree_Search(T->Lchild,e); 
}


int main()
{
	BSTree T,S;
	Creat_BSTree(T);
	cout<<"�����������������:"<<endl; 
	InOrderTraverse(T);
	cout<< endl;
	int key;
	cout<<"������Ҫ���ҵ�����(������\'0\'����):"<<endl;
	cin>>key;
	while(key)
	{
		S = BSTree_Search(T,key);
		if(!S){
			cout<<"�ý��δ�ҵ�"<<endl;
		}else{
			cout<<S->data<<endl;
			cout<<"�ý�����ҵ�"<<endl;
		}
		cout<<"������Ҫ���ҵ�����(������\'0\'����):"<<endl;
		cin>>key;
	}
	
	return 0;
 } 
