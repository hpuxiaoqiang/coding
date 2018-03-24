#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int judge(char id_card[][19],int people_num);
	char id_card[102][19];
	memset(id_card,'0',sizeof(id_card));
	int n ;
	scanf("%d",&n);
	getchar();
	for (int i = 0;i < n;i++)
	{
		for(int j = 1; j <= 18;j++)
		{
			scanf("%c",&id_card[i][j]);
		}
		getchar();
	}
	judge(id_card,n);
	return 0;
}
int judge(char id_card[][19],int people_num)
{
	int* sum = (int*)malloc(people_num*sizeof(int));
	memset(sum,0,sizeof(sum));
	int flag = 1;
	char check[11] = {'1' ,'0' ,'X' ,'9' ,'8' ,'7' ,'6' ,'5' ,'4' ,'3' ,'2'};
	int value[18] = {0,7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	for(int i = 0;i < people_num;i++)
	{
		for(int j = 1;j <= 17;j++)
		{
			if(id_card[i][j] < '0'||id_card[i][j] > '9') 
			{
				sum[i] = -1;
				break;	
			}
			else
			{
				sum[i] += (id_card[i][j] - '0')*value[j];
			}
			
		}
		int num = sum[i]%11;
		if(num >=0 && id_card[i][18] == check[num])
		{
			id_card[i][0] = '1';
		}
	}
	for(int i = 0;i < people_num;i++)
	{
		if(id_card[i][0] == '0')
		{
			flag = 0;
			for(int j = 1 ;j <= 18;j++)
			{
				printf("%c",id_card[i][j]);
			}
			printf("\n");
		}
	}
	if(flag)
	{
		printf("All passed\n");
	}
	free(sum);
	return 0;
}
