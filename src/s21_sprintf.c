#include <stdio.h>

#include "s21_string.h"

// для char ширина и флаги '-' и ' ' работают так же, как и для целых чисел,
// флаг + игнорируется ширина работает так же точность игнорируется длина как-то
// по-своему работает если типы разные, просто приводим типы

char *s21_float_to_str(elements p, long double num, char *res) {
  long double in = 0;
  long double frac = modfl(num, &in);
  int prec = p.precision;
  if (prec == 0) {
    prec = 6;
  }
  int save_prec = prec;
  if (frac + 0.000000000000001 >= 1) {
    frac = 0;
    in += 1;
  }
  for (int i = 0; i < 15; i++) {
    frac *= 10;
    if ((long)frac != 0) break;
  }
  // if(!prec && frac * 10 > 4) in += 1;
  frac = frac < 0 ? -frac : frac;
  while (prec > 1) {
    frac *= 10;
    prec--;
  }
  // if(fmodl(fabsl(frac) * 10, 10.0) > 4) frac = roundl(frac);
  /* надо сделать строку из frac и in*/
  char in_str[512] = {'\0'};
  char frac_str[512] = {'\0'};
  s21_int_to_str(in, in_str);
  if (frac == 0) {
    for (int i = 0; i < save_prec; i++) {
      frac_str[i] = '0';
    }
  } else {
    s21_int_to_str(frac, frac_str);
  }
  s21_strncpy(res, in_str, 512);
  if (p.precision != 0 || !(p.precision_set)) {
    s21_strncat(res, ".", 1);
  }
  if (!(p.precision_set && p.precision == 0 && (num == 0 || frac != 0)) &&
      !(p.precision_set && p.precision == 0 && (num != 0 || frac == 0))) {
    s21_strncat(res, frac_str, 512);
  }
  return res;
  /* надо обработать флаги */
}

char *s21_handle_float(long double num, elements els) {
  char strnum[512] = {'\0'};
  char *res = NULL;
  s21_strncpy(strnum, s21_float_to_str(els, num, strnum), 512);
  if ((strnum[0] != '-' && (els.plus || els.space))) {
    s21_strncpy(strnum, s21_plus_space(els, strnum), 512);
  }
  if (els.width > (int)s21_strlen(strnum)) {
    s21_strncpy(strnum, s21_width(els, strnum), 512);
  }
  res = strnum;
  return res;
}

char *s21_get_flags(char *format_str, elements *els, int *exit_code) {
  *exit_code = 0;
  switch (*format_str) {
    case '-':
      els->minus = 1;
      format_str++;
      break;
    case '+':
      els->plus = 1;
      format_str++;
      break;
    case ' ':
      els->space = 1;
      format_str++;
      break;
    default:
      break;
  }

  return format_str;
}

char *s21_get_width(char *format_str, elements *els, int *exit_code) {
  *exit_code = 0;
  if (*format_str != '*') {
    char number[512];
    int i = 0;
    while (isdigit(*format_str)) {
      number[i++] = *format_str++;
    }
    els->width = atoi(number);
  }
  return format_str;
}

char *s21_get_precision(char *format_str, elements *els, int *exit_code) {
  // для спецификатора %s точность определяет, сколько символов запишется. Если
  // написать длину, то строка выводиться не будет
  *exit_code = 0;
  if (*format_str == '.') {
    els->precision_set = 1;
    format_str++;
    if (*format_str != '*') {
      char number[512] = {'0'};
      int i = 0;
      while (isdigit(*format_str)) {
        number[i++] = *format_str++;
      }
      els->precision = atoi(number);
    }
  }
  return format_str;
}

char *s21_get_length(char *format_str, elements *els, int *exit_code) {
  *exit_code = 0;
  switch (*format_str) {
    case 'h':
      els->h = 1;
      format_str++;
      break;
    case 'l':
      els->l = 1;
      format_str++;
      break;
    default:
      break;
  }
  return format_str;
}

char *s21_parser(char *format_str, elements *els) {
  int exit_code = 0;
  format_str++;
  while (*format_str == '-' || *format_str == '+' || *format_str == ' ') {
    format_str = s21_get_flags(format_str, els, &exit_code);
  }
  format_str = s21_get_width(format_str, els, &exit_code);
  format_str = s21_get_precision(format_str, els, &exit_code);
  format_str = s21_get_length(format_str, els, &exit_code);
  els->specifier = *format_str;
  if (els->specifier != 'd' && els->specifier != 'u' && els->specifier != 'f' &&
      els->specifier != 'c' && els->specifier != '%' && els->specifier != 's') {
    exit_code = 1;
  }
  return format_str;
}

void s21_unsigned_to_str(unsigned long val, char *str_res) {
  char str_num_reversed[512] = {'\0'};
  char buff[512] = {'\0'};
  if (val == 0) {
    buff[0] = '0';
  } else {
    int i = 0, len_num = 0;
    for (; val > 0; val /= 10, i++) {
      str_num_reversed[i] = val % 10 + '0';
      len_num++;
    }
    for (int i = len_num - 1, j = 0; i >= 0; i--, j++) {
      buff[j] = str_num_reversed[i];
    }
  }
  s21_strncpy(str_res, buff, s21_strlen(buff));
}

void s21_int_to_str(long val, char *str_res) {
  char str_num_reversed[512] = {'\0'};
  char buff[512] = {'\0'};
  int i = 0, j = 0, len_num = 0;
  if (val < 0) {
    buff[0] = '-';
    j++;
  } else if (val == 0) {
    buff[0] = '0';
  }
  for (; val; val /= 10, i++) {  // при val = 0 не зайдёт ни в один цикл
    len_num++;                   //
    str_num_reversed[i] = '0' + val % 10;
  }                                          //
  for (i = len_num - 1; i >= 0; j++, i--) {  //
    buff[j] = str_num_reversed[i];           //
  }                                          //
  s21_strncpy(str_res, buff, s21_strlen(buff));
}

char *s21_precision_unsigned(
    elements els, char *strnum) {  // вроде работает, но если точность равна 0 и
                                   // число равно 0, то strncpy
  char res[512] = {'\0'};
  if (els.precision == 0 && s21_strncmp(strnum, "0", 512) == 0) {
    res[0] = (strnum[0] == '0' ? '\0' : res[0]);
  } else {
    int num_len = s21_strlen(strnum);
    int diff = els.precision - num_len;
    int i = 0;
    for (; i < diff; i++) {
      res[i] = '0';
    }
    s21_strncat(res, strnum, s21_strlen(strnum));
  }
  strnum = res;
  return strnum;
}

char *s21_precision_int(elements els,
                        char *strnum) {  // так же strncpy не скопирует пустую
                                         // строку, но вроде робит
  char res[512] = {'\0'};
  int num_len;
  if (els.precision == 0 && s21_strncmp(strnum, "0", 512) == 0) {
    res[0] = (strnum[0] == '0' ? '\0' : res[0]);
  } else {
    if (strnum[0] == '-') {
      num_len = s21_strlen(strnum) - 1;
      res[0] = '-';
      strnum++;
    } else {
      num_len = s21_strlen(strnum);
    }
    int diff = els.precision - num_len;
    int i = 0;
    if (res[0] == '-') {
      i = 1;
      diff++;
    }
    for (; i < diff; i++) {
      res[i] = '0';
    }
    s21_strncat(res, strnum, s21_strlen(strnum));
  }
  strnum = res;
  return strnum;
}

char *s21_width(elements els, char *strnum) {  // для всех спецификаторов
  char spaces[512] = {'\0'};
  char res[512] = {'\0'};
  int num_len = s21_strlen(strnum);
  if (num_len >= 0) {
    int diff = els.width - num_len;
    int i = 0;
    for (; i < diff; i++) {
      spaces[i] = ' ';
    }
    if (els.minus) {
      s21_strncpy(res, strnum, 512);
      s21_strncat(res, spaces, s21_strlen(spaces));
    } else {
      s21_strncpy(res, spaces, 512);
      s21_strncat(res, strnum, s21_strlen(strnum));
    }
  }
  strnum = res;
  return strnum;
}

char *s21_plus_space(elements els,
                     char *strnum) {  // будет вызываться только, если число
                                      // положительное и flag = '+' или space
  char buff[512] = {
      '\0'};  // поэтому проверки на отрицательность будут перед вызовом этой
              // функции будет вызываться до форматирования по ширине, где-то
              // вначале, после точности,
  if (els.plus) {  // длины и непосредственной работы с числом
    buff[0] = '+';  // проверка на ноль при точности = 0 тоже должна быть перед
                    // вызовом этой функции
  } else if (els.space) {
    buff[0] = ' ';
  }
  s21_strncat(buff, strnum, s21_strlen(strnum));
  strnum = buff;
  return strnum;
}

char *s21_space_unsigned(
    elements els,
    char *strnum) {  // для unsigned int, оказывается, флаг '+' игнорируется
  char buff[512] = {
      '\0'};  // а при выравнивании слева и флаге space пробела слева нет
  if (els.space && els.minus == 0) {
    buff[0] = ' ';
  }
  s21_strncat(buff, strnum, s21_strlen(strnum));
  strnum = buff;
  return strnum;
}

char *s21_handle_int(long num, elements els) {
  if (els.h) {
    num = (short int)num;
  } else if (els.l == 0 && els.h == 0) {
    num = (int)num;
  }
  char strnum[512] = {'\0'};
  char *res = NULL;
  s21_int_to_str(num, strnum);
  if (els.precision_set) {
    s21_strncpy(strnum, s21_precision_int(els, strnum), 512);
  }
  if ((strnum[0] != '-' && (els.plus || els.space))) {
    s21_strncpy(strnum, s21_plus_space(els, strnum), 512);
  }
  if (els.width > (int)s21_strlen(strnum)) {
    s21_strncpy(strnum, s21_width(els, strnum), 512);
  }
  res = strnum;
  return res;
}

char *s21_handle_unsigned(unsigned long int num, elements els) {
  if (els.h) {
    num = (short unsigned int)num;
  } else if (els.l == 0 && els.h == 0) {
    num = (unsigned int)num;
  }
  char strnum[512] = {'\0'};
  char *res = NULL;
  s21_unsigned_to_str(num, strnum);
  if (els.precision_set) {
    s21_strncpy(strnum, s21_precision_unsigned(els, strnum), 512);
  }
  // if ((strnum[0] != '-' && (els.plus || els.space))) {
  //   s21_strncpy(strnum, s21_space_unsigned(els, strnum), 512);
  // }
  if (els.width > (int)s21_strlen(strnum)) {
    s21_strncpy(strnum, s21_width(els, strnum), 512);
  }
  res = strnum;
  return res;
}

char *s21_handle_char(char ch, elements els) {
  char str[512] = {'\0'};
  char strch[2] = {ch, '\0'};
  char *res = NULL;
  if (els.width > 1 && ch != '%') {
    s21_strncpy(str, s21_width(els, strch), 512);
    res = str;
  } else {
    res = strch;
  }
  return res;
}

void prec_string(char *str_res, elements *els) {
  if (els->precision_set == 0) {
    return;
  }
  int len = (int)s21_strlen(str_res);
  if (len > els->precision) {
    str_res[els->precision] = '\0';
  }
}

char *s21_handle_char_w(wchar_t ch, elements els) {
  char str[512] = {'\0'};
  char strch[512] = {'\0'};
  wcstombs(strch, &ch, 512);
  char *res = NULL;
  if (els.width > 1 && *strch != '%') {
    s21_strncpy(str, s21_width(els, strch), 512);
    res = str;
  } else {
    res = strch;
  }
  return res;
}

void spec(char *format_str, elements *els, va_list val, char **res,
          int *counter) {
  char str[512] = {'\0'};
  char *tmp;
  switch (*format_str) {
    case 'd':
      s21_strncpy(str, s21_handle_int(va_arg(val, long), *els), 512);
      break;
    case 's':
      if (els->l == 0) {
        tmp = va_arg(val, char *);
        s21_strncpy(str, tmp, s21_strlen(tmp));
        prec_string(str, els);
      } else {
        wchar_t *tmp_s = va_arg(val, wchar_t *);
        wcstombs(str, tmp_s, 512);
        prec_string(str, els);
      }
      if (els->precision_set && els->precision < (int)s21_strlen(str)) {
        str[els->precision] = '\0';
      }
      if (els->width > 0) {
        s21_strncpy(str, s21_width(*els, str), 512);
      }
      break;
    case 'u':
      s21_strncpy(
          str, s21_handle_unsigned(va_arg(val, unsigned long int), *els), 512);
      break;
    case 'c':
      if (els->l == 1) {
        s21_strncpy(str, s21_handle_char_w(va_arg(val, wchar_t), *els), 100);
      } else {
        s21_strncpy(str, s21_handle_char(va_arg(val, int), *els), 100);
      }
      break;
    case '%':
      s21_strncpy(str, s21_handle_char('%', *els), 512);
      break;
    case 'f':
      s21_strncpy(str, s21_handle_float(va_arg(val, double), *els), 512);
    default:
      break;
  }
  s21_strncat(*res, str, s21_strlen(str));
  *res += s21_strlen(str);
  *counter += s21_strlen(str);
}

int s21_sprintf(char *str, char *format_str, ...) {
  va_list val;
  elements els = {0};
  char buff[512] = {'\0'};
  char *res = buff;
  va_start(val, format_str);
  int len = (int)s21_strlen(format_str);
  int counter = 0;
  for (int i = 0; i < len; i++) {
    if (*format_str == '%') {
      format_str = s21_parser(format_str, &els);
      spec(format_str, &els, val, &res, &counter);
      format_str++;
      continue;
    }
    counter++;
    *res++ = *format_str++;
  }
  va_end(val);
  res = buff;
  counter = s21_strlen(buff);
  s21_strncpy(str, res, 512);
  return counter;
}
