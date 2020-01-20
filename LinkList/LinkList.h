//
//  LinkList.h
//  11多文件开发
//
//  Created by 劢克科技 on 2020/1/14.
//  Copyright © 2020 meckey. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

#include <stdio.h>
#include <stdlib.h>

#ifndef MAX_SIZE
#define MAX_SIZE 100
#endif

#ifndef ElemType
typedef int ElemType;
#endif

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, LinkList;


/*-----------Base Function-----------*/

LinkList* InitLinkList(void);

void HeadInsert(LinkList *L);

void PrintLiList(LinkList *L);

void TailInsert(LinkList *L);

LNode* LinkListGetElem(LinkList *L, int i);

LNode* LinkListLocateElem(LinkList *L, ElemType e);

/*-----------Function-----------*/

void LiMaxMin(LinkList *L, int *max, int *min);

void LiReverse(LinkList *L);

void LiMerge(LinkList *L1, LinkList *L2);

void DeleteLinkListX(LinkList *L, ElemType x);

void R_Print(LinkList *L);

void DeleteLinkListMini(LinkList *L);

LinkList * sortLinkList(LinkList *L);
#endif /* LinkList_h */
