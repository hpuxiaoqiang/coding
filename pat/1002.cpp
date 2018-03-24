#include <stdio.h>
int main()
{
	int show(int n);
	char n;
	int sum;
	while(scanf("%c",&n)&&n!='\n')
	{
		int cToi;
		cToi = n - '0';
		sum+=cToi;
	}
	if(sum/100){
		show(sum/100);
		printf(" ");	
	}
	if(sum/10%10)
	{
		show(sum/10%10);
		printf(" ");	
	}
	show(sum%10);
	return 0;
}
int show(int n)
{
	switch(n)
	{
		case 0: printf("ling");break;
		case 1: printf("yi");break;
		case 2:	printf("er");break;
		case 3:	printf("san");break;
		case 4:	printf("si");break;
		case 5:	printf("wu");break;
		case 6:	printf("liu");break;
		case 7:	printf("qi");break;
		case 8:	printf("ba");break;
		case 9:	printf("jiu");break;
		default :break;
	}
}
