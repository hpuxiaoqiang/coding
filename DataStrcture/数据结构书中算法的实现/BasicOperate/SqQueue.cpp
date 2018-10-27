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
顺序队，利用数组，front和rear实际上是序号，等同于元素指针。 
//循环队列 
*/
typedef struct {
	ElemType *elem;
	int front;//头指针 
	int rear;//尾指针 
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
	if(Q.front == Q.rear) return ERROR;//队为空
	e = Q.elem[Q.front];
	Q.front = (Q.front+1)%MaxSize;//头指针向前移动一位
	return OK; 
}
                

int main()
{
	return 0;
}
