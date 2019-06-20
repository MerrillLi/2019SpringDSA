#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SortAlgorithm/HeapSort.h"
#include "SortAlgorithm/InsertionSort.h"
#include "SortAlgorithm/ShellSort.h"
#include "SortAlgorithm/MergeSort.h"
#include "SearchAlgorithm/Insertion/InsertionSearch.h"
#include "Graph/GraphAlgorithm.h"
#include "Graph/ArrayGraph.h"
#include "Graph/ALGraph.h"


int main() {
    ALGraph graph = init_algraph(10);
    add_edge_algraph(graph,1,2,6);
    add_edge_algraph(graph,1,3,4);
    add_edge_algraph(graph,1,4,4);
    add_edge_algraph(graph,2,3,5);
    add_edge_algraph(graph,2,5,7);
    add_edge_algraph(graph,3,4,2);
    add_edge_algraph(graph,3,6,6);
    add_edge_algraph(graph,3,7,3);
    add_edge_algraph(graph,4,7,4);
    add_edge_algraph(graph,5,6,7);
    add_edge_algraph(graph,5,8,9);
    add_edge_algraph(graph,5,9,8);
    add_edge_algraph(graph,6,7,2);
    add_edge_algraph(graph,7,8,3);
    add_edge_algraph(graph,8,9,5);
    BFS(graph,1);


}