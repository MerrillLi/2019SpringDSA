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
    int index = row * (row - 1) + col - 1;
    matrix->arr[index] = val;
}

int get_sparse_matrix(SparseMatrix matrix, int row, int col) {
    //adapt to array
    row--;
    col--;
    if (col > row)
        return get_sparse_matrix(matrix, col, row);

    int index = row * (row - 1) + col;
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
    if(abs(i - j) > 1)
        return false;
    int index = 3 * i + 1 + (i - j);
    matrix->arr[index] = val;
    return true;

}


#endif //INC_2019SPRINGDSA_ARRAY_H
