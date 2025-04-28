#ifndef PRINTER_H
#define PRINTER_H
#include "string.h"

typedef struct Printer {
    char *buffer;
    int buffer_size, pos;

    void (*free_Printer)(struct Printer *);

    void (*flush)(struct Printer *);

    void (*print_char)(struct Printer *, char);

    void (*print_string)(struct Printer *, const String *);

    void (*print_chars)(struct Printer *, const char *);

    void (*print_int)(struct Printer *, int);

    void (*print_long)(struct Printer *, long long);

    void (*print_double)(struct Printer *, double, int);

    void (*print_boolean)(struct Printer *, int);

    void (*println)(struct Printer *);

    void (*println_char)(struct Printer *, char);

    void (*println_string)(struct Printer *, const String *);

    void (*println_chars)(struct Printer *, const char *);

    void (*println_int)(struct Printer *, int);

    void (*println_long)(struct Printer *, long long);

    void (*println_double)(struct Printer *, double, int);

    void (*println_boolean)(struct Printer *, int);
} Printer;

Printer *new_Printer();

void free_Printer(Printer *out);

void print_char(Printer *out, char c);

void print_string(Printer *out, const String *str);

void print_chars(Printer *out, const char *str);

void print_int(Printer *out, int n);

void print_long(Printer *out, long long n);

void print_double(Printer *out, double n, int scale);

void print_boolean(Printer *out, int b);

void println(Printer *out);

void println_char(Printer *out, char c);

void println_string(Printer *out, const String *str);

void println_chars(Printer *out, const char *str);

void println_int(Printer *out, int n);

void println_long(Printer *out, long long n);

void println_double(Printer *out, double n, int scale);

void println_boolean(Printer *out, int b);

void flush(Printer *out);
#endif
