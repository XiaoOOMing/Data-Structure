//
//  Queue.h
//  11多文件开发
//
//  Created by 劢克科技 on 2020/1/9.
//  Copyright © 2020 meckey. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#ifndef MAX_SIZE
#define MAX_SIZE 100
#endif

#ifndef ElemType
typedef int ElemType;
#endif

#include <stdio.h>
#include <stdlib.h>

// 顺序队
typedef struct {
    ElemType data[MAX_SIZE];
    int front, rare;
} SqQueue;

// 初始化队列
void InitQueue(SqQueue *Q);

// 判断队空
int QueueEmpty(SqQueue *Q);

// 队列长度
int QueueLen(SqQueue *Q);

// 入队
int EnQueue(SqQueue *Q, ElemType x);
// 出队
int DeQueue(SqQueue *Q, ElemType *x);


/*--------------链队----------------*/


typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode;

typedef struct {
    LinkNode *front, *rare;
} LiQueue;

// 初始化链队
void InitLiQueue(LiQueue *Q);

// 判断队空
int LiQueueEmpty(LiQueue *Q);

// 入队
void EnLiQueue(LiQueue *Q, ElemType x);

// 出队
int DeLiQueue(LiQueue *Q, ElemType *x);

#endif /* Queue_h */
