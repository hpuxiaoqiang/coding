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
	int lowWeight;
	VerTexType adjvex;
}CloseEdge[MaxNum];
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
int Search(Graph G,CloseEdge &closeEdges)
{
		int min = Endless,minm;
		int i = 0;
		for(;i < G.vexnum;i++)
		{
			if(closeEdges[i].lowWeight != 0 && min > closeEdges[i].lowWeight)
			{
				min = closeEdges[i].lowWeight;
				minm = i;
			}
		}
		return minm;
}
void MiniSpanTree(Graph &G,VerTexType u)
{
	CloseEdge closeEdges; 
	int  k = Locate(G,u);
	for(int i = 0; i< G.vexnum ;i++)
	{
		if(i != k){
			closeEdges[i].adjvex = u;
			closeEdges[i].lowWeight = G.arcs[k][i];
		}
	}
	closeEdges[k].lowWeight = 0;
	for(int i = 1;i<G.vexnum;i++)
	{
		k = Search(G,closeEdges);
		VerTexType v0 = G.vexs[k];
		VerTexType u0 = closeEdges[k].adjvex;
		cout<<u0<<v0<<endl;
		closeEdges[k].lowWeight = 0;

		for(int i = 0;i< G.vexnum;i++)
		{
			if(G.arcs[k][i] < closeEdges[i].lowWeight)
			{
				closeEdges[i].adjvex = G.vexs[k];
				closeEdges[i].lowWeight = G.arcs[k][i];
			}
		}
	}
} 
int main()
{
	Graph G;
	Creat_Graph(G);
	VerTexType ch;
	cout<<"请输入起始顶点： "<<endl;
	cin>>ch;
	cout<<"最小生成树为： "<<endl;
	MiniSpanTree(G,ch);
	return 0;
}
