#ifndef PRINTER_H
#define PRINTER_H
#include "../String/string.h"

typedef struct Printer {
	char* buffer;
	int buffer_size, pos;

	void (*free_Printer)(struct Printer*);

	void (*flush)(struct Printer*);

	void (*print_char)(struct Printer*, char);

	void (*print_string)(struct Printer*, const String*);

	void (*print_chars)(struct Printer*, const char*);

	void (*print_int)(struct Printer*, int);

	void (*print_long)(struct Printer*, long long);

	void (*print_double)(struct Printer*, double, int);

	void (*print_boolean)(struct Printer*, int);

	void (*println)(struct Printer*);

	void (*println_char)(struct Printer*, char);

	void (*println_string)(struct Printer*, const String*);

	void (*println_chars)(struct Printer*, const char*);

	void (*println_int)(struct Printer*, int);

	void (*println_long)(struct Printer*, long long);

	void (*println_double)(struct Printer*, double, int);

	void (*println_boolean)(struct Printer*, int);
} Printer;

Printer* new_Printer();

void free_Printer(Printer*);

void print_char(Printer*, char);

void print_string(Printer*, const String*);

void print_chars(Printer*, const char*);

void print_int(Printer*, int);

void print_long(Printer*, long long);

void print_double(Printer*, double, int);

void print_boolean(Printer*, int);

void println(Printer*);

void println_char(Printer*, char);

void println_string(Printer*, const String*);

void println_chars(Printer*, const char*);

void println_int(Printer*, int);

void println_long(Printer*, long long);

void println_double(Printer*, double, int);

void println_boolean(Printer*, int);

void flush(Printer*);
#endif
