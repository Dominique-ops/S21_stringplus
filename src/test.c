#define BUFF_SIZE 512

#include "test.h"

START_TEST(find_in_empty_str) {
  char s21_str[] = "";
  char s21_c = '\0';
  char str[] = "";
  char c = '\0';
  s21_size_t n = 0;

  ck_assert_pstr_eq(s21_memchr(s21_str, s21_c, n), memchr(str, c, n));
}
END_TEST

START_TEST(find_empty_in_str) {
  char s21_str[] = "someIntellectualText";
  char s21_c = '\0';
  char str[] = "someIntellectualText";
  char c = '\0';
  s21_size_t n = 5;

  ck_assert_pstr_eq(s21_memchr(s21_str, s21_c, n), memchr(str, c, n));
}
END_TEST

START_TEST(find_uppercase) {
  char s21_str[] = "hello";
  char s21_c = 'H';
  char str[] = "hello";
  char c = 'H';
  s21_size_t n = 5;

  ck_assert_pstr_eq(s21_memchr(s21_str, s21_c, n), memchr(str, c, n));
}
END_TEST

START_TEST(find_in_start) {
  char s21_str[] = "Hello";
  char s21_c = 'H';
  char str[] = "Hello";
  char c = 'H';
  s21_size_t n = 5;

  ck_assert_pstr_eq(s21_memchr(s21_str, s21_c, n), memchr(str, c, n));
}
END_TEST

START_TEST(find_in_end) {
  char s21_str[] = "hello";
  char s21_c = 'o';
  char str[] = "hello";
  char c = 'o';
  s21_size_t n = 5;

  ck_assert_pstr_eq(s21_memchr(s21_str, s21_c, n), memchr(str, c, n));
}
END_TEST

START_TEST(find_num_in_string) {
  char s21_str[] = "hel3523522lo";
  char s21_c = '2';
  char str[] = "hel3523522lo";
  char c = '2';
  s21_size_t n = 10;

  ck_assert_pstr_eq(s21_memchr(s21_str, s21_c, n), memchr(str, c, n));
}
END_TEST

START_TEST(find_num_in_array) {
  int s21_arr[] = {1, 43, 235, 7, 23, 111, 9, 0};
  int s21_c = 235;
  int arr[] = {1, 43, 235, 7, 23, 111, 9, 0};
  int c = 235;
  s21_size_t n = sizeof(int) * 8;

  ck_assert_pstr_eq(s21_memchr(s21_arr, s21_c, n), memchr(arr, c, n));
}
END_TEST

Suite *suite_memchr() {
  Suite *suite = suite_create("memchr_suite");
  TCase *tcase_core = tcase_create("memchr_tc");

  tcase_add_test(tcase_core, find_in_empty_str);
  tcase_add_test(tcase_core, find_empty_in_str);
  tcase_add_test(tcase_core, find_uppercase);
  tcase_add_test(tcase_core, find_in_start);
  tcase_add_test(tcase_core, find_in_end);
  tcase_add_test(tcase_core, find_num_in_string);
  tcase_add_test(tcase_core, find_num_in_array);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(str1_more_str2) {
  const char str1[] = "1a3bc";
  const char str2[] = "123abc";
  s21_size_t n = 3;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(str1_less_str2) {
  const char str1[] = "123abc";
  const char str2[] = "1a3bc";
  s21_size_t n = 3;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(equal) {
  const char str1[] = "123abc";
  const char str2[] = "123abc";
  s21_size_t n = 3;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

Suite *suite_memcmp() {
  Suite *suite = suite_create("memcmp_suite");
  TCase *tcase_core = tcase_create("memcmp_tc");

  tcase_add_test(tcase_core, str1_more_str2);
  tcase_add_test(tcase_core, str1_less_str2);
  tcase_add_test(tcase_core, equal);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(simple_copy) {
  char s21_dest[5] = "";
  const char s21_src[] = "12345";
  const char src[] = "12345";
  char dest[5] = "";
  s21_size_t n = 3;

  ck_assert_str_eq(s21_memcpy((void *)s21_dest, s21_src, n),
                   memcpy((void *)dest, src, n));
}
END_TEST

START_TEST(n_zero) {
  char s21_dest[5] = "";
  const char s21_src[] = "12345";
  const char src[] = "12345";
  char dest[5] = "";
  s21_size_t n = 0;

  ck_assert_str_eq(s21_memcpy((void *)s21_dest, s21_src, n),
                   memcpy((void *)dest, src, n));
}
END_TEST

START_TEST(rewrite_test) {
  char s21_dest[25] = "Hello";
  const char s21_src[] = "zzzzz_world";
  const char src[] = "zzzzz_world";
  char dest[25] = "Hello";
  s21_size_t n = 6;

  ck_assert_str_eq(s21_memcpy((void *)s21_dest, s21_src, n),
                   memcpy((void *)dest, src, n));
}
END_TEST

START_TEST(test_with_underline) {
  char s21_dest[25] = "";
  const char s21_src[] = "Hello_world";
  const char src[] = "Hello_world";
  char dest[25] = "";
  s21_size_t n = 12;

  ck_assert_str_eq(s21_memcpy((void *)s21_dest, s21_src, n),
                   memcpy((void *)dest, src, n));
}
END_TEST

Suite *suite_memcpy() {
  Suite *suite = suite_create("memcpy_suite");
  TCase *tcase_core = tcase_create("memcpy_tc");

  tcase_add_test(tcase_core, simple_copy);
  tcase_add_test(tcase_core, n_zero);
  tcase_add_test(tcase_core, rewrite_test);
  tcase_add_test(tcase_core, test_with_underline);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(some_test) {
  char s21_dest[] = "someIntellectualText";
  char s21_src = 'i';
  char dest[] = "someIntellectualText";
  char src = 'i';
  s21_size_t n = 7;

  ck_assert_str_eq(s21_memset(s21_dest, s21_src, n), memset(dest, src, n));
}
END_TEST

START_TEST(zero_n_test) {
  char s21_dest[] = "someIntellectualText";
  char s21_src = 'i';
  char dest[] = "someIntellectualText";
  char src = 'i';
  s21_size_t n = 0;

  ck_assert_str_eq(s21_memset(s21_dest, s21_src, n), memset(dest, src, n));
}
END_TEST

START_TEST(empty_test) {
  char s21_dest[] = "";
  char s21_src = '\0';
  char dest[] = "";
  char src = '\0';
  s21_size_t n = 0;

  ck_assert_str_eq(s21_memset(s21_dest, s21_src, n), memset(dest, src, n));
}
END_TEST

START_TEST(replace_number_test) {
  char s21_dest[] = "hello";
  char s21_src = '2';
  char dest[] = "hello";
  char src = '2';
  s21_size_t n = 3;

  ck_assert_str_eq(s21_memset(s21_dest, s21_src, n), memset(dest, src, n));
}
END_TEST

START_TEST(replace_register_test) {
  char s21_dest[] = "hello";
  char s21_src = 'H';
  char dest[] = "hello";
  char src = 'H';
  s21_size_t n = 1;

  ck_assert_str_eq(s21_memset(s21_dest, s21_src, n), memset(dest, src, n));
}
END_TEST

START_TEST(long_test) {
  char s21_dest[] =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce nec "
      "tempus felis. Nullam dapibus nam.";
  char s21_src = '*';
  char dest[] =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce nec "
      "tempus felis. Nullam dapibus nam.";
  char src = '*';
  s21_size_t n = 10;

  ck_assert_str_eq(s21_memset(s21_dest, s21_src, n), memset(dest, src, n));
}
END_TEST

Suite *suite_memset() {
  Suite *suite = suite_create("memset_suite");
  TCase *tcase_core = tcase_create("memset_tc");

  tcase_add_test(tcase_core, some_test);
  tcase_add_test(tcase_core, zero_n_test);
  tcase_add_test(tcase_core, empty_test);
  tcase_add_test(tcase_core, replace_number_test);
  tcase_add_test(tcase_core, replace_register_test);
  tcase_add_test(tcase_core, long_test);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(empty_str) {
  char str[] = "";
  int c = '1';

  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(some_cin_str) {
  char str[] = "hellell56o";
  int c = '5';

  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(empty_str_and_c) {
  char str[] = "";
  int c = '\0';

  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(empty_c) {
  char str[] = "Some meaningless text";
  int c = '\0';

  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(regular_test) {
  char str[] = "1Greetings";
  int c = '1';

  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(no_match_test) {
  char str[] = "i need this text";
  int c = '5';

  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(one_symbol_test) {
  char str[] = "1";
  int c = '1';

  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

Suite *suite_strchr() {
  Suite *suite = suite_create("strchr_suite");
  TCase *tcase_core = tcase_create("strchr_tc");
  tcase_add_test(tcase_core, empty_str);
  tcase_add_test(tcase_core, some_cin_str);
  tcase_add_test(tcase_core, empty_c);
  tcase_add_test(tcase_core, empty_str_and_c);
  tcase_add_test(tcase_core, regular_test);
  tcase_add_test(tcase_core, no_match_test);
  tcase_add_test(tcase_core, one_symbol_test);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(len1) {
  char str[] = "hellell56o";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(len2) {
  char str[] = "";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(len3) {
  char str[] = "1";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

Suite *suite_strlen() {
  Suite *suite = suite_create("strlen_suite");
  TCase *tcase_core = tcase_create("strlen_tc");
  tcase_add_test(tcase_core, len1);
  tcase_add_test(tcase_core, len2);
  tcase_add_test(tcase_core, len3);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(empty_s1) {
  char s1[] = "";
  char s2[] = "Hello everyone123";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(some_s1_in_s2) {
  char s1[] = "hellello";
  char s2[] = "el";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(empty_s1s2) {
  char s1[] = "";
  char s2[] = "";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(empty_s2) {
  char s1[] = "Some meaningless text";
  char s2[] = "";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(reg_test) {
  char s1[] = "Hello World";
  char s2[] = "World";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(no_m_test) {
  char s1[] = "i need this text";
  char s2[] = "sorry";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(register_test) {
  char s1[] = "Hello World";
  char s2[] = "world";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(one_sym_test) {
  char s1[] = "Hi";
  char s2[] = "i";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

Suite *suite_strncat() {
  Suite *suite = suite_create("strncat_suite");
  TCase *tcase_core = tcase_create("strncat_tc");

  tcase_add_test(tcase_core, empty_s1);
  tcase_add_test(tcase_core, some_s1_in_s2);
  tcase_add_test(tcase_core, empty_s1s2);
  tcase_add_test(tcase_core, empty_s2);
  tcase_add_test(tcase_core, reg_test);
  tcase_add_test(tcase_core, no_m_test);
  tcase_add_test(tcase_core, register_test);
  tcase_add_test(tcase_core, one_sym_test);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(empty) {
  const char str1[] = "";
  const char str2[] = "";
  s21_size_t n = 1;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(empty_str1) {
  const char str1[] = "";
  const char str2[] = "123";
  s21_size_t n = 1;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(empty_str2) {
  const char str1[] = "123";
  const char str2[] = "";
  s21_size_t n = 1;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(str1_m_str2) {
  const char str1[] = "1a3bc";
  const char str2[] = "123abc";
  s21_size_t n = 3;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(str1_l_str2) {
  const char str1[] = "123abc";
  const char str2[] = "1a3bc";
  s21_size_t n = 3;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

Suite *suite_strncmp() {
  Suite *suite = suite_create("strncmp_suite");
  TCase *tcase_core = tcase_create("strncmp_tc");

  tcase_add_test(tcase_core, empty);
  tcase_add_test(tcase_core, empty_str1);
  tcase_add_test(tcase_core, empty_str2);
  tcase_add_test(tcase_core, str1_m_str2);
  tcase_add_test(tcase_core, str1_l_str2);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(emp) {
  char s21_dest[] = "";
  char s21_src[] = "";
  char dest[] = "";
  char src[] = "";
  s21_size_t n = 0;

  ck_assert_str_eq(s21_strncpy(s21_dest, s21_src, n), strncpy(dest, src, n));
}
END_TEST

START_TEST(n_ze) {
  char s21_dest[] = "Hello";
  char s21_src[] = "world";
  char dest[] = "Hello";
  char src[] = "world";
  s21_size_t n = 0;

  ck_assert_str_eq(s21_strncpy(s21_dest, s21_src, n), strncpy(dest, src, n));
}
END_TEST

START_TEST(empty_dest) {
  char s21_dest[3] = "";
  char s21_src[20] = "Lorem ipsum integer";
  char dest[3] = "";
  char src[20] = "Lorem ipsum integer";
  s21_size_t n = 2;

  ck_assert_str_eq(s21_strncpy(s21_dest, s21_src, n), strncpy(dest, src, n));
}
END_TEST

START_TEST(not_enough_byte_n) {
  char s21_dest[30] = "Lorem ipsum";
  char s21_src[20] = "Lorem ipsum integer";
  char dest[30] = "Lorem ipsum";
  char src[20] = "Lorem ipsum integer";
  s21_size_t n = 1;

  ck_assert_str_eq(s21_strncpy(s21_dest, s21_src, n), strncpy(dest, src, n));
}
END_TEST

START_TEST(enough_byte_n) {
  char s21_dest[30] = "Lorem ipsum";
  char s21_src[20] = "Lorem ipsum integer";
  char dest[30] = "Lorem ipsum";
  char src[20] = "Lorem ipsum integer";
  s21_size_t n = 19;

  ck_assert_str_eq(s21_strncpy(s21_dest, s21_src, n), strncpy(dest, src, n));
}
END_TEST

Suite *suite_strncpy() {
  Suite *suite = suite_create("strncpy_suite");
  TCase *tcase_core = tcase_create("strncpy_tc");

  tcase_add_test(tcase_core, emp);
  tcase_add_test(tcase_core, n_ze);
  tcase_add_test(tcase_core, empty_dest);
  tcase_add_test(tcase_core, not_enough_byte_n);
  tcase_add_test(tcase_core, enough_byte_n);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(emp_s1) {
  char s1[] = "";
  char s2[] = "Hello everyone123";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(so_s1_in_s2) {
  char s1[] = "hellello";
  char s2[] = "el";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(emp_s1s2) {
  char s1[] = "";
  char s2[] = "";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(emp_s2) {
  char s1[] = "Some meaningless text";
  char s2[] = "";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(regul_test) {
  char s1[] = "Hello World";
  char s2[] = "World";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(no_matc_test) {
  char s1[] = "i need this text";
  char s2[] = "sorry";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(regis_test) {
  char s1[] = "Hello World";
  char s2[] = "world";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(one_symbo_test) {
  char s1[] = "Hi";
  char s2[] = "i";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

Suite *suite_strpbrk() {
  Suite *suite = suite_create("strpbrk_suite");
  TCase *tcase_core = tcase_create("strpbrk_tc");

  tcase_add_test(tcase_core, emp_s1);
  tcase_add_test(tcase_core, so_s1_in_s2);
  tcase_add_test(tcase_core, emp_s1s2);
  tcase_add_test(tcase_core, emp_s2);
  tcase_add_test(tcase_core, regul_test);
  tcase_add_test(tcase_core, no_matc_test);
  tcase_add_test(tcase_core, regis_test);
  tcase_add_test(tcase_core, one_symbo_test);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(empty_st) {
  char str[] = "";
  int c = '1';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(some_cin_st) {
  char str[] = "hellell556o";
  int c = '5';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(empty_st_and_c) {
  char str[] = "";
  int c = '\0';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(empt_c) {
  char str[] = "Some meaningless text";
  int c = '\0';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(regula_test) {
  char str[] = "1Greetings";
  int c = '1';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(no_match_tes) {
  char str[] = "i need this text";
  int c = '5';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(one_symbol_tes) {
  char str[] = "1";
  int c = '1';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

Suite *suite_strrchr() {
  Suite *suite = suite_create("strrchr_suite");
  TCase *tcase_core = tcase_create("strrchr_tc");
  tcase_add_test(tcase_core, empty_st);
  tcase_add_test(tcase_core, some_cin_st);
  tcase_add_test(tcase_core, empt_c);
  tcase_add_test(tcase_core, empty_st_and_c);
  tcase_add_test(tcase_core, regula_test);
  tcase_add_test(tcase_core, no_match_tes);
  tcase_add_test(tcase_core, one_symbol_tes);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(empty_haystack) {
  char haystack[] = "";
  char needle[] = "Hello everyone123";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(some_needle_in_haystack) {
  char haystack[] = "hellello";
  char needle[] = "el";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(empty_haystack_and_needle) {
  char haystack[] = "";
  char needle[] = "";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(empty_needle) {
  char haystack[] = "Some meaningless text";
  char needle[] = "";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(egular_test) {
  char haystack[] = "Hello World";
  char needle[] = "World";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(o_match_test) {
  char haystack[] = "i need this text";
  char needle[] = "sorry";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(egister_test) {
  char haystack[] = "Hello World";
  char needle[] = "world";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(ne_symbol_test) {
  char haystack[] = "Hi";
  char needle[] = "i";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

Suite *suite_strstr() {
  Suite *suite = suite_create("strstr_suite");
  TCase *tcase_core = tcase_create("strstr_tc");

  tcase_add_test(tcase_core, empty_haystack);
  tcase_add_test(tcase_core, some_needle_in_haystack);
  tcase_add_test(tcase_core, empty_haystack_and_needle);
  tcase_add_test(tcase_core, empty_needle);
  tcase_add_test(tcase_core, egular_test);
  tcase_add_test(tcase_core, o_match_test);
  tcase_add_test(tcase_core, egister_test);
  tcase_add_test(tcase_core, ne_symbol_test);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(simple_token_string) {
  char s21_str[] = "Maecenas++mollis_*_!malesuada massa=======vitae";
  char str[] = "Maecenas++mollis__!malesuada massa=======vitae";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(hard_token_string) {
  char s21_str[] = "      Maecenas++mollis__! D !malesuada _massa=======vitae ";
  char str[] = "      Maecenas++mollis__! D !malesuada _massa=======vitae ";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(not_all_delims) {
  char s21_str[] = "Maecenas++mollis__!D!malesuada_massa=======vitae";
  char str[] = "Maecenas++mollis__!D!malesuada_massa=======vitae*";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(no_delims) {
  char s21_str[] = "MaecenasmollisMalesuadaMassaVitae";
  char str[] = "MaecenasmollisMalesuadaMassaVitae";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(delims_str) {
  char s21_str[] = "++!!= _";
  char str[] = "++!!= _";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_pstr_eq(s21, system);
}
END_TEST

START_TEST(delims_in_word) {
  char s21_str[] = "Maece+*+nasmollis    !malesu     ada=massa___vitae";
  char str[] = "Maece++nasmollis    !malesu     ada=massa___vitae";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(hard_word) {
  char s21_str[] = "!M+*+N***L M=M_F_V*H";
  char str[] = "!M+*+N***L M=M_F_V*H";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(hard_string) {
  char s21_str[] =
      "        !          Maece+*+nasmol***lis    !malesu     "
      "ada=massa_f__vitae*** *** *** hi";
  char str[] =
      "        !          Maece+*+nasmol***lis    !malesu     "
      "ada=massa_f__vitae*** *** *** hi";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

Suite *suite_strtok() {
  Suite *suite = suite_create("strtok_suite");
  TCase *tcase_core = tcase_create("strtok_tc");

  tcase_add_test(tcase_core, simple_token_string);
  tcase_add_test(tcase_core, hard_token_string);
  tcase_add_test(tcase_core, not_all_delims);
  tcase_add_test(tcase_core, no_delims);
  tcase_add_test(tcase_core, delims_str);
  tcase_add_test(tcase_core, delims_in_word);
  tcase_add_test(tcase_core, hard_word);
  tcase_add_test(tcase_core, hard_string);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

START_TEST(e) {
  char src[] = "";
  char res[] = "";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(gora_) {
  char src[] = "gora";
  char res[] = "";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(_gora) {
  char src[] = "";
  char res[] = "gora";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(any_register) {
  char src[] = "gora";
  char res[] = "gOra";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(num_num) {
  char src[] = "123";
  char res[] = "123";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(long_num_num) {
  char src[] = "12345";
  char res[] = "123";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(num_long_num) {
  char src[] = "123";
  char res[] = "12345";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(any_num) {
  char src[] = "1234567890";
  char res[] = "0987654321";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(num_with_letter) {
  char src[] = "1A2A3A4A5A";
  char res[] = "123";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(num_with_letter2) {
  char src[] = "a1aaa23aaa41235";
  char res[] = "123";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(basic_test) {
  char src[] = "absD";
  char res[] = "aD";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(any_sim) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "0987654321";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(upper_letter) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(lower_letter) {
  char src[] = "32jersASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890qwertyuiopasdfghjklczxcvbnm";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(not_uniq_sim) {
  char src[] = "33333";
  char res[] = "11133";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

Suite *suite_strcspn(void) {
  Suite *s = suite_create("suite_strcspn");
  TCase *tc = tcase_create("strcspn_tc");

  tcase_add_test(tc, e);
  tcase_add_test(tc, gora_);
  tcase_add_test(tc, _gora);
  tcase_add_test(tc, any_register);
  tcase_add_test(tc, num_num);
  tcase_add_test(tc, long_num_num);
  tcase_add_test(tc, num_long_num);
  tcase_add_test(tc, any_num);
  tcase_add_test(tc, num_with_letter);
  tcase_add_test(tc, num_with_letter2);
  tcase_add_test(tc, basic_test);
  tcase_add_test(tc, any_sim);
  tcase_add_test(tc, upper_letter);
  tcase_add_test(tc, lower_letter);
  tcase_add_test(tc, not_uniq_sim);

  suite_add_tcase(s, tc);
  return s;
}

START_TEST(all_std_errors_1) {
  for (int i = 0; i < 134; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
  // ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(all_std_errors_2) {
  // char *got = s21_strerror(-1);
  // char *expected = strerror(-1);
  ck_assert_str_eq(s21_strerror(-1), strerror(-1));
}
END_TEST

START_TEST(simple_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple value %d";
  int val = 69;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *suite_strerror(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("suite_strerror");
  tc = tcase_create("strerror_tc");
  tcase_add_test(tc, all_std_errors_1);
  tcase_add_test(tc, all_std_errors_2);

  suite_add_tcase(s, tc);
  return s;
}

START_TEST(precise_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5d";
  int val = 69;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  // ck_assert_int_eq(s21_sprintf(str1, format, val),
  //                  sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5d";
  int val = 69;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  // ck_assert_int_eq(s21_sprintf(str1, format, val),
  //                  sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(plus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+12d";
  int val = 69;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  // ck_assert_int_eq(s21_sprintf(str1, format, val),
  //                  sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(padding_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%12d";
  int val = 69;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  // ck_assert_int_eq(s21_sprintf(str1, format, val),
  //                  sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+5.31ld";
  long int val = 698518581899;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  // ck_assert_int_eq(s21_sprintf(str1, format, val),
  //                  sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_short_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16.9hd";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_another_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.ld";
  long val = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(zero_precision_zero_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(space_flag_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% 5.6u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}

START_TEST(unsigned_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(one_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-15.9s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s%s%s%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_width_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
/*
// START_TEST(float_precision) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%lf";
//     long double val = 513515.131513515151351;
//     s21_sprintf(str1, format, val);
//     sprintf(str2, format, val);
//     // ck_assert_int_eq(s21_sprintf(str1, format, val),
//     //                  sprintf(str2, format, val));
//     printf("%s|%s", str1, str2);
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
//
// START_TEST(float_width) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%10lf";
//     long double val = 15.35;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(float_precision_zero) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%.0lf";
//     long double val = 15.35;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(float_precision_empty) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%.lf";
//     long double val = 15.35;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(float_precision_huge) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%.15lf";
//     long double val = 15.35;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
*/

// START_TEST(float_precision_huge_negative) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%.15Lf";
//     long double val = -15.35581134;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(float_huge) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%Lf";
//     long double val = 72537572375.1431341;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(float_flags) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "% f";
//     float val = 0;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(float_many) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "% .0f %.lf %Lf %f %lf %Lf";
//     float val = 0;
//     double val1 = 0;
//     long double val2 = 3515315.153151;
//     float val3 = 5.5;
//     double val4 = 9851.51351;
//     long double val5 = 95919539159.53151351131;
//     ck_assert_int_eq(
//         s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
//         sprintf(str2, format, val, val1, val2, val3, val4, val5));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(all_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(empty_format_and_parameters) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

  ck_assert_str_eq(str1, str2);
}
END_TEST
/*
// START_TEST(test_many_dec) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100);
//     sprintf(str2, "%d%d%d%d", -999, 0, 666, -100);
//     // ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
//     //                  sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
*/
START_TEST(test_one_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  printf("fa");
  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));

  ck_assert_str_eq(str1, str2);
}
END_TEST
/*
// START_TEST(test_many_float) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(
//         s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
//         sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
*/
START_TEST(test_one_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(test_many_unsigned_dec) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
//                      sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
//                              (unsigned)666, (unsigned)100));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(test_one_char_with_aldgnment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char_with_aldgnment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(test_many_char_with_aldgnment) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(
//         s21_sprintf(str1, "|%3c|%-11c|%10c|%-2c|%c|A", '\t', '\n', '0', 'S',
//         's'), sprintf(str2, "A|%3c|%-11c|%10c|%-2c|%c|", '\t', '\n', '0',
//         'S', 's'));

//     printf("\n%s%s\n", str1, str2);

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(test_sprintf1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%10ld";

  ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%1.1f";

  ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%8.3c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+5.5d aboba";

  int val = 10000;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.7f";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                   sprintf(str2, format, 11.123456));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.4s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                   sprintf(str2, format, "aboba floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%6.6u";

  ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                   sprintf(str2, format, 12341151));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf9) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%ld%ld%lu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
                   sprintf(str2, format, 666666666666, 777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf10) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%hd%hd%hu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
                   sprintf(str2, format, 666, -777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST
/*
// START_TEST(test_sprintf11) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%+lu%+d%+lf";

//     ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
//                      sprintf(str2, format, -123, 321, -5555, -1213.123));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf12) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%-11.11ld%-35.5lu%-3.5ld%33.19Lf";
//     long double k = 333.33213;

//     ck_assert_int_eq(
//         s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, k),
//         sprintf(str2, format, 66666666666, 5555555555, 44444444444, k));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf14) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "% 0.0ld% 0.0lu% 0.0ld % 0.0lf";

//     ck_assert_int_eq(
//         s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
//         sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf15) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "% 0.0hi% 0.0hu% 0.0hd % 0.0hf";

//     ck_assert_int_eq(
//         s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
//         sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf16) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "% c";

//     ck_assert_int_eq(s21_sprintf(str1, format, 'a'),
//                      sprintf(str2, format, 'a'));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf17) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "% s";

//     ck_assert_int_eq(s21_sprintf(str1, format, "aboba ldkes floppa"),
//                      sprintf(str2, format, "aboba ldkes floppa"));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf18) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "% s% c";

//     ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
//                      sprintf(str2, format, "", 'f'));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf19) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%210s";

//     ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
//                      sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf20) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%-115s";

//     ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
//                      sprintf(str2, format, "Nick her"));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf24) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

//     ck_assert_int_eq(
//         s21_sprintf(str1, format, 'f', 21, 42, 666.666,
//                     "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
//         sprintf(str2, format, 'f', 21, 42, 666.666,
//                 "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf25) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%.f";

//     ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
//                      sprintf(str2, format, 121.123));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf26) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%%";

//     ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf27) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%%%%%%%%";

//     ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf28) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     int n1;
//     int n2;
//     int a = s21_sprintf(str1, "%d%n", 123, &n1);
//     int b = sprintf(str2, "%d%n", 123, &n2);

//     ck_assert_int_eq(a, b);
//     ck_assert_int_eq(n1, n2);
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf29) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%-.f";

//     ck_assert_int_eq(s21_sprintf(str1, format, 111.111),
//                      sprintf(str2, format, 111.111));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf30) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%-.1d";

//     ck_assert_int_eq(s21_sprintf(str1, format, 111),
//                      sprintf(str2, format, 111));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf31) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%e";
//     double x = 111;
//     ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf32) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%e%e%e%e";

//     ck_assert_int_eq(
//         s21_sprintf(str1, format, 11.111, 222.2222, 666., -555.125),
//         sprintf(str2, format, 11.111, 222.2222, 666., -555.125));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf33) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%Le";
//     long double x = 122.1231;

//     ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf35) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%.10e";

//     ck_assert_int_eq(s21_sprintf(str1, format, 111.184314818),
//                      sprintf(str2, format, 111.184314818));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf36) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%5.3e%3.2e%lf";

//     ck_assert_int_eq(s21_sprintf(str1, format, 0.000111, 111.555, 1.999),
//                      sprintf(str2, format, 0.000111, 111.555, 1.999));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf37) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%E";

//     ck_assert_int_eq(s21_sprintf(str1, format, 0.666666),
//                      sprintf(str2, format, 0.666666));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf38) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%E%E%E";

//     ck_assert_int_eq(s21_sprintf(str1, format, 0.0000999, 111.9999, 6.666),
//                      sprintf(str2, format, 0.0000999, 111.9999, 6.666));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf39) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%e ABOBA %Lf %Lf %Le";
//     long double c = 848181;
//     long double a = 0.00000001;
//     long double b = 1111111.11;
//     ck_assert_int_eq(s21_sprintf(str1, format, 123.123, a, b, c),
//                      sprintf(str2, format, 123.123, a, b, c));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf40) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%#e Floppa %#E%#f";

//     ck_assert_int_eq(s21_sprintf(str1, format, 123.111, 0.0000999, 0.555),
//                      sprintf(str2, format, 123.111, 0.0000999, 0.555));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf41) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%.Lf";
//     long double a = 7.9418438184;

//     ck_assert_int_eq(s21_sprintf(str1, format, a), sprintf(str2, format, a));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf42) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%#5p";
//     int a = 5;
//     ck_assert_int_eq(s21_sprintf(str1, format, &a), sprintf(str2, format,
&a));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf43) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%.5o";

//     ck_assert_int_eq(s21_sprintf(str1, format, 12345),
//                      sprintf(str2, format, 12345));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(wide_char) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "This is a simple wide char %lc";
//     unsigned long w = L'汉';
//     int a = s21_sprintf(str1, format, w);
//     int b = sprintf(str2, format, w);
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(a, b);
// }

// START_TEST(width_char) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "This is a simple wide char %5c";
//     char w = 'c';
//     int a = s21_sprintf(str1, format, w);
//     int b = sprintf(str2, format, w);
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(a, b);
// }
// START_TEST(minus_wide_char) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "This is a simple wide char %-5lc";
//     unsigned long w = L'森';
//     int a = s21_sprintf(str1, format, w);
//     int b = sprintf(str2, format, w);
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(a, b);
// }
// END_TEST
// START_TEST(wide_string) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "This is a simple wide char %ls";
//     wchar_t w[] = L"森我爱菠萝";
//     int a = s21_sprintf(str1, format, w);
//     int b = sprintf(str2, format, w);
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(a, b);
// }
// END_TEST

// START_TEST(wide_string1) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "This is a simple wide char %5.12ls";
//     wchar_t w[] = L"森我爱菠萝";
//     int a = s21_sprintf(str1, format, w);
//     int b = sprintf(str2, format, w);
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(a, b);
// }
// END_TEST

// START_TEST(wide_string2) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "This is a simple wide char %120ls ABOBA";
//     wchar_t w[] = L"森我爱菠萝";
//     int a = s21_sprintf(str1, format, w);
//     int b = sprintf(str2, format, w);
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(a, b);
// }
// END_TEST
// START_TEST(wide_string3) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "This is a simple wide char %-43ls";
//     wchar_t w[] = L"森我爱菠萝";
//     int a = s21_sprintf(str1, format, w);
//     int b = sprintf(str2, format, w);
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(a, b);
// }
// END_TEST
// START_TEST(wide_string4) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "This is a simple wide char %43ls";
//     wchar_t w[] = L"森我爱菠萝";
//     int a = s21_sprintf(str1, format, w);
//     int b = sprintf(str2, format, w);
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(a, b);
// }
// END_TEST
// START_TEST(wide_char2) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "This is a simple wide char %43lc";
//     unsigned long w = L'森';
//     int a = s21_sprintf(str1, format, w);
//     int b = sprintf(str2, format, w);
//     ck_assert_int_eq(a, b);
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
*/

Suite *suite_sprintf(void) {
  Suite *s = suite_create("suite_sprintf");
  TCase *tc = tcase_create("sprintf_tc");
  tcase_add_test(tc, simple_int);
  tcase_add_test(tc, precise_int);
  tcase_add_test(tc, width_int);
  tcase_add_test(tc, plus_width_int);
  tcase_add_test(tc, padding_int);
  tcase_add_test(tc, flags_long_int);
  tcase_add_test(tc, flags_short_int);
  tcase_add_test(tc, flags_another_long_int);
  tcase_add_test(tc, zero_precision_zero_int);
  tcase_add_test(tc, space_flag_int);
  tcase_add_test(tc, unsigned_val);
  tcase_add_test(tc, unsigned_val_width);
  tcase_add_test(tc, unsigned_val_flags);
  tcase_add_test(tc, unsigned_val_precision);
  tcase_add_test(tc, unsigned_val_many_flags);
  tcase_add_test(tc, unsigned_val_short);
  tcase_add_test(tc, unsigned_val_long);
  tcase_add_test(tc, unsigned_val_many);
  tcase_add_test(tc, unsigned_zero);
  tcase_add_test(tc, one_char);
  tcase_add_test(tc, one_precision);
  tcase_add_test(tc, one_flags);
  tcase_add_test(tc, one_width);
  tcase_add_test(tc, one_many);
  tcase_add_test(tc, one_many_flags);
  tcase_add_test(tc, string);
  tcase_add_test(tc, string_precision);
  tcase_add_test(tc, string_width);
  tcase_add_test(tc, string_flags);
  tcase_add_test(tc, string_long);
  tcase_add_test(tc, string_many);
  tcase_add_test(tc, string_width_huge);
  // tcase_add_test(tc, float_precision);
  // tcase_add_test(tc, float_width);
  // tcase_add_test(tc, float_precision_zero);
  // tcase_add_test(tc, float_precision_empty);
  // tcase_add_test(tc, float_precision_huge);
  // tcase_add_test(tc, float_precision_huge_negative);
  // tcase_add_test(tc, float_huge);
  // tcase_add_test(tc, float_flags);
  // tcase_add_test(tc, float_many);
  tcase_add_test(tc, all_empty);
  tcase_add_test(tc, empty_format_and_parameters);
  tcase_add_test(tc, test_one_char);
  tcase_add_test(tc, test_many_char);
  tcase_add_test(tc, test_one_string);
  tcase_add_test(tc, test_many_string);
  tcase_add_test(tc, test_one_dec);
  // tcase_add_test(tc, test_many_dec);
  tcase_add_test(tc, test_one_float);
  // tcase_add_test(tc, test_many_float);
  tcase_add_test(tc, test_one_unsigned_dec);
  // tcase_add_test(tc, test_many_unsigned_dec);
  tcase_add_test(tc, test_one_char_with_aldgnment_left);
  tcase_add_test(tc, test_one_char_with_aldgnment_right);
  // tcase_add_test(tc, test_many_char_with_aldgnment);
  tcase_add_test(tc, test_sprintf1);
  tcase_add_test(tc, test_sprintf2);
  tcase_add_test(tc, test_sprintf3);
  tcase_add_test(tc, test_sprintf4);
  tcase_add_test(tc, test_sprintf6);
  tcase_add_test(tc, test_sprintf7);
  tcase_add_test(tc, test_sprintf8);
  tcase_add_test(tc, test_sprintf9);
  tcase_add_test(tc, test_sprintf10);
  // tcase_add_test(tc, test_sprintf11);
  // tcase_add_test(tc, test_sprintf12);
  // tcase_add_test(tc, test_sprintf14);
  // tcase_add_test(tc, test_sprintf15);
  // tcase_add_test(tc, test_sprintf16);
  // tcase_add_test(tc, test_sprintf17);
  // tcase_add_test(tc, test_sprintf18);
  // tcase_add_test(tc, test_sprintf19);
  // tcase_add_test(tc, test_sprintf20);
  // tcase_add_test(tc, test_sprintf24);
  // tcase_add_test(tc, test_sprintf25);
  // tcase_add_test(tc, test_sprintf28);
  // tcase_add_test(tc, test_sprintf29);
  // tcase_add_test(tc, test_sprintf30);
  // tcase_add_test(tc, test_sprintf31);
  // tcase_add_test(tc, test_sprintf32);
  // tcase_add_test(tc, test_sprintf33);
  // tcase_add_test(tc, test_sprintf35);
  // tcase_add_test(tc, test_sprintf36);
  // tcase_add_test(tc, test_sprintf37);
  // tcase_add_test(tc, test_sprintf38);
  // tcase_add_test(tc, test_sprintf39);
  // tcase_add_test(tc, test_sprintf40);
  // tcase_add_test(tc, test_sprintf41);
  // tcase_add_test(tc, test_sprintf42);
  // tcase_add_test(tc, test_sprintf43);
  // tcase_add_test(tc, test_sprintf26);
  // tcase_add_test(tc, test_sprintf27);
  // tcase_add_test(tc, wide_char);
  // tcase_add_test(tc, width_char);
  // tcase_add_test(tc, minus_wide_char);
  // tcase_add_test(tc, wide_string);
  // tcase_add_test(tc, wide_string1);
  // tcase_add_test(tc, wide_string2);
  // tcase_add_test(tc, wide_string3);
  // tcase_add_test(tc, wide_string4);
  // tcase_add_test(tc, wide_char2);
  suite_add_tcase(s, tc);
  return s;
}
