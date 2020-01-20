//
//  Graph.c
//  11多文件开发
//
//  Created by 劢克科技 on 2020/1/15.
//  Copyright © 2020 meckey. All rights reserved.
//

#include "Graph.h"

/*------------Base Functions---------------*/

int VexNumber(MGraph *G, VertexType v) {
    for (int i = 0; i < G->vexnum; i++) {
        if (G->Vex[i] == v) {
            return i;
        }
    }
    return -1;
}

int FirstNeighbor(MGraph *G, VertexType v) {
    for (int i = 0; i < G->vexnum; i++) {
        if (G->Edge[v][i] > 0) {
            return i;
        }
    }
    return -1;
}

int NextNeighbor(MGraph *G, VertexType v, VertexType w) {
    for (int i = w + 1; i < G->vexnum; i++) {
        if (G->Edge[v][i] > 0) {
            return i;
        }
    }
    return -1;
}

void visit(VertexType v) {
    printf("%d ", v+1);
}

/*------------BFS广度优先搜索---------------*/

bool visited[MAX_VEX_NUM];

// 循环顶点，让每个顶点执行BFS

void BFSTraverse(MGraph *G) {
    for (int i = 0; i < G->vexnum; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < G->vexnum; i++) {
        if (visited[i] == 0) {
            BFS(G, i);
        }
    }
    printf("\n");
}

void BFS(MGraph *G, int v) {
    // 访问顶点然后入队
    // 出队，遍历所有相邻顶点，如果没有在visited数组中，执行访问，加入visited，入队
    // 循环上述条件知道队列为空
    // 一句话总结：点附近的点，对其访问然后入队，全局数组记录访问记录。（类似树的层次遍历）
    
    SqQueue Sq;
    SqQueue *Q = &Sq;
    InitQueue(Q);
    
    visit(v);
    visited[v] = 1;
    EnQueue(Q, v);
    
    while (!QueueEmpty(Q)) {
        DeQueue(Q, &v);
        for (int w = FirstNeighbor(G, v); w>=0; w=NextNeighbor(G, v, w)) {
            if (visited[w] == 0) {
                visit(w);
                visited[w] = 1;
                EnQueue(Q, w);
            }
        }
    }
}

// 空间复杂度O(V)
// 邻接矩阵时间复杂度 O(V*V)
// 邻接表时间复杂度 O(V+E)

void BFS_MIN_Distance(MGraph *G, int u) {
    int d[G->vexnum];
    for (int i = 0; i < G->vexnum; i++) {
        d[i] = -1;
    }
    SqQueue Sq;
    SqQueue *Q = &Sq;
    InitQueue(Q);

    visited[u] = 1;
    d[u] = 0;
    EnQueue(Q, u);
    while (!QueueEmpty(Q)) {
        DeQueue(Q, &u);
        for (int w = FirstNeighbor(G, u); w>=0; w=NextNeighbor(G, u, w)) {
            if (visited[w] == 0) {
                visited[w] = 1;
                EnQueue(Q, w);
                d[w] = d[u] + 1;
            }
        }
    }
    for (int i = 0; i < G->vexnum; i++) {
        printf("%d->%d:%d ", 1, i+1,d[i]);
    }
    printf("\n");
}

/*------------DFS深度优先搜索---------------*/

void DFSTraverse(MGraph *G) {
    for (int i = 0; i < G->vexnum; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < G->vexnum; i++) {
        if (visited[i] == 0) {
            DFS(G, i);
        }
    }
    printf("\n");
}

void DFS(MGraph *G, int v) {
    // 访问v，加入visited数组中
    // 遍历v的所有邻居顶点，如果顶点未被访问，递归DFS(G, w)
    // 总结：访问 然后递归，全局数组记录访问记录。
    visit(v);
    visited[v] = 1;
    for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
        if (visited[w] == 0) {
            DFS(G, w);
        }
    }
}

// 空间复杂度O(V)
// 邻接矩阵时间复杂度 O(V*V)
// 邻接表时间复杂度 O(V+E)


/*---------------Prim最小生成树------------------*/

void MST_Prim(MGraph *G) {
    int min_weight[G->vexnum];
    int adjvex[G->vexnum];
    for (int i = 0; i < G->vexnum; i++) {
        min_weight[i] = G->Edge[0][i];
        adjvex[i] = 0;
    }
    
    int min_arc = 0, min_vex = 0;
    
    for (int i = 1; i < G->vexnum; i++) {
        min_arc = INT_MAX;
        for (int j = 1; j < G->vexnum; j++) {
            if (min_weight[j] != 0 && min_weight[j] < min_arc) {
                min_arc = min_weight[j];
                min_vex = j;
            }
        }
        min_weight[min_vex] = 0;
        for (int j = 0; j < G->vexnum; j++) {
            if (min_weight[j] != 0 && G->Edge[min_vex][j] < min_weight[j]) {
                min_weight[j] = G->Edge[min_vex][j];
                adjvex[j] = min_vex;
            }
        }
    }
    
    for (int i = 0; i < G->vexnum; i++) {
           printf("%d ", min_weight[i]);
       }
       printf("\n");
       for (int i = 0; i < G->vexnum; i++) {
           printf("%d ", adjvex[i]);
       }
       printf("\n");
}

void MST_Prim2(MGraph *G) {
    int min_weight[G->vexnum];
    int adjvex[G->vexnum];
    for (int i = 0; i < G->vexnum; i++) {
        min_weight[i] = G->Edge[0][i];
        adjvex[i] = 0;
    }
    
    int min_arc, min_vex = 0;
    
    for (int i = 1; i < G->vexnum; i++) {
        min_arc = INT_MAX;
        for (int j = 1; j < G->vexnum; j++) {
            if (min_weight[j] != 0 && min_weight[j] < min_arc) {
                min_arc = min_weight[j];
                min_vex = j;
            }
        }
        min_weight[min_vex] = 0;
        for (int j = 1; j < G->vexnum; j++) {
            if (min_weight[j] != 0 && G->Edge[min_vex][j] < min_weight[j]) {
                min_weight[j] = G->Edge[min_vex][j];
                adjvex[j] = min_vex;
            }
        }
    }
    
    for (int i = 0; i < G->vexnum; i++) {
        printf("%d ", min_weight[i]);
    }
    printf("\n");
    for (int i = 0; i < G->vexnum; i++) {
        printf("%d ", adjvex[i]);
    }
    printf("\n");
}


/*---------------Kruskal最小生成树------------------*/

typedef struct Edge {
    int a, b;
    int weight;
} Edge;

void MST_Kruskal(MGraph G, Edge *egdes, int *parent) {
    // 1. 对edges进行堆排序（从小到大排序）
    // 2. 初始化parent（设为-1）
    
    int num = G.vexnum - 1;
    for (int i = 0; i < G.arcnum && num >= 0; i++, num--) {
        // a = find(parent, egdes[i].a)
        // b = find(parent, egdes[i].b)
        // if a != b => union(parent, a, b)
    }
}

// 时间复杂度：O(E * logE)


/*---------------Dijkstra------------------*/

/*
    dist          s            path
 0 5 3 ∞ 8    1 0 0 0 0    -1 0 0 -1 0
 0 5 3 ∞ 7    1 0 1 0 0    -1 0 0 -1 2
 0 5 3 6 7    1 1 1 0 0    -1 0 0 1 2
 0 5 3 6 7    1 1 1 1 0    -1 0 0 1 2
 0 5 3 6 7    1 1 1 1 1    -1 0 0 1 2
 */

void Dijkstra(MGraph G, int v) {
    int dist[G.vexnum];
    int s[G.vexnum];
    int path[G.vexnum];
    for (int i = 0; i < G.vexnum; i++) {
        dist[i] = G.Edge[v][i];
        s[i] = 0;
        if (G.Edge[v][i] < INT_MAX) {
            path[i] = 0;
        } else {
            path[i] = -1;
        }
    }
    s[v] = 1;
    path[v] = -1;
    
    for (int i = 1; i < G.vexnum; i++) {
        
        // 找到最小的dist的顶点
        int min_vex = INT_MAX, min_vex_i = 0;
        for (int j = 0; j < G.vexnum; j++) {
            if (s[j] == 0 && dist[j] < min_vex) {
                min_vex_i = j;
                min_vex = dist[j];
            }
        }
        
        // 将最小dist顶点设为已处理
        s[min_vex_i] = 1;
        
        // 找到最小顶点出边距离小于dist数组中的值，并且修改dist和path
        for (int j = 0; j < G.vexnum; j++) {
            if (G.Edge[min_vex_i][j] > 0 && G.Edge[min_vex_i][j] < INT_MAX) {
                int v_dist = dist[j];
                int m_dist = dist[min_vex_i] + G.Edge[min_vex_i][j];
                if (m_dist < v_dist) {
                    dist[j] = m_dist;
                    path[j] = min_vex_i;
                }
            }
        }
    }
    
    for (int i = 0; i < G.vexnum; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");
    for (int i = 0; i < G.vexnum; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");
    for (int i = 0; i < G.vexnum; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

// 不使用于带有负权重的图
// 时间复杂度O(v*v)

