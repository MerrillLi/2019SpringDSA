//
// Created by 黎钰晖 on 2019-02-18.
//

#ifndef INC_2019SPRINGDSA_BINARYSEARCHTREE_H
#define INC_2019SPRINGDSA_BINARYSEARCHTREE_H

#include <stdlib.h>
#include <stdbool.h>

#define KeyType int
#define ValueType int


typedef struct __BSTNode
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

BSTNode* internalCreateNode(KeyType key,ValueType value)
{
    BSTNode* node = (BSTNode*)malloc(sizeof(struct __BSTNode));
    node->key = key;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

BinarySearchTree InitBST()
{
    BinarySearchTree tree = malloc(sizeof(struct __BST));
    tree->root = NULL;
    tree->size = 0;
    return  tree;
}

void addNode(BSTNode* node,KeyType key,ValueType value)
{
    if(node == NULL)
    {
        node = internalCreateNode(key,value);
    }
    else if(key < node->key)
    {
        addNode(node->left,key,value);
    }
    else
    {
        addNode(node->right,key,value);
    }
}

void BSTAdd(BinarySearchTree tree,KeyType key,ValueType value)
{
    BSTNode* node = tree->root;
    addNode(node,key,value);
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

void RecursiveInOrder(BSTNode* node,(*Visit)(KeyType,ValueType))
{
    RecursiveInOrder(node->left,Visit);
    Visit(node->key,node->value);
    RecursiveInOrder(node->right,Visit);
}

void RecursivePreOrder(BSTNode* node,(*Visit)(KeyType,ValueType))
{
    Visit(node->key,node->value);
    RecursiveInOrder(node->left,Visit);
    RecursiveInOrder(node->right,Visit);
}

void RecursivePostOrder(BSTNode* node,(*Visit)(KeyType,ValueType))
{
    RecursiveInOrder(node->left,Visit);
    RecursiveInOrder(node->right,Visit);
    Visit(node->key,node->value);

}

void LoopInOrder(BSTNode* root,(*Visit)(KeyType,ValueType))
{
    //stack decl
    BSTNode** stack = (BSTNode**)malloc(sizeof(BSTNode*) * 32);
    int top = -1;
    if(root != NULL)
    {
        //根节点入栈
        stack[++top] = root;
        //栈不空
        while(top != -1)
        {
            BSTNode* node = NULL;
        }
    }

}

void LoopPreOrder(BSTNode* node,(*Visit)(KeyType,ValueType))
{

}

void LoopPostOrder(BSTNode* node,(*Visit)(KeyType,ValueType))
{

}




#endif //INC_2019SPRINGDSA_BINARYSEARCHTREE_H
