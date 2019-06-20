//
// Created by 黎钰晖 on 2019-06-20.
//

#include "ALGraph.h"

ALGraph init_algraph(int vertexNum) {

    ALGraph graph = (ALGraph)malloc(sizeof(struct ALGraph));
    graph->vertexs = (ALVertex*)malloc(sizeof(ALVertex) * vertexNum);
    for (int i = 0; i < vertexNum; ++i) {
        graph->vertexs[i].data = 0;
        graph->vertexs[i].outdegree = 0;
        graph->vertexs[i].nextadj = NULL;
    }
    graph->vertexNum = vertexNum;
    graph->edge = 0;
    return graph;
}

void add_edge_algraph(ALGraph graph, int start, int end, int weight) {

    //初始化节点
    ALLink *link = (ALLink *) malloc(sizeof(ALLink));
    link->vertex = end;
    link->weight = weight;

    //插入顶点的链表中
    link->nextadj = graph->vertexs[start].nextadj;
    graph->vertexs[start].nextadj = link;

    //更新图的信息
    graph->edge++;
    graph->vertexs[start].outdegree++;
}

ALVertex *al_firstadj(ALGraph graph, int vertex) {
    int vertexIndex = graph->vertexs[vertex].nextadj->vertex;

    return &graph->vertexs[vertex];
}

ALVertex *al_nextadj(ALGraph graph, int vertex, ALVertex *last) {

    //定位到上一个节点
    ALLink *linklist = graph->vertexs[vertex].nextadj;
    while (linklist != NULL && &graph->vertexs[linklist->vertex] != last) {
        linklist = linklist->nextadj;
    }
    //如果上次的节点存在下一个节点的话，就返回
    if(linklist->nextadj != NULL)
        return &graph->vertexs[linklist->nextadj->vertex];
    return NULL;
}
