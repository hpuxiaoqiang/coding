/*
顺序表的基本操作 
*/ 

#include <iostream>
using namespace  std;
#define OK 1
#define ERROR 0
#define MaxSize 1000
typedef int ElemType;

typedef struct {
	ElemType *elem;
	int SQListSize;
}SQList;

int Init(SQList &L){
	L.elem = new ElemType[MaxSize];
	if(!L.elem) return ERROR;
	L.SQListSize = MaxSize;
	return OK; 
}



int main()
{

	return 0;
}
