#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define OK 1
#define ERROR 0
#define MaxNum 100
#define Max 32767
int Mark[MaxNum];
typedef char VexNameType;//��������� 
typedef int ArcType;//�ߵ�Ȩֵ 
typedef char QueueElemType;
typedef int Status;

typedef struct {
	 VexNameType vexs[MaxNum];
	 ArcType arcs[MaxNum][MaxNum];
	 int VexNum,ArcNum;
}Graph;

typedef struct QueueNode{
	QueueElemType data;
	struct QueueNode *next;
}QueueNode,*QueuePtr;
typedef struct{
	QueuePtr front;//��ͷָ�� 
	QueuePtr rear;//��βָ�� 
}LinkQueue;

//�ж϶����Ƿ�Ϊ�� 
int QueueEmpty(LinkQueue Q)
{
	if(Q.front == Q.rear) return 1;
	return 0;
}
//��ʼ������ 
Status InitQueue(LinkQueue &Q)
{
	Q.front = Q.rear = new QueueNode;
	Q.front->next = NULL;
	return OK;
}
//��� 
Status InQueue(LinkQueue &Q,QueuePtr e)
{
	if(Q.front == Q.rear) return ERROR;
	QueueNode *p;
	p = new QueueNode;
	p->data = e->data;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	
}
//���� 
Status DeQueue(LinkQueue &Q,QueuePtr &e)
{
	if(Q.front == Q.rear) return ERROR;
	QueueNode *p;
	p = Q.front->next;
	e->data = p->data;
	Q.front->next = Q.front->next->next;//��Ϊ����һ��ͷ���
	if(Q.rear == p) Q.front = Q.rear; 
	delete p;
} 

//�õ�ĳ���������� 
int LocateVex(Graph G,VexNameType V)
{
	for(int i= 1;i <= G.VexNum;i++)
	{
		if(G.vexs[i] == V) return i;
	}
}

//���ڽӾ���ķ�ʽ�洢,������Ȩ����ͼ 
int Creat_Graph(Graph &G)
{
	cout<<"�����붥������ͱߵĸ�����"<<endl; 
	cin>>G.VexNum>>G.ArcNum;
	cout<<"�����붥������:"<<endl;
	for(int i = 1; i <= G.VexNum;i++ )
	{
		cin>>G.vexs[i];	
	}
	for(int i = 1;i<=G.VexNum;i++)
	{
		for(int j =1;j<=G.VexNum;j++)
		{
			G.arcs[i][j] = Max;
		}
	}
	cout<<"�����������������붥�����ϵ��"<<endl;
	cout<<"������ߵ�������֣��յ����֣��ߵ�Ȩֵ���Կո�������"<<endl; 
	for(int i = 1; i <=G.ArcNum;i++)
	{
		VexNameType v1,v2;
		int  p1,p2,w;
		cin>>v1>>v2>>w;
		p1 = LocateVex(G,v1);
		p2 = LocateVex(G,v2);
		G.arcs[p1][p2] = w;
		G.arcs[p2][p1] = G.arcs[p1][p2];
	}
	return OK; 
} 


//�õ��Ķ����һ���ڽӵĵ���� 
int FirstAdjVex(Graph G,int V)
{
	for(int i = 1;i<=G.VexNum;i++)
	{
		if(G.arcs[V][i]<Max) return i;
	}
	return ERROR;
}

//�õ������w,V����һ���ڽӵ����� 
int NextAdjVex(Graph G,int V,int w)
{
	for(int i =w+1;i<=G.VexNum;i++)
	{
		if(G.arcs[V][i]<Max) return i;
	}
	return ERROR;
}

//��bug 
void BFS(Graph G,int Vnum)
{
	LinkQueue Q;
	InitQueue(Q);
	QueueNode *e;
	cout<<G.vexs[Vnum];
	Mark[Vnum];
	e->data = G.vexs[Vnum];
	InQueue(Q,e);
	while(!QueueEmpty(Q))
	{
		DeQueue(Q,e);
		for(int w = FirstAdjVex(G,LocateVex(G,e->data));w>=1;w = NextAdjVex(G,LocateVex(G,e->data),w))
		{
			if(!Mark[w]) 
			{
				cout<<G.vexs[w];
				e->data = G.vexs[w];
				Mark[w] = 1;
				InQueue(Q,e);	
			}
		}
	} 
}
int main()
{
	Graph G;
	Creat_Graph(G);
	BFS(G,1);
	return 0;
} 
