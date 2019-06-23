//
// Created by 黎钰晖 on 2019-06-20.
//


#include "GraphAlgorithm.h"
#include "ALGraph.h"
#include "ArrayGraph.h"

//DEBUG控制宏定义
#define DEBUG

#define min(a, b) (a<b?a:b)

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
#ifdef DEBUG
    for (int k = 0; k < edge_index; ++k) {
        Edge *edge = &edges[k];
        printf("生成的边:%d<-->%d, 权重:%d\n", edge->begin + 1, edge->end + 1, edge->weight);

    }
    printf("------------------------\n");
#endif
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

void DFS_Recursive(ALGraph graph, int vertex, int *visited) {
    if (visited[vertex] == 1)
        return;
    //访问到当前节点
    visited[vertex] = 1;
    printf("当前访问节点:%d\n", vertex);
    //访问这个节点的所有邻接点
    ALLink *list = graph->vertexs[vertex].nextadj;
    while (list != NULL) {
        DFS_Recursive(graph, list->vertex, visited);
        list = list->nextadj;
    }
}


void DFS(ALGraph graph, int vertex) {

    int *visited = (int *) malloc(sizeof(int) * graph->vertexNum);
    memset(visited, 0, sizeof(int) * graph->vertexNum);

    DFS_Recursive(graph, vertex, visited);

    for (int i = 0; i < graph->vertexNum; ++i) {
        if (visited[i] == 0) {
            printf("存在非联通部分,入口:%d", i);
            DFS_Recursive(graph, i, visited);
        }

    }
}

/*
 * 宽度优先搜索
 */

void BFS_Recursive(ALGraph graph, int vertex, int *visited) {

    //访问队列
    int *queue = (int *) malloc(sizeof(int) * graph->vertexNum);
    int front = 0;
    int end = 0;


    queue[end++] = vertex;

    //队列循环
    while (front < end) {
        //获取当前节点号
        int current = queue[front++];

        //阻止访问已经访问过的节点
        if (visited[current] == 1)
            continue;

        //访问当前节点
        visited[current] = 1;
        printf("当前访问:%d\n", current);

        //获取节点的出边链表
        ALLink *list = graph->vertexs[current].nextadj;
        while (list != NULL) {
            queue[end++] = list->vertex;
            list = list->nextadj;
        }
    }

}

void BFS(ALGraph graph, int vertex) {
    int *visited = (int *) malloc(sizeof(int) * graph->vertexNum);
    memset(visited, 0, sizeof(int) * graph->vertexNum);

    BFS_Recursive(graph, vertex, visited);

    for (int i = 0; i < graph->vertexNum; ++i) {
        if (visited[i] == 0) {
            printf("存在非联通部分,入口:%d", i);
            BFS_Recursive(graph, i, visited);
        }

    }
}


/*
 * 拓扑排序
 */

int select(ALGraph graph, int *degrees) {
    for (int i = 0; i < graph->vertexNum; ++i) {
        if (degrees[i] == 0)
            return i;
    }
}

void toposort_algraph(ALGraph graph) {

    // 初始化栈
    int *stack = (int *) malloc(sizeof(int) * graph->vertexNum);
    int top = -1;

    // 初始化出度
    int *degrees = (int *) malloc(sizeof(int) * (graph->vertexNum));
    for (int i = 0; i < graph->vertexNum; ++i) {
        degrees[i] = graph->vertexs[i].indegree;
        if (degrees[i] == 0) {
            stack[++top] = i;
        }
    }


    // 初始化标志
    int vexNum = 0;

    while (top != -1) {
        int vertex = stack[top--];
        printf("%d  ", vertex);
        vexNum++;
        ALLink *vertexlink = graph->vertexs[vertex].nextadj;
        while (vertexlink != NULL) {
            degrees[vertexlink->vertex]--;
            if (degrees[vertexlink->vertex] == 0)
                stack[++top] = vertexlink->vertex;
            vertexlink = vertexlink->nextadj;
        }
    }

    if (vexNum != graph->vertexNum)
        printf("图存在环\n");
}


/*
 * 关键路径
 */

void critical_path(ALGraph graph) {

    // 初始化访问栈
    int *stack = (int *) malloc(sizeof(int) * graph->vertexNum);
    int top = -1;


    int *degrees = (int *) malloc(sizeof(int) * graph->vertexNum);
    //初始化入度数组
    for (int i = 0; i < graph->vertexNum; ++i) {
        degrees[i] = graph->vertexs[i].indegree;
        if (degrees[i] == 0)
            stack[++top] = i;
    }

    //拓扑序列
    while (top != -1) {
        int i = stack[top--];
        ALVertex vertex = graph->vertexs[i];
        printf("当前访问节点%d,时间%d", i, vertex.data);

        ALLink *link = vertex.nextadj;
        while (link != NULL) {

            ALVertex *nextVertex = &graph->vertexs[link->vertex];
            nextVertex->data = min(nextVertex->data, vertex.data + link->weight);
            link = link->nextadj;

            if (--degrees[link->vertex] == 0)
                stack[++top] = link->vertex;
        }
    }



}

/*
 * 狄杰斯特拉带源最短路径
 */

void dijkstra(MatGraph graph, int src) {

    int *dist = malloc(sizeof(int) * graph->vertexNum);
    int *pre = malloc(sizeof(int) * graph->vertexNum);
    int *visited = malloc(sizeof(int) * graph->vertexNum);


    for (int i = 0; i < graph->vertexNum; ++i) {
        visited[i] = 0;
        pre[i] = 0;
        int dst = graph->mat[src][i];
        dist[i] = dst;
    }

    visited[src] = 1;
    dist[src] = 0;


#ifdef DEBUG
    for (int l = 0; l < graph->vertexNum; ++l) {
        printf("%d ", visited[l]);
    }
    printf("\n");
    for (int l = 0; l < graph->vertexNum; ++l) {
        printf("%d ", pre[l]);
    }
    printf("\n");
    for (int l = 0; l < graph->vertexNum; ++l) {
        printf("%d ", dist[l]);
    }
#endif

    for (int i = 0; i < graph->vertexNum; ++i) {

        int min = INT32_MAX;
        int tail = 0;
        for (int j = 0; j < graph->vertexNum; ++j) {
            if (visited[j] == 0 && dist[j] < min) {
                min = dist[j];
                tail = j;
            }
        }
        visited[tail] = 1;

        //更新路径
        for (int k = 0; k < graph->vertexNum; ++k) {
            if (visited[k] == 0 && graph->mat[tail][k] != INT32_MAX
                && dist[tail] + graph->mat[tail][k] < dist[k]) {
                dist[k] = dist[tail] + graph->mat[tail][k];
                pre[k] = tail;
            }

        }

    }

    //打印结果
    for (int i = 0; i < graph->vertexNum; ++i) {
        printf("到%d的最短路径长度：%d", i, dist[i]);
        //打印路径
        int dest = i;
        printf("路径为:");
        while (dest != src) {
            printf("%d ", dest);
            dest = pre[dest];
        }
        printf("\n");
    }

}

/*
 * 最小生成树Prim
 * O(n^3) 的实现方式，比较的简单易懂，但不是最好的实现方式
 */

void prim(MatGraph graph, int src) {

    //初始化从源点到其他顶点的距离
    int *dist = (int *) malloc(sizeof(int) * graph->vertexNum);
    for (int i = 0; i < graph->vertexNum; ++i) {
        dist[i] = graph->mat[src][i];
    }

    //创建visited数组
    int *visited = (int *) malloc(sizeof(int) * graph->vertexNum);
    memset(visited, 0, sizeof(int) * graph->vertexNum);
    visited[src] = 1;

    //当有节点没有被访问到的时候,继续循环
    int count = 1;
    while (count != graph->vertexNum) {
        // 选择一条最小的边
        int minweight = INT32_MAX;
        int head = -1;
        int tail = -1;

        // 这条边是[i,j]的
        for (int i = 0; i < graph->vertexNum; ++i) {
            for (int j = 0; j < graph->vertexNum; ++j) {
                //选择V->S的边
                if (visited[i] == 1 && visited[j] == 0) {
                    if (graph->mat[i][j] < INT32_MAX) {
                        minweight = graph->mat[i][j];
                        head = i;
                        tail = j;
                    }
                }
            }
        }

        //添加进入最小生成树中
        printf("产生边%d<->%d\n，权重:%d", head, tail, minweight);

        //标记为已经访问
        visited[tail] = 1;
        //更新已经加入最小生成树的节点个数
        count++;
    }

}


/*
 * 优化的Prim
 * O(n^2)
 */

void prim_optimize(MatGraph graph, int src) {

    //初始化dist数组
    int *dist = (int *) malloc(sizeof(int) * (graph->vertexNum));
    for (int i = 0; i < graph->vertexNum; ++i) {
        dist[i] = graph->mat[src][i];
    }

    //初始化visited数组
    int *visited = (int *) malloc(sizeof(int) * graph->vertexNum);
    memset(visited, 0, sizeof(int) * graph->vertexNum);

    visited[src] = 1;
    printf("选择源节点%d", src);

    // 如果不是全部点都在树中，则继续访问
    int count = 1;
    while (count != graph->vertexNum) {

        int tail = 0;
        int minval = INT32_MAX;
        //选择最小的边
        for (int i = 0; i < graph->vertexNum; ++i) {
            if (dist[i] < minval)
                tail = i;
        }

        printf("选择节点%d,权重%d", tail, minval);
        visited[tail] = 1;

        //更新受tail节点加入影响的dist
        for (int j = 0; j < graph->vertexNum; ++j) {
            if (graph->mat[tail][j] < dist[j]) {
                dist[j] = graph->mat[tail][j];
            }
        }

    }
}

