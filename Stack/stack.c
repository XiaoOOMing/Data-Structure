//
//  stack.c
//  11多文件开发
//
//  Created by 劢克科技 on 2020/1/9.
//  Copyright © 2020 meckey. All rights reserved.
//

#include "stack.h"

// 初始化
void InitStack(SqStack *S) {
    S->top = -1;
}

// 判断栈空
int StackEmpty(SqStack S) {
    return S.top == -1;
}

// 入栈
int Push(SqStack *S, ElemType x) {
    if (S->top == MAX_SIZE - 1)
        return 0;
    
    S->data[++S->top] = x;
    
    return 1;
}

// 出栈
int Pop(SqStack *S, ElemType *x) {
    if (StackEmpty(*S))
        return 0;
    
    *x = S->data[S->top--];
    
    return 1;
}

// 读取栈顶元素
int GetTop(SqStack *S, ElemType *x) {
    if (StackEmpty(*S))
        return 0;
    
    *x = S->data[S->top];
    
    return 1;
}

// 释放栈
void ClearStack(SqStack *S) {
    free(S);
}


/* -----------链栈------------- */


// 初始化链栈
void InitLiStack(LiStack *S) {
    S->next = NULL;
    S->data = 0;
}

// 判断栈空
int LiStackEmpty(LiStack *S) {
    return S->next == NULL;
}

// 入栈
int LiPush(LiStack *S, ElemType x) {
    LiStack *node = (LiStack*)malloc(sizeof(LiStack));
    InitLiStack(node);
    
    node->data = x;
    node->next = S->next;
    S->next = node;
    
    return 1;
}

// 出栈
int LiPop(LiStack *S, ElemType *x) {
    if (LiStackEmpty(S))
        return 0;
    
    LiStack *p = S->next;
    *x = p->data;
    S->next = p->next;
    free(p);
    
    return 1;
}

// 读取栈顶元素
int GetLiTop(LiStack *S, ElemType *x) {
    if (LiStackEmpty(S))
        return 0;
    
    *x = S->next->data;
    
    return 1;
}
