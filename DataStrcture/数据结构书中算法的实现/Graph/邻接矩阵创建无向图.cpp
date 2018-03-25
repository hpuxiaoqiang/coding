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
	VerTexType Ver[MaxVNum];//����� 
	ArcType arcs[MaxVNum][MaxVNum];//�ڽӾ��� 
	int vernum,arcnum;	//��ǰ�������ͱ��� 
}Graph;

int LocateVer(Graph G,VerTexType ch)
{
	for(int i = 0;i< G.vernum;i++)
	{
		if(G.Ver[i] == ch) return i;
	}
}


int Creat_Graph(Graph &G){
	cin>>G.vernum>>G.arcnum;//�����ܵĶ������ͱ���; 
	for(int i = 0;i< G.vernum;i++)
	{
		for(int j = 1;j< G.arcnum;j++)
		{
			G.arcs[i][j] = MaxInt;
		}
	}
	for(int i = 0;i< G.arcnum;i++)//�����ڽӾ���,���ձߵĶ���������;
	{
		VerTexType v1,v2;
		int w;
		cin>>v1>>v2>>w;//����ߵ�����������ֺ������ߵ�Ȩֵ 
		int num1 = 	LocateVer(G,v1);//�ҵ������������ڵ�λ��,���������±� 
		int num2 = LocateVer(G,v2);
		G.arcs[num1][num2] = G.arcs[num2][num1] = w;//��Ϊ��������ͼ,Ȩֵһ�� 
	}
	return OK; 
} 

int main()
{
	Graph G;
	Creat_Graph(G);
	return 0;
}
