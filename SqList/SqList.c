//
//  SqList.c
//  11多文件开发
//
//  Created by 劢克科技 on 2020/1/14.
//  Copyright © 2020 meckey. All rights reserved.
//

#include "SqList.h"


/*----------Base Functions-----------*/

void InitSqList(SqList *L) {
    L->length = 0;
}

int SqListInsert(SqList *L, int i, ElemType x) {
    if (i < 1 || i > MAX_SIZE + 1)
        return 0;
    if (L->length == MAX_SIZE)
        return 0;
    
    for (int j = L->length; j >= i; j++) {
        L->data[j] = L->data[j - 1];
    }
    
    L->data[i - 1] = x;
    L->length++;
    
    return 1;
}

int SqListDelete(SqList *L, int i, ElemType *e) {
    if (i < 1 || i > L->length)
        return 0;
    L->data[i - 1] = *e;
    for (int j = i; j < L->length; j++)
        L->data[j - 1] = L->data[j];
    L->length--;
    return 1;
}

int LocaleElem(SqList *L, ElemType e) {
    int i = 0;
    for (; i < L->length; i++)
        if (L->data[i] == e)
            return i+1;
    return 0;
}


/*-----------Function-----------*/

void SqMaxMin(SqList *L, ElemType *max, ElemType *min) {
    if (L->length == 0)
        return;
    *max = *min = L->data[0];
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] < *min)
            *min = L->data[i];
        if (L->data[i] > *max)
            *max = L->data[i];
    }
}

void SqReverse(SqList *L) {
    int i = 0, j = L->length - 1;
    ElemType temp;
    while (i < j) {
        temp = L->data[i];
        L->data[i] = L->data[j];
        L->data[j] = temp;
        i++;
        j--;
    }
}

void SqMerge(SqList *L1, SqList *L2) {
    if (L1->length + L2->length >= MAX_SIZE)
        return;
    SqList *L = (SqList*)malloc(sizeof(SqList));
    InitSqList(L);
    int i = 0, j = 0, k = 0;
    while (i < L1->length && j < L2->length) {
        if (L1->data[i] < L2->data[j]) {
            L->data[k++] = L1->data[i++];
            L->length++;
        } else {
            L->data[k++] = L2->data[j++];
            L->length++;
        }
    }
    while (i < L1->length) {
        L->data[k++] = L1->data[i++];
        L->length++;
    }
    while (j < L2->length) {
        L->data[k++] = L2->data[j++];
        L->length++;
    }
}

void deleteMinVal(SqList *L, ElemType *x) {
    ElemType min = L->data[0];
    int min_i = 0;
    for (int i = 1; i < L->length; i++) {
        if (L->data[i] < min) {
            min = L->data[i];
            min_i = i;
        }
    }
    *x = min;
    L->data[min_i] = L->data[L->length-1];
    L->length--;
}

void DeleteX(SqList *L, ElemType x) {
    int k = 0;
    
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] != x) {
            L->data[k++] = L->data[i];
        }
    }
    
    L->length = k;
}

int DeleteRange(SqList *L, ElemType s, ElemType t) {
    if (s >= t) {
        return 0;
    }
    
    int k = 0;
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] < s || L->data[i] > t) {
            L->data[k++] = L->data[i];
        }
    }
    L->length = k;
    return 1;
}

int DeleteRepeat(SqList *L) {
    if (L->length == 0) {
        return 0;
    }
    
    int k = 1;
    for (int i = 1; i < L->length; i++) {
        if (L->data[i] != L->data[i - 1]) {
            L->data[k++] = L->data[i];
        }
    }
    L->length = k;
    return 1;
}

int BinarySearch(SqList *L, ElemType x) {
    int low = 0, high = L->length, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (L->data[mid] == x) {
            return mid;
        } else if (L->data[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// 若x出现的次数m>n/2,则x为主元素。（求众数）
// 找到主元素
int MainElem(int *A, int n) {
    int res = A[0], count = 1, m = 0;
    for (int i = 1; i < n; i++) {
        if (A[i] == res) {
            count++;
        } else if (count == 0) {
            count = 1;
            res = A[i];
        } else {
            count--;
        }
    }
    
    for (int j = 0; j < n; j++) {
        if (A[j] == res) {
            m++;
        }
    }
    if (m > (n / 2)) {
        return res;
    }
    
    return -1;
}

// 找出未出现的最小正整数
int MinInteger(int A[], int n) {
    // 初始化一个长度为n的数组
    int B[n];
    for (int i = 0; i < n; i++) {
        B[n] = 0;
    }
    
    for (int j = 0; j < n; j++) {
        if (A[j] <= n && A[j] > 0) {
            B[A[j] - 1] = 1;
        }
    }
    
    for (int k = 0; k < n; k++) {
        if (B[k] == 0) {
            return k + 1;
        }
    }
    return n + 1;
}
