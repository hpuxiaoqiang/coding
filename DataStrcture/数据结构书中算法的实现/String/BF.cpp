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
			i = i-j+2;//ƥ��ʧ�ܣ�i���ݵ���һ��λ�����¿�ʼ�ٴ�ƥ�� 
			j = 1;
		} 
	}
	if( j > T.length) return i - T.length;
	return ERROR;
}
void Creat_Sstring(Sstring &S,int len)
{
	cout<<"�����봮:"<<endl; 
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
	cout<<"�����������ĳ��ȣ�������99��:"<<endl;
	cin>>len;
	Creat_Sstring(S,len);
	cout<<"������ģʽ���ĳ��ȣ�������99��:"<<endl;
	cin>>len;
	Creat_Sstring(T,len);
	int mod = BF(S,T,1);
	cout<<"�״�ƥ��ɹ���λ���ǣ�"<<mod<<endl;
	return 0;
}
