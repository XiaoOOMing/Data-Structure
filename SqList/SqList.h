//
//  SqList.h
//  11多文件开发
//
//  Created by 劢克科技 on 2020/1/14.
//  Copyright © 2020 meckey. All rights reserved.
//

#ifndef SqList_h
#define SqList_h

#include <stdio.h>
#include <stdlib.h>

#ifndef MAX_SIZE
#define MAX_SIZE 100
#endif

#ifndef ElemType
typedef int ElemType;
#endif


/*----------Base Functions-----------*/

typedef struct {
    ElemType data[MAX_SIZE];
    int length;
} SqList;

void InitSqList(SqList *L);

int SqListInsert(SqList *L, int i, ElemType x);

int SqListDelete(SqList *L, int i, ElemType *e);

int LocaleElem(SqList *L, ElemType e);

/*-----------Function-----------*/

void SqMaxMin(SqList *L, ElemType *max, ElemType *min);

void SqReverse(SqList *L);

void SqMerge(SqList *L1, SqList *L2);

void deleteMinVal(SqList *L, ElemType *x);

void DeleteX(SqList *L, ElemType x);

int DeleteRange(SqList *L, ElemType s, ElemType t);

int DeleteRepeat(SqList *L);

int BinarySearch(SqList *L, ElemType x);

int MainElem(int *A, int n);

int MinInteger(int A[], int n);
#endif /* SqList_h */
