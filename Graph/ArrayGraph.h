//
// Created by 黎钰晖 on 2019-06-04.
//

#ifndef INC_2019SPRINGDSA_ARRAYGRAPH_H
#define INC_2019SPRINGDSA_ARRAYGRAPH_H

#include <stdlib.h>
#include <memory.h>
typedef struct Vertex{

}*Vertex;
typedef struct MatGraph{
    Vertex* verts;
    int** mat;
    int row;
    int col;
}*MatGraph;

MatGraph init_matgraph(int vertexNum){
    MatGraph graph = (MatGraph)malloc(sizeof(struct MatGraph));
    graph->verts = (Vertex*)malloc(sizeof(struct Vertex) * vertexNum);
    graph->mat = (int**)malloc(sizeof(int*) * vertexNum);
    for (int i = 0; i < vertexNum; ++i) {
        graph->mat[i] = (int*)malloc(sizeof(int) * vertexNum);
        memset(graph->mat[i],0, sizeof(int) * vertexNum);
    }
    return graph;
}

//检查出度
int first_adj(int vertex){

}
//检查出度
int next_adj(int vertex, int last){

}



#endif //INC_2019SPRINGDSA_ARRAYGRAPH_H
