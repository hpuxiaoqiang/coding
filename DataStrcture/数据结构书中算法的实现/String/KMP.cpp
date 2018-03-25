#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define Max 1024
#define ERROR 0
using namespace std;
typedef struct{
	int length;
	char ch[Max];
}Sstring;
int next[Max];

void Get_next(Sstring T,int next[])
{
	int i = 1;
	int j = 0;
	next[1] = 0;
	while(i < T.length)
	{
		if(j == 0||T.ch[i] == T.ch[j])
		{
			++i;
			++j;
			next[i] = j;
		}else{
			j = next[j];
		}
	}
}

void get_nextval(Sstring T,int nextval[]){
	int i= 1;
	nextval[1] = 0;
	int j = 0;
	while(i < T.length)
	{
		if(j == 0||T.ch[i] == T.ch[j])
		{
			i++;
			j++;
			if(T.ch[i]!=T.ch[j]) nextval[i] = j;
			else nextval[i] = nextval[j];
		}
		else{
			j = nextval[j];
		}
	}
	
}

int KMP(Sstring S,Sstring T,int pos)
{
	if(S.length < T.length) return ERROR;
	int i = pos;
	int j = 1;
	while( i <= S.length && j <= T.length)
	{
		if( j == 0 || S.ch[i] == T.ch[j] )
		{
			i++;
			j++;
		}
		else{
			j = next[j];
		}
	}
	if(j > T.length) return i - T.length;
	return ERROR;
 } 
  
void Creat_Sstring(Sstring &S,int len)
{
	cout<<"请输入串:"<<endl;
	for(int i = 1; i <= len;i++)
	{
		cin>>S.ch[i];
		S.length++;
	}
}

int main()
{
	Sstring S,T;
	int len;
	cout<<"请输入主串的长度（不超过99）:"<<endl;
	cin>>len;
	Creat_Sstring(S,len);
	cout<<"请输入模式串的长度（不超过99）:"<<endl;
	cin>>len;
	Creat_Sstring(T,len);
	Get_next(T,next);
	int mod = KMP(S,T,1);
	cout<<"首次匹配成功的位置是："<<mod<<endl;
	return 0;
}
