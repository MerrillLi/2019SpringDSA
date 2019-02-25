cmake_minimum_required(VERSION 3.13)
project(2019SpringDSA C)

set(CMAKE_C_STANDARD 11)

add_executable(2019SpringDSA main.c DualCycleLinkedList/DualCycleLinkedList.h DualCycleLinkedList/DualCycleLinkedList.c Tree/RBTree/RBTree.h Tree/RBTree/RBTree.c Tree/AVLTree/AVLTree.c Tree/AVLTree/AVLTree.h LinkedHashMap/LinkedHashMap.c LinkedHashMap/LinkedHashMap.h Graph/Graph.h BinarySearchTree/BinarySearchTree.h Vector/Vector.h SinglyLinkedList/SinglyLinkedList.h SortAlgorithm/Sort.h String/String.h Vector/Vector.c SinglyLinkedList/SinglyLinkedList.c Queue/ArrayBaseQueue/Queue.c Queue/ArrayBaseQueue/Queue.h Stack/ArrayBaseStack/Stack.c Stack/ArrayBaseStack/Stack.h Tree/SegmentTree/SegmentTree.c Tree/SegmentTree/SegmentTree.h Queue/ArrayDeque/Deque.c Queue/ArrayDeque/Deque.h Stack/LinkedBaseStack/LinkedStack.c Stack/LinkedBaseStack/LinkedStack.h Queue/LinkedQueue/LinkedQueue.c Queue/LinkedQueue/LinkedQueue.h)