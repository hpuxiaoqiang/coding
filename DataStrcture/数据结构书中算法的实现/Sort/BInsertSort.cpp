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

void BInsertSort(SQList &L)
{
	for(int i = 2;i <= L.length;i++)
	{
		L.elem[0] = L.elem[i];
		int low = 1,high = i-1;
		while(low <= high)
		{
			int mid = (low+high)/2;
			if(L.elem[0]  < L.elem[mid])
			{
				high = mid - 1;
			}
			else
			{
				low = mid+1;
			}
		}
		for(int j = i-1;j >= high+1;j--)
		{
			L.elem[j+1] = L.elem[j];
		}
		L.elem[high+1] = L.elem[0];
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
	BInsertSort(L);
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
