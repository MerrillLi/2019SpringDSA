//
// Created by 黎钰晖 on 2019-06-04.
//

#ifndef INC_2019SPRINGDSA_ARRAYGRAPH_H
#define INC_2019SPRINGDSA_ARRAYGRAPH_H

#include <stdlib.h>
#include <memory.h>

#define VertexType int
typedef struct Vertex {
    VertexType data;
} *Vertex;

typedef struct MatGraph {
    Vertex *verts;
    int **mat;
    int vertexNum;
    int edgeNum;
} *MatGraph;

MatGraph init_matgraph(int vertexNum);

//检查出度
int outdegree(MatGraph graph, int vertex);

//检查入度
int indegree(MatGraph graph, int vertex);

//第一个邻接点
int firstadj(MatGraph graph, int vertex);

//下一个邻接点
int nextadj(MatGraph graph,int vertex,int last);

//添加边
void add_nodirect_edge(MatGraph graph,int begin,int end,int weight);


#endif //INC_2019SPRINGDSA_ARRAYGRAPH_H
