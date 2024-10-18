#include "test_main.h"

START_TEST(s21_mul_matrix_test_1) {
  const int rows = 3;
  const int cols = 2;
  matrix_t m = {0};
  matrix_t mtx = {0};
  matrix_t check = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(cols, rows, &mtx);
  s21_create_matrix(m.rows, mtx.columns, &check);

  m.matrix[0][0] = 1;
  m.matrix[0][1] = 4;
  m.matrix[1][0] = 2;
  m.matrix[1][1] = 5;
  m.matrix[2][0] = 3;
  m.matrix[2][1] = 6;

  mtx.matrix[0][0] = 1;
  mtx.matrix[0][1] = -1;
  mtx.matrix[0][2] = 1;
  mtx.matrix[1][0] = 2;
  mtx.matrix[1][1] = 3;
  mtx.matrix[1][2] = 4;

  check.matrix[0][0] = 9;
  check.matrix[0][1] = 11;
  check.matrix[0][2] = 17;
  check.matrix[1][0] = 12;
  check.matrix[1][1] = 13;
  check.matrix[1][2] = 22;
  check.matrix[2][0] = 15;
  check.matrix[2][1] = 15;
  check.matrix[2][2] = 27;

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_matrix(&m, &mtx, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&res, &check), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_mul_matrix_test_2) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  rows = -rows;
  cols = -cols;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(cols, rows, &mtx);

  matrix_t check = {0};
  s21_create_matrix(m.rows, mtx.columns, &check);

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_matrix(&m, &mtx, &res), CALC_ERROR);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_mul_matrix_test_3) {
  matrix_t m = {0};
  int rows = 2;
  int cols = 3;
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  int rows1 = 4;
  int cols1 = 5;
  s21_create_matrix(rows1, cols1, &mtx);

  matrix_t check = {0};
  s21_create_matrix(m.rows, mtx.columns, &check);

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_matrix(&m, &mtx, &res), CALC_ERROR);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

Suite *test_mul_matrix() {
  Suite *s = suite_create("S21_MATRIX_MUL_MATRIX_TEST");
  TCase *tc = tcase_create("case_mul_matrix");
  tcase_add_test(tc, s21_mul_matrix_test_1);
  tcase_add_test(tc, s21_mul_matrix_test_2);
  tcase_add_test(tc, s21_mul_matrix_test_3);

  suite_add_tcase(s, tc);
  return s;
}