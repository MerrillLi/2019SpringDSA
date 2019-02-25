//
// Created by 黎钰晖 on 2019-02-16->
//

#include "AVLTree.h"
#include <stdlib.h>
#include <stdbool.h>

#define max(a,b) ((a>b?a:b))
#define min(a,b) ((a>b?b:a))

//基础函数
AVLTree InitAVLTree()
{
    AVLTree tree = malloc(sizeof(struct __AVLT));
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

//创建一个节点
AVLTreeNode* CreateNode(KeyType key,ValueType value)
{
    AVLTreeNode* newNode = malloc(sizeof(struct AVLTreeNode));
    newNode->key = key;
    newNode->value = value;
    newNode->height = 1;
    newNode->balanceFactor = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//获取节点高度值
static inline int getHeight(AVLTreeNode* node)
{
    if(node == NULL) return 0;
    return node->height;
}

//获取节点的平衡因子
static inline int getBalanceFactor(AVLTreeNode* node)
{
    if(node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

//RR旋转
static inline AVLTreeNode* rightRotate(struct AVLTreeNode* y)
{
    //右旋转
    struct AVLTreeNode* x = y->left;
    struct AVLTreeNode* T3 = x->right;
    x->right = y;
    y->left = T3;

    //更新节点高度值
    y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left),getHeight(x->right)) + 1;

    //x是新的根节点
    return x;

}

//LL旋转
static inline AVLTreeNode* leftRotate(struct AVLTreeNode* y)
{
    //左旋转
    AVLTreeNode* x = y->right;
    AVLTreeNode* t3 = x->left;

    x->left = y;
    y->right = t3;

    //更新节点高度值
    y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left),getHeight(x->right)) + 1;

    //x是新的根节点
    return x;

}

//向树中添加一个元素的内部方法
AVLTreeNode* add(const AVLTree tree,AVLTreeNode* node,KeyType key,ValueType value)
{
    //如果节点为空，则直接插入
    if(node == NULL)
    {
        tree->size++;
        return CreateNode(key,value);
    }

    //寻找插入点
    if( key < node->key )
        //插入左边
        node->left = add(tree,node->left,key,value);
    else if( key > node->key )
        //插入右边
        node->right = add(tree,node->right,key,value);
    else
        //已经存在则更新值
        node->value = value;

    //计算节点高度
    node->height = max(getHeight(node->left),getHeight(node->right)) + 1;

    //计算平衡因子
    int balanceFactor = getBalanceFactor(node);

    //维护平衡

    //case LL
    if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0)
        return rightRotate(node);

    //case RR
    if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0)
        return leftRotate(node);

    //case LR
    if(balanceFactor > 1 && getBalanceFactor(node->left) < 0)
    {
        //对节点的左节点进行左旋，转化为LL形
        node->left = leftRotate(node->left);
        //进行右旋转操作
        return rightRotate(node);
    }

    //case RL
    if(balanceFactor < -1 && getBalanceFactor(node->right) > 0)
    {
        //对节点的右节点进行右旋转
        node->right = rightRotate(node->right);
        //对节点进行左旋转
        return leftRotate(node);
    }





    return node;


}

//向树中添加Key-Value对
void AVLTreePut(AVLTree tree,KeyType key,ValueType value) {
    tree->root = add(tree,tree->root,key,value);
}

//查找是否存在对应的Key
bool AVLTreeContains(AVLTree tree,KeyType key)
{
    AVLTreeNode* node = tree->root;
    while(node != NULL)
    {
        if(node->key == key) return true;
        if(node->key < key) node = node->right;
        if(node->key > key) node = node->left;
    }
    return false;
}

//从树中获取对应Key的值
ValueType AVLTreeGet(AVLTree tree,KeyType key)
{
    AVLTreeNode* node = tree->root;
    while(node != NULL)
    {
        if(node->key == key) return node->value;
        if(node->key < key) node = node->right;
        if(node->key > key) node = node->left;
    }
    return NULL;
}

//向树中设置对应Key的值,返回旧的Key对应的值
ValueType AVLTreeSet(AVLTree tree,KeyType key,ValueType value)
{
    AVLTreeNode* node = tree->root;
    while(node != NULL)
    {
        if(node->key == key)
        {
            int oldVal = node->value;
            node->value = value;
            return oldVal;
        }
        if(node->key < key) node = node->right;
        if(node->key > key) node = node->left;
    }
    return NULL;
}

//子树的最小节点
AVLTreeNode* minimum(AVLTreeNode* node)
{
    if(node->left == NULL) return node;
    return minimum(node->left);
}

//实现树节点的删除
AVLTreeNode* remove(const AVLTree tree,AVLTreeNode* node,KeyType key)
{
    if(node == NULL) return NULL;
    AVLTreeNode* retNode;
    if(key < node->key)
    {
        node->left = remove(tree,node->left, key);
        retNode = node;
    }
    else if (key > node->key)
    {
        node->right = remove(tree,node->right,key);
        retNode = node;
    }
    else
    {
        //其中一边节点为空
        if(node->left == NULL)
        {
            AVLTreeNode* right = node->right;
            node->right = NULL;
            tree->size--;
            retNode = right;
        }

        else if(node->right == NULL)
        {
            AVLTreeNode* left = node->left;
            node->left = NULL;
            tree->size--;
            retNode = left;
        }
        //左右子树均不为空
        else
        {
            AVLTreeNode* succ = minimum(node->right);
            succ->right = remove(tree,node->right,succ->key);
            succ->left = node->left;

            node->left = node->right = NULL;

            retNode = succ;

        }
    }

    if(retNode == NULL)
        return NULL;

    // 更新height
    retNode->height = 1 + max(getHeight(retNode->left), getHeight(retNode->right));

    // 计算平衡因子
    int balanceFactor = getBalanceFactor(retNode);

    // 平衡维护
    // LL
    if (balanceFactor > 1 && getBalanceFactor(retNode->left) >= 0)
        return rightRotate(retNode);

    // RR
    if (balanceFactor < -1 && getBalanceFactor(retNode->right) <= 0)
        return leftRotate(retNode);

    // LR
    if (balanceFactor > 1 && getBalanceFactor(retNode->left) < 0) {
        retNode->left = leftRotate(retNode->left);
        return rightRotate(retNode);
    }

    // RL
    if (balanceFactor < -1 && getBalanceFactor(retNode->right) > 0) {
        retNode->right = rightRotate(retNode->right);
        return leftRotate(retNode);
    }

    return retNode;




}

//查找到对应的节点
AVLTreeNode* getNode(const AVLTreeNode* node,KeyType key)
{

    if(node == NULL)
        return NULL;
    if(key == node->key)
        return node;
    else if(key < node->key)
        return getNode(node->left, key);
    else // if(key->compareTo(node->key) > 0)
        return getNode(node->right, key);
}

//删除树中的节点,并返回Key的旧值Value
ValueType AVLTreeRemove(AVLTree tree,KeyType key)
{
    AVLTreeNode* node = getNode(tree->root,key);
    if(node != NULL)
    {
        tree->root = remove(tree,tree->root,key);
        return node->value;
    }
    return NULL;
}




