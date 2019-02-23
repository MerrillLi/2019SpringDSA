//
// Created by 黎钰晖 on 2019-02-15.
//

#ifndef INC_2019SPRINGDSA_RBTREE_H
#define INC_2019SPRINGDSA_RBTREE_H

#define KeyType int
#define ValueType int
#define BLACK false
#define  RED true

#include <stdbool.h>
//定义树节点
typedef struct RBTreeNode
{
    bool Deleted;
    KeyType key;
    ValueType value;
    bool Color;
    struct RBTreeNode* left;
    struct RBTreeNode* right;
}RBTreeNode;

//封装红黑树
typedef struct __RBT
{
    struct RBTreeNode* root;
    int size;
}*RedBlackTree;


RedBlackTree InitializeTreeMap();

ValueType TreeMapGet(RedBlackTree tree,KeyType key);

void TreeMapPut(RedBlackTree tree,KeyType key,ValueType value);

bool TreeMapContains(RedBlackTree tree,KeyType key);

ValueType TreeMapRemove(RedBlackTree tree,KeyType key);




#endif //INC_2019SPRINGDSA_RBTREE_H
