#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int sum[100+1];
	int *problems = (int*)malloc(sizeof(int)*(m+1));
	int *answers = (int*)malloc(sizeof(int)*(m+1));
	memset(sum,0,sizeof(sum));
	for(int i = 1;i<=m;i++ )
	{
		scanf("%d",problems+i);
	}
	for(int i = 1;i<=m;i++ )
	{
		scanf("%d",answers+i);
	}
	for(int j =1;j<=n;j++)
	{
		for(int i =1;i<= m;i++)
		{
			int ans = 0;
			scanf("%d",&ans);
			if(ans == *(answers+i) )
			{
				sum[j] = sum[j] + (*(problems+i));
			}
		}
	}
	for(int i = 1;i<= n;i++)
	{
		printf("%d\n",sum[i]);
	}
	free(problems);
	free(answers)
;	return 0;
}
