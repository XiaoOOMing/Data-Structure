//
//  Graph.h
//  11多文件开发
//
//  Created by 劢克科技 on 2020/1/15.
//  Copyright © 2020 meckey. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#include "../Queue/Queue.h"

// 邻接矩阵法
// 空间复杂度为(nxn)，只适合保存稠密图，否则会浪费大量的空间
#define MAX_VEX_NUM 100
typedef int VertexType;
typedef int EdgeType;
typedef struct {
    VertexType Vex[MAX_VEX_NUM];
    EdgeType Edge[MAX_VEX_NUM][MAX_VEX_NUM];
    int vexnum, arcnum;
} MGraph;

// 邻接表法
// 适合稀疏图
typedef struct ArcNode {
    int vexindex;
    struct ArcNode *next;
} ArcNode;

typedef struct {
    VertexType data;
    ArcNode *first;
} VNode, VNodeList[MAX_VEX_NUM];

typedef struct {
    VNodeList vexs;
    int vexnum, arcnum;
} ALGraph;

// 十字链表
// 适合有向图，很容易找到出边和入边
typedef struct TArcNode {
    int tailtex, headtex;
    struct TArcNode *tlink, *hlink;
} TArcNode;

typedef struct TVNode {
    VertexType data;
    ArcNode *firstin, *firstout;
} TVNode;

typedef struct TGraph {
    TVNode vlists[MAX_VEX_NUM];
    int vexnum, arcnum;
} TGraph;

// 邻接多重表
// 适合无向图，是邻接表的优化
typedef struct MArcNode {
    int ivex, jvex;
    struct MArcNode *inode, *jnode;
} MArcNode;

typedef struct MVNode {
    VertexType data;
    MArcNode *arcnode;
} MVNode;

typedef struct MulGraph {
    MVNode nodelists[MAX_VEX_NUM];
    int vexnum, arcnum;
} MulGraph;

// 抽象的图
typedef struct Graph {
    VertexType vexlist[MAX_VEX_NUM];
} Graph;


/*------------Base Functions---------------*/

int VexNumber(MGraph *G, VertexType v);

int FirstNeighbor(MGraph *G, VertexType v);

int NextNeighbor(MGraph *G, VertexType v, VertexType w);

void BFS(MGraph *G, int v);

void BFSTraverse(MGraph *G);

void DFS(MGraph *G, int v);

void DFSTraverse(MGraph *G);

void BFS_MIN_Distance(MGraph *G, int u);

void MST_Prim(MGraph *G);

void MST_Prim2(MGraph *G);

void Dijkstra(MGraph G, int v);

void Floyd(MGraph G);
#endif /* Graph_h */
