//
// Created by 黎钰晖 on 2019-06-20.
//

#include "GraphAlgorithm.h"
#include "ALGraph.h"

/*
 * 克鲁斯卡尔算法
 */
int edge_cmp(const void *a, const void *b) {
    return (*(Edge *) a).weight - (*(Edge *) b).weight;
}

int get_parent(int *parent, int vertex) {
    while (parent[vertex] != -1) {
        vertex = parent[vertex];
    }
    return vertex;
}

void kruskal(MatGraph graph) {

    int vertexNum = graph->vertexNum;
    int edgeCount = graph->edgeNum;

    //生成点集合,并且置为-1
    int *parent = (int *) malloc(sizeof(int) * vertexNum);
    memset(parent, -1, sizeof(int) * vertexNum);

    //生成边的集合

    //开辟足够的空间
    Edge *edges = (Edge *) malloc(sizeof(Edge) * edgeCount);
    int edge_index = 0;
    for (int i = 0; i < graph->vertexNum; ++i) {
        for (int j = i + 1; j < graph->vertexNum; ++j) {
            if (graph->mat[i][j] != 0) {
                edges[edge_index].begin = i;
                edges[edge_index].end = j;
                edges[edge_index].weight = graph->mat[i][j];
                edge_index++;
            }
        }
    }

    //排序边的集合
    qsort(edges, edgeCount, sizeof(Edge), edge_cmp);

    for (int k = 0; k < edge_index; ++k) {
        Edge *edge = &edges[k];
        printf("生成的边:%d<-->%d, 权重:%d\n", edge->begin + 1, edge->end + 1, edge->weight);

    }
    printf("------------------------\n");
    //生成树算法
    for (int i = 0; i < edge_index; ++i) {
        Edge *edge = &edges[i];
        //判断无环
        int n = get_parent(parent, edge->begin);
        int m = get_parent(parent, edge->end);

        if (n != m) {
            printf("生成的边:%d<-->%d, 权重:%d\n", edge->begin + 1, edge->end + 1, edge->weight);
            parent[n] = m;
        }


    }


}


/*
 * 深度优先搜索
 */

void DFS_Recursive(ALGraph graph,int vertex,int* visited){
    if(visited[vertex] == 1)
        return;
    //访问到当前节点
    visited[vertex] = 1;
    printf("当前访问节点:%d\n",vertex);
    //访问这个节点的所有邻接点
    ALLink* list = graph->vertexs[vertex].nextadj;
    while (list != NULL){
        DFS_Recursive(graph,list->vertex,visited);
        list = list->nextadj;
    }
}


void DFS(ALGraph graph, int vertex) {
    int* visited = (int*)malloc(sizeof(int) * graph->vertexNum);
    memset(visited,0, sizeof(int) * graph->vertexNum);
    DFS_Recursive(graph,vertex,visited);

    for (int i = 0; i < graph->vertexNum; ++i) {
        if(visited[i] == 0){
            printf("存在非联通部分,入口:%d",i);
            DFS_Recursive(graph,i,visited);
        }

    }
}



void BFS(ALGraph graph, int vertex){

    //初始化访问数组
    int* visited = (int*)malloc(sizeof(int) * graph->vertexNum);
    memset(visited,0, sizeof(int) * graph->vertexNum);

    //访问队列
    int* queue = (int*)malloc(sizeof(int) * graph->vertexNum);
    int front = 0;
    int end = 0;


    queue[end++] = vertex;

    //队列循环
    while(front < end){
        //获取当前节点号
        int current = queue[front++];

        //阻止访问已经访问过的节点
        if(visited[current] == 1)
            continue;

        //访问当前节点
        printf("当前访问:%d\n",current);
        visited[current] = 1;

        //获取节点的出边链表
        ALLink* list = graph->vertexs[current].nextadj;
        while (list != NULL)
        {
            queue[end++] = list->vertex;
            list = list->nextadj;
        }
    }

}