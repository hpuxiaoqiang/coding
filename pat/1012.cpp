#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int a[1010];
	long long A1 = 0;
	long  long count2 = 0,A2 = 0;
	int count3 = 0,A3 = 0;
	int count4 = 0;
	long long sum4 = 0;
	int A5 = 0;
	int j = 0,n =0;
	scanf("%d",&a[0]);
	for(int i = 1;i<= a[0];i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i = 1;i<=a[0];i++)
	{
		int num;
		num = a[i];
		if(!(num%5)&&!(num&1))
		{
			A1+=num;
		}
		else if(num%5==1)
		{
			if(count2&1)
			{
				A2-=num;
			}
			else
			{
				A2+=num;
			}
			count2+=1;
		}
		else if(num%5==2)
		{
			count3++;
		}
		else if(num%5==3)
		{
			sum4+=num;
			count4++;
		}
		else if(num%5 ==4&&num>A5){
			A5 = num;
		}
		
	}
	if(A1>0)
		{
			printf("%lld ",A1);
		}else{
			printf("N ");
		}
		if(count2>0)
		{
			printf("%lld ",A2);
		}else{
			printf("N ");
		}
		if(count3>0){
			printf("%d ",count3);
		}else{
			printf("N ");
		}
		if(count4>0)
		{
			printf("%.1lf ",(double)sum4/count4*1.0);
		}else{
			printf("N ");
		}
		if(A5>0)
		{
			printf("%d\n",A5);
		}else{
			printf("N\n");
		}
	return 0;
}
