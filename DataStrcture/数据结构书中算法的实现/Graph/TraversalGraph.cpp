#include <iostream>
#include <cstdio>
#include <cstring>
#define OK 1
#define ERROR 0
#define Max 32767
#define MaxNum 100
using namespace std;
int Mark[MaxNum];
typedef int Status;
/*************ͼ�Ĵ洢�ṹ*****************/ 
typedef int VexNameType;
//�߽��� 
typedef struct ArcNode{
	struct ArcNode *next;
	int adjvex;
}ArcNode; 
//����˳������ 
typedef struct{
	VexNameType vex;
	ArcNode *FirstArcNode;
}VexNode,AdjList[MaxNum];
//ͼ 
typedef struct{
	AdjList vertices;
	int VexNum,ArcNum;
}Graph;

/**************���еĴ洢�ṹ****************/
typedef int QueueElemtype; 
typedef struct QueueNode{
	struct QueueNode *next;
	QueueElemtype data;
}QueueNode,*QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rare;
}LinkQueue;

/**************���еĻ�������****************/
//�ж��Ƿ�Ϊ�� 
Status Queue_is_Empty(LinkQueue Q)
{
	if(Q.front == Q.rare) return 1;
	else return 0;
}

//��� 
Status InQueue(LinkQueue &Q,QueueElemtype e)
{
	QueueNode *q;
	q = new QueueNode;
	q->data = e;
	q->next = NULL;
	Q.rare->next = q;
	Q.rare = q; 
	return OK;
}
//���� 
Status DeQueue(LinkQueue &Q,QueueElemtype &e)
{
	QueueNode *q;
	if(Q.front == Q.rare) return ERROR;
	e = Q.front->next->data;
	q = Q.front->next;
	Q.front->next = Q.front->next->next;
	if(Q.rare == q) Q.rare = Q.front;//���һ����㱻ɾ������Ϊ�� 
	//bug cache:"if(Q.rare = q) Q.rare = Q.front;"
	delete q;
	return OK;
}
//��ʼ�� 
int InitQueue(LinkQueue &Q)
{
	Q.front = Q.rare =  new QueueNode;
	Q.front->next = NULL;
	return OK; 
}

/**************ͼ�Ļ�������****************/
//��λ���� 
int LocateVex(Graph G,VexNameType V)
{
	for(int i = 1;i<=G.VexNum;i++)
	{
		if(G.vertices[i].vex == V) return i;
	}
}
//����ͼ(���ڽ��������ʽ) 
int Creat_Graph(Graph &G)
{
	cout<<"�����붥�����ͱߵ���Ŀ"<<endl; 
	cin>>G.VexNum>>G.ArcNum;
	cout<<"�����붥������֣��Կո��������"<<endl; 
	for(int i = 1;i<=G.VexNum;i++)
	{
		cin>>G.vertices[i].vex;
		G.vertices[i].FirstArcNode = NULL;
	}
	cout<<"���������������֮�����ϵ��"<<endl; 
	cout<<"������:"<<endl;
	cout<<"��� �յ㣨�Կո������"<<endl; 
	for(int i = 1;i<=G.ArcNum;i++)
	{
		VexNameType v1,v2;
		int p1,p2;
		int w;
		cin>>v1>>v2;
		p1 = LocateVex(G,v1); //�õ�p1��Ӧ�ı�ͷ������ 
		p2 = LocateVex(G,v2);
		/*������б�*/
		/*ǰ�巨*/ 
		ArcNode *temp1;
		temp1 = new ArcNode;
		temp1->adjvex = p2;
		temp1->next = G.vertices[p1].FirstArcNode;
		G.vertices[p1].FirstArcNode = temp1;
		
		ArcNode *temp2;
		temp2 = new ArcNode;
		temp2->adjvex = p1;
		temp2->next = G.vertices[p2].FirstArcNode;
		G.vertices[p2].FirstArcNode = temp2;
	}
}
//DFS������ͨͼ 
void DFS(Graph G,int v)
{
	ArcNode *p;
	cout<<G.vertices[v].vex;
	Mark[v] = 1;
	p = G.vertices[v].FirstArcNode;
	while(p != NULL)
	{
		int w = p->adjvex;
		if(!Mark[w]) DFS(G,w);
		p = p->next;	
	}
}
//DFS�������ͨͼ
void DFS_For_nuLinkMap(Graph G)
{
	for(int i=1;i <= G.VexNum;i++)
	{
		if(!Mark[i]) DFS(G,i);
	}
}

//DFS������ͨͼ 
void BFS(Graph G,int i)
{
	LinkQueue Q;
	InitQueue(Q);
	QueueElemtype e;
	ArcNode *p;
	cout<<G.vertices[i].vex;
	Mark[i] = 1;
	InQueue(Q,i);
	while(!Queue_is_Empty(Q))
	{
		DeQueue(Q,e);
		p = G.vertices[e].FirstArcNode;
		while(p!=NULL)
		{
			if(!Mark[p->adjvex])
			{
				cout<<G.vertices[p->adjvex].vex;
				Mark[p->adjvex] = 1;
				InQueue(Q,p->adjvex);
			}
			p = p->next;	
		}
	}
}

//DFS�������ͨͼ 
void BFS_for_UnLinkMap(Graph G)
{
	for(int i=1;i <= G.VexNum;i++)
	{
		if(!Mark[i]) BFS(G,i);
	}
}

int main()
{
	int menu;
	Graph G;
	Creat_Graph(G);
	while(true)
	{
		cout<<"��ѡ�������ʽ:"<<endl;
		cout<<"0.DFS"<<endl; 
		cout<<"1.BFS"<<endl;
		cout<<"-1.Exit"<<endl;
		cin>>menu;
		switch(menu)
		{
			case 0:{
				memset(Mark,0,sizeof(Mark));
				DFS_For_nuLinkMap(G);
				cout<<endl;
				break;
			}
			case 1:{
				memset(Mark,0,sizeof(Mark));
				BFS_for_UnLinkMap(G);
				cout<<endl;
				break;
			}
			case -1:{
				exit(0);
				break;
			}
		}
	}
	 
	return 0;
}
