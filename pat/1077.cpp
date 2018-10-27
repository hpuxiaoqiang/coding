#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define flag  -1
int main()
{
	//注释部分为14分，部分正确 
/*	int N,M;
	int **score;
	scanf("%d %d",&N,&M);
	score = (int**)malloc(sizeof(int*)*N);
	for(int i = 0;i<N;i++)
	{
		score[i] = (int*)malloc(sizeof(int)*N);
	}
	for(int i = 0; i< N ; i++)
	{
		for (int j = 0 ; j < N ; j++)
		{
			int num;
			scanf("%d",&num);
			if (num >= 0 && num <= 50)
			{
				score[i][j] = num;
			}else{
				score[i][j] = flag;
			}
		}
		int min_tag = 1;
		int max_tag = 1;
		for(int j = 1 ;j< N-1;j++)
		{
			if(score[i][max_tag]!=-1)
			{
				if(score[i][min_tag]>score[i][j+1]&&score[i][j+1]!=-1) min_tag = j+1;
			}else{
				min_tag = j+1;
			}
			if(score[i][max_tag]<score[i][j+1]) max_tag = j+1;
		}
		score[i][min_tag] = -1;
		score[i][max_tag] = -1;
	}
	for(int i = 0;i< N;i++)
	{
		int sum = 0,count = 0;
		for(int j = 1;j < N ;j++)
		{
			if(score[i][j]!=-1)
			{
				sum+=score[i][j];
				count++;
			}
		}
		float G1 = sum*1.0/count;
		printf("%d\n",(int)((G1+score[i][0])/2+0.5));
	}
	free(score);
	return 0;*/
	int N,M;
	scanf("%d %d",&N,&M);
	int G2;
	for(int i = 0;i< N;i++)
	{
		
		scanf("%d",&G2);
		int max = 0;
		int min = 110;//max，min小细节， 
		int num = 0,sum= 0,count = 0;
		for(int j = 1;j<N;j++)
		{
			scanf("%d",&num);
			if(num>= 0&&num<=M)
			{
				sum+=num;
				if(num > max) max = num;
				if(num < min) min = num; 
				count++;
			}
		}
		sum -= max;
		sum -= min;
		count-=2;
		sum = sum/count;
		sum = (float)(sum+G2)/2+0.5;//处理四舍五入的方法之一 
		printf("%d\n",sum);
	}
	return 0;
 } 
 
