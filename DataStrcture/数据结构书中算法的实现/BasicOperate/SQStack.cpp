/*
˳��ջ�Ļ������� 
*/ 


#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define MaxSize 100
typedef int ElemType;
typedef struct {
	ElemType *top;
	ElemType *base;
	int StackSize;
}SQStack;
//��ʼ�� 
int Init(SQStack &S){
	S.base = new ElemType[MaxSize];
	if(!S.base) return ERROR;
	S.top = S.base;
	S.StackSize = MaxSize;
	return OK;
}
//Ԫ����ջ 
int Push(SQStack &S,ElemType e){
	if(S.top - S.base == S.StackSize) return ERROR;
	*S.top = e;
	S.top ++;
	return OK;
}
//Ԫ�س�ջ 
int Pop(SQStack &S,ElemType &e){
	if(S.top == S.base) return ERROR;
	S.top--;
	e = *S.top;
	return OK;
}
//�õ��׸�Ԫ�� 
int GetHead(SQStack &S,ElemType &e){
	if(S.base != S.top){
		e = *(S.top - 1);
		return OK;
	}else{
		return ERROR;
	}

}

int main()
{
	
	return 0;
}
