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
ѧ����Ϣ�ṹ�� 
*/
typedef struct {
	char name[20];
	char number[8];
	int score;
}StudentInfo;

/**
˳��� 
*/
typedef struct {
	StudentInfo *elem;
	int length;
}SqList;

/**
˳���ĳ�ʼ�� 
*/
int InitList(SqList &L){
	L.elem = new StudentInfo[Max];//Ϊ˳�����䴢��ռ� 
	if(!L.elem) {
		exit(False);//����ʧ�����˳�ϵͳ 
	}
	L.length = 0;
	
	return OK;
}

/*
ѧ����Ϣ���뺯�� 
*/ 
void InputInfo(SqList &L,int length){
	StudentInfo stu;//����һ����ʱ��StudentInfo������������������Ϣ 
	L.length = length;
	for(int i = 0 ;i < length;i++)
	{
		printf("�������%d��ѧ������:\n",i+1);
		scanf("%s",stu.name);
		printf("������ѧ��:\n");
		scanf("%s",stu.number);
		printf("������ɼ�:\n");
		scanf("%d",&stu.score);
		L.elem[i] = stu;
	}
}


/**
����ָ��λ�� 
*/
int GetElem(SqList &L,int i,StudentInfo &e){
	if(i < 1 || i > L.length) return False;
	e = L.elem[i-1];
	return OK;
}
/**
���������� 
*/
int SearchElemByName(SqList &L,StudentInfo &e){
	for(int i = 0;i < L.length;i++)
	{
		if(!strcmp(L.elem[i].name,e.name)){
			printf("ѧ�ţ�%s\n",L.elem[i].number);
			printf("�ɼ���%d\n",L.elem[i].score);
			return OK;
		} 
	}
	printf("��ѧ����Ϣ������!\n");
	return False;
}

/**
ɾ��ָ��λ��ѧ����Ϣ 
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
�޸�ָ��λ��ѧ����Ϣ 
*/
int ChangeElem(SqList &L,int i)
{
	StudentInfo stu;
	if( i < 1 || i>L.length) return False;
	printf("����:%s\n",L.elem[i-1].name);
	printf("ѧ��:%s\n",L.elem[i-1].number);
	printf("�ɼ�:%d\n",L.elem[i-1].score);
	printf("�������޸ĵ����֣�\n");
	scanf("%s",stu.name); 
	printf("�������޸ĵ�ѧ�ţ�\n");
	scanf("%s",stu.number); 
	printf("�������޸ĵĳɼ���\n");
	scanf("%d",&stu.score);
	L.elem[i-1] = stu;
	return OK;
}


/**
��ָ��λ�ò���ѧ����Ϣ 
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
��ʾ����ѧ����Ϣ 
*/
int ShowAll(SqList &L){
	printf("--------------------------\n");
	printf("����\tѧ��\t�ɼ�\n"); 
	for(int i = 0;i <L.length;i++)
	{
		printf("%s\t%s\t%d\n",L.elem[i].name,L.elem[i].number,L.elem[i].score);
		//printf("--------------------------\n");
	}
	return OK;
}

void tips(){
	printf("------------------------\n");
	printf("	1.¼��ѧ����Ϣ\n");
	printf("	2.����������ѧ����Ϣ\n");
	printf("	3.����ָ��λ��ѧ����Ϣ\n");
	printf("	4.�޸�ָ��λ��ѧ����Ϣ\n"); 
	printf("	5.ɾ��ָ��λ��ѧ����Ϣ\n");
	printf("	6.��ָ��λ�ò���ѧ����Ϣ\n");
	printf("	7.��ʾ����ѧ����Ϣ\n");
	printf("	8.�˳�ϵͳ\n");
	printf("-------------------------\n");
}

int main(){
	
	StudentInfo TestStu;
	SqList L;
	InitList(L);
	int menul;
	int num;
	printf("	��ӭʹ��ѧ���ɼ�����ϵͳ\n");
	while(true)
	{
			
		tips();
		printf("�������������:\n"); 
		scanf("%d",&menul);
		switch(menul){
		case 1:
			printf("������ѧ������:\n");
			scanf("%d",&num);
			InputInfo(L,num);
			system("cls");
			break;
		case 2:
			printf("������Ҫ���ҵ�ѧ������:\n");
			scanf("%s",TestStu.name);
			SearchElemByName(L,TestStu); 
			break;		
		case 3:
			printf("������Ҫ���ҵ�λ��:\n");
			scanf("%d",&num);
			GetElem(L,num,TestStu);
			printf("����:%s\n",TestStu.name); 
			printf("ѧ��:%s\n",TestStu.number); 
			printf("�ɼ�:%d\n",TestStu.score);
			break;
		case 4:
			printf("������Ҫ�޸ĵ�λ��:");
			scanf("%d",&num);
			if(ChangeElem(L,num)){
				printf("�޸ĳɹ���\n");
			}else{
				printf("��ѧ����Ϣ�����ڣ�\n");
			} 
			break;
		case 5:
			printf("������Ҫɾ����λ��:");
			scanf("%d",&num);
			if(DeleteElem(L,num,TestStu)){
				printf("ɾ���ɹ���\n");
			}else{
				printf("ɾ��ʧ�ܣ�\n");
			} 
			break; 
		case 6:
			printf("������Ҫ�����λ��:\n");
			scanf("%d",&num);
			printf("������ѧ������:\n");
			scanf("%s",TestStu.name);
			printf("������ѧ��:\n");
			scanf("%s",TestStu.number);
			printf("������ɼ�:\n");
			scanf("%d",&TestStu.score);
			if(InsertElem(L,num,TestStu)){
				printf("����ɹ���\n");
			}
			else{
				printf("����ʧ�ܣ�\n");	
			}
			break;
		case 7:
			ShowAll(L);
			break;
		case 8:
			printf("�˳���");
			Sleep(300);
			printf(".");
			Sleep(300);
			printf("."); 
			Sleep(300);
			printf(".\n"); 
			Sleep(500);
			printf("�ɹ��˳���\n");
			exit(0); 
		}	
	}
	
	return 0;
}

