#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
#define ERROR 0
#define TRUE 1
#define MaxSize 100
#define OK 1
typedef int Status;
typedef int SElemType;
//typedef struct 
//{
//	int data;
//}Data;
typedef struct 
{
	SElemType *top;
	SElemType *base;
	int stackSize;
}SqStack;

Status Initstack(SqStack &s)
{
	s.base = new SElemType[MaxSize];
	if(!s.base) return ERROR;
	s.top =s.base;
	s.stackSize = MaxSize;
	return OK;
}
Status Push(SqStack &s,SElemType e)
{
	if(s.top - s.base == s.stackSize) return ERROR;
	*s.top = e;
	s.top++;
}
Status Pop(SqStack &s,SElemType &e)
{
	if(s.top == s.base) return ERROR;
	e = *(s.top--);
}
void GetTop(SqStack &s,SElemType &e)
{
	e = *(s.top-1);
}
void creatStack(SqStack &s,int n)
{
	SElemType tem;
	cin>>n;
	for(int i= 0;i < n; i++)
	{
		cin>>tem;
		*s.top = tem;
		s.top++; 
		s.stackSize++;
	}
}
void Print(SqStack s)
{
	int num = s.top-s.base;
	for (int i = 0; i < num; i++)
	{
		/* code */
		cout<<*(s.top-1)<<endl;
		s.top--;
	}
}
int main()
{
	int n;
	SElemType Temper;
	SqStack S;
	if(Initstack(S))
	{
		cout<<"栈初始化成功！"<<endl;
	}else{
		cout<<"栈初始化失败！"<<endl;
	} 
	creatStack(S,n);
	Print(S);
	return 0;
}
