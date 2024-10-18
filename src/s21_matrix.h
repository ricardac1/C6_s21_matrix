#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

#define OK 0
#define INCORRECT_MATRIX 1
#define CALC_ERROR 2
#define CALLOC_FAILED 3
#define EPSILON 1e-7  // Для сравнения погрешности чисел с плавающей точкой

// создание матрицы
int s21_create_matrix(int rows, int columns, matrix_t *result);
// удаление матрицы
void s21_remove_matrix(matrix_t *A);
// сравнение возращает 1 если матрицы равны
int s21_eq_matrix(matrix_t *A, matrix_t *B);
// арифметика
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// вспомогательные функции
void s21_copy_matrix(matrix_t *A, matrix_t *result);
void s21_gauss(matrix_t *temp, double *result);
void s21_deletion(matrix_t *A, matrix_t *result, int i_row, int j_col);

#endif