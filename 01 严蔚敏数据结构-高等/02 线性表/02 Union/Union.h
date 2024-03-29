/********************************
 *                              *
 * 文件夹: ▲02 线性表\02 Union *
 *                              *
 * 文件名: Union.h              *
 *                              *
 * 内  容: 求并集相关操作列表   *
 *                              *
 ********************************/
#ifndef UNION_H
#define UNION_H
#include "../01 SequenceList/SequenceList.c"

/*并集函数列表*/
/*━━━━━━━━━━━┓
┃(01)算法2.1：A=A∪B。 ┃
┗━━━━━━━━━━━*/
void Union(SqList *La, SqList Lb);

/*━━━━━━━━━━━━┓
┃(02)判断两元素是否相等。┃
┗━━━━━━━━━━━━*/
Status equal(LElemType_Sq e1, LElemType_Sq e2);

#endif 
