/*******************************************
 *                                         *
 * 文件夹: ▲02 线性表\04 SinglyLinkedList *
 *                                         *
 * 文件名: SinglyLinkedList.c              *
 *                                         *
 * 算  法: 2.8、2.9、2.10、2.11            * 
 *                                         *
 *******************************************/

#ifndef SINGLYLINKEDLIST_C
#define SINGLYLINKEDLIST_C

#include "SinglyLinkedList.h" 			//**▲02 线性表**//

/* 由于头结点的指针本身就是个结构指针，
所以在初始化、创建、销毁等需要改变头结点指针的地方，
则要注意函数形参为二级指针，即指向头指针的指针; 
即 LinkList *L 中， *L 为二级指针 */

/* 一级指针：
LinkList	*L;
(*L).成员；
(L)->成员；

二级指针：
LinkList	**L;
(**L).成员；
(*L)->成员；

一般的(狗代表任意级指针):
指针   *狗；
(*狗).成员；
(狗)->成员；
*/

//LinkList 是一个别名，代表了指向单链表节点的    指针类型。
//"LinkList *L" 声明了一个名为 L 的指针变量，它指向 LinkList 类型的对象。
//"LinkList L" 中的 "" 符号表示解引用操作符，它用于访问指针所指向的对象。在这里，"*L" 表示 L 指针指向的对象是一个 LinkList 类型的对象。
//因此，"LinkList *L" 可以理解为 L 是一个指向 LinkList 对象的指针变量，通过 L 可以操作（读取、修改）该 LinkList 对象。
//总结起来，"LinkList *L" 是声明了一个指向 LinkList 类型对象的指针变量 L。

Status InitList_L(LinkList *L)  				// 指向 LinkList 类型的指针的指针
{
	(*L) = (LinkList)malloc(sizeof(LNode)); 	// *L 存储指向结点的地址；
	if(!(*L))
		exit(OVERFLOW);
	(*L)->next = NULL;
	// (**L).next = NULL;  						//访问成员该语句也可以；
	
	return OK;
}

Status ClearList_L(LinkList L)			//保留头结点 
{	
	LinkList pre, p;
	
	if(!L)				// 如果L为空链表,返回报错 判定L是否为NULL ; "!L" 表示对指针 L 进行取反操作，即如果 L 是一个空指针，则结果为真（非零）；
		return ERROR;
	
	pre = L->next;  // L是头结点, L->next是 第一个 有数据的节点
	
	while(pre)  		//YY(隐喻):吃甘蔗, 咬到下一节,才吃掉当前节点 ,迟到所有汁水(数据元素)的节点
	{
		p = pre->next;
		free(pre);    //Aim(目的):释放有数据元素的 节点内存
		pre = p;
	}
	
	L->next = NULL;
	
	return OK; 
}

void DestroyList_L(LinkList *L)			//销毁所有结点 
{
	LinkList p = *L;	//p和L一样也是一个二级指针，这里的*的作用是取内容 此处存储的是 头结点；
	
	while(p)		//YY(隐喻):对于每一个节点都释放,包括 头结点
	{
		p = (*L)->next;
		free(*L);
		(*L) = p;
	}
}

Status ListEmpty_L(LinkList L)			//LinkList L 中，L 为指针变量，即头指针，指向头结点；
{
	if(L!=NULL && L->next==NULL)		//链表存在且只有头结点 
		return TRUE;
	else
		return FALSE;
}

int ListLength_L(LinkList L)
{
	LinkList p;
	int i;
	
	if(L)				//判定L是否是 空链表
	{
		i = 0;
		p = L->next;	 //指向第一个结点；
		while(p)		 //从第一个数据结点开始计算长度；
		{
			i++;
			p = p->next;
		}
		return i;
	}
	
	return INFEASIBLE;  	//值为 -1  长度一定是  大于0 的正整数存在负数 一定是错误的
	//return i;   //QA如果 是空链表, i没有赋值,此时i的值是多少?   未初始化的局部变量的值是不确定的
}

/*════╗
║ 算法2.8║ 
╚════*/
Status GetElem_L(LinkList L, int i, LElemType_L *e)
{
	int j;
	LinkList p = L->next;				//含头结点，所以指向第一个结点；
	
	j = 1;
	p = L->next;
	
	while(p && j<i)						//p不为空且还未到达i处
	{
		j++;
		p = p->next;
	}//指针指向第 i 个结点；
	
	if(!p || j>i)						//第i个元素不存在 
		return ERROR;
	
	*e = p->data;
	
	return OK; 
}

//返回单链表L中第一个与e满足Compare关系的元素位序;
int LocateElem_L(LinkList L, LElemType_L e, Status(Compare)(LElemType_L, LElemType_L))
{
	int i;
	LinkList p;
	
	i = -1;								//L不存在时返回-1 
	
	if(L)
	{
		i = 0;
		p = L->next;
		
		while(p)
		{
			i++;
			
			if(!Compare(e, p->data))
			{
				p = p->next;
				if(p==NULL)		//失配时已经是最后一个结点 
					i++;
			}
			else
				break;
		}	
	}
	
	return i;	
}

/* 银行排队算法中，此处两个函数不能直接使用，原因是结构不能直接比较 */
#ifndef BANKQUEUING_C				
Status PriorElem_L(LinkList L, LElemType_L cur_e, LElemType_L *pre_e)
{
	LinkList p, suc;
	
	if(L)
	{
		p = L->next;
		
		if(p->data!=cur_e)				//第一个结点无前驱 
		{
			while(p->next)				//若p结点有后继 
			{
				suc = p->next;			//suc指向p的后继
				if(suc->data==cur_e)
				{
					*pre_e = p->data;
					return OK;
				}
				p = suc;
			}			
		}	
	}
	
	return ERROR;
}

Status NextElem_L(LinkList L, LElemType_L cur_e, LElemType_L *next_e)
{
	LinkList p, suc;
	
	if(L)
	{
		p = L->next;
		
		while(p && p->next)
		{
			suc = p->next;
			
			if(suc && p->data==cur_e)
			{
				*next_e = suc->data;
				return OK;
			}
			
			if(suc)
				p = suc;
			else
				break;
		}	
	}
	
	return ERROR;
}
#endif

/*════╗
║ 算法2.9║ 
╚════*/
//默认含头结点；
Status ListInsert_L(LinkList L, int i, LElemType_L e)
{
	LinkList p, s;
	int j;
	
	p = L;
	j = 0; 	//j=0 在头结点的位置；
	
	while(p && j<i-1)					//p 指向第i-1个结点 
	{
		p = p->next;
		++j;	
	}//p 指向第i-1个结点；当做块记住，常用； 
	
	if(!p || j>i-1)
		return ERROR;
	
	s = (LinkList)malloc(sizeof(LNode));	//生成一个 s 指向的结点；
	if(!s)
		exit(OVERFLOW);
	s->data = e;
	s->next = p->next;
	p->next = s;
	
	return OK;
}

/*═════╗
║ 算法2.10 ║ 
╚═════*/
//默认含头结点；
Status ListDelete_L(LinkList L, int i, LElemType_L *e)
{
	LinkList pre, p; 
	int j;
	
	pre = L;
	j = 0; 		//j=0 在头结点的位置；
	
	while(pre->next && j<i-1)			//寻找第i个结点，并令pre指向其前驱 
	{
		pre = pre->next;
		++j;
	}//pre 指向第 i-1 个结点；当做块记住，常用；
	
	if(!pre->next || j>i)				//删除位置不合理
		return ERROR;
	
	p = pre->next;						//p 指针记录要删除的结点；
	pre->next = p->next;
	*e = p->data;
	free(p);
	
	return OK; 
}

Status ListTraverse_L(LinkList L, void(Visit)(LElemType_L))
{
	LinkList p;
	
	if(!L)
		return ERROR;
	else
		p = L->next;	//含头结点，所以指向第一个数据结点；
	
	while(p)
	{
		Visit(p->data);
		p = p->next;
	}
	
	return OK;
}

/*═════╗
║ 算法2.11 ║ 
╚═════*/
Status CreateList_HL(FILE *fp, LinkList *L, int n)
{
	int i;
	LinkList p;
	LElemType_L tmp;
	
	*L = (LinkList)malloc(sizeof(LNode));
	if(!(*L))
		exit(OVERFLOW);
	(*L)->next = NULL;							//建立头结点 
	
	for(i=1; i<=n; ++i)
	{
		if(Scanf(fp, "%d", &tmp)==1)
		{
			p = (LinkList)malloc(sizeof(LNode));
			if(!p)
				exit(OVERFLOW);
			p->data = tmp;						//录入数据 
			p->next = (*L)->next;
			(*L)->next = p;		
		}
		else
			return ERROR;
	}
	
	return OK;
}  

Status CreateList_TL(FILE *fp, LinkList *L, int n)
{
	int i;
	LinkList p, q;
	LElemType_L tmp;	
	
	*L = (LinkList)malloc(sizeof(LNode));
	if(!(*L))
		exit(OVERFLOW);
	(*L)->next = NULL;
	
	for(i=1,q=*L; i<=n; ++i)
	{
		if(Scanf(fp, "%d", &tmp)==1)
		{
			p = (LinkList)malloc(sizeof(LNode));
			if(!p)
				exit(OVERFLOW);
			p->data = tmp;						//录入数据 
			q->next = p;
			q = q->next;		
		}
		else
			return ERROR;		
	}
	
	q->next = NULL;
	
	return OK;
}

#endif 
