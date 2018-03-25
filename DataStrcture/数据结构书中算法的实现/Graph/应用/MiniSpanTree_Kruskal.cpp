#include <iostream> 
#include <cstdio>
#include <cstring>
using namespace std;
#define OK 1
#define ERROR 0
#define Endless 32767
#define MaxNum 60
typedef int ArcType;
typedef char VerTexType;
typedef struct {
	VerTexType vexs[MaxNum];
	ArcType arcs[MaxNum][MaxNum];
	int vexnum,arcnum;
}Graph;
typedef struct Edge{
	VerTexType Head;
	VerTexType Tail;
	int weight;
}Edge,CloseEdge[MaxNum];
int Locate(Graph &G,char ad)
{
	for(int i = 0;i <= G.vexnum;i++)
	{
		if(G.vexs[i] == ad) return i;
	}
}
void Creat_Graph(Graph &G)
{
	int Vnum,Anum;
	cout<<"Please input the number of VerTex and Arc:"<<endl;
	cin>>Vnum>>Anum;
	G.vexnum = Vnum;
	G.arcnum = Anum;
	for(int i = 0;i < G.vexnum;i++ )
	{
		cout<<"Please input the name of VerTex"<<endl;
		cin>>G.vexs[i];
	}
	for(int i = 0; i < G.vexnum;i++)
	{
		for(int j = 0;j < G.vexnum;j++)
		{
			G.arcs[i][j] = Endless;
		}
	}
	char vex1,vex2;
	int weight;
	for(int i = 0;i < G.arcnum;i++)
	{
		cout<<"请输入边的顶点和权值： "<<endl;
		cin>>vex1>>vex2>>weight;	
		int ad1 = Locate(G,vex1);
		int ad2 = Locate(G,vex2);
		G.arcs[ad1][ad2] = G.arcs[ad2][ad1] = weight;
	}
}
void Sort(Graph G,CloseEdge &edge)
{
	for(int i = 0;i < G.arcnum;i++)
	{
		for(int j =0;j< G.arcnum-i ;j++)
		{
			if(edge[j].weight>edge[j+1].weight)
			{
				Edge temp;
				temp = edge[j];
				edge[j] = edge[j+1];
				edge[j+1] = temp;
			}
		}
	}
}
void MiniSpanTree_Kruskal(Graph &G)
{
	int VexSet[MaxNum];
	CloseEdge edge;
	int k =0;
	for(int j = 0;j<G.vexnum;j++)
	{
		for(int i = 0;i<G.vexnum;i++)
		{
			if(i>=j&&G.arcs[i][j]<Endless)
			{
				edge[k].Head = G.vexs[j];
				edge[k].Tail = G.vexs[i];
				edge[k].weight = G.arcs[j][i];
				k++;
			}
		}
	}
	for(int k = 0;k<G.arcnum;k++)
	{
		cout<<edge[k].Head<<" "<<edge[k].Tail<<" "<<edge[k].weight<<endl;
	}
	Sort(G,edge);
	
	for(int i = 1;i<G.vexnum;i++)
	{
		VexSet[i] = i;
	}
	for(int i =0;i<G.arcnum;i++)
	{
		int v1 = Locate(G,edge[i].Head);
		int v2 = Locate(G,edge[i].Tail);
		int vs1 = VexSet[v1];
		int vs2 = VexSet[v2];
		if(vs1 != vs2)
		{
			cout<<edge[i].Head<<" "<<edge[i].Tail<<endl;
			for(int j = 0;j < G.vexnum;j++)
			{
				if(VexSet[j] == vs2) VexSet[j] = vs1;
			}
		}
	}
}
int main()
{
	Graph G;
	Creat_Graph(G);
	cout<<"最小生成树为："<<endl;
	MiniSpanTree_Kruskal(G);
	return 0;
 } 
