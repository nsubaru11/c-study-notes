#include "printer.h"

#include <stdio.h>
#include <stdlib.h>

Printer *new_Printer() {
    Printer *out = malloc(sizeof(Printer));
    out->BUFFER_SIZE = 1024;
    out->pos = 0;
    out->buffer = malloc(out->BUFFER_SIZE);
    out->methods = malloc(sizeof(PrinterMethods));

    out->methods->new_Printer = new_Printer;
    out->methods->free_Printer = free_Printer;
    out->methods->print_char = print_char;
    out->methods->print_string = print_string;
    out->methods->print_int = print_int;
    out->methods->print_long = print_long;
    out->methods->print_double = print_double;
    out->methods->println = println;
    out->methods->println_char = println_char;
    out->methods->println_string = println_string;
    out->methods->println_int = println_int;
    out->methods->println_long = println_long;
    out->methods->println_double = println_double;

    return out;
}

void free_Printer(Printer *out) {
    if (out) {
        if (out->pos > 0) {
            fwrite(out->buffer, 1, out->pos, stdout);
        }
        free(out->buffer);
        free(out->methods);
        free(out);
        fflush(stdout);
    }
}

void write(Printer *out) {
    if (out->pos == 0) return;
    fwrite(out->buffer, 1, out->pos, stdout);
    out->pos = 0;
}

void print_char(Printer *out, char c) {
    if (out->pos + 1 == out->BUFFER_SIZE) {
        write(out);
    }
    out->buffer[out->pos++] = c;
}

void print_string(Printer *out, const String *str) {
    for (int i = 0; i < str->len; i++) {
        print_char(out, str->array[i]);
    }
}

inline void print_int(Printer *out, int n) {
    if (out->pos + 11 >= out->BUFFER_SIZE) {
        write(out);
    }
    if (n < 0) {
        out->buffer[out->pos++] = '-';
        n = -n;
    }
    int start_pos = out->pos;
    while (n > 0) {
        out->buffer[out->pos++] = (char) ('0' + (n % 10));
        n /= 10;
    }
    int end_pos = out->pos - 1;
    while (start_pos < end_pos) {
        char temp = out->buffer[start_pos];
        out->buffer[start_pos] = out->buffer[end_pos];
        out->buffer[end_pos] = temp;
        start_pos++;
        end_pos--;
    }
}

inline void print_long(Printer *out, long long n) {
    if (out->pos + 20 >= out->BUFFER_SIZE) {
        write(out);
    }
    if (n < 0) {
        out->buffer[out->pos++] = '-';
        n = -n;
    }
    int start_pos = out->pos;
    while (n > 0) {
        out->buffer[out->pos++] = (char) ('0' + (n % 10));
        n /= 10;
    }
    int end_pos = out->pos - 1;
    while (start_pos < end_pos) {
        char temp = out->buffer[start_pos];
        out->buffer[start_pos] = out->buffer[end_pos];
        out->buffer[end_pos] = temp;
        start_pos++;
        end_pos--;
    }
}

inline void print_double(Printer *out, double n) {
    if (out->pos + 30 >= out->BUFFER_SIZE) {
        write(out);
    }
    if (n < 0) {
        out->buffer[out->pos++] = '-';
        n = -n;
    }
    long long int_part = (long long) n;
    double frac_part = n - (double) int_part;
    if (int_part == 0) {
        out->buffer[out->pos++] = '0';
    } else {
        int start_pos = out->pos;
        while (int_part > 0) {
            out->buffer[out->pos++] = (char) ('0' + (int_part % 10));
            int_part /= 10;
        }
        int end_pos = out->pos - 1;
        while (start_pos < end_pos) {
            char temp = out->buffer[start_pos];
            out->buffer[start_pos] = out->buffer[end_pos];
            out->buffer[end_pos] = temp;
            start_pos++;
            end_pos--;
        }
    }
    if (frac_part > 0) {
        out->buffer[out->pos++] = '.';
        for (int i = 0; i < 6; i++) {
            frac_part *= 10;
            int digit = (int) frac_part;
            out->buffer[out->pos++] = (char) ('0' + digit);
            frac_part -= digit;
            if (frac_part < 0.000001) break;
        }
    }
}

inline void println(Printer *out) {
    print_char(out, '\n');
}

inline void println_char(Printer *out, char c) {
    print_char(out, c);
    println(out);
}

inline void println_string(Printer *out, const String *str) {
    print_string(out, str);
    println(out);
}

inline void println_int(Printer *out, int n) {
    print_int(out, n);
    println(out);
}

inline void println_long(Printer *out, long long n) {
    print_long(out, n);
    println(out);
}

inline void println_double(Printer *out, double n) {
    print_double(out, n);
    println(out);
}
