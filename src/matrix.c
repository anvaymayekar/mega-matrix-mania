// author: @anvaymayekar
// matrix.c - Core implementation of matrix operations
// Provides logic for determinant, inverse, multiplication, rank, transpose, etc.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../header/proto.h"
#include "../header/utils.h"

Matrix create_matrix(int rows, int cols)
{
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        mat.data[i] = (double *)malloc(cols * sizeof(double));
    }
    return mat;
}

void free_matrix(Matrix mat)
{
    for (int i = 0; i < mat.rows; i++)
    {
        free(mat.data[i]);
    }
    free(mat.data);
}

Matrix copy_matrix(Matrix original)
{
    Matrix copy = create_matrix(original.rows, original.cols);
    for (int i = 0; i < original.rows; i++)
    {
        for (int j = 0; j < original.cols; j++)
        {
            copy.data[i][j] = original.data[i][j];
        }
    }
    return copy;
}

void gaussian_elimination(Matrix mat)
{
    for (int i = 0; i < mat.rows; i++)
    {
        if (mat.data[i][i] == 0)
        {
            for (int k = i + 1; k < mat.rows; k++)
            {
                if (mat.data[k][i] != 0)
                {
                    double *temp = mat.data[i];
                    mat.data[i] = mat.data[k];
                    mat.data[k] = temp;
                    break;
                }
            }
        }
        for (int j = i + 1; j < mat.rows; j++)
        {
            double ratio = mat.data[j][i] / mat.data[i][i];
            for (int k = 0; k < mat.cols; k++)
            {
                mat.data[j][k] -= ratio * mat.data[i][k];
            }
        }
    }
}

double determinant(Matrix mat)
{
    if (mat.rows != mat.cols)
        return NAN;
    Matrix temp = copy_matrix(mat);
    gaussian_elimination(temp);
    double det = 1.0;
    for (int i = 0; i < temp.rows; i++)
    {
        det *= temp.data[i][i];
    }
    free_matrix(temp);
    return det;
}

Matrix generate_cofactor(Matrix mat, int row, int col)
{
    Matrix cof = create_matrix(mat.rows - 1, mat.cols - 1);
    int r = 0, c;
    for (int i = 0; i < mat.rows; i++)
    {
        if (i == row)
            continue;
        c = 0;
        for (int j = 0; j < mat.cols; j++)
        {
            if (j == col)
                continue;
            cof.data[r][c++] = mat.data[i][j];
        }
        r++;
    }
    return cof;
}

Matrix adjoint(Matrix mat)
{
    if (mat.rows != mat.cols)
        return create_matrix(0, 0);
    Matrix adj = create_matrix(mat.rows, mat.cols);
    for (int i = 0; i < mat.rows; i++)
    {
        for (int j = 0; j < mat.cols; j++)
        {
            Matrix sub = generate_cofactor(mat, i, j);
            double det = determinant(sub);
            adj.data[j][i] = pow(-1, i + j) * det;
            free_matrix(sub);
        }
    }
    return adj;
}

Matrix cofactor(Matrix mat)
{
    Matrix cf = create_matrix(mat.rows, mat.cols);
    for (int i = 0; i < mat.rows; i++)
    {
        for (int j = 0; j < mat.cols; j++)
        {
            Matrix sub = generate_cofactor(mat, i, j);
            double det = determinant(sub);
            cf.data[i][j] = det;
            free_matrix(sub);
        }
    }
    return cf;
}

Matrix inverse(Matrix mat)
{
    double det = determinant(mat);
    if (fabs(det) < EPSILON)
        return create_matrix(0, 0);
    Matrix adj = adjoint(mat);
    Matrix inv = create_matrix(mat.rows, mat.cols);
    for (int i = 0; i < mat.rows; i++)
    {
        for (int j = 0; j < mat.cols; j++)
        {
            inv.data[i][j] = adj.data[i][j] / det;
        }
    }
    free_matrix(adj);
    return inv;
}

Matrix generate_identity(int order)
{
    Matrix identity = create_matrix(order, order);
    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            identity.data[i][j] = (i == j) ? 1 : 0;
        }
    }
    return identity;
}

Matrix transpose_matrix(Matrix mat)
{
    Matrix transposed = create_matrix(mat.cols, mat.rows);
    for (int i = 0; i < mat.rows; i++)
    {
        for (int j = 0; j < mat.cols; j++)
        {
            transposed.data[j][i] = mat.data[i][j];
        }
    }
    return transposed;
}

Matrix scalar_multiply(Matrix mat, double scalar)
{
    Matrix result = create_matrix(mat.rows, mat.cols);
    for (int i = 0; i < mat.rows; i++)
    {
        for (int j = 0; j < mat.cols; j++)
        {
            result.data[i][j] = mat.data[i][j] * scalar;
        }
    }
    return result;
}

Matrix multiply_matrices(Matrix A, Matrix B)
{
    if (A.cols != B.rows)
        return create_matrix(0, 0);
    Matrix result = create_matrix(A.rows, B.cols);
    for (int i = 0; i < A.rows; i++)
    {
        for (int j = 0; j < B.cols; j++)
        {
            result.data[i][j] = 0;
            for (int k = 0; k < A.cols; k++)
            {
                result.data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }
    return result;
}

Matrix row_echelon_form(Matrix mat)
{
    Matrix ref = copy_matrix(mat);
    int pivot_row = 0;
    for (int col = 0; col < ref.cols && pivot_row < ref.rows; col++)
    {
        int max_row = pivot_row;
        for (int i = pivot_row; i < ref.rows; i++)
        {
            if (fabs(ref.data[i][col]) > fabs(ref.data[max_row][col]))
            {
                max_row = i;
            }
        }
        if (fabs(ref.data[max_row][col]) < EPSILON)
            continue;
        if (max_row != pivot_row)
        {
            double *temp = ref.data[pivot_row];
            ref.data[pivot_row] = ref.data[max_row];
            ref.data[max_row] = temp;
        }
        for (int i = pivot_row + 1; i < ref.rows; i++)
        {
            double factor = ref.data[i][col] / ref.data[pivot_row][col];
            for (int j = col; j < ref.cols; j++)
            {
                ref.data[i][j] -= factor * ref.data[pivot_row][j];
            }
        }
        pivot_row++;
    }
    return ref;
}

int matrix_rank(Matrix mat)
{
    Matrix ref = row_echelon_form(mat);
    int rank = 0;
    for (int i = 0; i < ref.rows; i++)
    {
        int non_zero = 0;
        for (int j = 0; j < ref.cols; j++)
        {
            if (fabs(ref.data[i][j]) > EPSILON)
            {
                non_zero = 1;
                break;
            }
        }
        if (non_zero)
            rank++;
    }
    free_matrix(ref);
    return rank;
}
