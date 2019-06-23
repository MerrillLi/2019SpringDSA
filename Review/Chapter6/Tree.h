//
// Created by 黎钰晖 on 2019-06-23.
//

#ifndef INC_2019SPRINGDSA_TREE_H
#define INC_2019SPRINGDSA_TREE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct treenode {
    int data;
    struct treenode *left;
    struct treenode *right;
    int leftThread, rightThread;
} node, *Tree;


Tree init_tree() {
    Tree t = (Tree) malloc(sizeof(node));
    t->left = NULL;
    t->right = NULL;
    t->leftThread = 0;
    t->leftThread = 1;

    return t;
}

void preorder_nonrecursive(Tree t) {

    node *p = t;
    node **stack = (node **) malloc(sizeof(node *) * 100);
    int top = -1;

    stack[++top] = t;

    while (p || top != -1) {

        //前序遍历,访问左子树并沿左子树一路走到底
        while (p != NULL) {
            stack[++top] = p;
            printf("当前访问%d\n", p->data);
            p = p->left;
        }

        //此时已经走到左子树的底了，开始退栈并进入右子树
        p = stack[top--];
        p = p->right;
    }
}

void inorder_nonrecursive(Tree t) {
    node *p = t;
    node **stack = (node **) malloc(sizeof(node *) * 100);
    int top = -1;

    stack[++top] = p;

    while (p || top != -1) {

        //先进入左子树，一路走到底
        while (p) {
            stack[++top] = p;
            p = p->left;
        }

        //退栈之后访问节点
        p = stack[top--];
        printf("当前访问节点:%d\n", p->data);
        //然后转入右子树
        p = p->right;

    }
}

Tree forest_to_tree(Tree *forest, int size) {

    //先生成一棵树作为根
    Tree t = init_tree();

    //遍历所有树根
    for (int i = 0; i < size; ++i) {

        //对每一个子树采取层次遍历

        //树的右分支存储树根
        t->right = forest[i];
        //TODO::未完待续


    }

}

node *pre;

void inoreder_thread(Tree t) {

    //中序遍历终止条件
    if (t == NULL) return;

    //递归遍历，进入左子树
    if (t->left != NULL && t->leftThread != 1)
        inoreder_thread(t->left);

    //访问当前节点

    //左子树连接
    if (t->left == NULL) {
        t->left = pre;
        t->leftThread = 1;
    }
    //右子树连接
    if (pre != NULL && pre->right == NULL) {
        pre->right = t;
        pre->rightThread = 1;
    }
    pre = t;


    if (t->right != NULL && t->rightThread != 1)
        inoreder_thread(t->right);

}

void preorder_thread(Tree t) {

    //先序遍历终止条件
    if (t == NULL)
        return;

    //先序访问根节点
    //建立左子树连接关系
    if (t->left == NULL) {
        t->left = pre;
        t->leftThread = 1;
    }

    //建立右子树连接关系
    if (pre != NULL && pre->right == NULL) {
        pre->right = t;
        pre->rightThread = 1;
    }
    pre = t;

    //递归左子树
    if (t->left != NULL && t->leftThread != 1)
        preorder_thread(t->left);

    //递归右子树
    if (t->right != NULL && t->rightThread != 1)
        preorder_thread(t->right);

}

void inorder_thread_traverse(Tree t) {

    /*
     * 速记法： 有左则左，无左则后(访问)，无后则右
     *
     * 中序遍历
     * 1.有左则左（进入左子树，但不访问）
     * 2.访问节点
     * 2.无左则后 (模拟递归回溯)
     * 3.无后则右 (回退完后，有右子树就进入)
     *
     */

    node *p = t;

    while (p != NULL) {
        //有左则左
        while (p->leftThread != 1) {
            p = p->left;
        }
        //访问当前节点
        printf("当前访问%d\n", p->data);
        //进入后继元素，当后继元素不是线索化的节点
        //则意味着这个节点有右节点，那么就可能存在左子树
        while (p->right != NULL && p->rightThread == 1) {
            p = p->right;
            printf("当前访问%d\n", p->data);
        }
        //进入右子树
        p = p->right;
    }
}

void preorder_thread_tarverse(Tree t){

    /*
     * 速记法： 有左则左(访问)，无左则后，无后则右
     */

    node* p = t;
    while(p != NULL){
        //有左则左
        while (p->left != NULL && p->leftThread == 0)
        {
            printf("当前访问%d",p->data);
            p = p->left;
        }

        //无左则后
        while (p->rightThread == 1 && p->right != NULL){
            p = p->right;
            printf("当前访问%d",p->data);
        }

        //无后则右
        p = p->right;


    }

}


#endif //INC_2019SPRINGDSA_TREE_H
