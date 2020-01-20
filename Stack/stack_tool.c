//
//  stack_tool.c
//  11多文件开发
//
//  Created by 劢克科技 on 2020/1/9.
//  Copyright © 2020 meckey. All rights reserved.
//

#include "stack_tool.h"

// 括号匹配问题
/**
 依次读入括号
 1. 如果是(，入栈
 2. 如果是)，出栈，若栈空则错误
 3. 若遍历完毕，栈非空则错误
 */
//int parenthesisValid(char *s) {
//    unsigned long len = strlen(s);
//    SqStack *S = (SqStack*)malloc(sizeof(SqStack));
//    InitStack(S);
//    
//    if (len == 0)
//        return 1;
//    
//    for (int i = 0; i < len; i++) {
//        if (s[i] == '(')
//            Push(S, s[i]);
//        else {
//            char c;
//            if (!Pop(S, &c)) {
//                return 0;
//            }
//        }
//    }
//    
//    return StackEmpty(*S);
//}

// 斐波那契数列
// 栈的应用：递归转换为非递归算法
int fib(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n-1) + fib(n-2);
}

int fib2(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    
    SqStack *S = (SqStack*)malloc(sizeof(SqStack));
    InitStack(S);
    int temp;
    Push(S, 0);
    Push(S, 1);
    for (int i = 0; i < n - 2; i++) {
        temp = S->data[S->top] + S->data[S->top-1];
        Push(S, temp);
    }
    return S->data[S->top] + S->data[S->top - 1];
}
