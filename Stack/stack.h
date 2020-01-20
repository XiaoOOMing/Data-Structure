//
//  stack.h
//  11多文件开发
//
//  Created by 劢克科技 on 2020/1/9.
//  Copyright © 2020 meckey. All rights reserved.
//

#ifndef stack_h
#define stack_h

#ifndef MAX_SIZE
#define MAX_SIZE 100
#endif

#ifndef ElemType
typedef int ElemType;
#endif

#include <stdio.h>
#include <stdlib.h>

// 顺序栈
typedef struct {
    ElemType data[MAX_SIZE];
    int top;
} SqStack;

// 初始化
void InitStack(SqStack *S);

// 判断栈空
int StackEmpty(SqStack S);

// 入栈
int Push(SqStack *S, ElemType x);

// 出栈
int Pop(SqStack *S, ElemType *x);

// 读取栈顶元素
int GetTop(SqStack *S, ElemType *x);

// 释放栈
void ClearStack(SqStack *S);


/* -----------链栈------------- */


// 链栈
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LiStack, LNode;

// 初始化链栈
void InitLiStack(LiStack *S);

// 判断栈空
int LiStackEmpty(LiStack *S);

// 入栈
int LiPush(LiStack *S, ElemType x);

// 出栈
int LiPop(LiStack *S, ElemType *x);

// 读取栈顶元素
int GetLiTop(LiStack *S, ElemType *x);

#endif /* stack_h */
