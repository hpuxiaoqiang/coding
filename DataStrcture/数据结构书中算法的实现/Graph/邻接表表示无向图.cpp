#include <iostream>
#include <cstdio>
#include <cstring>
#define OK 1
#define ERROR 0
#define MaxNum 100
using namespace std;
typedef  int OtherInfo;
typedef char VexName;

//vertics ����,��ߵ�;adjective ���ڵ� 

//�ڽӵ� 
typedef struct ArcNode{
	int FirstVex;//ǰһ���ڵ����� 
	struct ArcNode *nextVex;//ָ����һ���߽ڵ� 
	OtherInfo info;//ÿһ���ڵ�洢��������Ϣ,����ߵ�Ȩֵ	
}ArcNode; 

//���� 
typedef struct VexNode{
	VexName data;//�ڵ������
	ArcNode *FirstArcNode;//����ĵ�һ�����ڽڵ� 
}VexNode,MapSqList[MaxNum];//ֱ����typedefһ���ṹ������, �Ͳ���Ҫ�����new��Init�� 

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
	MapSqList vertics;//�洢�����˳��� 
	int vexnum,arcnum;//��ǰ�ĵ����ͱ��� 
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
		//ȷ��v1,v2��ͼG�е�λ��,ʵ�ʾ��� vertics��������; 
		OredrNumber1 = LocateVex(G,v1);
		OredrNumber2 = LocateVex(G,v2);
		ArcNode *p1 = new ArcNode;
		ArcNode *p2 = new ArcNode;
		
		//���ڽӵ���뵽�߱� 
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
