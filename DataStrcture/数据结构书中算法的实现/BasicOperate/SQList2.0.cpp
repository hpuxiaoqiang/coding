#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <windows.h>
#define Max 100
#define Ture 1
#define OK 1
#define False 0
using namespace std;


/**
学生信息结构体 
*/
typedef struct {
	char name[20];
	char number[8];
	int score;
}StudentInfo;

/**
顺序表 
*/
typedef struct {
	StudentInfo *elem;
	int length;
}SqList;

/**
顺序表的初始化 
*/
int InitList(SqList &L){
	L.elem = new StudentInfo[Max];//为顺序表分配储存空间 
	if(!L.elem) {
		exit(False);//分配失败则退出系统 
	}
	L.length = 0;
	
	return OK;
}

/*
学生信息输入函数 
*/ 
void InputInfo(SqList &L,int length){
	StudentInfo stu;//构建一个临时的StudentInfo变量用来存放输入的信息 
	L.length = length;
	for(int i = 0 ;i < length;i++)
	{
		printf("请输入第%d个学生姓名:\n",i+1);
		scanf("%s",stu.name);
		printf("请输入学号:\n");
		scanf("%s",stu.number);
		printf("请输入成绩:\n");
		scanf("%d",&stu.score);
		L.elem[i] = stu;
	}
}


/**
查找指定位置 
*/
int GetElem(SqList &L,int i,StudentInfo &e){
	if(i < 1 || i > L.length) return False;
	e = L.elem[i-1];
	return OK;
}
/**
按姓名查找 
*/
int SearchElemByName(SqList &L,StudentInfo &e){
	for(int i = 0;i < L.length;i++)
	{
		if(!strcmp(L.elem[i].name,e.name)){
			printf("学号：%s\n",L.elem[i].number);
			printf("成绩：%d\n",L.elem[i].score);
			return OK;
		} 
	}
	printf("该学生信息不存在!\n");
	return False;
}

/**
删除指定位置学生信息 
*/
int DeleteElem(SqList &L,int i,StudentInfo &e){
	if( i < 1 || i>L.length) return False;
	for(int j = i;j < L.length;j++)
	{
		L.elem[j-1] = L.elem[j];
	}
	L.length--;
	return OK;
}

/**
修改指定位置学生信息 
*/
int ChangeElem(SqList &L,int i)
{
	StudentInfo stu;
	if( i < 1 || i>L.length) return False;
	printf("姓名:%s\n",L.elem[i-1].name);
	printf("学号:%s\n",L.elem[i-1].number);
	printf("成绩:%d\n",L.elem[i-1].score);
	printf("请输入修改的名字：\n");
	scanf("%s",stu.name); 
	printf("请输入修改的学号：\n");
	scanf("%s",stu.number); 
	printf("请输入修改的成绩：\n");
	scanf("%d",&stu.score);
	L.elem[i-1] = stu;
	return OK;
}


/**
在指定位置插入学生信息 
*/
int InsertElem(SqList &L,int i,StudentInfo &e){
	if( i < 1 || i>L.length+1) return False;
	if(L.length == Max) return False;
	for(int j = L.length - 1; j >= i-1;j--)
	{
		L.elem[j+1] = L.elem[j];
	}
	L.elem[i-1] = e;
	L.length++;
	return OK;
}

/**
显示所有学生信息 
*/
int ShowAll(SqList &L){
	printf("--------------------------\n");
	printf("姓名\t学号\t成绩\n"); 
	for(int i = 0;i <L.length;i++)
	{
		printf("%s\t%s\t%d\n",L.elem[i].name,L.elem[i].number,L.elem[i].score);
		//printf("--------------------------\n");
	}
	return OK;
}

void tips(){
	printf("------------------------\n");
	printf("	1.录入学生信息\n");
	printf("	2.按姓名查找学生信息\n");
	printf("	3.查找指定位置学生信息\n");
	printf("	4.修改指定位置学生信息\n"); 
	printf("	5.删除指定位置学生信息\n");
	printf("	6.在指定位置插入学生信息\n");
	printf("	7.显示所有学生信息\n");
	printf("	8.退出系统\n");
	printf("-------------------------\n");
}

int main(){
	
	StudentInfo TestStu;
	SqList L;
	InitList(L);
	int menul;
	int num;
	printf("	欢迎使用学生成绩管理系统\n");
	while(true)
	{
			
		tips();
		printf("请输入命令序号:\n"); 
		scanf("%d",&menul);
		switch(menul){
		case 1:
			printf("请输入学生人数:\n");
			scanf("%d",&num);
			InputInfo(L,num);
			system("cls");
			break;
		case 2:
			printf("请输入要查找的学生姓名:\n");
			scanf("%s",TestStu.name);
			SearchElemByName(L,TestStu); 
			break;		
		case 3:
			printf("请输入要查找的位置:\n");
			scanf("%d",&num);
			GetElem(L,num,TestStu);
			printf("姓名:%s\n",TestStu.name); 
			printf("学号:%s\n",TestStu.number); 
			printf("成绩:%d\n",TestStu.score);
			break;
		case 4:
			printf("请输入要修改的位置:");
			scanf("%d",&num);
			if(ChangeElem(L,num)){
				printf("修改成功！\n");
			}else{
				printf("该学生信息不存在！\n");
			} 
			break;
		case 5:
			printf("请输入要删除的位置:");
			scanf("%d",&num);
			if(DeleteElem(L,num,TestStu)){
				printf("删除成功！\n");
			}else{
				printf("删除失败！\n");
			} 
			break; 
		case 6:
			printf("请输入要插入的位置:\n");
			scanf("%d",&num);
			printf("请输入学生姓名:\n");
			scanf("%s",TestStu.name);
			printf("请输入学号:\n");
			scanf("%s",TestStu.number);
			printf("请输入成绩:\n");
			scanf("%d",&TestStu.score);
			if(InsertElem(L,num,TestStu)){
				printf("插入成功！\n");
			}
			else{
				printf("插入失败！\n");	
			}
			break;
		case 7:
			ShowAll(L);
			break;
		case 8:
			printf("退出中");
			Sleep(300);
			printf(".");
			Sleep(300);
			printf("."); 
			Sleep(300);
			printf(".\n"); 
			Sleep(500);
			printf("成功退出！\n");
			exit(0); 
		}	
	}
	
	return 0;
}

