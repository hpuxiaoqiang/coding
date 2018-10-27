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
		flag = false;//说明本趟排序没有发生交换 
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
				lastExcahange = i;//最后一次交换的位置，下次排序到此位置结束 
			}
		}
		m = lastExcahange;//令下一次排序的循环结束条件为到上一趟排序最后一次交换位置结束 
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
	cout<<"排序后为："<<endl; 
	PutAllNum(L1);
	cout<<"总的比较次数是："<<CompareNum<<endl;
	cout<<"总的交换次数是："<<ExchangeNum<<endl;
	
	CompareNum=0;
	ExchangeNum=0;
	UpBubble(L2);
	cout<<"排序后为："<<endl; 
	PutAllNum(L2);
	cout<<"优化后总的比较次数是："<<CompareNum<<endl;
	cout<<"优化后总的交换次数是："<<ExchangeNum<<endl;
	return 0;
}
