#include "test_main.h"

START_TEST(test_s21_inverse_matrix_1) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;

  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;

  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  int res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(B.matrix[0][0], 1);
  ck_assert_int_eq(B.matrix[0][1], -1);
  ck_assert_int_eq(B.matrix[0][2], 1);
  ck_assert_int_eq(B.matrix[1][0], -38);
  ck_assert_int_eq(B.matrix[1][1], 41);
  ck_assert_int_eq(B.matrix[1][2], -34);
  ck_assert_int_eq(B.matrix[2][0], 27);
  ck_assert_int_eq(B.matrix[2][1], -29);
  ck_assert_int_eq(B.matrix[2][2], 24);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_inverse_matrix_2) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 2;

  A.matrix[1][0] = 2;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 8;

  A.matrix[2][0] = 3;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 2;

  int res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_3) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 2, &A);

  int res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

Suite *test_invert_matrix() {
  Suite *s = suite_create("S21_MATRIX_INVERSE_TEST");
  TCase *tc = tcase_create("case_inverse_matrix");
  tcase_add_test(tc, test_s21_inverse_matrix_1);
  tcase_add_test(tc, test_s21_inverse_matrix_2);
  tcase_add_test(tc, test_s21_inverse_matrix_3);
  suite_add_tcase(s, tc);
  return s;
}