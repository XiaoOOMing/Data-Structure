//
//  Queue.c
//  11多文件开发
//
//  Created by 劢克科技 on 2020/1/9.
//  Copyright © 2020 meckey. All rights reserved.
//

#include "Queue.h"

// 初始化队列
void InitQueue(SqQueue *Q) {
    Q->front = 0;
    Q->rare = 0;
}

// 判断队空
int QueueEmpty(SqQueue *Q) {
    return Q->front == Q->rare;
}

// 队列长度
int QueueLen(SqQueue *Q) {
    return (Q->rare - Q->front + MAX_SIZE) % MAX_SIZE;
}

// 入队
int EnQueue(SqQueue *Q, ElemType x) {
    if ((Q->rare + 1) % MAX_SIZE == Q->front)
        return 0;
    
    Q->data[Q->rare] = x;
    Q->rare = (Q->rare + 1) % MAX_SIZE;
    
    return 1;
}

// 出队
int DeQueue(SqQueue *Q, ElemType *x) {
    if (QueueEmpty(Q))
        return 0;
    
    *x = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAX_SIZE;
    
    return 1;
}


/*--------------链队----------------*/


// 初始化链队
void InitLiQueue(LiQueue *Q) {
    Q->front = (LinkNode*)malloc(sizeof(LinkNode));
    Q->rare = Q->front;
    Q->front->next = NULL;
}

// 判断队空
int LiQueueEmpty(LiQueue *Q) {
    return Q->front == Q->rare;
}

// 入队
void EnLiQueue(LiQueue *Q, ElemType x) {
    LinkNode *node = (LinkNode*)malloc(sizeof(LinkNode));
    node->data = x;
    node->next = Q->rare->next;
    Q->rare->next = node;
    Q->rare = node;
}

// 出队
int DeLiQueue(LiQueue *Q, ElemType *x) {
    if (LiQueueEmpty(Q))
        return 0;
    
    LinkNode *p = Q->front->next;
    *x = p->data;
    Q->front->next = p->next;
    if (Q->rare == p)
        Q->rare = Q->front;
    free(p);
    
    return 1;
}
