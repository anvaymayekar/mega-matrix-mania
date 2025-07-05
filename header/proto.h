// author: @anvaymayekar
// proto.h - Matrix operation prototypes and data structure
// Defines the Matrix struct and declares all matrix manipulation functions.

#ifndef MATRIX_H
#define MATRIX_H

#define EPSILON 1e-9

typedef struct
{
    int rows;
    int cols;
    double **data;
} Matrix;

Matrix create_matrix(int rows, int cols);
Matrix copy_matrix(Matrix original);
Matrix transpose_matrix(Matrix mat);
Matrix scalar_multiply(Matrix mat, double scalar);
Matrix multiply_matrices(Matrix A, Matrix B);
Matrix generate_identity(int order);
Matrix generate_cofactor(Matrix mat, int row, int col);
Matrix cofactor(Matrix mat);
Matrix adjoint(Matrix mat);
Matrix inverse(Matrix mat);
Matrix row_echelon_form(Matrix mat);
int matrix_rank(Matrix mat);
double determinant(Matrix mat);
void gaussian_elimination(Matrix mat);
void free_matrix(Matrix mat);

#endif
