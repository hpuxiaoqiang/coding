#include <iostream>
using namespace std;
#define Max 128
typedef int ElemType;
int sum = 0;

typedef struct 
{
	ElemType *num;
	int Length;
}SQList;

void Show(SQList L)
{
	for(int i =1;i<=L.Length;i++)
	{
		cout<<L.num[i]<<" ";
	}
	cout<<endl;
}
int Partition(SQList &L,int low,int high)
{
	int privotkey = L.num[low];
	L.num[0] = L.num[low];
	while(low < high)
	{
		while(low < high && L.num[high] >= privotkey)
		{
			high--;
		}
		L.num[low] = L.num[high];
		L.num[high] = 0;
//		Show(L);
		sum++;
		while(low < high && L.num[high] <= privotkey)
		{
			low++;
		}
		L.num[high] = L.num[low];
		L.num[low] = 0;
		cout<<"一次交换之后："<<endl;
		Show(L);
		sum++; 
	}
	L.num[low] = L.num[0];
	return low;
}

void QSort(SQList &L,int low,int high)
{
	if(low < high )
	{
		int prvotloc = Partition(L,low,high);
		QSort(L,low,prvotloc-1);
		QSort(L,prvotloc+1,high);
	}
}

void Init(SQList &L)
{
	L.num = new ElemType[Max+1]; 
	L.Length = 0;
	if(L.num == NULL) 
	{
		cout<<"Init Faild!"<<endl;
		exit(0);
	}
}

void Creat_SQList(SQList &L)
{
	int num;
	cin>>num;
	for(int i = 1;i <= num;i++ )
	{
		cin>>L.num[i];
		L.Length++; 
	}
}

int main()
{
	SQList L;
	Init(L);
	Creat_SQList(L);
	QSort(L,1,L.Length);
	Show(L);
	cout<<sum/2;
	return 0;
}
