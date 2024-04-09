#include <stdio.h>

#include "s21_string.h"

#ifdef __APPLE__
#define MAX_ERR 107
#define ERROR "Unknown error: "
#define ARRAY                                                                 \
  char errlist[107][70] = {"Undefined error: 0",                              \
                           "Operation not permitted",                         \
                           "No such file or directory",                       \
                           "No such process",                                 \
                           "Interrupted system call",                         \
                           "Input/output error",                              \
                           "Device not configured",                           \
                           "Argument list too long",                          \
                           "Exec format error",                               \
                           "Bad file descriptor",                             \
                           "No child processes",                              \
                           "Resource deadlock avoided",                       \
                           "Cannot allocate memory",                          \
                           "Permission denied",                               \
                           "Bad address",                                     \
                           "Block device required",                           \
                           "Resource busy",                                   \
                           "File exists",                                     \
                           "Cross-device link",                               \
                           "Operation not supported by device",               \
                           "Not a directory",                                 \
                           "Is a directory",                                  \
                           "Invalid argument",                                \
                           "Too many open files in system",                   \
                           "Too many open files",                             \
                           "Inappropriate ioctl for device",                  \
                           "Text file busy",                                  \
                           "File too large",                                  \
                           "No space left on device",                         \
                           "Illegal seek",                                    \
                           "Read-only file system",                           \
                           "Too many links",                                  \
                           "Broken pipe",                                     \
                           "Numerical argument out of domain",                \
                           "Result too large",                                \
                           "Resource temporarily unavailable",                \
                           "Operation now in progress",                       \
                           "Operation already in progress",                   \
                           "Socket operation on non-socket",                  \
                           "Destination address required",                    \
                           "Message too long",                                \
                           "Protocol wrong type for socket",                  \
                           "Protocol not available",                          \
                           "Protocol not supported",                          \
                           "Socket type not supported",                       \
                           "Operation not supported",                         \
                           "Protocol family not supported",                   \
                           "Address family not supported by protocol family", \
                           "Address already in use",                          \
                           "Can't assign requested address",                  \
                           "Network is down",                                 \
                           "Network is unreachable",                          \
                           "Network dropped connection on reset",             \
                           "Software caused connection abort",                \
                           "Connection reset by peer",                        \
                           "No buffer space available",                       \
                           "Socket is already connected",                     \
                           "Socket is not connected",                         \
                           "Can't send after socket shutdown",                \
                           "Too many references: can't splice",               \
                           "Operation timed out",                             \
                           "Connection refused",                              \
                           "Too many levels of symbolic links",               \
                           "File name too long",                              \
                           "Host is down",                                    \
                           "No route to host",                                \
                           "Directory not empty",                             \
                           "Too many processes",                              \
                           "Too many users",                                  \
                           "Disc quota exceeded",                             \
                           "Stale NFS file handle",                           \
                           "Too many levels of remote in path",               \
                           "RPC struct is bad",                               \
                           "RPC version wrong",                               \
                           "RPC prog. not avail",                             \
                           "Program version wrong",                           \
                           "Bad procedure for program",                       \
                           "No locks available",                              \
                           "Function not implemented",                        \
                           "Inappropriate file type or format",               \
                           "Authentication error",                            \
                           "Need authenticator",                              \
                           "Device power is off",                             \
                           "Device error",                                    \
                           "Value too large to be stored in data type",       \
                           "Bad executable (or shared library)",              \
                           "Bad CPU type in executable",                      \
                           "Shared library version mismatch",                 \
                           "Malformed Mach-o file",                           \
                           "Operation canceled",                              \
                           "Identifier removed",                              \
                           "No message of desired type",                      \
                           "Illegal byte sequence",                           \
                           "Attribute not found",                             \
                           "Bad message",                                     \
                           "EMULTIHOP (Reserved)",                            \
                           "No message available on STREAM",                  \
                           "ENOLINK (Reserved)",                              \
                           "No STREAM resources",                             \
                           "Not a STREAM",                                    \
                           "Protocol error",                                  \
                           "STREAM ioctl timeout",                            \
                           "Operation not supported on socket",               \
                           "Policy not found",                                \
                           "State not recoverable",                           \
                           "Previous owner died",                             \
                           "Interface output queue is full"}
#elif __linux__
#define MAX_ERR 134
#define ERROR "Unknown error "
#define ARRAY                                              \
  char errlist[134][70] = {                                \
      "Success",                                           \
      "Operation not permitted",                           \
      "No such file or directory",                         \
      "No such process",                                   \
      "Interrupted system call",                           \
      "Input/output error",                                \
      "No such device or address",                         \
      "Argument list too long",                            \
      "Exec format error",                                 \
      "Bad file descriptor",                               \
      "No child processes",                                \
      "Resource temporarily unavailable",                  \
      "Cannot allocate memory",                            \
      "Permission denied",                                 \
      "Bad address",                                       \
      "Block device required",                             \
      "Device or resource busy",                           \
      "File exists",                                       \
      "Invalid cross-device link",                         \
      "No such device",                                    \
      "Not a directory",                                   \
      "Is a directory",                                    \
      "Invalid argument",                                  \
      "Too many open files in system",                     \
      "Too many open files",                               \
      "Inappropriate ioctl for device",                    \
      "Text file busy",                                    \
      "File too large",                                    \
      "No space left on device",                           \
      "Illegal seek",                                      \
      "Read-only file system",                             \
      "Too many links",                                    \
      "Broken pipe",                                       \
      "Numerical argument out of domain",                  \
      "Numerical result out of range",                     \
      "Resource deadlock avoided",                         \
      "File name too long",                                \
      "No locks available",                                \
      "Function not implemented",                          \
      "Directory not empty",                               \
      "Too many levels of symbolic links",                 \
      "Unknown error 41",                                  \
      "No message of desired type",                        \
      "Identifier removed",                                \
      "Channel number out of range",                       \
      "Level 2 not synchronized",                          \
      "Level 3 halted",                                    \
      "Level 3 reset",                                     \
      "Link number out of range",                          \
      "Protocol driver not attached",                      \
      "No CSI structure available",                        \
      "Level 2 halted",                                    \
      "Invalid exchange",                                  \
      "Invalid request descriptor",                        \
      "Exchange full",                                     \
      "No anode",                                          \
      "Invalid request code",                              \
      "Invalid slot",                                      \
      "Unknown error 58",                                  \
      "Bad font file format",                              \
      "Device not a stream",                               \
      "No data available",                                 \
      "Timer expired",                                     \
      "Out of streams resources",                          \
      "Machine is not on the network",                     \
      "Package not installed",                             \
      "Object is remote",                                  \
      "Link has been severed",                             \
      "Advertise error",                                   \
      "Srmount error",                                     \
      "Communication error on send",                       \
      "Protocol error",                                    \
      "Multihop attempted",                                \
      "RFS specific error",                                \
      "Bad message",                                       \
      "Value too large for defined data type",             \
      "Name not unique on network",                        \
      "File descriptor in bad state",                      \
      "Remote address changed",                            \
      "Can not access a needed shared library",            \
      "Accessing a corrupted shared library",              \
      ".lib section in a.out corrupted",                   \
      "Attempting to link in too many shared libraries",   \
      "Cannot exec a shared library directly",             \
      "Invalid or incomplete multibyte or wide character", \
      "Interrupted system call should be restarted",       \
      "Streams pipe error",                                \
      "Too many users",                                    \
      "Socket operation on non-socket",                    \
      "Destination address required",                      \
      "Message too long",                                  \
      "Protocol wrong type for socket",                    \
      "Protocol not available",                            \
      "Protocol not supported",                            \
      "Socket type not supported",                         \
      "Operation not supported",                           \
      "Protocol family not supported",                     \
      "Address family not supported by protocol",          \
      "Address already in use",                            \
      "Cannot assign requested address",                   \
      "Network is down",                                   \
      "Network is unreachable",                            \
      "Network dropped connection on reset",               \
      "Software caused connection abort",                  \
      "Connection reset by peer",                          \
      "No buffer space available",                         \
      "Transport endpoint is already connected",           \
      "Transport endpoint is not connected",               \
      "Cannot send after transport endpoint shutdown",     \
      "Too many references: cannot splice",                \
      "Connection timed out",                              \
      "Connection refused",                                \
      "Host is down",                                      \
      "No route to host",                                  \
      "Operation already in progress",                     \
      "Operation now in progress",                         \
      "Stale file handle",                                 \
      "Structure needs cleaning",                          \
      "Not a XENIX named type file",                       \
      "No XENIX semaphores available",                     \
      "Is a named type file",                              \
      "Remote I/O error",                                  \
      "Disk quota exceeded",                               \
      "No medium found",                                   \
      "Wrong medium type",                                 \
      "Operation canceled",                                \
      "Required key not available",                        \
      "Key has expired",                                   \
      "Key has been revoked",                              \
      "Key was rejected by service",                       \
      "Owner died",                                        \
      "State not recoverable",                             \
      "Operation not possible due to RF-kill",             \
      "Memory page has hardware error"}
#endif

char* s21_strerror(int errnum) {
  static char res[100] = {'\0'};
  ARRAY;
  int flag = 1;
  for (int i = 0; i < MAX_ERR; i++) {
    if (errnum == i) {
      s21_strncpy(res, errlist[i], 100);
      flag = 0;
    }
  }
  if (flag == 1) {
    char str[100] = ERROR;
    char tmp[100] = {'\0'};
    char errnum_str[100] = {'\0'};
    s21_support_error(errnum, errnum_str);
    s21_strncat(tmp, str, 100);
    s21_strncat(tmp, errnum_str, 100);
    s21_strncpy(res, tmp, 100);
  }
  return res;
}

void s21_support_error(int val, char* str_res) {
  char str_num_reversed[512] = {'\0'};
  char buff[512] = {'\0'};
  int i = 0, j = 0, len_num = 0;
  if (val < 0) {
    buff[0] = '-';
    j++;
  } else if (val == 0) {
    buff[0] = '0';
  }

  for (; abs(val) > 0; val /= 10, i++) {
    len_num++;
    str_num_reversed[i] = '0' + abs(val) % 10;
  }
  for (i = len_num - 1; i >= 0; j++, i--) {
    buff[j] = str_num_reversed[i];
  }
  s21_strncpy(str_res, buff, s21_strlen(buff));
}