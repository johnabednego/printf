#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
char fmt;
int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handling_printing(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int char_print(va_list types, char buffer[],
int flags, int width, int precision, int size);
int string_print(va_list types, char buffer[],
int flags, int width, int precision, int size);
int percent_print(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Functions to print numbers */
int int_print(va_list types, char buffer[],
int flags, int width, int precision, int size);
int binary_print(va_list types, char buffer[],
int flags, int width, int precision, int size);
int unsigned_print(va_list types, char buffer[],
int flags, int width, int precision, int size);
int octal_print(va_list types, char buffer[],
int flags, int width, int precision, int size);
int hexadecimal_print(va_list types, char buffer[],
int flags, int width, int precision, int size);
int hexa_upper_print(va_list types, char buffer[],
int flags, int width, int precision, int size);

int hexa_print(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int non_printable_print(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Funcion to print memory address */
int pointer_print(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int getting_flags(const char *format, int *i);
int getting_width(const char *format, int *i, va_list list);
int getting_precision(const char *format, int *i, va_list list);
int getting_size(const char *format, int *i);

/*Function to print string in reverse*/
int reverse_print(va_list types, char buffer[],
int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int rot13string_print(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
