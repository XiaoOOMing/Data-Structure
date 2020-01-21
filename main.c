//
//  main.c
//  11多文件开发
//
//  Created by 劢克科技 on 2019/6/17.
//  Copyright © 2019 meckey. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
#include "Graph/Graph.h"

int main(int argc, const char * argv[]) {
    
    MGraph *G = (MGraph*)malloc(sizeof(Graph));
    
    VertexType arr[] = {0,1,2,3};
    int vex_num = sizeof(arr) / sizeof(VertexType);
    for (int i = 0; i < vex_num; i++) {
        G->Vex[i] = arr[i];
    }
    
    EdgeType e[][4] = {
        {0,1,1,INT_MAX},
        {INT_MAX,0,1,1},
        {INT_MAX,INT_MAX,0,1},
        {INT_MAX,INT_MAX,INT_MAX,0},
    };
    
    for (int i = 0; i < vex_num; i++) {
        for (int j = 0; j < vex_num; j++) {
            G->Edge[i][j] = e[i][j];
        }
    }
    
    G->vexnum = vex_num;
    G->arcnum = 7;
    
//    for (int i = 0; i < vex_num; i++) {
//        printf("%d的第一个邻居编号是%d\n", i, FirstNeighbor(G, i));
//    }
        
    TopologicalSort(*G);
    return 0;
}
