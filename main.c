// author: @anvaymayekar
// main.c - Matrix Mania CLI entry point
// Handles user interaction, displays menus, invokes matrix operations.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "proto.h"
#include "io.h"
#include "utils.h"
#include "title.h"

int main()
{
    int n, choice;

    set_title("Mega Matrix Mania");
    printf(BOLD GREEN "<======> Mega Matrix Mania <======>\n" RESET);
    printf("\nprogrammed by @anvaymayekar\n");

    get_choice("\nEnter primary matrix order [n x n] (n): ", &n, &n, 0);
    Matrix primary = create_matrix(n, n);

    while (1)
    {
        printf("\n=== Matrix Operations ===\n");
        printf("\n0. Change the order\n");
        printf("1. Display Matrix\n");
        printf("2. Transpose\n");
        printf("3. Scalar Multiplication\n");
        printf("4. Matrix Multiplication\n");
        printf("5. Determinant\n");
        printf("6. Adjoint\n");
        printf("7. Inverse\n");
        printf("8. Identity\n");
        printf("9. Cofactor\n");
        printf("10. Row Echelon Form\n");
        printf("11. Rank of a Matrix\n");
        printf("12. Exit\n\n");
        SLEEP(100);
        get_choice("Choice: ", &choice, &choice, -1);

        switch (choice)
        {
        case 0:
        {
            int old = n;
            printf("\n--- 0. Change the order ---\n");
            get_choice("Change the primary matrix order (n): ", &n, &n, 0);
            printf(GREEN "Changed the matrix order from %d -> %d\n" RESET, old, n);
            primary = create_matrix(n, n);
            break;
        }
        case 1:
        {
            printf("\n--- 1. Display Matrix ---\n");
            input_matrix(primary);
            printf("\nEntered Matrix:\n");
            display_matrix(primary);
            break;
        }
        case 2:
        {
            printf("\n--- 2. Transpose ---\n");
            input_matrix(primary);
            Matrix transposed = transpose_matrix(primary);
            printf("\nPrimary Matrix:\n");
            display_matrix(primary);
            printf("\nTransposed Matrix:\n");
            display_matrix(transposed);
            free_matrix(transposed);
            break;
        }
        case 3:
        {
            printf("\n--- 3. Scalar Multiplication ---\n");
            double scalar;
            get_scalar("\nEnter scalar value: ", &scalar);
            input_matrix(primary);
            Matrix scaled = scalar_multiply(primary, scalar);
            printf("\nScalar: %lf\n", scalar);
            printf("\nPrimary Matrix:\n");
            display_matrix(primary);
            printf("\nScalar Product:\n");
            display_matrix(scaled);
            free_matrix(scaled);
            break;
        }
        case 4:
        {
            printf("\n--- 4. Matrix Multiplication ---\n");
            int rows, cols;
            printf("\nMatrix A\n");
            input_matrix(primary);
            printf("\nMatrix B\n");
            get_choice("Enter second matrix dimensions (row col): ", &rows, &cols, 1);
            Matrix secondary = create_matrix(rows, cols);
            input_matrix(secondary);
            printf("\nPrimary Matrix:\n");
            display_matrix(primary);
            printf("\nSecondary Matrix:\n");
            display_matrix(secondary);
            Matrix product = multiply_matrices(primary, secondary);
            if (product.rows > 0)
            {
                printf("\nMatrix Product:\n");
                display_matrix(product);
                free_matrix(product);
            }
            free_matrix(secondary);
            break;
        }
        case 5:
        {
            printf("\n--- 5. Determinant ---\n");
            input_matrix(primary);
            double det = determinant(primary);
            if (!isnan(det))
            {
                printf("\nPrimary Matrix:\n");
                display_matrix(primary);
                printf("\nDeterminant: %.2f\n", det);
            }
            break;
        }
        case 6:
        {
            printf("\n--- 6. Adjoint ---\n");
            input_matrix(primary);
            Matrix adj = adjoint(primary);
            if (adj.rows > 0)
            {
                printf("\nPrimary Matrix:\n");
                display_matrix(primary);
                printf("\nAdjoint Matrix:\n");
                display_matrix(adj);
                free_matrix(adj);
            }
            break;
        }
        case 7:
        {
            printf("\n--- 7. Inverse ---\n");
            input_matrix(primary);
            printf("\nPrimary Matrix:\n");
            display_matrix(primary);
            Matrix inv = inverse(primary);
            if (inv.rows > 0)
            {
                printf("\nInverse Matrix:\n");
                display_matrix(inv);
                free_matrix(inv);
            }
            break;
        }
        case 8:
        {
            printf("\n--- 8. Identity ---\n");
            int order;
            get_choice("Enter the order (Integer > 0): ", &order, &order, 0);
            Matrix ident = generate_identity(order);
            printf("\nIdentity Matrix of order %d:\n", order);
            display_matrix(ident);
            break;
        }
        case 9:
        {
            printf("\n--- 9. Cofactor ---\n");
            input_matrix(primary);
            Matrix cfx = cofactor(primary);
            printf("\nPrimary Matrix:\n");
            display_matrix(primary);
            printf("\nCofactor Matrix:\n");
            display_matrix(cfx);
            free_matrix(cfx);
            break;
        }
        case 10:
        {
            printf("\n--- 10. Row Echelon Form ---\n");
            input_matrix(primary);
            Matrix ref = row_echelon_form(primary);
            printf("\nPrimary Matrix:\n");
            display_matrix(primary);
            printf("\nRow Echelon Form:\n");
            display_matrix(ref);
            free_matrix(ref);
            break;
        }
        case 11:
        {
            printf("\n--- 10. Rank of a Matrix ---\n");
            input_matrix(primary);
            int rank = matrix_rank(primary);
            printf("\nPrimary Matrix:\n");
            display_matrix(primary);
            printf("\nRank of Matrix: %d\n", rank);
            break;
        }
        case 12:
        {
            free_matrix(primary);
            printf(RED "\nUser requested for termination.\n" RESET);
            SLEEP(1000);
            printf(GREEN "...The program has been aborted!\n" RESET);
            SLEEP(1000);
            return 0;
        }
        default:
            printf(RED "Invalid choice!\n" RESET);
        }
    }
}