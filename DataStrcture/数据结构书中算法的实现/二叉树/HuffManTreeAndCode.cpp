#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std; 
#define Max 128

typedef int ElemType;
typedef struct{
	int Parent;
	int Lchild;
	int Rchild;
	bool flag;
	ElemType data;
}HTNode,*HuffManTree;


typedef char **HuffManCode;
/*typedef struct{
	char *hc;
}HTCode,*HuffManCode;
*/
void Select(HuffManTree &HT,int num,int &s1,int &s2)
{
	int min1,min2;
	s1  = 0;
	s2 = 0; 
	min1 = 0;
	min2 = 0;
	/***************************/
	//先找到未被使用的两个数初始化min1和min2 
	for(int i = 1; i <= num;i++)
	{
		if(!HT[i].flag)
		{
			min1 = HT[i].data;
			s1 = i;
			break;
		}
	}
	for(int i = 1; i <= num;i++)
	{
		if(i!=s1&&!HT[i].flag)
		{
			min2 = HT[i].data;
			s2 = i;
			break;
		}
	}
	/***************************/
	//然后再在顺序表中找到未被使用的两个最小的数，返回地址 
	for(int i = 1; i <= num;i++ )
	{
		if(min1>HT[i].data&&!HT[i].flag)
		{
			min2 = min1;
			min1 = HT[i].data;
			s2 = s1;
			s1 = i;
		}
		else {
			if(min2>HT[i].data&&i!=s1&&!HT[i].flag)
			{
				min2 = HT[i].data;
				s2 = i;
			}
		}
	}
}

void Craet_HuffManTree(HuffManTree &HT,int n)
{
	if(n<1) return;
	HT = new HTNode[2*n];
	for(int i = 0;i <= 2*n-1;i++)
	{
		HT[i].flag = false;
		HT[i].Parent = HT[i].Lchild = HT[i].Rchild = 0;	
	}
	cout<<"输入结点数据:"<<endl;
	for(int i = 1; i <= n;i++)
	{
		cin>>HT[i].data;
	}
	int S1 = 0,S2 = 0; 
	for(int i = n+1; i <= 2*n-1;i++)
	{
		Select(HT,i-1,S1,S2);
		HT[S1].Parent = HT[S2].Parent = i;
		HT[S1].flag = HT[S2].flag = true;
		HT[i].Lchild = S1;
		HT[i].Rchild = S2;
		HT[i].data = HT[S1].data+HT[S2].data;
	} 
}

void Creat_HuffManCode(HuffManTree HT,HuffManCode &HC,int n)
{
	HC = new char* [n+1];
	char *cd = new char[n];
	cd[n-1] = '\0';
	for(int i = 1;i <= n;i++)
	{
		int start = n-1;
		int c = i;
		int f = HT[i].Parent;
		while(f!=0)
		{
			--start;
			if(HT[f].Lchild == c)
			{
				cd[start] = '0';	
			}else{
				cd[start] = '1';
			}
			c = f;
			f = HT[f].Parent;
		}
		HC[i] = new char[n-start];
		strcpy(HC[i],&cd[start]);
	}
	delete cd;
}

void InOrderTraverse(HuffManTree HT,int num)
{
	if(num>0)
	{
		InOrderTraverse(HT,HT[num].Lchild);
		cout<<HT[num].data<<" ";
		InOrderTraverse(HT,HT[num].Rchild);
	}
	
}
void PostOrderTraverse(HuffManTree HT,int num)
{
	if(num>0)
	{
		PostOrderTraverse(HT,HT[num].Lchild);
		PostOrderTraverse(HT,HT[num].Rchild);
		cout<<HT[num].data<<" ";
	}
	
}

int  main()
{
	int number;
	HuffManTree HT;
	HuffManCode HC;
	cout<<"输入结点数："<<endl; 
	cin>>number;
	Craet_HuffManTree(HT,number);
	cout<<"HuffManTree的最终形态为："<<endl;
	for(int i = 1;i <= 2*number-1;i++)
	{
		cout<<HT[i].data<<"\t"<<HT[i].Parent<<"\t"<<HT[i].Lchild<<"\t"<<HT[i].Rchild<<endl;
	}
	cout<<"中序遍历结果为:"<<endl;
	
	InOrderTraverse(HT,2*number-1);
	cout<<endl;
	cout<<"后序遍历结果为:"<<endl;
	PostOrderTraverse(HT,2*number-1);
	cout<<endl;
	cout<<"哈夫曼编码为："<<endl;
	Creat_HuffManCode(HT,HC,number);                     
	for(int i = 1;i<=number;i++)
	{
		cout<<HT[i].data<<":	"<<HC[i]<<endl;
	}
	return 0;
 }
 
 
 

 
