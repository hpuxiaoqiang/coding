#include <iostream>
#include <cstring>
#include <cstdio>
using namespace  std;
#define OK 1
#define ERROR 0
#define MaxSize 100
typedef int ElemType;
typedef int status;
/*
˳��ӣ��������飬front��rearʵ��������ţ���ͬ��Ԫ��ָ�롣 
//ѭ������ 
*/
typedef struct {
	ElemType *elem;
	int front;//ͷָ�� 
	int rear;//βָ�� 
}SqQueue;
status Init(SqQueue &Q){
	Q.elem = new ElemType[MaxSize];
	if(!Q.elem) return ERROR;
	Q.front = Q.rear;
	return OK;
}
status InQueue(SqQueue &Q,ElemType e){
	if((Q.front+1)%MaxSize == Q.rear) return ERROR;
	Q.elem[Q.front] = e;
	Q.rear = (Q.rear+1)%MaxSize;
	return OK;
}
status DeQueue(SqQueue &Q,ElemType &e){
	if(Q.front == Q.rear) return ERROR;//��Ϊ��
	e = Q.elem[Q.front];
	Q.front = (Q.front+1)%MaxSize;//ͷָ����ǰ�ƶ�һλ
	return OK; 
}
                

int main()
{
	return 0;
}
