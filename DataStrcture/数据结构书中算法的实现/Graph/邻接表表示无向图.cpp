#include <iostream>
#include <cstdio>
#include <cstring>
#define OK 1
#define ERROR 0
#define MaxNum 100
using namespace std;
typedef  int OtherInfo;
typedef char VexName;

//vertics 顶点,最高点;adjective 相邻的 

//邻接点 
typedef struct ArcNode{
	int FirstVex;//前一个节点的序号 
	struct ArcNode *nextVex;//指向下一个边节点 
	OtherInfo info;//每一个节点存储的其他信息,比如边的权值	
}ArcNode; 

//顶点 
typedef struct VexNode{
	VexName data;//节点的名字
	ArcNode *FirstArcNode;//顶点的第一个相邻节点 
}VexNode,MapSqList[MaxNum];//直接用typedef一个结构体数组, 就不需要下面的new和Init了 

/*
typedef struct {
	VexNode *elem;
	int VexNodeNum;
}MapSqList;
int Init(MapSqList &SqM)
{
	SqM.elem = new VexNode[MaxNum];
	if(!SqM.elem) return ERROR;
	SqM.VexNodeNum = 0
	return OK;
}*/

typedef struct{
	MapSqList vertics;//存储顶点的顺序表 
	int vexnum,arcnum;//当前的点数和边数 
}ArcGraph; 

int LocateVex(ArcGraph G,VexName v)
{
	for(int i = 0;i<G.vexnum;i++)
	{
		if(G.vertics[i].data == v) return i;
	}
}

void Creat_Graph(ArcGraph G)
{
	cin>>G.vexnum>>G.arcnum;
	for(int i= 1;i<=G.vexnum;i++)
	{
		cin>>G.vertics[i].data;
		G.vertics[i].FirstArcNode = NULL;	
	}
	for(int i =0;i<G.arcnum;i++)
	{
		VexName v1,v2;
		cin>>v1>>v2;
		int OredrNumber1,OredrNumber2;
		//确定v1,v2在图G中的位置,实际就是 vertics数组的序号; 
		OredrNumber1 = LocateVex(G,v1);
		OredrNumber2 = LocateVex(G,v2);
		ArcNode *p1 = new ArcNode;
		ArcNode *p2 = new ArcNode;
		
		//将邻接点插入到边表 
		p1->FirstVex = OredrNumber1;
		p1->nextVex = G.vertics[OredrNumber1].FirstArcNode;
		G.vertics[OredrNumber1].FirstArcNode = p1;
		
		p2->FirstVex = OredrNumber2;
		p2->nextVex = G.vertics[OredrNumber2].FirstArcNode;
		G.vertics[OredrNumber2].FirstArcNode = p2;
	}	
} 

int main()
{
	ArcGraph G;
	Creat_Graph(G)	;
	return 0;
}
