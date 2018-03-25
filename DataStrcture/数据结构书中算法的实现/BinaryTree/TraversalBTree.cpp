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
//�ж�ջ�Ƿ�Ϊ�� 
status Stack_is_Empty(LinkStack &S)
{
	if(S == NULL) return 1;
	else return 0;
}
//����������������� 
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

//����ݹ���������� 
void ZhongXuOrderTraverse(BiTree T)
{
	if(T == NULL) return ;
	else{
		ZhongXuOrderTraverse(T->Lchild);
		cout<<T->data;
		ZhongXuOrderTraverse(T->Rchild);
	}
} 
//����ݹ����������
void HouXuOrderTraverse(BiTree T)
{
	if(T == NULL) return ;
	else{
		HouXuOrderTraverse(T->Lchild);
		HouXuOrderTraverse(T->Rchild);
		cout<<T->data;
	}
}
//����ݹ����������
void XianxuOrderTraverse(BiTree T)
{
	if(T == NULL) return ;
	else{
		cout<<T->data;
		XianxuOrderTraverse(T->Lchild);
		XianxuOrderTraverse(T->Rchild);
	}
}

//�ǵݹ�������������� 
void InOrderTraverse(BiTree T)
{
	LinkStack S;
	Init(S);
	BiTNode *p,*q;
	q = new BiTNode;
	p = T;
	while(p||!Stack_is_Empty(S))
	{
		if(p)//��p�ƶ������������·� 
		{
			Push(S,p);
			p = p->Lchild;
		}
		else{
			Pop(S,q);
			cout<<q->data;//��ʼ���ʸ��ڵ� 
			p = q->Rchild;
		}
	}
 }
//�ǵݹ�������������� 
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
			cout<<p->data;//���ʸ��ڵ� 
			Push(S,p);
			p =p->Lchild;//һֱ������������ 
		}
		Pop(S,p);//��ʼ��ջ���ʸ��ڵ� 
		p = p->Rchild;
	}
}

//�ǵݹ������������� 
void PostOrderTraverse(BiTree T)
{
	LinkStack S;
	Init(S);
	BiTNode *pCurrent,*pLastVisit;
	pCurrent = T;
	pLastVisit = NULL;
	//�Ƚ�pCurrent�ƶ������������·� 
	while(pCurrent)
	{
		Push(S,pCurrent);
		pCurrent = pCurrent->Lchild;
	}
	
	while(!Stack_is_Empty(S))
	{
		Pop(S,pCurrent);//���ڵ��ջ 
		if((pCurrent->Rchild == NULL)||(pCurrent->Rchild == pLastVisit))//���ʸ��ڵ��ǰ����������Ϊ�ջ����������Ѿ������ʹ� 
		{
			cout<<pCurrent->data;//���ʸ��ڵ� 
			pLastVisit = pCurrent;//�޸�������ʽڵ� 
		}
		else
		{
			//����������,˵���������ձ����ʹ�,��ô��Ҫ����Ҫ�Ƚ��������� 
			Push(S,pCurrent);//���ڵ������ջ 
			pCurrent = pCurrent->Rchild;//����������,���ҿ��Կ϶�������һ������ 
			while(pCurrent)//���������� 
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
	cout<<"�봴����������������������ķ�ʽ����"<<endl; 
	Create_BiTree(T);
	cout<<"��ѡ�������ʽ��"<<endl;
	cout<<"0.�ǵݹ����"<<endl;
	cout<<"1.�ݹ����"<<endl;
	cout<<"-1.�˳�"<<endl; 
	while(true)
	{
		cin>>menu;
		switch(menu)
		{
			case 0:{
				cout<<"�ǵݹ����������"; 
				InOrderTraverse(T);
				cout<<endl;
				cout<<"�ǵݹ����������";
				FirstlyOrderTraverse(T);
				cout<<endl;
				cout<<"�ǵݹ���������";
				PostOrderTraverse(T);
				cout<<endl;
				break;
			}
			case 1:{
				cout<<"�ݹ����������"; 
				ZhongXuOrderTraverse(T);
				cout<<endl;
				cout<<"�ݹ����������";
				XianxuOrderTraverse(T);
				cout<<endl;
				cout<<"�ݹ���������";
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
