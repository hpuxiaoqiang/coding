#include <iostream>
#include <cstring>
#include <cstdio>

#define OK 1
#define ERROR 0
#define MaxNum 100
#define Max 32767

using namespace std;

typedef char VexNameType;
typedef int ArcType;
int Mark[MaxNum];

typedef struct {
	VexNameType vexs[MaxNum];//顶点表,点的名字集合 
	ArcType arcs[MaxNum][MaxNum];//邻接矩阵 
	int VexNum,ArcNum;//当前点数，边数 
}Graph;

//得到当前顶点的序号 
int LocateVex(Graph G,VexNameType v)
{
	for(int i = 1;i<= G.VexNum;i++)
	{
		if(G.vexs[i] == v) return i;
	}
}


//以邻接矩阵的方式存储,构建带权无向图 
int Creat_Graph(Graph &G)
{
	cout<<"请输入顶点个数和边的个数："<<endl; 
	cin>>G.VexNum>>G.ArcNum;
	cout<<"请输入顶点名字:"<<endl;
	for(int i = 1; i<=G.VexNum;i++ )
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
	cout<<"接下来将建立顶点与顶点的联系！"<<endl;
	cout<<"请输入边的起点名字，终点名字，边的权值（以空格间隔）："<<endl; 
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

//得到的顶点第一个邻接的点序号 
int FirstAdjVex(Graph G,int V)
{
	for(int i = 1;i<=G.VexNum;i++)
	{
		if(G.arcs[V][i]<Max) return i;
	}
	return ERROR;
}

//得到相对于w,V的下一个邻接点的序号 
int NextAdjVex(Graph G,int V,int w)
{
	for(int i =w+1;i<=G.VexNum;i++)
	{
		if(G.arcs[V][i]<Max) return i;
	}
	return ERROR;
}

//DFS连通图 
void DFS(Graph G,int Vnum)
{
	cout<<G.vexs[Vnum];
	Mark[Vnum] = 1;
	for(int w = FirstAdjVex(G,Vnum);w>=1;w = NextAdjVex(G,Vnum,w))
	{
		if(!Mark[w]) DFS(G,w);
	}	
}

//DFS非连通图 
void DFS_For_UnlinkMap(Graph G)
{
	for(int i =1;i<=G.VexNum;i++)
	{
		if(!Mark[i]) DFS(G,i);
	}
}

int main()
{
	Graph G;
	memset(Mark,0,sizeof(Mark));
	Creat_Graph(G);
	cout<<"DFS遍历结果为:"<<endl;
	DFS_For_UnlinkMap(G);
	return 0;
}
