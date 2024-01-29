/********************************
 *                              *
 * 文件夹: ▲02 线性表\02 Union *
 *                              *
 * 文件名: Union.c              *
 *                              *
 * 算  法: 2.1                  * 
 *                              *
 ********************************/

#ifndef UNION_C
#define UNION_C

#include "Union.h"

void Union(SqList *La, SqList Lb){
	int La_len, Lb_len;
	int i;
	LElemType_Sq e;
	
	La_len = ListLength_Sq(*La);
	Lb_len = ListLength_Sq(Lb);
	
	for(i = 1; i <= Lb_len; i++){
		GetElem_Sq(Lb, i, &e);
		if(!LocateElem_Sq(*La, e, equal)){
			ListInsert_Sq(La, ++La_len, e);
		}
	}
}


Status equal(LElemType_Sq e1, LElemType_Sq e2){
	return e1 == e2 ? TRUE : FALSE;
}
#endif
