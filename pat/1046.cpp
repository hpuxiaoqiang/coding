#include <stdio.h>
int main()
{
	int n;
	int sum1 = 0,sum2 = 0;
	scanf("%d",&n);
	while(n--)
	{
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		if(y1 != y2)
		{
			if((x1+x2) == y1)
			{
				sum2++;
			}
			else if ((x1+x2) == y2)
			{
				sum1++;
			}
		}
	}
	printf("%d %d\n",sum1,sum2);
	return 0;
}
