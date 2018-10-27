#include <iostream>
#include <cstdio>
#include <cstring>
#define OK 1
#define ERROR 0
#define MaxSize
using namespace std;
typedef int status;

typedef char ElemType;
typedef struct BiTNode{
	struct BiTNode *Lchild,*Rchild;
	ElemType data;
}BiTNode,*BiTree;

typedef struct StackNode{
	struct StackNode *next;
	BiTNode *data;
}StackNode,*LinkStack;

int Init(LinkStack &S)
{
	S = NULL;
	return OK;
  }  
status Push(LinkStack &S,BiTNode *e)
{
	StackNode *p;
	p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}
status Pop(LinkStack &S,BiTree &e)
{
	StackNode *p;
	if(S == NULL ) return ERROR;
	e = S->data;
	p = S;
	S = S->next;
	delete p;
	return OK;
}
//判断栈是否为空 
status Stack_is_Empty(LinkStack &S)
{
	if(S == NULL) return 1;
	else return 0;
}
//先序遍历创建二叉树 
void Create_BiTree(BiTree &T)
{
	ElemType ch;
	cin>>ch;
	if(ch == '#') T = NULL;
	else{
		T = new BiTNode;
		T->data = ch;
		Create_BiTree(T->Lchild);
		Create_BiTree(T->Rchild);
	} 
}

//中序递归遍历二叉树 
void ZhongXuOrderTraverse(BiTree T)
{
	if(T == NULL) return ;
	else{
		ZhongXuOrderTraverse(T->Lchild);
		cout<<T->data;
		ZhongXuOrderTraverse(T->Rchild);
	}
} 
//后序递归遍历二叉树
void HouXuOrderTraverse(BiTree T)
{
	if(T == NULL) return ;
	else{
		HouXuOrderTraverse(T->Lchild);
		HouXuOrderTraverse(T->Rchild);
		cout<<T->data;
	}
}
//先序递归遍历二叉树
void XianxuOrderTraverse(BiTree T)
{
	if(T == NULL) return ;
	else{
		cout<<T->data;
		XianxuOrderTraverse(T->Lchild);
		XianxuOrderTraverse(T->Rchild);
	}
}

//非递归中序遍历二叉树 
void InOrderTraverse(BiTree T)
{
	LinkStack S;
	Init(S);
	BiTNode *p,*q;
	q = new BiTNode;
	p = T;
	while(p||!Stack_is_Empty(S))
	{
		if(p)//将p移动到左子树最下方 
		{
			Push(S,p);
			p = p->Lchild;
		}
		else{
			Pop(S,q);
			cout<<q->data;//开始访问根节点 
			p = q->Rchild;
		}
	}
 }
//非递归先序遍历二叉树 
void FirstlyOrderTraverse(BiTree T)
{
	LinkStack S;
	Init(S);
	BiTNode *p;
	p = T;
	while(p || !Stack_is_Empty(S))
	{
		while(p)
		{
			cout<<p->data;//访问根节点 
			Push(S,p);
			p =p->Lchild;//一直往左子树访问 
		}
		Pop(S,p);//开始出栈访问根节点 
		p = p->Rchild;
	}
}

//非递归后序遍历二叉树 
void PostOrderTraverse(BiTree T)
{
	LinkStack S;
	Init(S);
	BiTNode *pCurrent,*pLastVisit;
	pCurrent = T;
	pLastVisit = NULL;
	//先将pCurrent移动到左子树最下方 
	while(pCurrent)
	{
		Push(S,pCurrent);
		pCurrent = pCurrent->Lchild;
	}
	
	while(!Stack_is_Empty(S))
	{
		Pop(S,pCurrent);//根节点出栈 
		if((pCurrent->Rchild == NULL)||(pCurrent->Rchild == pLastVisit))//访问根节点的前提是右子树为空或者右子树已经被访问过 
		{
			cout<<pCurrent->data;//访问根节点 
			pLastVisit = pCurrent;//修改最近访问节点 
		}
		else
		{
			//条件不满足,说明左子树刚被访问过,那么就要先需要先进入右子树 
			Push(S,pCurrent);//根节点继续入栈 
			pCurrent = pCurrent->Rchild;//进入右子树,而且可以肯定右子树一定存在 
			while(pCurrent)//进入右子树 
			{
				Push(S,pCurrent);
				pCurrent = pCurrent->Lchild;
			}	
		}
	}
}
 
int main()
{
	BiTree T;
	int menu;
	cout<<"请创建二叉树（按照先序遍历的方式）："<<endl; 
	Create_BiTree(T);
	cout<<"请选择遍历方式："<<endl;
	cout<<"0.非递归遍历"<<endl;
	cout<<"1.递归遍历"<<endl;
	cout<<"-1.退出"<<endl; 
	while(true)
	{
		cin>>menu;
		switch(menu)
		{
			case 0:{
				cout<<"非递归中序遍历："; 
				InOrderTraverse(T);
				cout<<endl;
				cout<<"非递归先序遍历：";
				FirstlyOrderTraverse(T);
				cout<<endl;
				cout<<"非递归后序遍历：";
				PostOrderTraverse(T);
				cout<<endl;
				break;
			}
			case 1:{
				cout<<"递归中序遍历："; 
				ZhongXuOrderTraverse(T);
				cout<<endl;
				cout<<"递归先序遍历：";
				XianxuOrderTraverse(T);
				cout<<endl;
				cout<<"递归后序遍历：";
				HouXuOrderTraverse(T);
				cout<<endl;
				break;
			}
			case -1:{
				exit(0);
			}
		 } 
	}
	return 0;
}
