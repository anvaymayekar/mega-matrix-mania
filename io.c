// author: @anvaymayekar
// io.c - Matrix input and formatted output
// Implements matrix I/O using console prompts and color formatting.

#include <stdio.h>
#include <string.h>
#include "io.h"
#include "proto.h"
#include "utils.h"

void get_choice(const char *prompt, int *rows, int *cols, int two_values)
{
    char input[100];
    float a, b;
    int r, c;
    int del = 1;

    const char *text_style = CYAN "%s" RESET;
    if (two_values == -1)
    {
        del = 0;
        text_style = GREEN "%s" RESET;
        two_values = 0;
    }

    const char *invalid_msg = YELLOW "Invalid entry. Please enter valid number(s).\n" RESET;
    const char *limit_msg = YELLOW "Limit: Entry must be between %d-%d.\n" RESET;
    const char *truncate_msg = MAGENTA "Info: %.2f truncated to %d\n" RESET;

    while (1)
    {
        printf(text_style, prompt);

        // Read full line using scanf (like fgets)
        scanf(" %[^\n]", input); // Read line till newline
        while (getchar() != '\n')
            ; // Clear stdin buffer

        if (two_values)
        {
            char extra;
            if (sscanf(input, "%f %f %c", &a, &b, &extra) != 2)
            {
                printf("%s", invalid_msg);
                continue;
            }

            r = (int)a;
            c = (int)b;

            if (a != r && r >= del && r <= MAX)
                printf(truncate_msg, a, r);
            if (b != c && c >= del && c <= MAX)
                printf(truncate_msg, b, c);

            if (r < del || r > MAX || c < del || c > MAX)
            {
                printf(limit_msg, del, MAX);
                continue;
            }

            *rows = r;
            *cols = c;
            break;
        }
        else
        {
            char extra;
            if (sscanf(input, "%f %c", &a, &extra) != 1)
            {
                printf("%s", invalid_msg);
                continue;
            }

            r = (int)a;

            if (a != r && r >= del && r <= MAX)
                printf(truncate_msg, a, r);

            if (r < del || r > MAX)
            {
                printf(limit_msg, del, MAX);
                continue;
            }

            *rows = *cols = r;
            break;
        }
    }

    SLEEP(100); // optional short delay
}

void get_scalar(const char *prompt, double *value)
{
    char input[100];
    float temp;
    char extra;

    while (1)
    {
        printf(CYAN "%s" RESET, prompt);

        scanf(" %[^\n]", input); // Read full line
        while (getchar() != '\n')
            ; // Clear buffer

        // Check if input is valid float and has no extra junk
        if (sscanf(input, "%f %c", &temp, &extra) != 1)
        {
            printf(YELLOW "Invalid entry. Please enter a valid number.\n" RESET);
            continue;
        }

        *value = (double)temp;
        break;
    }
}

void input_matrix(Matrix mat)
{
    printf(BOLD "\nEnter matrix elements (%dx%d):\n" RESET, mat.rows, mat.cols);
    for (int i = 0; i < mat.rows; i++)
    {
        for (int j = 0; j < mat.cols; j++)
        {
            printf("[%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &mat.data[i][j]);
        }
    }
}

void display_matrix(Matrix mat)
{
    printf("\n");
    for (int i = 0; i < mat.rows; i++)
    {
        for (int j = 0; j < mat.cols; j++)
        {
            printf(CYAN "%12.2f" RESET, mat.data[i][j]);
        }
        printf("\n");
    }
}
