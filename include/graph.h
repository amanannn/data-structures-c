/* graph.h - 图头文件 */
#ifndef GRAPH_H
#define GRAPH_H

#include "common.h"

#define INFINITY_VALUE INT_MAX
#define MAX_VERTICES 100

/* 邻接矩阵图结构 */
typedef struct {
    int vertices[MAX_VERTICES];
    int edges[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
    int numEdges;
} MGraph;

/* 全局变量（遍历需要） */
extern bool visited[MAX_VERTICES];

/* 函数声明 */
Status InitMGraph(MGraph *G, int n);
Status AddEdge(MGraph *G, int i, int j, int weight);
void PrintMGraph(MGraph G);
void DFSTraverse_MGraph(MGraph G);
void BFS_MGraph(MGraph G);
Status Dijkstra(MGraph G, int start, int dist[]);

#endif /* GRAPH_H */