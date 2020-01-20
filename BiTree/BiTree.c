//
//  BiTree.c
//  11多文件开发
//
//  Created by 劢克科技 on 2020/1/13.
//  Copyright © 2020 meckey. All rights reserved.
//

#include "BiTree.h"

/*--------------ThreadTree-----------------*/

void InThread(ThreadTree *p, ThreadNode *pre) {
    if (p != NULL) {
        InThread(p->lchild, pre);
        
        if (p->lchild == NULL) {
            p->ltag = 1;
            p->lchild = pre;
        }
        
        if (pre != NULL && pre->rchild == NULL) {
            pre->rtag = 1;
            pre->rchild = p;
        }
        pre = p;
        
        InThread(p->rchild, pre);
    }
}

void CreateThreadThree(ThreadTree *T) {
    ThreadNode *pre = NULL;
    if (T != NULL) {
        InThread(T, pre);
        pre->rtag = 1;
        pre->rchild = NULL;
    }
}

ThreadNode* FirstNode(ThreadTree *p) {
    while (p->ltag == 0) {
        p = p->lchild;
    }
    return p;
}

ThreadNode* NextNode(ThreadTree *p) {
    if (p->rtag == 1)
        return p;
    else
        return FirstNode(p->rchild);
}

void ThreadInOrder(ThreadTree *T) {
    ThreadNode *p = FirstNode(T);
    for (; p!=NULL; p = NextNode(p)) {
        printf("%d\n", p->data);
    }
}


/*---------------BST---------------*/

BiNode* BST_Search(BiTree *T, ElemType x) {
    BiTree *p = T;
    while (p != NULL && p->data != x) {
        if (p->data > x)
            p = p->lchild;
        else
            p = p->rchild;
    }
    return p;
}

int BST_Insert(BiTree *T, ElemType x) {
    if (T == NULL) {
        T = (BiNode*)malloc(sizeof(BiNode));
        T->data = x;
        T->lchild = NULL;
        T->rchild = NULL;
        return 1;
    } else if (T->data == x) {
        return 0;
    } else {
        if (T->data > x)
            return BST_Insert(T->lchild, x);
        else
            return BST_Insert(T->rchild, x);
    }
}

void BST_Create(BiTree *T, ElemType *arr, int len) {
    T = NULL;
    for (int i = 0; i < len; i++) {
        BST_Insert(T, arr[i]);
    }
}


/*---------------AVL-----------------*/

/*
 高度为h的最小平衡二叉树的结点数：Nh = Nh-1 + Nh-2 + 1
 N0 = 0; N1 = 1;
 */

void Judge_Balance(BiTree *p, int *b, int *h) {
    int bl = 0, br = 0, hl = 0, hr = 0;
    if (p == NULL) {
        *b = 1;
        *h = 0;
    } else if (p->lchild == NULL && p->rchild == NULL) {
        *b = 1;
        *h = 0;
    } else {
        Judge_Balance(p->lchild, &bl, &hl);
        Judge_Balance(p->rchild, &br, &hr);
        
        if (hl > hr)
            *h = hl + 1;
        else
            *h = hr + 1;
        
        if (abs(hl - hr) < 2 && bl == 1 && br == 1)
            *b = 1;
    }
}
