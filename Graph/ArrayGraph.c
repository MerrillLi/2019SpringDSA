//
// Created by 黎钰晖 on 2019-06-04.
//
#include "ArrayGraph.h"
#include <stdint.h>
#include <stdio.h>
void add_nodirect_edge(MatGraph graph, int begin, int end, int weight) {
    graph->mat[begin][end] = weight;
    graph->mat[end][begin] = weight;
    graph->edgeNum++;

}


void add_direct_edge(MatGraph graph, int begin, int end, int weight) {
    graph->mat[begin][end] = weight;
    graph->edgeNum++;
}

int nextadj(MatGraph graph, int vertex, int last) {
    //先找到上一个邻接点
    vertex = vertex - 1;
    for (int i = last + 1; i < graph->vertexNum; ++i) {
        if (graph->mat[vertex][i] != 0) {
            return i;
        }
    }
    return -1;
}

int firstadj(MatGraph graph, int vertex) {
    for (int i = 0; i < graph->vertexNum; ++i) {
        if (graph->mat[vertex][i] != 0) {
            return i;
        }
    }
    return -1;
}

int indegree(MatGraph graph, int vertex) {
    int ret = 0;
    //检查列
    for (int i = 0; i < graph->vertexNum; ++i) {
        if (graph->mat[i][vertex] != 0) {
            ret++;
        }
    }
    return ret;
}

int outdegree(MatGraph graph, int vertex) {

    int ret = 0;
    for (int i = 0; i < graph->vertexNum; ++i) {
        //检查行
        if (graph->mat[vertex][i] != 0) {
            ret++;
        }
    }
    return ret;
}

MatGraph init_matgraph(int vertexNum) {
    MatGraph graph = (MatGraph) malloc(sizeof(struct MatGraph));
    graph->verts = (Vertex *) malloc(sizeof(struct Vertex) * vertexNum);
    graph->vertexNum = vertexNum;
    graph->edgeNum = 0;
    graph->mat = (int **) malloc(sizeof(int *) * vertexNum);
    for (int i = 0; i < vertexNum; ++i) {
        graph->mat[i] = (int *) malloc(sizeof(int) * vertexNum);
        for (int j = 0; j < graph->vertexNum; ++j) {
            graph->mat[i][j] = INT32_MAX;
        }
    }

    return graph;
}
