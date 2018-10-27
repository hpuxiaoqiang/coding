#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define OK 1
#define ERROR 0
#define Max 32767
#define MaxNum 100
typedef int OtherInfo;
typedef char VexNameType;

int Mark[MaxNum]; 

typedef struct ArcNode{
	struct ArcNode *NextArc;//指向下一条边的结点 
	int adjVex;//该边的顶点 
	OtherInfo info;//存储其他信息,比如边的权值 
}ArcNode;

typedef struct{
		VexNameType vex;//顶点的名字 
		ArcNode *firstvex;//表头链表结点指向的第一个边结点 
}VexNode,AdjList[MaxNum];

typedef struct{
	AdjList vertices;
	int vexnum,arcnum;
}Graph;

//定位点的序号 
int LocateVex(Graph G,VexNameType V)
{
	for(int i = 1;i <= G.vexnum;i++)
	{
		if(G.vertices[i].vex == V) return i;
	}
}
//以邻接表存储图 
int Creat_Graph(Graph &G)
{
	cout<<"请输入顶点数和边的数目"<<endl; 
	cin>>G.vexnum>>G.arcnum;
	cout<<"请输入顶点的名字："<<endl; 
	for(int i = 1;i <= G.vexnum;i++)
	{
		
		cin>>G.vertices[i].vex;
		G.vertices[i].firstvex = NULL;
	}
	cout<<"接下来建立 点与点之间的联系！"<<endl; 
	cout<<"请输入起点终点和边的权（以空格隔开）："<<endl;
	for(int i = 1;i <= G.arcnum;i++)
	{ 
		VexNameType v1,v2;
		ArcNode *temp1,*temp2;
		int p1,p2;
		int w;
		cin>>v1>>v2>>w;
		p1 = LocateVex(G,v1); //得到p1对应的表头结点序号 
		p2 = LocateVex(G,v2);
		/*插入边列表*/
		/*前插法*/ 
		temp1 = new ArcNode;
		temp1->adjVex = p2;
		temp1->NextArc = G.vertices[p1].firstvex;
		G.vertices[p1].firstvex = temp1;
		
		temp2 = new ArcNode;
		temp2->adjVex = p1;
		temp2->NextArc = G.vertices[p2].firstvex;
		G.vertices[p2].firstvex = temp2;//一个小bug,复制粘贴惹的祸 G.vertices[p1].firstvex = temp2
	}
}

void DFS(Graph G,int i)
{
	cout<<G.vertices[i].vex;
	Mark[i] = 1;
	ArcNode *p;
	p = G.vertices[i].firstvex;
	while(p!=NULL){
		int w = p->adjVex;
		if(!Mark[w]) DFS(G,w);
		p = p->NextArc;
	}	
}

//遍历非连通图 
void DFS_Tarverse(Graph G)
{
	for(int i = 1;i <=G.vexnum;i++)
	{
		if(!Mark[i]) DFS(G,i);
	}
	
}
int main()
{
	Graph G;
	memset(Mark,0,sizeof(Mark));
	Creat_Graph(G);
	DFS_Tarverse(G); 
	return 0;
}
