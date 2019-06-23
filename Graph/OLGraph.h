//
// Created by ¿ËÓ⁄ÍÕ on 2019-06-22.
//

#ifndef INC_2019SPRINGDSA_OLGRAPH_H
#define INC_2019SPRINGDSA_OLGRAPH_H

typedef struct OLEdge {
    int data;
    int head;
    int tail;
    struct OLEdge *headlink;
    struct OLEdge *taillink;
} OLEdge;

typedef struct OLVertex {
    int data;
    OLEdge *firstin;
    OLEdge *firstout;

} OLVertex;

typedef struct OLGraph {
    OLVertex *vertexs;
    int vertexnum;

} *OLGraph;

void add_edge_olgraph(OLGraph graph, int head, int tail, int weight) {

}

#endif //INC_2019SPRINGDSA_OLGRAPH_H
