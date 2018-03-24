#include <stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i = 1;i <= n/100;i++)
		{
			printf("B");
		}
		for(int i =1;i <=((n/10)%10);i++)
		{
			printf("S");
		}
		for(int i =1;i<=n%10;i++)
		{
			printf("%d",i);
		}
		printf("\n");
	}
	return 0;
}
