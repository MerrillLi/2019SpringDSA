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
#include "Review/Chapter4/kmp.h"


//int main(){
//    int arr[10];
//    srand(time(NULL));
//    for (int i = 0; i < 10; ++i) {
//        arr[i] = rand()%100;
//    }
//
//    for (int j = 0; j < 10; ++j) {
//        printf("%d ", arr[j]);
//    }
//
//    printf("\n");
//    MergeSort(arr,10);
//    for (int j = 0; j < 10; ++j) {
//        printf("%d ", arr[j]);
//    }
//}

int main() {
    MatGraph graph = init_matgraph(13);
    add_direct_edge(graph,0,1,6);
    add_direct_edge(graph,2,1,6);
    add_direct_edge(graph,1,4,4);
    add_direct_edge(graph,2,3,5);
    add_direct_edge(graph,2,5,7);
    add_direct_edge(graph,3,4,2);
    add_direct_edge(graph,3,6,6);
    add_direct_edge(graph,3,7,3);
    add_direct_edge(graph,4,7,4);
    add_direct_edge(graph,5,6,7);
    add_direct_edge(graph,5,8,9);
    add_direct_edge(graph,5,9,8);
    add_direct_edge(graph,6,7,2);
    add_direct_edge(graph,7,8,3);
    add_direct_edge(graph,8,9,5);
    add_direct_edge(graph,9,10,1);
    add_direct_edge(graph,9,11,1);
    add_direct_edge(graph,9,12,1);
    add_direct_edge(graph,11,12,1);

    dijkstra(graph,0);

    //DFS(graph,1);
//    toposort_algraph(graph);
//

}

//int main(){
//    char* pattern = "abcabaa";
//    int *next = (int*)malloc(sizeof(int) * strlen(pattern));
//    memset(next,0,sizeof(int) * strlen(pattern));
//    makeNext(pattern,next);
//
//    for (int i = 0; i < strlen(pattern); ++i) {
//        printf("%d  ",next[i]);
//    }
//}