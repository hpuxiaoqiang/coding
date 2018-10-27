#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define OK 1
#define ERROR 0
typedef int Status;

typedef struct {
	char name[20];
	char sex;
}Person;

typedef struct QNode{
	struct QNode *next;
	Person person;
}QNode,*QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

int InitQueue(LinkQueue &Q){
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;
	return OK;
}

int EnQueue(LinkQueue &Q,Person e){
	QueuePtr p;
	p = new QNode;
	p->person = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

int DeQueue(LinkQueue &Q,Person &e)
{
	QueuePtr p;
	if(Q.front == Q.rear) return ERROR;
	p = Q.front->next;
	e = Q.front->next->person;
	Q.front->next = p->next;
	if(Q.rear == p) Q.front = Q.rear;
	delete p;
	return OK; 
}

int GetHead(LinkQueue Q,Person &e){
	if(Q.front!=Q.rear) 
	{
		e = Q.front->next->person;
		return OK;	
	}else{
		return ERROR;
	}
}
int QueueEmpty(LinkQueue &Q)
{
	if(Q.front == Q.rear)	return OK;
	return ERROR;
}
void DancePartner(Person Dancing[],int num)
{
	Person temp; 
	LinkQueue FemaleDancer;
	LinkQueue MaleDancer;
	InitQueue(FemaleDancer);
	InitQueue(MaleDancer);
	for(int i =0;i< num;i++){
		temp = Dancing[i];
		if(temp.sex == 'F') EnQueue(FemaleDancer,temp);
		else EnQueue(MaleDancer,temp);
	}
	cout<<"The dancing partner are :"<<endl;
	cout<<"Woman\'s name	Man\'name"<<endl;
	while(!QueueEmpty(FemaleDancer)&&!QueueEmpty(MaleDancer))
	{
		DeQueue(FemaleDancer,temp);
		cout<<temp.name<<"		";
		DeQueue(MaleDancer,temp);
		cout<<temp.name<<endl;
	}
	cout<<endl;
	if(!QueueEmpty(FemaleDancer)){
		GetHead(FemaleDancer,temp);
		cout<<"Next Time,The first woman to get a parter is \""<<temp.name<<"\""<<endl;
	}else if(!QueueEmpty(MaleDancer)){
		GetHead(MaleDancer,temp);
		cout<<"Next Time,The first man to get a parter is \""<<temp.name<<"\""<<endl;
	}
}

int main()
{
	Person Dancing_People[110]; 
	int people_number;
	cout<<"Please input the people's number:"<<endl;
	cin>>people_number;
	for(int i =0;i< people_number;i++)
	{
		cout<<"Please input NO."<<i+1<<"\'s name:"<<endl;
		cin>>Dancing_People[i].name;
		cout<<"Please input NO."<<i+1<<"\'s sex:"<<endl;
		cin>>Dancing_People[i].sex;
	}
	DancePartner(Dancing_People,people_number);
	return 0;
}
