#include <stdio.h>	  // 标准 输入 输出功能
#include <stdlib.h>   // 常用的函数和常量,处理 字符串,内存分配等
#include <io.h>
#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 		/*存储空间 初始分配量*/

typedef int Status; 	/*Status 函数类型, 值是 函数结果状态代码, 例如 ERROR*/

typedef int ElemType; 	/* Elem 类型  根据 实际情况而定, 此处 假定int*/
/* AD: 异常检测
   CC: 核心代码*/

typedef struct{
	ElemType data[MAXSIZE];			/*数组, 存储数据元素*/
	int length;						/*线性表 当前长度*/
}SqList;

/*初始化 顺序线性表*/
Status InitList(SqList *L){
	L ->length = 0;
	return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty(SqList L){
	if(L.length == 0){
		return TRUE;
	}else{
		return ERROR;
	}
}

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(SqList *L){
	L->length = 0;
	return OK;
}
/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(SqList L){
	return L.length;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始 */
Status GetElem(SqList L,int i, ElemType *e){
	if(L.length == 0 || i < 1 || i > L.length){
		return ERROR;			/*AD: 空表或 位置不合法*/
	}
	
	*e = L.data[i - 1];
	return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int LocateElem(SqList L,ElemType e){
	int i;
	if(L.length == 0){
		return 0;			/* AD:空表, 返回 0*/
	}
	for(i = 0; i < L.length; i++){
		if(L.data[i] == e){
			break;
		}
	}
	if(i >= L.length){
		return 0;		/* AD: 轮询一圈, 未找到 返回0*/
	}
	
	return i + 1;       /*CC :i的含义是 下标;  位置(下标 + 1)*/
}

/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */

Status ListInsert(SqList *L,int i,ElemType e){
	
	int k;
	if(L->length == MAXSIZE){			/*AD:顺序线性表 已满,无插入空间*/
		return ERROR;
	}
	
	if(i < 1 || i > L->length + 1){		/*AD:插入位置 不在 合法范围内,无法插入*/
		return ERROR;
	}
	/* CC:若插入数据位置不在表尾 */
	if(i <= L->length){
		/* CC: k是下标,插入位置往后的所有元素 后移一位; 先后移,再插入*/
		for(k = L->length -1; k >=i -1; k--){
			L->data[k + 1] = L->data[k];		/* 将要插入位置之后的数据元素向后移动一位 */
		}
	}
	/* 将新元素插入 位置i对应的下标是  i-1*/
	L->data[i - 1] = e; 
	L->length++;
	
	return OK ;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(SqList *L,int i,ElemType *e){
	
	int k;
	if(L->length == 0){			/*AD: 空表,如删除数据*/
		return ERROR;
	}
	
	if(i < 1 || i > L->length){		/*AD: 删除位置 不合法*/
		return ERROR;
	}
	
	*e = L->data[i - 1];
	if(i < L->length){			 			/* 如果删除不是最后位置 */
		for(k = i; i < L ->length; k++){
			L->data[k - 1] = L->data[k];    /* 将删除位置后继元素前移 */
		}
	}
	
	L->length--;
	return OK;
}

Status visit(ElemType c){
	printf("%d ",c);
	return OK;
}
/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(SqList L){
	int i;
	for(i = 0; i < L.length; i++){
		visit(L.data[i]);
	}
	printf("\n");
	return OK ;
}

void unionL(SqList *La,SqList Lb){
	int La_len,Lb_len,i;
	ElemType e;
	La_len = ListLength(*La);
	Lb_len = ListLength(Lb);
	for(i = 1; i <= Lb_len; i++){
		GetElem(Lb,i,&e);
		if(!LocateElem(*La,e)){
			ListInsert(La,++La_len,e);
		}
	}
}

int main()
{
	SqList L;
	SqList Lb;
	
	ElemType e;
	Status i;
	int j,k;
	//初始化
	i = InitList(&L);
	printf("初始化L后:L.length = %d\n",L.length);
	// 插入
	for(j = 1; j <= 5; j++){
		i = ListInsert(&L,1,j);
	}
	printf("在L的表头依次插入1~5后:L.data=");
	ListTraverse(L);
	//判空
	printf("L.length = %d \n",L.length);
	i = ListEmpty(L);
	printf("L 是否空 i = %d(1:是,0:否)\n",i);
	//清空表
	i = ClearList(&L);
	printf("清空L后: L.length = %d\n",L.length);
	i = ListEmpty(L);
	printf("L 是否空 i = %d(1:是,0:否)\n",i);
	//尾插
	for(j = 1; j <= 10; j++){
		ListInsert(&L,j,j);
	}
	printf("在L的表尾后依次插入1~10后:L.data=");
	ListTraverse(L);
	printf("L.length=%d \n",L.length);
	
	//插值
	ListInsert(&L,1,0);
	printf("在L的表头 插入 0后:L.data= ");
	ListTraverse(L);
	printf("L.length=%d \n",L.length);
	
	//根据位置 查找值
	GetElem(L,5,&e);
	printf("第5个元素的值为: %d\n",e);
	for(j = 3; j <= 4; j++){
		k = LocateElem(L,j);
		if(k){
			printf("第%d个元素的值为%d\n",k,j);
		}else{
			printf("没有值为%d的元素\n",j);
		}
	}
	
	//删除
	k = ListLength(L);		/* k 为 表长*/
	for(j = k + 1; j >= k; j--){
		i = ListDelete(&L,j,&e);    //删除第j个数据
		if(i == ERROR){
			printf("删除第%d个数据失败\n",j);
		}else{
			printf("删除第%d个元素的值为:%d\n",j,e);
		}
	}
	printf("依次输出L的元素:");
	ListTraverse(L);
	
	// 删除
	j = 5;
	ListDelete(&L,j,&e);
	printf("删除第%d个的元素值为:%d\n",j,e);
	
	
	printf("依次输出L的元素:");
	ListTraverse(L);
	
	//构造 一个有 10个数的Lb
	i = InitList(&Lb);
	for(j = 6; j <= 15; j++){
		i = ListInsert(&Lb,1,j);
	}
	
	unionL(&L,Lb);
	printf("依次输出合并了Lb的L的元素:");
	ListTraverse(L);
	

	getchar(); // 等待 输入回车次才关闭
	return 0;
}

