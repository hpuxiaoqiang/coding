void PostOrderTraverse(BiTree T)
{
	LinkStack S;
	Init(S);
	BiTNode *pCur,*pLastVisit;
	if( T == NULL) return ;	
	pCur = T;
	pLastVisit = NULL;
	//先把pCur移动到左子树最下边 
	while(pCur)
	{
		Push(S,pCur);
		pCur = pCur->Lchild;
	}
	while(!Stack_is_Empty(S))
	{
		Pop(S,pCur);//根节点出栈 
		if(pCur->Rchild == NULL||pCur->Rchild == pLastVisit)//一个根节点被访问的前提是无右子树或者右子树已经被访问 
		{
			cout<<pCur->data;//访问根节点 
			pLastVisit = pCur;//修改最近访问节点 
		}
		/*
		如果上面的条件没有满足，那么下面这个条件一定满足 
		else if(pCur->Lchild == pLastVisit)
		因为左子树访问过了那么就会先进入右子树，而LastVisit就会指向上次访问的左子树 
		*/ 
		else
		{
			
			Push(S,pCur);//不满足条件，根节点再次入栈 
			pCur = pCur->Rchild;
			while(pCur)
			{
				Push(s,pCur);
				pCur  = pCur->Lchild;
			}
		}
	}
 } 
