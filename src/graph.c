/* graph.c - 图的实现 */
#include "../include/graph.h"

/* 全局变量定义 */
bool visited[MAX_VERTICES];

Status InitMGraph(MGraph *G, int n) {
    G->numVertices = n;
    G->numEdges = 0;
    for (int i = 0; i < n; i++) {
        G->vertices[i] = i;
        for (int j = 0; j < n; j++) {
            G->edges[i][j] = (i == j) ? 0 : INFINITY_VALUE;
        }
    }
    return OK;
}

Status AddEdge(MGraph *G, int i, int j, int weight) {
    if (i < 0 || i >= G->numVertices || j < 0 || j >= G->numVertices) return ERROR;
    G->edges[i][j] = weight;
    G->edges[j][i] = weight;
    G->numEdges++;
    return OK;
}

static void DFS_MGraph(MGraph G, int i) {
    visited[i] = true;
    printf("%d ", G.vertices[i]);
    for (int j = 0; j < G.numVertices; j++) {
        if (G.edges[i][j] != INFINITY_VALUE && !visited[j]) {
            DFS_MGraph(G, j);
        }
    }
}

void DFSTraverse_MGraph(MGraph G) {
    for (int i = 0; i < G.numVertices; i++) visited[i] = false;
    printf("DFS: ");
    for (int i = 0; i < G.numVertices; i++) {
        if (!visited[i]) DFS_MGraph(G, i);
    }
    printf("\n");
}

void BFS_MGraph(MGraph G) {
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    for (int i = 0; i < G.numVertices; i++) visited[i] = false;
    printf("BFS: ");
    for (int i = 0; i < G.numVertices; i++) {
        if (!visited[i]) {
            visited[i] = true;
            printf("%d ", G.vertices[i]);
            queue[rear++] = i;
            while (front < rear) {
                int u = queue[front++];
                for (int v = 0; v < G.numVertices; v++) {
                    if (G.edges[u][v] != INFINITY_VALUE && !visited[v]) {
                        visited[v] = true;
                        printf("%d ", G.vertices[v]);
                        queue[rear++] = v;
                    }
                }
            }
        }
    }
    printf("\n");
}

Status Dijkstra(MGraph G, int start, int dist[]) {
    bool final[MAX_VERTICES];
    for (int i = 0; i < G.numVertices; i++) {
        final[i] = false;
        dist[i] = G.edges[start][i];
    }
    dist[start] = 0;
    final[start] = true;
    for (int i = 1; i < G.numVertices; i++) {
        int min = INFINITY_VALUE;
        int k = -1;
        for (int j = 0; j < G.numVertices; j++) {
            if (!final[j] && dist[j] < min) {
                min = dist[j];
                k = j;
            }
        }
        if (k == -1) break;
        final[k] = true;
        for (int j = 0; j < G.numVertices; j++) {
            if (!final[j] && G.edges[k][j] != INFINITY_VALUE) {
                if (dist[k] + G.edges[k][j] < dist[j]) {
                    dist[j] = dist[k] + G.edges[k][j];
                }
            }
        }
    }
    return OK;
}

void PrintMGraph(MGraph G) {
    printf("邻接矩阵:\n");
    for (int i = 0; i < G.numVertices; i++) {
        for (int j = 0; j < G.numVertices; j++) {
            if (G.edges[i][j] == INFINITY_VALUE) printf("∞ ");
            else printf("%d ", G.edges[i][j]);
        }
        printf("\n");
    }
}