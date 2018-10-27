#include <iostream>
#include <cstdio>
#define OK 1
#define ERROR 0
typedef int ElemType;
using namespace std;
typedef struct QNode{
	struct QNode *next;
	ElemType data;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
//����һ���յ����� 
int InitQueue(LinkQueue &Q){
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;
	return OK;
}

int EnQueue(LinkQueue &Q,ElemType e){
	QueuePtr p;
	p = new QNode;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

int DeQueue(LinkQueue &Q,ElemType &e)
{
	QueuePtr p;
	if(Q.front == Q.rear) return ERROR;
	p = Q.front->next;//��pָ���ͷԪ�أ�������ͷԪ�صĵ�ַ 
	e = Q.front->next->data;//������ͷԪ�ص�ֵ
	Q.front->next = p->next;
	if(Q.rear == p) Q.front = Q.rear;//���һ��Ԫ�ر�ɾ������βָ��ָ��ͷ�ڵ㣬��Ϊ�� 
	//if(Q.front->next==NULL) Q.rear =  Q.front;//����ͷ�ڵ��nextΪ�� 
	delete p;
	return OK; 
}
int GetHead(LinkQueue Q){
	if(Q.front!=Q.rear)
		return Q.front->next->data;
}

int main(){
	return 0;
}
