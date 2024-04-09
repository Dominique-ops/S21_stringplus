#define BUFF_SIZE 512

#include "test.h"

START_TEST(simple_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(precise_int) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%.5d";
//     int val = 69;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(width_int) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%5d";
//     int val = 69;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(plus_width_int) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%+12d";
//     int val = 69;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(padding_int) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%012i";
//     int val = 69;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(star_width_int) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%0*d";
//     int val = 69;
//     ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
//                      sprintf(str2, format, 5, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(flags_long_int) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%+5.31ld";
//     long int val = 698518581899;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(flags_short_int) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%-16.9hi";
//     short int val = 6958;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(flags_another_long_int) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%0.ld";
//     long val = 8581385185;
//     ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
//                      sprintf(str2, format, 5, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(zero_precision_zero_int) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%.0d";
//     int val = 0;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(space_flag_int) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "% d";
//     int val = 0;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(unsigned_val) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%u";
//     unsigned int val = 14140;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(unsigned_val_width) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%15u";
//     unsigned int val = 14140;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(unsigned_val_flags) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%-16u";
//     unsigned int val = 14140;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(unsigned_val_precision) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%.51u";
//     unsigned int val = 14140;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(unsigned_val_many_flags) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "% 5.51u";
//     unsigned int val = 14140;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(unsigned_val_short) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%hu";
//     unsigned short int val = 14140;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(unsigned_val_long) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%lu";
//     unsigned long int val = 949149114140;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(unsigned_val_many) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%lu, %u, %hu, %.5u, %5.u";
//     unsigned long int val = 949149114140;
//     ck_assert_int_eq(s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
//                      sprintf(str2, format, val, (unsigned)14,
//                              (unsigned short)1441, (unsigned)14414,
//                              (unsigned)9681));

//     ck_assert_str_eq(str1, str2);
// }
// START_TEST(unsigned_zero) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%u";
//     ck_assert_int_eq(s21_sprintf(str1, format, 0),
//                      sprintf(str2, format, (unsigned)0));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(one_char) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%c";
//     char val = 'X';
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(one_precision) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%.5c";
//     char val = 'c';
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(one_flags) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "% -5c";
//     char val = 'c';
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(one_width) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%15c";
//     char val = 'c';
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(one_many) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
//     char val = 'c';
//     ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
//                      sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(one_many_flags) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%-5.3c";
//     char val = 'c';
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(string) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%s";
//     char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(string_precision) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%.15s";
//     char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(string_width) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%15s";
//     char *val = "69 IS MY FAVORITE NUMBER";
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(string_flags) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%-15.9s";
//     char *val = "69 IS MY FAVORITE NUMBER";
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(string_long) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%s";
//     char *val =
//         "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(string_many) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%s%s%s%s";
//     char *val =
//         "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
//     char *s1 = "";
//     char *s2 = "87418347813748913749871389480913";
//     char *s3 = "HAHAABOBASUCKER";
//     ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
//                      sprintf(str2, format, val, s1, s2, s3));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(string_width_huge) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *val = "kjafdiuhfjahfjdahf";
//     char *format = "%120s";
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// END_TEST
// START_TEST(float_precision) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%Lf";
//     long double val = 513515.131513515151351;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(float_width) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%10Lf";
//     long double val = 15.35;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(float_precision_zero) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%.0Lf";
//     long double val = 15.35;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(float_precision_empty) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%.Lf";
//     long double val = 15.35;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(float_precision_huge) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%.15Lf";
//     long double val = 15.35;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

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

// START_TEST(all_empty) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(empty_format_and_parameters) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_one_char) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c",
//     '\t'));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_many_char) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S',
//     's'),
//                      sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_one_string) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
//                      sprintf(str2, "%s", "Drop Sega PLS"));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_many_string) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(
//         s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
//         sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_one_dec) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_many_dec) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
//                      sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_one_float) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
//                      sprintf(str2, "%f", 0.0001));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_many_float) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(
//         s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
//         sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_one_unsigned_dec) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
//                      sprintf(str2, "%u", (unsigned)100));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_many_unsigned_dec) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
//                      sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
//                              (unsigned)666, (unsigned)100));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_one_char_with_aldgnment_left) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'),
//                      sprintf(str2, "%8c", '\t'));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_one_char_with_aldgnment_right) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
//                      sprintf(str2, "%-8c", '\t'));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_many_char_with_aldgnment) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(
//         s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
//         sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf1) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%10ld";

//     ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf2) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%1.1f";

//     ck_assert_int_eq(s21_sprintf(str1, format, 1.1),
//                      sprintf(str2, format, 1.1));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf3) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%8.3c";

//     ck_assert_int_eq(s21_sprintf(str1, format, 'a'),
//                      sprintf(str2, format, 'a'));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf4) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%+5.5d aboba";

//     int val = 10000;
//     int a = s21_sprintf(str1, format, val);
//     int b = sprintf(str2, format, val);
//     ck_assert_int_eq(a, b);

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf6) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%7.7f";

//     ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
//                      sprintf(str2, format, 11.123456));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf7) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%7.4s";

//     ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
//                      sprintf(str2, format, "aboba floppa"));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf8) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%6.6u";

//     ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
//                      sprintf(str2, format, 12341151));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf9) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%ld%ld%lu";

//     ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
//                      sprintf(str2, format, 666666666666, 777, 111));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf10) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%hi%hd%hu";

//     ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
//                      sprintf(str2, format, 666, -777, 111));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

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
//     &a));

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

Suite *suite_sprintf(void) {
  Suite *s = suite_create("suite_sprintf");
  TCase *tc = tcase_create("sprintf_tc");
  tcase_add_test(tc, simple_int);
  // tcase_add_test(tc, precise_int);
  // tcase_add_test(tc, width_int);
  // tcase_add_test(tc, plus_width_int);
  // tcase_add_test(tc, padding_int);
  // tcase_add_test(tc, star_width_int);
  // tcase_add_test(tc, flags_long_int);
  // tcase_add_test(tc, flags_short_int);
  // tcase_add_test(tc, flags_another_long_int);
  // tcase_add_test(tc, zero_precision_zero_int);
  // tcase_add_test(tc, space_flag_int);
  // tcase_add_test(tc, unsigned_val);
  // tcase_add_test(tc, unsigned_val_width);
  // tcase_add_test(tc, unsigned_val_flags);
  // tcase_add_test(tc, unsigned_val_precision);
  // tcase_add_test(tc, unsigned_val_many_flags);
  // tcase_add_test(tc, unsigned_val_short);
  // tcase_add_test(tc, unsigned_val_long);
  // tcase_add_test(tc, unsigned_val_many);
  // tcase_add_test(tc, unsigned_zero);
  // tcase_add_test(tc, one_char);
  // tcase_add_test(tc, one_precision);
  // tcase_add_test(tc, one_flags);
  // tcase_add_test(tc, one_width);
  // tcase_add_test(tc, one_many);
  // tcase_add_test(tc, one_many_flags);
  // tcase_add_test(tc, string);
  // tcase_add_test(tc, string_precision);
  // tcase_add_test(tc, string_width);
  // tcase_add_test(tc, string_flags);
  // tcase_add_test(tc, string_long);
  // tcase_add_test(tc, string_many);
  // tcase_add_test(tc, string_width_huge);
  // tcase_add_test(tc, float_precision);
  // tcase_add_test(tc, float_width);
  // tcase_add_test(tc, float_precision_zero);
  // tcase_add_test(tc, float_precision_empty);
  // tcase_add_test(tc, float_precision_huge);
  // tcase_add_test(tc, float_precision_huge_negative);
  // tcase_add_test(tc, float_huge);
  // tcase_add_test(tc, float_flags);
  // tcase_add_test(tc, float_many);
  // tcase_add_test(tc, all_empty);
  // tcase_add_test(tc, empty_format_and_parameters);
  // tcase_add_test(tc, test_one_char);
  // tcase_add_test(tc, test_many_char);
  // tcase_add_test(tc, test_one_string);
  // tcase_add_test(tc, test_many_string);
  // tcase_add_test(tc, test_one_dec);
  // tcase_add_test(tc, test_many_dec);
  // tcase_add_test(tc, test_one_float);
  // tcase_add_test(tc, test_many_float);
  // tcase_add_test(tc, test_one_unsigned_dec);
  // tcase_add_test(tc, test_many_unsigned_dec);
  // tcase_add_test(tc, test_one_char_with_aldgnment_left);
  // tcase_add_test(tc, test_one_char_with_aldgnment_right);
  // tcase_add_test(tc, test_many_char_with_aldgnment);
  // tcase_add_test(tc, test_sprintf1);
  // tcase_add_test(tc, test_sprintf2);
  // tcase_add_test(tc, test_sprintf3);
  // tcase_add_test(tc, test_sprintf4);
  // tcase_add_test(tc, test_sprintf6);
  // tcase_add_test(tc, test_sprintf7);
  // tcase_add_test(tc, test_sprintf8);
  // tcase_add_test(tc, test_sprintf9);
  // tcase_add_test(tc, test_sprintf10);
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
