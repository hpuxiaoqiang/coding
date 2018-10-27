#include <iostream>
#include <cstdio>
#define OK 1
#define ERROR 0
typedef char ElemType;
using namespace std;
typedef struct QNode{
	struct QNode *next;
	ElemType data;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
//����һ���յ����� 
int InitQueue(LinkQueue &Q){
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;//ͷָ�벻ʹ�� 
	return OK;
}

int EnQueue(LinkQueue &Q,ElemType e){
	QueuePtr p;
	p = new QNode;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

int DeQueue(LinkQueue &Q,ElemType &e)
{
	QueuePtr p;
	if(Q.front == Q.rear) return ERROR;
	p = Q.front->next;//��pָ���ͷԪ�أ�������ͷԪ�صĵ�ַ 
	e = Q.front->next->data;//������ͷԪ�ص�ֵ
	Q.front->next = p->next;
	if(Q.rear == p) Q.front = Q.rear;//���һ��Ԫ�ر�ɾ������βָ��ָ��ͷ�ڵ㣬��Ϊ�� 
	//if(Q.front->next==NULL) Q.rear =  Q.front;//����ͷ�ڵ��nextΪ�� 
	delete p;
	return OK; 
}
int GetHead(LinkQueue Q){
	if(Q.front!=Q.rear)
		return Q.front->next->data;
	else return 0;
}

int main(){
	LinkQueue Q;
	InitQueue(Q);
	char model;
	scanf("%c",&model);
	getchar();
	if(model == 'C')
	{
		char ch1;
		char ch;
		int num = 1;
		scanf("%c",&ch);
		scanf("%c",&ch1);
		while(ch !='\n')
		{
			if(ch == ch1)
			{
				ch = ch1;
				num++;
				/*��һ��bug������ͨ���� �� 
				  ����ѹ��ʱnum>=10,����ֱ�����û�д��� 
				*/
				scanf("%c",&ch1);
			}else{
				if(num>1){//��num>9���д��� 
					if(num > 9 )
					{
						if(num/100!=0)
						{
							EnQueue(Q,(num/100+'0'));
							num%=100; 
						}
						if(num/10!=0)
						{
							EnQueue(Q,(num/10+'0'));
							EnQueue(Q,(num%10+'0'));
						}	
					}else{
						EnQueue(Q,(num+'0'));	
					}
					EnQueue(Q,ch);
					num = 1;
				}else {
					EnQueue(Q,ch);
				}
				ch = ch1;
				if(ch1 == '\n') break;
				scanf("%c",&ch1);
			}
		}
		while(GetHead(Q))
		{
			char s;
			DeQueue(Q,s);
			if (s>='0' && s <= '9') 
				printf("%d",s-'0');	
			else printf("%c",s);
		}	
	}else if(model == 'D')
	{
		char ch;
		scanf("%c",&ch);
		while(ch!= '\n')
		{
			EnQueue(Q,ch);
			scanf("%c",&ch);
		}
		while(GetHead(Q))
		{
			int num = 0;
			char s;
			DeQueue(Q,s);
			while(s>= '0'&& s<='9' )
			{
				num = num*10+(s-'0');
				DeQueue(Q,s);
			}
			if(num > 0 )
			{
				for(int i = 1;i<= num;i++)
				{
					printf("%c",s);
				}
			}else{
					printf("%c",s);
			}
		}
		printf("\n");
	}
	return 0;
}
