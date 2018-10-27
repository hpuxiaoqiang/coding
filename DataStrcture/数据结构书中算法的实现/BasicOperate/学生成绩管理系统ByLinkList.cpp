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
//ǰ�巨�������� 
void CreatList(LinkList &L,int n)
{
	 
	for(int i = 0;i< n;i++)
	{
		p = new LNode;
		cout<<"������ѧ������:"<<endl;
		cin >> p->data.name;
		cout<<"������ɼ�:"<<endl;
		cin >> p->data.score;
		p->next = L->next;
		L->next = p;
	}
}*/

//��巨�������� 
void CreatList(LinkList &L,int n)
{
	LNode *r;
	LNode *p;
	r = L; 
	for(int i = 0;i< n;i++)
	{
		p = new LNode;
		cout<<"������ѧ������:"<<endl;
		cin >> p->data.name;
		cout<<"������ɼ�:"<<endl;
		cin >> p->data.score;
		p->next = NULL;
		r->next = p;
		r = p;//���浱ǰp 
	}
}

//ɾ��ָ��λ�ýڵ� 
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
//��ָ��λ�ò���ڵ� 
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

//�õ�ָ��λ�ýڵ��data���ݣ��ýṹ�屣�� 
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

//�������ֲ��� 
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
//�޸�ָ��λ�õ����� 
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
//		cout<<"ѧ����Ϣ�����ڣ�"<<endl;
		return Error;	
	}
	cout<<"����"<<"\t"<<"�ɼ�"<<endl;
	cout<<p->data.name<<"\t"<<p->data.score<<endl;
	cout<<"�������޸ĺ�ĳɼ�:"<<endl;
	cin>>e.score;
	p->data.score = e.score;
	return OK;
}
//����������� 
void ShowAll(LinkList &L)
{
	LNode *p;
	p = L->next;
	cout<<"����"<<"\t"<<"�ɼ�"<<endl;
	while(p)
	{
		cout<<p->data.name<<"\t"<<p->data.score<<endl;
		p = p->next;
	}
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

int main() 
{
		
	LinkList L;
	StudentInfo TestStu;
	InitinalList(L);
	int menul;
	int num;
	printf("	��ӭʹ��ѧ���ɼ�����ϵͳ\n");
	while(true)
	{
		int total;	
		tips();
		printf("�������������:\n"); 
		scanf("%d",&menul);
		switch(menul){
		case 1:
			printf("������ѧ������:\n");
			scanf("%d",&num);
			total = num;
			CreatList(L,num);
			system("cls");
			break;
		case 2:
			printf("������Ҫ���ҵ�ѧ������:\n");
			scanf("%s",TestStu.name);
			if(SearchElemByName(L,TestStu))
			{
				printf("����:%s\n",TestStu.name); 
				printf("�ɼ�:%d\n",TestStu.score);	
			}else{
				cout<<"��ѧ����Ϣ�����ڣ�"<<endl;
			}
			
			break;		
		case 3:
			cout<<"������Ҫ���ҵ�λ��:"<<"��(1~"<<total<<")֮��"<<"\n";
			scanf("%d",&num);
			if(GetElem(L,num,TestStu))
			{
				printf("����:%s\n",TestStu.name); 
				printf("�ɼ�:%d\n",TestStu.score);
			}else{
				cout<<"�������ݳ�����������"<<endl;
			}
			break;
		case 4:
			printf("������Ҫ�޸ĵ�λ��:");
			scanf("%d",&num);
			if(ChangeElem(L,num,TestStu)){
				printf("�޸ĳɹ���\n");
			}else{
				printf("��ѧ����Ϣ�����ڣ�\n");
			} 
			break;
		case 5:
			printf("������Ҫɾ����λ��:");
			scanf("%d",&num);
			if(DeleteListElem(L,num)){
				printf("ɾ���ɹ���\n");
			}else{
				printf("ɾ��ʧ�ܣ�\n");
			} 
			break; 
		case 6:
			cout<<"������Ҫ�����λ��:"<<"��(1~"<<total<<")֮��"<<"\n";
			scanf("%d",&num);
			printf("������ѧ������:\n");
			scanf("%s",TestStu.name);
			printf("������ɼ�:\n");
			scanf("%d",&TestStu.score);
			if(Insert(L,num,TestStu)){
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
