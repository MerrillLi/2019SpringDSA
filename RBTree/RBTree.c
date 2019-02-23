//
// Created by 黎钰晖 on 2019-02-15.
//
#include "RBTree.h"
#include <stdbool.h>
#include <stdlib.h>



//判断是否为红色节点
static bool TreeNodeIsRed(RBTreeNode* node)
{
    if (node == NULL) return BLACK;
    return node->Color;
}

//左旋
static RBTreeNode* leftRotate(RBTreeNode* node)
{
    RBTreeNode* x = node->right;
    node->right = x->left;
    x->left = node;

    //颜色调整
    x->Color = node->Color;
    node->Color = RED;

    return x;
}

//右旋
static RBTreeNode* rightRotate(RBTreeNode* node)
{
    RBTreeNode* x = node->left;
    node->left = x->right;
    x->right = node;

    //颜色调整
    x->Color = node->Color;
    node->Color = RED;

    return x;

}

//颜色反转
static void flipColors(RBTreeNode* node)
{
    node->Color = RED;
    node->left->Color = BLACK;
    node->right->Color = BLACK;
}

//创建树
RedBlackTree InitializeTreeMap() {
    RedBlackTree tree = malloc(sizeof(struct __RBT));
    tree->size = 0;
    tree->root = NULL;
    return tree;
}

static RBTreeNode* createNode(KeyType key, ValueType val)
{
    RBTreeNode* newNode = malloc(sizeof(RBTreeNode));
    newNode->key = key;
    newNode->value = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->Color = RED;
    return newNode;
}

static RBTreeNode* NodeAdd(const RedBlackTree tree,RBTreeNode* node,KeyType key,ValueType val)
{
    //处理添加流程
    if (node == NULL)
    {
        tree->size++;
        return createNode(key,val);
    }

    if(key < node->key)
    {
        node->left = NodeAdd(tree,node->left,key,val);
    }
    else if(key > node->key)
    {
        node->right = NodeAdd(tree,node->right,key,val);
    }else
    {
        node->value = val;
    }

    //处理平衡问题
    if (TreeNodeIsRed(node->right) && !TreeNodeIsRed(node->left))
        node = leftRotate(node);

    if (TreeNodeIsRed(node->left) && TreeNodeIsRed(node->left->left))
        node = rightRotate(node);

    if(TreeNodeIsRed(node->left) && TreeNodeIsRed(node->right))
        flipColors(node);

    return node;

}

//加载进入红黑树
void TreeMapPut(RedBlackTree tree,KeyType key,ValueType value)
{
    (tree)->root = NodeAdd((tree),(tree)->root,key,value);
    (tree)->root->Color = BLACK;
}

static ValueType get(RBTreeNode* node,KeyType key)
{
    //节点为空，返回NULL
    if(node == NULL) return NULL;

    if(node->key < key)
    {
        return get(node->right,key);
    }
    else if(node->key > key)
    {
        return get(node->left,key);
    }
    else
    {
        return node->value;
    }

}

//查找节点,查找失败返回NULL
ValueType TreeMapGet(RedBlackTree tree,KeyType key)
{
    return get(tree->root,key);
}

//查询是否包含指定key的键值对
bool TreeMapContains(RedBlackTree tree,KeyType key)
{

    RBTreeNode* node = tree->root;
    while(node != NULL)
    {
        if(node->key == key) return true;
        if(key < node->key) node = node->left;
        if(key > node->key) node = node->right;
    }

    return false;



}


static RBTreeNode* internalMinimum(RBTreeNode* node)
{
    if(node->left == NULL) return node;
    return internalMinimum(node->left);
}

static RBTreeNode* internalRemoveMinimum(RedBlackTree tree,RBTreeNode* node)
{
    if(node->left == NULL)
    {
        RBTreeNode* rightNode = node->right;
        node->right = NULL;
        tree->size --;
        return rightNode;
    }
    node->left = internalRemoveMinimum(tree,node->left);
    return node;
}

//删除操作
RBTreeNode* internalRemove(RedBlackTree tree,RBTreeNode* node,KeyType key)
{
    if(node == NULL) return NULL;

    if(key < node->key)
    {
        node->left = internalRemove(tree,node->left,key);
        return node;
    }

    if(key > node->key)
    {
        node->right = internalRemove(tree,node->right,key);
        return node;
    }
    else
    {
        if(node->left == NULL)
        {
            RBTreeNode* rightNode = node->right;
            node->right = NULL;
            tree->size --;
            return rightNode;
        }

        if(node->right == NULL)
        {
            RBTreeNode* leftNode = node->right;
            node->left = NULL;
            tree->size --;
            return leftNode;
        }

        RBTreeNode* succ = internalMinimum(node->right);
        succ->right = internalRemoveMinimum(tree,node->right);
        succ->left = node->left;
        node->left = node->right = NULL;
        return succ;
    }

}

RBTreeNode* internalGetNode(RBTreeNode* node,KeyType key)
{
    if(node == NULL) return NULL;

    if(key == node->key) return node;
    else if(key < node->key) return internalGetNode(node->left,key);
    else return internalGetNode(node->right,key);
}

//从红黑树中移除一个元素
ValueType TreeMapRemove(RedBlackTree tree,KeyType key)
{
    RBTreeNode* node = internalGetNode(tree->root,key);
    if(node != NULL)
    {
        tree->root = internalRemove(tree,tree->root,key);
        return node->value;
    }
    return NULL;
}






