//
// Created by ¿ËÓ⁄ÍÕ on 2019-06-20.
//

#include "ArrayGraph.h"
#include "ALGraph.h"
#include <stdio.h>
#ifndef INC_2019SPRINGDSA_GRAPHALGORITHM_H
#define INC_2019SPRINGDSA_GRAPHALGORITHM_H

typedef struct{
    int begin;
    int end;
    int weight;
}Edge;


void kruskal(MatGraph graph);

void DFS(ALGraph graph,int vertex);

void BFS(ALGraph graph, int vertex);

void toposort_algraph(ALGraph graph);

void dijkstra(MatGraph graph, int src);

#endif //INC_2019SPRINGDSA_GRAPHALGORITHM_H
