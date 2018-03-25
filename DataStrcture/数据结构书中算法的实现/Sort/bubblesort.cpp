#include <iostream>
using namespace std;

#define Max 100
#define OK 1
typedef int ElemType;
typedef struct{
	ElemType *elem;
	int length;
}SqList;

int CompareNum = 0;
int ExchangeNum = 0;

int Init(SqList &L)
{
	L.elem = new ElemType[Max];
	if(!L.elem) 
	{
		cout<<"Initialize SqList Fail"<<endl;
		exit(0);
	}
	L.length = 0;
	return OK;
}

void Creat_SqList(SqList &L)
{
	int num;
	cout<<"Please input the number of number"<<endl;
	cin>>num;
	cout<<"Please input the number:"<<endl;
	for(int i = 1;i<=num;i++)
	{
		cin>>L.elem[i];
		L.length++;
	}
}

void Bubble(SqList &L)
{
	for(int i = 1;i <= L.length-1;i++ )
	{
		for(int j = 1; j <= L.length-i;j++)
		{
			CompareNum++;
			if(L.elem[j]>L.elem[j+1]) 
			{
				ElemType temp;
				temp = L.elem[j];
				L.elem[j] = L.elem[j+1];
				L.elem[j+1] = temp;
				ExchangeNum++;
			}
		}
	}
}

void CopySqList(SqList &L1,SqList &L2)
{
	L2.length = L1.length;
	for(int i = 1;i<=L1.length;i++)
	{
		L2.elem[i] = L1.elem[i];
	}
}

void UpBubble(SqList &L)
{
	int lastExcahange;
	int m = L.length;
	bool flag = true;
	while(m>1&&flag)
	{
		flag = false;//˵����������û�з������� 
		for(int i = 1;i<m;i++)
		{
			CompareNum++;
			if(L.elem[i]>L.elem[i+1]) 
			{
				flag = true;
				ElemType temp;
				temp = L.elem[i];
				L.elem[i] = L.elem[i+1];
				L.elem[i+1] = temp;
				ExchangeNum++;
				lastExcahange = i;//���һ�ν�����λ�ã��´����򵽴�λ�ý��� 
			}
		}
		m = lastExcahange;//����һ�������ѭ����������Ϊ����һ���������һ�ν���λ�ý��� 
	}
}


void PutAllNum(SqList L)
{
	for(int i = 1;i<=L.length;i++)
	{
		cout<<L.elem[i]<<" ";	
	}
	cout<<endl;
}

int main()
{
	SqList L1,L2;
	Init(L1);
	Init(L2);
	Creat_SqList(L1);
	CopySqList(L1,L2);
	Bubble(L1);
	cout<<"�����Ϊ��"<<endl; 
	PutAllNum(L1);
	cout<<"�ܵıȽϴ����ǣ�"<<CompareNum<<endl;
	cout<<"�ܵĽ��������ǣ�"<<ExchangeNum<<endl;
	
	CompareNum=0;
	ExchangeNum=0;
	UpBubble(L2);
	cout<<"�����Ϊ��"<<endl; 
	PutAllNum(L2);
	cout<<"�Ż����ܵıȽϴ����ǣ�"<<CompareNum<<endl;
	cout<<"�Ż����ܵĽ��������ǣ�"<<ExchangeNum<<endl;
	return 0;
}
