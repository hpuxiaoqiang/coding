#include <iostream>
#include <cstdio>
#include <cstring>
#define ERROR 0
#define MaxSize 1000
using namespace std;
typedef struct {
	char ch[MaxSize];
	int length = 0;
}SString;
int Index_KMP(SString strKey,SString str,int next[])
{
	int i = 0;
	int j = 0;
	while(i < str.length-1 && j < strKey.length-1)
	{
		if(str.ch[i]==strKey.ch[j] || j == 0 )
		{
			i++;
			j++;
		}else{
			j = next[j];
		}
	 } 
	if(j > strKey.length) return i - strKey.length;
	return ERROR; 
}
void GetNext(SString strKey,int next[])
{
	int k = -1;
	int j = 0;
	next[0] = 0;
	while( j < strKey.length -1  )
	{
		if(strKey.ch[j] == strKey.ch[k] || k == -1){
			next[++j] = ++k;
		}else{
			k = next[k];
		}
	 } 
 }
void Input_str(SString str)
{
	int i = 0;
	char c;
	cin>>c;
	while(c!= '#')
	{
		str.length++;
		str.ch[i] = c;
		cin>>c;
		i++;	
	}
	
 } 
int main()
{
	SString strKey;
	SString str;
	int next[MaxSize];
	cout<<"Please inout the str(End with \"#\"):"<<endl;
	Input_str(str);
	cout<<"Please inout the strKey(End with \"#\"):"<<endl;
	Input_str(strKey);
	GetNext(strKey,next);
	cout<< Index_KMP(strKey,str,next)<<endl;
	return 0;
}
