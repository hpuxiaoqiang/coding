#include <iostream>
#include <cctype>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int n ;
	cin>>n;
	getchar();
	for (int i = 0;i< n;i++)
	{
		string str;
		getline(cin,str);
		int len = str.length();
		if(len <6) cout<<"Your password is tai duan le."<<endl;
		else
		{
			int num = 0,zimu = 0,others = 0;
			for(int i = 0;i<len;i++)
			{
				if(str[i]>='0' && str[i] <= '9')    num++;  
                else if(str[i]>='a' && str[i] <= 'z')   zimu++;  
                else if(str[i]>='A' && str[i] <= 'Z')   zimu++;  
                else if(str[i] == '.');  
                else others++;  
			}
			if(others != 0 )    cout << "Your password is tai luan le." << endl;  
            else if(zimu == 0)  cout << "Your password needs zi mu." << endl;  
            else if(num == 0) cout << "Your password needs shu zi." << endl;  
            else    cout << "Your password is wan mei."<<endl;  
		}
	}
	return 0;
}
 
