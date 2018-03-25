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
/*************图的存储结构*****************/ 
typedef int VexNameType;
//边结点表 
typedef struct ArcNode{
	struct ArcNode *next;
	int adjvex;
}ArcNode; 
//顶点顺序链表 
typedef struct{
	VexNameType vex;
	ArcNode *FirstArcNode;
}VexNode,AdjList[MaxNum];
//图 
typedef struct{
	AdjList vertices;
	int VexNum,ArcNum;
}Graph;

/**************队列的存储结构****************/
typedef int QueueElemtype; 
typedef struct QueueNode{
	struct QueueNode *next;
	QueueElemtype data;
}QueueNode,*QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rare;
}LinkQueue;

/**************队列的基本操作****************/
//判断是否为空 
Status Queue_is_Empty(LinkQueue Q)
{
	if(Q.front == Q.rare) return 1;
	else return 0;
}

//入队 
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
//出队 
Status DeQueue(LinkQueue &Q,QueueElemtype &e)
{
	QueueNode *q;
	if(Q.front == Q.rare) return ERROR;
	e = Q.front->next->data;
	q = Q.front->next;
	Q.front->next = Q.front->next->next;
	if(Q.rare == q) Q.rare = Q.front;//最后一个结点被删除，队为空 
	//bug cache:"if(Q.rare = q) Q.rare = Q.front;"
	delete q;
	return OK;
}
//初始化 
int InitQueue(LinkQueue &Q)
{
	Q.front = Q.rare =  new QueueNode;
	Q.front->next = NULL;
	return OK; 
}

/**************图的基本操作****************/
//定位顶点 
int LocateVex(Graph G,VexNameType V)
{
	for(int i = 1;i<=G.VexNum;i++)
	{
		if(G.vertices[i].vex == V) return i;
	}
}
//创建图(以邻接链表的形式) 
int Creat_Graph(Graph &G)
{
	cout<<"请输入顶点数和边的数目"<<endl; 
	cin>>G.VexNum>>G.ArcNum;
	cout<<"请输入顶点的名字（以空格隔开）："<<endl; 
	for(int i = 1;i<=G.VexNum;i++)
	{
		cin>>G.vertices[i].vex;
		G.vertices[i].FirstArcNode = NULL;
	}
	cout<<"接下来建立点与点之间的联系！"<<endl; 
	cout<<"请输入:"<<endl;
	cout<<"起点 终点（以空格隔开）"<<endl; 
	for(int i = 1;i<=G.ArcNum;i++)
	{
		VexNameType v1,v2;
		int p1,p2;
		int w;
		cin>>v1>>v2;
		p1 = LocateVex(G,v1); //得到p1对应的表头结点序号 
		p2 = LocateVex(G,v2);
		/*插入边列表*/
		/*前插法*/ 
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
//DFS无向连通图 
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
//DFS无向非连通图
void DFS_For_nuLinkMap(Graph G)
{
	for(int i=1;i <= G.VexNum;i++)
	{
		if(!Mark[i]) DFS(G,i);
	}
}

//DFS无向连通图 
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

//DFS无向非连通图 
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
		cout<<"请选择遍历方式:"<<endl;
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
