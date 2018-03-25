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

void InsertSort(SQList &L)
{
	for(int i = 2;i <= L.length;i++)
	{	
		com++;
		if(L.elem[i]<L.elem[i-1])
		{
			sum++;
			int j = 0;
			L.elem[0] = L.elem[i];
			L.elem[i] = L.elem[i-1];
			for(j = i-2;L.elem[0]<L.elem[j];j--)
			{
				com++;
				sum++;
				L.elem[j+1] = L.elem[j];
			}
			L.elem[j+1] = L.elem[0];
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
	InsertSort(L);
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
