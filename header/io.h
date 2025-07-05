// author: @anvaymayekar
// io.h - Matrix input/output interface
// Declares functions for user input and formatted display of matrices.

#ifndef IO_H
#define IO_H

#include "proto.h"
#include "utils.h"

void get_choice(const char *prompt, int *rows, int *cols, int two_values);
void get_scalar(const char *prompt, double *value);
void input_matrix(Matrix mat);
void display_matrix(Matrix mat);

#endif
