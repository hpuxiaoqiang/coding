#include <iostream>
#define Max 128
using namespace std;
int sum = 0,com = 0;
typedef int ElemType;
typedef struct{
	ElemType *elem;
	int length;
}SQList;

void Init(SQList &L)
{
	L.elem = new ElemType[Max+1];
	L.length = 0;
} 

int Creat_List(SQList &L,int num)
{
	cout<<"Please Input "<<num<<" numbers:"<<endl;
	for(int i = 1;i <= num;i++)
	{
		cin>>L.elem[i];
		L.length++; 
	}
}
void selectSort(SQList &L)
{
	for(int i = 1;i < L.length;i++)
	{
		int k = i;
		for(int j = i+1;j <= L.length;j++)
		{
			com++;
			if(L.elem[j]<L.elem[k]) //找到L.[i------n]中最小的一个，把索引保存下来 
			{
				k = j;	
			}
		}
		if(k!=i)//看找到的是不是比L.[i]小，是则交换位置 
		{
			ElemType temp = L.elem[i];
			L.elem[i] = L.elem[k];
			L.elem[k] = temp;
			sum++;
		}
	}
}


int main()
{
	SQList L;
	Init(L);
	int num;
	cout<<"Please input the numbers of number:"<<endl;
	cin>>num;
	Creat_List(L,num);
	selectSort(L);
	cout<<"the result of sort:"<<endl;
	for(int i = 1;i <= L.length;i++)
	{
		cout<<L.elem[i]<<" "; 
	}
	cout<<endl;
	cout<<"the exchange times is "<<sum<<endl;
	cout<<"the compare times is "<<com<<endl;
	return 0;
}
