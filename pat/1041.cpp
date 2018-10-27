#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	char card[14];
	int x1;
	int x2;
}stu_info;
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	stu_info* stu = (stu_info*)malloc(n*sizeof(stu_info)) ;
	for(int i =0;i < n; i++)
	{
		scanf("%s %d %d",stu[i].card,&stu[i].x1,&stu[i].x2);
		getchar();
	}
	int miss_num = 0;
	scanf("%d",&miss_num);
	for(int i =0;i < miss_num;i++)
	{
		int lost_locate = -1;
		scanf("%d",&lost_locate);
		for(int j = 0;j < n;j++)
		{
			if(stu[j].x1 == lost_locate)
			{
				printf("%s %d\n",stu[j].card,stu[j].x2);
			}
		}
	}
	free(stu);
	return 0;
}
