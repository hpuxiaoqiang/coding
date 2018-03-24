#include<stdio.h>
#include <string.h>
#include <stdlib.h> 
typedef struct{
	char name[11];
	char stu_num[11];
	int score;
}stu_info;
int main()
{
	stu_info init;
	int n;
	scanf("%d",&n);
	getchar();
	stu_info* stu = (stu_info*)malloc(n*sizeof(stu_info));
	for(int i =0;i< n;i++)
	{
		memset(stu[i].name,0,sizeof(stu[i].name));
		memset(stu[i].stu_num,0,sizeof(stu[i].stu_num));
		int count = 0;
		char ch ; 
		scanf("%c",&ch);
		while(ch != 32)
		{
			stu[i].name[count] = ch;
			count++;
			scanf("%c",&ch);
		}
		count = 0;
		scanf("%c",&ch); 
		while(ch != 32)
		{
			stu[i].stu_num[count] = ch;
			count++;
			scanf("%c",&ch);
		}
		int num = 0;
		scanf("%d",&num);
		stu[i].score = num;
		getchar();
	}
	int min = 0,max = 0;
	for(int i = 0;i < n;i++)
	{
		if(stu[min].score>stu[i].score) min = i;
		if(stu[max].score<stu[i].score) max = i;
	}
	printf("%s %s\n",stu[max].name,stu[max].stu_num);
	printf("%s %s\n",stu[min].name,stu[min].stu_num);
	free(stu);
	return 0;
}
