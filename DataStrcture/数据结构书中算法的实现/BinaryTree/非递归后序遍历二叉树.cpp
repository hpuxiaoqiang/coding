void PostOrderTraverse(BiTree T)
{
	LinkStack S;
	Init(S);
	BiTNode *pCur,*pLastVisit;
	if( T == NULL) return ;	
	pCur = T;
	pLastVisit = NULL;
	//�Ȱ�pCur�ƶ������������±� 
	while(pCur)
	{
		Push(S,pCur);
		pCur = pCur->Lchild;
	}
	while(!Stack_is_Empty(S))
	{
		Pop(S,pCur);//���ڵ��ջ 
		if(pCur->Rchild == NULL||pCur->Rchild == pLastVisit)//һ�����ڵ㱻���ʵ�ǰ�����������������������Ѿ������� 
		{
			cout<<pCur->data;//���ʸ��ڵ� 
			pLastVisit = pCur;//�޸�������ʽڵ� 
		}
		/*
		������������û�����㣬��ô�����������һ������ 
		else if(pCur->Lchild == pLastVisit)
		��Ϊ���������ʹ�����ô�ͻ��Ƚ�������������LastVisit�ͻ�ָ���ϴη��ʵ������� 
		*/ 
		else
		{
			
			Push(S,pCur);//���������������ڵ��ٴ���ջ 
			pCur = pCur->Rchild;
			while(pCur)
			{
				Push(s,pCur);
				pCur  = pCur->Lchild;
			}
		}
	}
 } 
