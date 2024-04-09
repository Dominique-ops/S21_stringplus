#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <wchar.h>

#define s21_NULL (void *)0

typedef unsigned long s21_size_t;

typedef struct {
  int minus;
  int plus;
  int space;
  int width;
  int precision_set;
  int precision;
  int zero;
  int h;
  int l;
  char specifier;
} elements;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memcpy(void *dest, const void *src, size_t n);
void *s21_memset(void *str, int c, size_t n);
s21_size_t s21_strlen(const char *str);
char *s21_strncat(char *dest, const char *src, size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strncpy(char *dest, const char *src, size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
char *s21_strerror(int errnum);
void s21_support_error(int val, char *str_res);
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

char *s21_parser(char *format_str, elements *els);
int s21_sprintf(char *str, char *format_str, ...);

#endif