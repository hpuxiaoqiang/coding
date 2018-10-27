#include <iostream> 
#include <cstdio>
#include <cstring>
using namespace std;

#define OK 1
#define MaxInt 32767 
#define MaxVNum 100

typedef char VerTexType;
typedef int ArcType;

typedef struct{
	VerTexType Ver[MaxVNum];//顶点表 
	ArcType arcs[MaxVNum][MaxVNum];//邻接矩阵 
	int vernum,arcnum;	//当前顶点数和边数 
}Graph;

int LocateVer(Graph G,VerTexType ch)
{
	for(int i = 0;i< G.vernum;i++)
	{
		if(G.Ver[i] == ch) return i;
	}
}


int Creat_Graph(Graph &G){
	cin>>G.vernum>>G.arcnum;//输入总的顶点数和边数; 
	for(int i = 0;i< G.vernum;i++)
	{
		for(int j = 1;j< G.arcnum;j++)
		{
			G.arcs[i][j] = MaxInt;
		}
	}
	for(int i = 0;i< G.arcnum;i++)//构造邻接矩阵,按照边的多少来输入;
	{
		VerTexType v1,v2;
		int w;
		cin>>v1>>v2>>w;//输入边的两个点的名字和这条边的权值 
		int num1 = 	LocateVer(G,v1);//找到这两个点所在的位置,即顶点表的下标 
		int num2 = LocateVer(G,v2);
		G.arcs[num1][num2] = G.arcs[num2][num1] = w;//因为还是无向图,权值一样 
	}
	return OK; 
} 

int main()
{
	Graph G;
	Creat_Graph(G);
	return 0;
}
