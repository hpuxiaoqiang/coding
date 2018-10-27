#include <iostream>
#include <stdio.h>
#include <cstring>
#include <windows.h>
using namespace std;
#define Flase 0
#define True 1
#define OK 1
#define Error 0

typedef struct 
{
	char name[15];
	int score;
}StudentInfo;

typedef struct LNode
{
	StudentInfo data;
	struct LNode *next;
}LNode,*LinkList;


//LNode *p;


int InitinalList(LinkList &L)
{
	L = new LNode;
	L->next = NULL;
}

/*
//前插法创建链表 
void CreatList(LinkList &L,int n)
{
	 
	for(int i = 0;i< n;i++)
	{
		p = new LNode;
		cout<<"请输入学生姓名:"<<endl;
		cin >> p->data.name;
		cout<<"请输入成绩:"<<endl;
		cin >> p->data.score;
		p->next = L->next;
		L->next = p;
	}
}*/

//后插法创建链表 
void CreatList(LinkList &L,int n)
{
	LNode *r;
	LNode *p;
	r = L; 
	for(int i = 0;i< n;i++)
	{
		p = new LNode;
		cout<<"请输入学生姓名:"<<endl;
		cin >> p->data.name;
		cout<<"请输入成绩:"<<endl;
		cin >> p->data.score;
		p->next = NULL;
		r->next = p;
		r = p;//保存当前p 
	}
}

//删除指定位置节点 
int DeleteListElem(LinkList &L,int n)
{
	LNode *p;
	LNode *q;
	int j = 0;
	p = L;
	while((p->next)&&(j < n-1))
	{
		p = p->next;
		j++;
	 }
	if(!(p->next)||(j>n-1)) return Error;
	q = p->next;
	p->next = q->next;
	delete q;
	return OK;
}
//在指定位置插入节点 
int Insert(LinkList &L,int n,StudentInfo &e)
{
	LNode *p;
	LNode *s = new LNode;
	p = L;
	int j = 0;
	while((p->next)&&(j < n-1))
	{
		p = p->next;
		j++;
	}
	if(!p || (j > n-1)) return Error;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

//得到指定位置节点的data数据，用结构体保存 
int GetElem(LinkList &L,int n,StudentInfo &e)
{
	LNode *p;
	p = L->next;
	int j = 1;
	while( p && j < n)
	{
		p = p->next;
		j++;
	}
	if(!p || (j > n)) 
	{
		return Error;	
	}
	e = p->data;
	return OK;
}

//根据名字查找 
int SearchElemByName(LinkList &L,StudentInfo &e)
{
	LNode *p;
	p = NULL;
	p = L->next;
	while( p && strcmp(p->data.name,e.name)!=0)
	{
		p = p->next;
	}
	if(!p) return Error; 
	e = p->data;
	return OK;
}
//修改指定位置的数据 
int ChangeElem(LinkList &L,int n,StudentInfo &e)
{
	LNode *p;
	int j =1;
	p = L->next;
	while( p &&(j < n))
	{
		p = p->next;
		j++; 
	}
	if(!(p->next)||(j>n)) 
	{
//		cout<<"学生信息不存在！"<<endl;
		return Error;	
	}
	cout<<"姓名"<<"\t"<<"成绩"<<endl;
	cout<<p->data.name<<"\t"<<p->data.score<<endl;
	cout<<"请输入修改后的成绩:"<<endl;
	cin>>e.score;
	p->data.score = e.score;
	return OK;
}
//输出所有数据 
void ShowAll(LinkList &L)
{
	LNode *p;
	p = L->next;
	cout<<"姓名"<<"\t"<<"成绩"<<endl;
	while(p)
	{
		cout<<p->data.name<<"\t"<<p->data.score<<endl;
		p = p->next;
	}
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

int main() 
{
		
	LinkList L;
	StudentInfo TestStu;
	InitinalList(L);
	int menul;
	int num;
	printf("	欢迎使用学生成绩管理系统\n");
	while(true)
	{
		int total;	
		tips();
		printf("请输入命令序号:\n"); 
		scanf("%d",&menul);
		switch(menul){
		case 1:
			printf("请输入学生人数:\n");
			scanf("%d",&num);
			total = num;
			CreatList(L,num);
			system("cls");
			break;
		case 2:
			printf("请输入要查找的学生姓名:\n");
			scanf("%s",TestStu.name);
			if(SearchElemByName(L,TestStu))
			{
				printf("姓名:%s\n",TestStu.name); 
				printf("成绩:%d\n",TestStu.score);	
			}else{
				cout<<"该学生信息不存在！"<<endl;
			}
			
			break;		
		case 3:
			cout<<"请输入要查找的位置:"<<"在(1~"<<total<<")之间"<<"\n";
			scanf("%d",&num);
			if(GetElem(L,num,TestStu))
			{
				printf("姓名:%s\n",TestStu.name); 
				printf("成绩:%d\n",TestStu.score);
			}else{
				cout<<"输入数据超过总人数！"<<endl;
			}
			break;
		case 4:
			printf("请输入要修改的位置:");
			scanf("%d",&num);
			if(ChangeElem(L,num,TestStu)){
				printf("修改成功！\n");
			}else{
				printf("该学生信息不存在！\n");
			} 
			break;
		case 5:
			printf("请输入要删除的位置:");
			scanf("%d",&num);
			if(DeleteListElem(L,num)){
				printf("删除成功！\n");
			}else{
				printf("删除失败！\n");
			} 
			break; 
		case 6:
			cout<<"请输入要插入的位置:"<<"在(1~"<<total<<")之间"<<"\n";
			scanf("%d",&num);
			printf("请输入学生姓名:\n");
			scanf("%s",TestStu.name);
			printf("请输入成绩:\n");
			scanf("%d",&TestStu.score);
			if(Insert(L,num,TestStu)){
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
