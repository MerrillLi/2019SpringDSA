#include <stdio.h>
#include <stdlib.h>
#include "AVLTree/AVLTree.h"
#include "LinkedHashMap/LinkedHashMap.h"
#include "DualCycleLinkedList/DualCycleLinkedList.h"
#include "RBTree/RBTree.h"
#include "Vector/Vector.h"
#include "Queue/ArrayBaseQueue/Queue.h"
#include <time.h>


int HashIndex(void* obj)
{

    return abs((int)(obj)%101);
}

int main() {

    srand((unsigned int)time(NULL));
    int array[1000000] = {0};

    for (int j = 0; j < 1000000; ++j) {
        array[j] = rand();
    }

    //Hash测速
    time_t start1 = time(NULL);

    for (int k = 0; k < 10; ++k) {

        LinkedHashMap map = InitHashMap(1000000);
        for (int i = 0; i < 10000; ++i) {
            HashMapPut(map, array[i], array[i] * 2);
            assert(HashMapGet(map, array[i]) == array[i] * 2);
            assert(HashMapSet(map, array[i], array[i] * 2) == array[i] * 2 );
            HashMapRemove(map,array[i]);
            assert(HashMapContains(map,array[i]) == false);


        }


    }

    time_t end1 = time(NULL);

    //Tree测速

    for (int l = 0; l < 10; ++l) {
        RedBlackTree rbmap = InitializeTreeMap();
        for (int i = 0; i < 10000; ++i) {
            TreeMapPut(rbmap,array[i],array[i]*2);
            assert(TreeMapGet(rbmap,array[i]) == array[i]*2);
            assert(TreeMapContains(rbmap,array[i]));
            assert(TreeMapRemove(rbmap,array[i]) == array[i]*2);
            assert(TreeMapContains(rbmap,array[i]) == false);
        }
    }

    time_t end2 = time(NULL);



    //AVLTree测速

    for (int l = 0; l < 10; ++l) {
        AVLTree avlTree = InitAVLTree();
        for (int i = 0; i < 10000; ++i) {
            AVLTreePut(avlTree,array[i],array[i]*2);
            assert(AVLTreeGet(avlTree,array[i]) == array[i]*2);
            assert(AVLTreeContains(avlTree,array[i]));
            assert(AVLTreeRemove(avlTree,array[i]) == array[i] * 2);
            assert(AVLTreeContains(avlTree,array[i]) == false);
        }
    }

    time_t end3 = time(NULL);

    //DualCycleLinkedList测速
    for (int l = 0; l < 10; ++l) {
        DualCycLinkedList linkedList = InitDualCycList();

        for (int i = 0; i < 10000; ++i) {
            DualCycListInsert(linkedList,array[i]);
            assert(DualCycListContains(linkedList,array[i]));
//            DualCycListRemove(linkedList,array[i]);
//            assert(DualCycListContains(linkedList,array[i]) == false);
//            assert(DualCycListIsEmpty(linkedList));
        }
    }

    time_t end4 = time(NULL);

    //Vector测速
    for (int l = 0; l < 2; ++l) {
        Vector vector = InitVector(10);

        for (int i = 0; i < 20; ++i) {
            VectorAddFirst(vector,array[i]);
            assert(VectorGet(vector,VectorFind(vector,array[i])) == array[i]);
        }

    }

    time_t end5 = time(NULL);
    //Queue测试
    for (int l = 0; l < 2; ++l) {
        Queue queue = InitQueue();

        for (int i = 0; i < 30; ++i) {
            EnQueue(queue,array[i]);
            assert(DeQueue(queue) == array[i]);
            assert(QueueSize(queue) == 0);
        }

    }


    time_t final = time(NULL);

    printf("HashMap = %d\n",end1 - start1);
    printf("RedBlackTree = %d\n",end2 - end1);
    printf("AVLTree = %d\n",end3 - end2);
    printf("DualCycleLinkedList = %d\n",end4 - end3);
    printf("Vector = %d\n",end5 - end4);
    printf("Queue = %d\n",final - end5);


    return 0;
}