#include "printer.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Printer *new_Printer() {
    Printer *out = malloc(sizeof(Printer));
    out->buffer_size = 1024;
    out->pos = 0;
    out->buffer = malloc(out->buffer_size);
    out->free_Printer = free_Printer;
    out->flush = flush;
    out->print_char = print_char;
    out->print_string = print_string;
    out->print_chars = print_chars;
    out->print_int = print_int;
    out->print_long = print_long;
    out->print_double = print_double;
    out->print_boolean = print_boolean;
    out->println = println;
    out->println_char = println_char;
    out->println_string = println_string;
    out->println_chars = println_chars;
    out->println_int = println_int;
    out->println_long = println_long;
    out->println_double = println_double;
    out->println_boolean = println_boolean;
    return out;
}

void free_Printer(Printer *out) {
    if (out) {
        if (out->pos > 0) {
            fwrite(out->buffer, 1, out->pos, stdout);
        }
        fflush(stdout);
        free(out->buffer);
        free(out);
    }
}

void flush(Printer *out) {
    if (out->pos > 0) {
        fwrite(out->buffer, 1, out->pos, stdout);
        out->pos = 0;
    }
    fflush(stdout);
}

void write(Printer *out) {
    if (out->pos == 0) return;
    fwrite(out->buffer, 1, out->pos, stdout);
    out->pos = 0;
}

void print_char(Printer *out, char c) {
    if (out->pos + 1 >= out->buffer_size) {
        write(out);
    }
    out->buffer[out->pos++] = c;
}

void print_string(Printer *out, const String *str) {
    for (int i = 0; i < str->len; i++) {
        out->print_char(out, str->array[i]);
    }
}

void print_chars(Printer *out, const char *str) {
    for (int i = 0; str[i] != 0; i++) {
        out->print_char(out, str[i]);
    }
}

void print_int(Printer *out, int n) {
    if (out->pos + 11 >= out->buffer_size) {
        write(out);
    }
    if (n < 0) {
        out->buffer[out->pos++] = '-';
        n = -n;
    }
    int l = out->pos;
    while (n > 0) {
        out->buffer[out->pos++] = (char) (n % 10 + '0');
        n /= 10;
    }
    int r = out->pos - 1;
    while (l < r) {
        char temp = out->buffer[l];
        out->buffer[l] = out->buffer[r];
        out->buffer[r] = temp;
        l++;
        r--;
    }
}

void print_long(Printer *out, long long n) {
    if (out->pos + 20 >= out->buffer_size) {
        write(out);
    }
    if (n < 0) {
        out->buffer[out->pos++] = '-';
        n = -n;
    }
    int l = out->pos;
    while (n > 0) {
        out->buffer[out->pos++] = (char) (n % 10 + '0');
        n /= 10;
    }
    int r = out->pos - 1;
    while (l < r) {
        char temp = out->buffer[l];
        out->buffer[l] = out->buffer[r];
        out->buffer[r] = temp;
        l++;
        r--;
    }
}

void print_double(Printer *out, double n, int scale) {
    if (scale == 0) {
        out->print_long(out, llround(n));
        return;
    }
    if (n < 0) {
        out->print_char(out, '-');
        n = -n;
    }
    n += pow(10, -scale) / 2;
    out->print_long(out, (long long) n);
    if (out->pos + scale + 1 >= out->buffer_size) {
        write(out);
    }
    out->buffer[out->pos++] = '.';
    n -= (double) (long long) n;
    while (scale-- > 0) {
        n *= 10;
        out->buffer[out->pos++] = (char) ((int) n + '0');
        n -= (int) n;
    }
}

void print_boolean(Printer *out, int b) {
    if (b) {
        out->print_chars(out, "true");
    } else {
        out->print_chars(out, "false");
    }
}

void println(Printer *out) {
    out->print_char(out, '\n');
}

void println_char(Printer *out, char c) {
    out->print_char(out, c);
    out->println(out);
}

void println_string(Printer *out, const String *str) {
    out->print_string(out, str);
    out->println(out);
}

void println_chars(Printer *out, const char *str) {
    out->print_chars(out, str);
    out->println(out);
}

void println_int(Printer *out, int n) {
    out->print_int(out, n);
    out->println(out);
}

void println_long(Printer *out, long long n) {
    out->print_long(out, n);
    out->println(out);
}

void println_double(Printer *out, double n, int scale) {
    out->print_double(out, n, scale);
    out->println(out);
}

void println_boolean(Printer *out, int b) {
    if (b) {
        out->println_chars(out, "true");
    } else {
        out->println_chars(out, "false");
    }
}
