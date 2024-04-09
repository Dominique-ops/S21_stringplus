#ifndef S21_SPRINTF
#define S21_SPRINTF

#include <check.h>
#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <wchar.h>

#include "s21_string.h"

typedef struct {
  int minus;
  int plus;
  int space;
  int width;
  int precision_set;
  int precision;
  int h;
  int l;
  char specifier;
} elements;

char *s21_get_flags(char *format, elements *els, int *exit_code);
char *s21_get_width(char *format_str, elements *els, int *exit_code);
char *s21_get_precision(char *format_str, elements *els, int *exit_code);
char *s21_get_length(char *format_str, elements *els, int *exit_code);
void s21_int_to_str(long val, char *str);
void s21_unsigned_to_str(unsigned long val, char *str_res);
char *s21_precision_unsigned(elements els, char *strnum);
char *s21_precision_int(elements els, char *number);
char *s21_width(elements els, char *strnum);
char *s21_plus_space(elements els, char *strnum);
char *s21_handle_int(long num, elements els);
char *s21_handle_unsigned(unsigned long int num, elements els);
char *s21_handle_char(char ch, elements els);
int s21_sprintf(char *str, char *format_str, ...);
void prec_string(char *str_res, elements *els);
char *s21_handle_float(long double num, elements els);
char *s21_handle_char_w(wchar_t ch, elements els);
void spec(char *format_str, elements *els, va_list val, char **res,
          int *counter);
char *s21_parser(char *format_str, elements *els);
int s21_sprintf(char *str, char *format_str, ...);

#endif
