//
// Created by ¿ËÓ⁄ÍÕ on 2019-02-18.
//

#ifndef INC_2019SPRINGDSA_BINARYSEARCHTREE_H
#define INC_2019SPRINGDSA_BINARYSEARCHTREE_H

#include <stdlib.h>
#include <stdbool.h>

#define KeyType int
#define ValueType int


struct __BSTNode
{
    KeyType key;
    ValueType value;
    struct __BSTNode *left,*right;
}BSTNode;

typedef struct __BST
{
    struct __BSTNode* root;
    int size;
}*BinarySearchTree;


BinarySearchTree InitBST()
{
    BinarySearchTree tree = malloc(sizeof(struct __BST));
    tree->root = NULL;
    tree->size = 0;
    return  tree;
}

void BSTAdd(BinarySearchTree tree,KeyType key,ValueType value)
{

}

void BSTRemove(BinarySearchTree tree,KeyType key)
{

}

void BSTSet(BinarySearchTree tree,KeyType key)
{

}

bool BSTContains(BinarySearchTree tree,KeyType key)
{

}

void RecursiveInOrder(BinarySearchTree tree)
{

}

void RecursivePreOrder(BinarySearchTree tree)
{

}

void RecursivePostOrder(BinarySearchTree tree)
{

}

void LoopInOrder(BinarySearchTree tree)
{

}

void LoopPreOrder(BinarySearchTree tree)
{

}

void LoopPostOrder(BinarySearchTree tree)
{

}




#endif //INC_2019SPRINGDSA_BINARYSEARCHTREE_H
