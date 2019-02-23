//
// Created by ÀèîÚêÍ on 2019-02-18.
//

#ifndef INC_2019SPRINGDSA_GRAPH_H
#define INC_2019SPRINGDSA_GRAPH_H

#define DataType int

struct __Vertex;
struct __Edge;


struct __Vertex
{
    int indegree;
    int outdegree;
    struct __Edge** edges;
};

typedef struct __Vertex Vertex;

struct __Edge
{
    struct __Vertex source;
    struct __Vertex target;

};

typedef struct __Edge Edge;

struct __Graph
{
    int VertexCount;
    Vertex*** matrix;

};


#endif //INC_2019SPRINGDSA_GRAPH_H
