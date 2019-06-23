//
// Created by јиоЏкЌ on 2019-06-22.
//

#ifndef INC_2019SPRINGDSA_ARRAY_H
#define INC_2019SPRINGDSA_ARRAY_H

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct SparseMatrix {
    int *arr;
    int n;
} *SparseMatrix;


SparseMatrix init_saprse_matrix(int n) {
    SparseMatrix matrix = (SparseMatrix) malloc(sizeof(struct SparseMatrix));
    matrix->arr = (int *) malloc(sizeof(int) * (n) * (n - 1) / 2);
    matrix->n = n;
    return matrix;
}

void put_sparse_matrix(SparseMatrix matrix, int val, int row, int col) {
    if (col > row) {
        put_sparse_matrix(matrix, val, col, row);
        return;
    }
    int index = row * (row - 1) / 2 + col - 1;
    matrix->arr[index] = val;
}

int get_sparse_matrix(SparseMatrix matrix, int row, int col) {

    if (col > row)
        return get_sparse_matrix(matrix, col, row);

    int index = row * (row - 1) / 2 + col - 1;
    return matrix->arr[index];
}

typedef struct TriMatrix {
    int *arr;
    int n;

} *TriMatrix;

TriMatrix init_tri_matrix(int n) {
    TriMatrix matrix = (TriMatrix) malloc(sizeof(struct TriMatrix));
    matrix->arr = (int *) malloc(sizeof(int) * (3 * n - 2));
    matrix->n = n;
    return matrix;
}

bool put_tri_matrix(TriMatrix matrix, int val, int i, int j) {
    i--;
    j--;
    if (abs(i - j) > 1)
        return false;
    int index = 3 * (i - 1) + (j - i);
    matrix->arr[index] = val;
    return true;

}


typedef struct ol_node {
    int row;
    int col;
    int val;
    struct ol_node* right;
    struct ol_node* down;
} ol_node;


typedef struct OLMatrix {
    int rowsize;
    int colsize;
    int nodesize;
    ol_node *rowarr;
    ol_node *colarr;
} *OLMatrix;


OLMatrix init_olmatrix(int row, int col) {
    OLMatrix matrix = (OLMatrix) malloc(sizeof(struct OLMatrix));
    matrix->rowarr = (ol_node *) malloc(sizeof(ol_node) * (row + 1));
    matrix->colarr = (ol_node *) malloc(sizeof(ol_node) * (col + 1));
    matrix->rowsize = row;
    matrix->colsize = col;
    return matrix;
}



void add_olmatrix(OLMatrix matrix, int val, int row, int col)
{
    ol_node* newnode = (ol_node*)malloc(sizeof(ol_node));
    newnode->row = row;
    newnode->col = col;
    newnode->val = val;
    newnode->right = NULL;
    newnode->down = NULL;

    ol_node* rowlink = &matrix->rowarr[row];
    ol_node* collink = &matrix->colarr[col];

    while (rowlink->right != NULL && rowlink->right->col < col) rowlink = rowlink->right;
    newnode->down = rowlink->down;
    rowlink->down = newnode;

    while (collink->down != NULL && collink->down->row < row) collink = collink->down;
    newnode->down = collink->down;
    collink->down = newnode;

}



#endif //INC_2019SPRINGDSA_ARRAY_H
