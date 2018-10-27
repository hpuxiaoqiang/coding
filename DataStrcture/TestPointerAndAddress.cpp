#include <iostream>
using namespace std; 
int main()
{
	int a[5] = {0,1,2,3,4};
	int *p;
	p = a+2;
	
	cout<<(a+4)-a<<endl;
	cout<<*a+1<<endl;
	cout<<*(a+2)<<endl;
	cout<<*a+3<<endl;
	cout<<*a+4<<endl;	
	cout<<"---------"<<endl; 
	cout<<p-1<<endl;
//	cout<<(p+1)-p<<endl;
//	cout<<p+1<<endl;
//	cout<<p+2<<endl;
//	cout<<p+3<<endl;
//	cout<<p+4<<endl;
	return 0;
 } 
