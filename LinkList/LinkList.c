//
//  LinkList.c
//  11多文件开发
//
//  Created by 劢克科技 on 2020/1/14.
//  Copyright © 2020 meckey. All rights reserved.
//

#include "LinkList.h"


/*-----------Base Function-----------*/

LinkList* InitLinkList() {
    LinkList *L = (LinkList*)malloc(sizeof(LinkList));
    L->data = 0;
    L->next = NULL;
    return L;
}

void PrintLiList(LinkList *L) {
    LinkList *p = L->next;
    printf("------Print LiList-------\n");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void HeadInsert(LinkList *L) {
    ElemType x = 0;
    printf("Please input number:\n");
    scanf("%d", &x);
    while (x != 0) {
        LNode *node = InitLinkList();
        node->data = x;
        node->next = L->next;
        L->next = node;
        printf("Please input number:\n");
        scanf("%d", &x);
    }
}

void TailInsert(LinkList *L) {
    LNode *r = L;
    ElemType x = 0;
    printf("Please input number:\n");
    scanf("%d", &x);
    while (x != 0) {
        LNode *node = InitLinkList();
        node->data = x;
        node->next = r->next;
        r->next = node;
        r = node;
        printf("Please input number:\n");
        scanf("%d", &x);
    }
}

LNode* LinkListGetElem(LinkList *L, int i) {
    LNode *p = L;
    if (i == 0)
        return L;
    if (i < 1)
        return NULL;
    for (int j = 0; j < i && p != NULL; j++)
        p = p->next;
    return p;
}

LNode* LinkListLocateElem(LinkList *L, ElemType e) {
    LNode *p = L->next;
    while (p->data != e && p != NULL)
        p = p->next;
    return p;
}


/*-----------Function-----------*/

void LiMaxMin(LinkList *L, int *max, int *min) {
    LNode *p = L->next;
    *max = *min = p->data;
    while (p != NULL) {
        if (p->data < *min)
            *min = p->data;
        if (p->data > *max)
            *max = p->data;
        p = p->next;
    }
}

void LiReverse(LinkList *L) {
    if (L == NULL)
        return;
    LNode *r = L->next, *p = L, *temp;
    while (r->next != NULL)
        r = r->next;
    while (p->next != r) {
        temp = p->next;
        p->next = temp->next;
        temp->next = r->next;
        r->next = temp;
    }
}

void LiMerge(LinkList *L1, LinkList *L2) {
    LinkList *L3 = InitLinkList();
    LNode *r = L3;
    while (L1->next != NULL && L2->next != NULL) {
        if (L1->next->data < L2->next->data) {
            r->next = L1->next;
            L1->next = L1->next->next;
            r = r->next;
        } else {
            r->next = L2->next;
            L2->next = L2->next->next;
            r = r->next;
        }
    }
    if (L1->next != NULL)
        r->next = L1->next;
    if (L2->next != NULL)
        r->next = L2->next;
    free(L1);
    free(L2);
    PrintLiList(L3);
}

void DeleteLinkListX(LinkList *L, ElemType x) {
    LNode *p = L->next, *pre = L;
    while (p != NULL) {
        if (p->data == x) {
            pre->next = p->next;
            free(p);
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
}

void R_Print(LinkList *L) {
    if (L != NULL) {
        R_Print(L->next);
        printf("%d ", L->data);
    }
}

void DeleteLinkListMini(LinkList *L) {
    LNode *pre = L, *p = L->next, *min_pre = L, *min = L->next;
    
    while (p != NULL) {
        if (p->data < min->data) {
            min = p;
            min_pre = pre;
        }
        pre = p;
        p = p->next;
    }
    
    min_pre->next = min->next;
    free(min);
}

LinkList * sortLinkList(LinkList *L) {
    LNode *pre, *p = L->next, *r = L->next->next, *temp;
    p->next = NULL;
    
    while (r != NULL) {
        p = L->next;
        pre = L;
        while (p != NULL && p->data < r->data) {
            pre = p;
            p = p->next;
        }
        
        temp = r;
        r = r->next;
        temp->next = pre->next;
        pre->next = temp;
    }
    
    return L;
}

void RangeDelete(LinkList *L, int min, int max) {
    LinkList *pre = L, *p = L->next;
    while (p != NULL) {
        if (p->data >= min && p->data <= max) {
            pre->next = p->next;
            free(p);
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
}
