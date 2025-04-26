#ifndef PRINTER_H
#define PRINTER_H
#include "string.h"

typedef struct PrinterMethods {
    struct Printer * (*new_Printer)();

    void (*free_Printer)(struct Printer *);

    void (*print_char)(struct Printer *, char);

    void (*print_string)(struct Printer *, const String *);

    void (*print_int)(struct Printer *, int);

    void (*print_long)(struct Printer *, long long);

    void (*print_double)(struct Printer *, double);

    void (*println)(struct Printer *);

    void (*println_char)(struct Printer *, char);

    void (*println_string)(struct Printer *, const String *);

    void (*println_int)(struct Printer *, int);

    void (*println_long)(struct Printer *, long long);

    void (*println_double)(struct Printer *, double);
} PrinterMethods;

typedef struct Printer {
    char *buffer;
    int BUFFER_SIZE, pos;
    PrinterMethods *methods;
} Printer;

Printer *new_Printer();

void free_Printer(Printer *out);

void print_char(Printer *out, char c);

void print_string(Printer *out, const String *str);

void print_int(Printer *out, int n);

void print_long(Printer *out, long long n);

void print_double(Printer *out, double n);

void println(Printer *out);

void println_char(Printer *out, char c);

void println_string(Printer *out, const String *str);

void println_int(Printer *out, int n);

void println_long(Printer *out, long long n);

void println_double(Printer *out, double n);
#endif
