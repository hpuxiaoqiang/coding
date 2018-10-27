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
//构造一个空的链队 
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
	p = Q.front->next;//用p指向队头元素，保留队头元素的地址 
	e = Q.front->next->data;//保留队头元素的值
	Q.front->next = p->next;
	if(Q.rear == p) Q.front = Q.rear;//最后一个元素被删除，队尾指针指向头节点，队为空 
	//if(Q.front->next==NULL) Q.rear =  Q.front;//或者头节点的next为空 
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
