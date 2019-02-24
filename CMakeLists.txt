cmake_minimum_required(VERSION 3.13)
project(2019SpringDSA C)

set(CMAKE_C_STANDARD 11)

add_executable(2019SpringDSA main.c DualCycleLinkedList/DualCycleLinkedList.h DualCycleLinkedList/DualCycleLinkedList.c RBTree/RBTree.h RBTree/RBTree.c AVLTree/AVLTree.c AVLTree/AVLTree.h LinkedHashMap/LinkedHashMap.c LinkedHashMap/LinkedHashMap.h Graph/Graph.h BinarySearchTree/BinarySearchTree.h Vector/Vector.h SinglyLinkedList/SinglyLinkedList.h SortAlgorithm/Sort.h String/String.h Vector/Vector.c SinglyLinkedList/SinglyLinkedList.c Queue/Queue.c Queue/Queue.h Stack/Stack.c Stack/Stack.h SegmentTree/SegmentTree.c SegmentTree/SegmentTree.h ArrayDeque/Deque.c ArrayDeque/Deque.h)