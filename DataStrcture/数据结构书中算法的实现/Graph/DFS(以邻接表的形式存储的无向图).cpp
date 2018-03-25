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
	struct ArcNode *NextArc;//ָ����һ���ߵĽ�� 
	int adjVex;//�ñߵĶ��� 
	OtherInfo info;//�洢������Ϣ,����ߵ�Ȩֵ 
}ArcNode;

typedef struct{
		VexNameType vex;//��������� 
		ArcNode *firstvex;//��ͷ������ָ��ĵ�һ���߽�� 
}VexNode,AdjList[MaxNum];

typedef struct{
	AdjList vertices;
	int vexnum,arcnum;
}Graph;

//��λ������ 
int LocateVex(Graph G,VexNameType V)
{
	for(int i = 1;i <= G.vexnum;i++)
	{
		if(G.vertices[i].vex == V) return i;
	}
}
//���ڽӱ�洢ͼ 
int Creat_Graph(Graph &G)
{
	cout<<"�����붥�����ͱߵ���Ŀ"<<endl; 
	cin>>G.vexnum>>G.arcnum;
	cout<<"�����붥������֣�"<<endl; 
	for(int i = 1;i <= G.vexnum;i++)
	{
		
		cin>>G.vertices[i].vex;
		G.vertices[i].firstvex = NULL;
	}
	cout<<"���������� �����֮�����ϵ��"<<endl; 
	cout<<"����������յ�ͱߵ�Ȩ���Կո��������"<<endl;
	for(int i = 1;i <= G.arcnum;i++)
	{ 
		VexNameType v1,v2;
		ArcNode *temp1,*temp2;
		int p1,p2;
		int w;
		cin>>v1>>v2>>w;
		p1 = LocateVex(G,v1); //�õ�p1��Ӧ�ı�ͷ������ 
		p2 = LocateVex(G,v2);
		/*������б�*/
		/*ǰ�巨*/ 
		temp1 = new ArcNode;
		temp1->adjVex = p2;
		temp1->NextArc = G.vertices[p1].firstvex;
		G.vertices[p1].firstvex = temp1;
		
		temp2 = new ArcNode;
		temp2->adjVex = p1;
		temp2->NextArc = G.vertices[p2].firstvex;
		G.vertices[p2].firstvex = temp2;//һ��Сbug,����ճ���ǵĻ� G.vertices[p1].firstvex = temp2
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

//��������ͨͼ 
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
