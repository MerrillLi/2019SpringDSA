//
// Created by 黎钰晖 on 2019-06-20.
//

#ifndef INC_2019SPRINGDSA_ALGRAPH_H
#define INC_2019SPRINGDSA_ALGRAPH_H

#include <stdlib.h>

#define VertexType int

typedef struct ALLink {
    int vertex;
    int weight;
    struct ALLink *nextadj;
} ALLink;

typedef struct ALVertex {
    VertexType data;
    int outdegree;
    ALLink *nextadj;
} ALVertex;

typedef struct ALGraph {
    ALVertex *vertexs;
    int vertexNum;
    int edge;
} *ALGraph;


//初始化ALGraph
ALGraph init_algraph(int vertexNum);

//添加边到邻接表中，采用头插法
void add_edge_algraph(ALGraph graph, int start, int end, int weight);

//首个邻接点
ALVertex *al_firstadj(ALGraph graph, int vertex);

//下一个邻接点
ALVertex *al_nextadj(ALGraph graph, int vertex, ALVertex *last);



#endif //INC_2019SPRINGDSA_ALGRAPH_H
