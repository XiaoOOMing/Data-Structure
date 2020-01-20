//
//  BiTree.h
//  11多文件开发
//
//  Created by 劢克科技 on 2020/1/13.
//  Copyright © 2020 meckey. All rights reserved.
//

#ifndef BiTree_h
#define BiTree_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef MAX_SIZE
#define MAX_SIZE 100
#endif

#ifndef ElemType
typedef int ElemType;
#endif

// 二叉树
typedef struct BiNode {
    ElemType data;
    struct BiNode *lchild, *rchild;
} BiNode, BiTree;

// 线索二叉树
typedef struct ThreadNode {
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadTree, ThreadNode;

// 双亲表示法
typedef struct {
    ElemType data;
    int parent;
} PNode;

typedef struct {
    PNode nodes[MAX_SIZE];
    int n;
} PTree;

// 孩子表示法
typedef struct CNode {
    int child;
    struct CNode *next;
} CNode;

typedef struct {
    ElemType data;
    CNode *child;
} CPNode;

typedef struct {
    CPNode nodes[MAX_SIZE];
    int n;
} CTree;

// 孩子兄弟表示法
typedef struct CSNode {
    ElemType data;
    struct CSNode *firstChild, *nextSibling;
} CSTree;

#endif /* BiTree_h */
