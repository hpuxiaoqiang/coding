#include <iostream>
#include <cstdio>
#include <cstring> 
#define MaxSize 100
#define ERROR 0
using namespace std;
typedef struct {
	int length = 0;
	char str[MaxSize];	
}Sstring;
int BF(Sstring S,Sstring T,int pos){
	int i = pos;
	int j = 1;
	if(S.length < T.length) return ERROR; 
	while(i <= S.length && j <= T.length)
	{
		if(S.str[i] == T.str[j])
		{
			i++;
			j++;
		}else{
			i = i-j+2;//匹配失败，i回溯到下一个位置重新开始再次匹配 
			j = 1;
		} 
	}
	if( j > T.length) return i - T.length;
	return ERROR;
}
void Creat_Sstring(Sstring &S,int len)
{
	cout<<"请输入串:"<<endl; 
	for(int i = 1; i <= len;i++)
	{
		cin>>S.str[i];
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
	int mod = BF(S,T,1);
	cout<<"首次匹配成功的位置是："<<mod<<endl;
	return 0;
}
