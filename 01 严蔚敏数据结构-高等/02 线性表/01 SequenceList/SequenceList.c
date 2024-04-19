/***************************************
 *                                     *
 * 文件夹: ▲02 线性表\01 SequenceList *
 *                                     *
 * 文件名: SequenceList.c              *
 *                                     *
 * 算  法: 2.3、2.4、2.5、2.6          * 
 *                                     *
 ***************************************/
#ifndef SEQUENCELIST_C
#define SEQUENCELIST_C

#include "SequenceList.h"   //*02 线性表*/
#include <assert.h>

////调试版本, assert 生效 --- DeBug Version
//#ifdef NDEBUG
//#include <assert.h>
//#endif

//发布版本  assert 不生效  --- Release Version
//#ifdef NDEBUG
//#define NDEBUG
//#endif
//#include <assert.h>

 /*════╗
 ║算法2.3 ║
 ╚════*/
Status InitList_Sq(SqList *L){
	/*QA: 此时 分配空间,占据内存, 请问此时 元素值是多少? 是否需要 进行默认值填充*/
	(*L).elem = (LElemType_Sq*)malloc(LIST_INIT_SIZE * sizeof(LElemType_Sq));
	if(!(*L).elem){
		exit(OVERFLOW);			//分配内存失败
	}
	
	/*CC: 初始化成功状态是 :  SqList的 elem为默认容量, length = 0, listsize = 默认长度*/
	(*L).length = 0;
	(*L).listsize = LIST_INIT_SIZE;
	
	
	return OK;
	
}

void ClearList_Sq(SqList* L) {
	/*CC:清空List 便是 将 长度置为0*/
	/*QA:elem 是 指向 存储空间的指针, 仅 指示位置, 并不直接存储元素,所以 无需 对 elme中的元素进行处理(即 不需要释放内存) */
	(*L).length = 0;
}

void DestroyList_Sq(SqList* L) {
	free((*L).elem);  // 释放内存

	/*CC:销毁是 彻底的清空  释放内存后 重置指针*/
	(*L).elem = NULL;
	(*L).length = 0;
	(*L).listsize = 0;
}

Status ListEmpty_Sq(SqList L)
{
	return 	L.length==0 ? TRUE : FALSE;
}

int ListLength_Sq(SqList L) {
	return L.length;
}

Status GetElem_Sq(SqList L, int i, LElemType_Sq* e) {
	/*AD: 空表 或 位置i不合法 ;  ⁉️ 空表(L.length == 0) 的判定 可 通过 i > L.length 进行替代,故省略*/
	if (i < 1 || i > L.length) {
		return ERROR;
	}else{
		/*CC: 位置转下标 , 可返回 元素*/
		*e = L.elem[i - 1];    // i是 位置, 需 转为 下标
		return OK;
	}

	
}

int LocateElem_Sq(SqList L, LElemType_Sq e, Status(Compare)(LElemType_Sq, LElemType_Sq)) {
	if (L.length == 0) {
		return ERROR;		// AD:异常判定,如果是 空表,且没有在 前置 进行判定, 则 存在  空表中查找永远返回1的问题;
	}
	int i = 1;   // i: 迭代变量
	//Compare函数 是 理解侧重点
	while (i <= L.length && !Compare(e, L.elem[i - 1])) {    
		++i;
	}
	
	// 返回值 是  位置 (1 ~ L.length) 返回值 非空 是 有效, 返回是 0 则 无效
	if (i <= L.length){
		return i;
	}else {
		return 0;
	}
	
}

Status PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq* pre_e) {
	if (L.length == 0){    // 空表直接跳出, 非空表 继续执行
		return ERROR;
	}
//	assert(L.length > 0); // 如果为空表, 直接跳出, 不继续执行
	int i = 1;    // 迭代变量 & 位置
	if (L.elem[0] != cur_e){     // 第一个节点 无前驱;   CC:SqList  中的元素 需 唯一非重复, 否则可能出现  (2,1,2) 此时 的判定就会有误
		while (i < L.length && L.elem[i] != cur_e) {
			++i;
		}
		// CC : 此处 i 有两种 结果 (i < L.length,说明找到 , i == L.length, 说明 没找到)
		/* QA:边界 判定条件就是 i = L.length ?
			  因为 循环迭代的目的是 从第二个元素 开始找 前驱节点, 最后一个 有前驱节点的是 最后一个节点, 
			  最后一个节点对应的位置i == L.Length*/
		if (i < L.length){
			*pre_e = L.elem[i - 1];
			return OK;
		}
		
	}

	return ERROR;
}

Status NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq* next_e) {
	/*AD: 空表跳出,非空表 继续执行*/
	if (L.length == 0) {
		return  ERROR;
	}
	
	int i = 0;  // 迭代变量 & 下标
	while (i < L.length && L.elem[i] != cur_e) {
		++i;
	}
	// 边界判定条件 i = (L.length -1)  最后一个元素没有后继节点,所以i 应是 在 倒数第二个节点处 停止迭代
	if (i < L.length - 1){
		*next_e = L.elem[i + 1];
		return OK;
	}

	return ERROR;

}

/*════╗
║算法2.4 ║
╚════*/
Status ListInsert_Sq(SqList* L, int i, LElemType_Sq e) {
	if (i < 1 || i > (*L).length + 1){
		return ERROR;		// AD:插入位置不合法,直接跳出 防御式编程
	}

	LElemType_Sq* newbase;    //Aim: 容量扩增 使用,如果不扩增,不使用,可忽略
	LElemType_Sq* p, * q;
	
	if((*L).length >= (*L).listsize){			//AD:存储空间已满,开辟新空间
		// QA :malloc 与 realloc函数的区别
		newbase = (LElemType_Sq*)realloc((*L).elem, ((*L).listsize + LISTINCREMENT) * sizeof(LElemType_Sq));
		
		if(!newbase){
			exit(OVERFLOW);
		}
		
		(*L).elem = newbase;
		(*L).listsize += LISTINCREMENT;
	}
	
	q = &(*L).elem[i - 1];   // 获取 位置i 对应的 元素, 作为 循环截止条件 
	//CC: 遵循朴素统一的 插入原则: 从后往前,对于每一个 ,后移1位
	for(p = &(*L).elem[(*L).length -1]; p >= q; --p){
		*(p + 1) = *p;
	}
	
	*q = e;
	(*L).length++;
	
	return OK;
}


/*════╗
║算法2.5 ║ 
╚════*/
Status ListDelete_Sq(SqList *L, int i, LElemType_Sq *e){
	//AD:删除位置不合法或空表 
	if(i < 1 || i > (*L).length){
		return ERROR;
	}
	
	LElemType_Sq *p, *q;		
	
	p  =  &(*L).elem[ i - 1];  	// p为 被删除元素的位置
	*e = *p;
	q = (*L).elem + (*L).length - 1;		//表尾元素位置, ,这里的指针按元素计算, 并不按字节计算, 相当于 指针p + 1;
	
	for(++p; p <= q; ++p){
		*(p - 1) = *p;			// 被删元素之后 左移一位
	}
	
	(*L).length--;			//表长减 1
	return OK ;
}

Status ListTraverse_Sq(SqList L, void(Visit)(LElemType_Sq)){
	if(L.length == 0){
		return ERROR;
	}
	
	int i;
	for(i = 0; i < L.length; i++){
		Visit(L.elem[i]);
	}
	
	return OK;
}

Status ListUpdateElem_Sq(SqList *L, int i, LElemType_Sq e)
{
	if(i < 0 || i > (*L).length){
		return ERROR; // 空表或者更新位置不合法, 直接跳出
	}
	// 更新位置合法,且非空表,则继续执行 , i为位置,需转为下标 
	(*L).elem[i - 1] = e;
	return  OK;
}

#endif 

