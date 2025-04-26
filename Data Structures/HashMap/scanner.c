#include "scanner.h"

#include <stdio.h>
#include <stdlib.h>

#include "string.h"

Scanner *new_Scanner() {
    Scanner *sc = malloc(sizeof(Scanner));
    sc->BUFFER_SIZE = 1024;
    sc->pos = 0;
    sc->cnt = 0;
    sc->buffer = malloc(sc->BUFFER_SIZE * sizeof(unsigned char));
    sc->methods = malloc(sizeof(ScannerMethods));

    sc->methods->new_Scanner = new_Scanner;
    sc->methods->free_Scanner = free_Scanner;
    sc->methods->next = next;
    sc->methods->nextLine = nextLine;
    sc->methods->nextInt = nextInt;
    sc->methods->nextLong = nextLong;
    sc->methods->nextDouble = nextDouble;

    return sc;
}

void free_Scanner(Scanner *sc) {
    if (sc) {
        free(sc->buffer);
        free(sc->methods);
        free(sc);
    }
}

int isDelimiter(int c) {
    return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == ',' || c == '.';
}

int read(Scanner *sc) {
    if (sc->pos == sc->cnt) {
        sc->cnt = fread(sc->buffer, 1, sc->BUFFER_SIZE, stdin);
        sc->pos = 0;
    }
    return sc->buffer[sc->pos++];
}

String *next(Scanner *sc) {
    String *s = new_String();
    unsigned char c = read(sc);
    while (isDelimiter(c)) {
        c = read(sc);
    }
    while (!isDelimiter(c) && c != 0) {
        s->append(s, (char) c);
        c = read(sc);
    }
    return s;
}

String *nextLine(Scanner *sc) {
    String *s = new_String();
    unsigned char c = read(sc);
    while (isDelimiter(c)) {
        c = read(sc);
    }
    while (isDelimiter(c)) {
        c = read(sc);
    }
    while (c != '\n' && c != 0) {
        s->append(s, (char) c);
        c = read(sc);
    }
    return s;
}

int nextInt(Scanner *sc) {
    unsigned char c = read(sc);
    while (isDelimiter(c)) {
        c = read(sc);
    }
    const bool neg = c == '-';
    if (neg) c = read(sc);
    int n = 0;
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = read(sc);
    }
    return neg ? -n : n;
}

long long nextLong(Scanner *sc) {
    unsigned char c = read(sc);
    while (isDelimiter(c)) {
        c = read(sc);
    }
    const bool neg = c == '-';
    if (neg) c = read(sc);
    long long n = 0;
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = read(sc);
    }
    return neg ? -n : n;
}

double nextDouble(Scanner *sc) {
    unsigned char c = read(sc);
    while (isDelimiter(c)) {
        c = read(sc);
    }
    const bool neg = c == '-';
    if (neg) c = read(sc);
    double n = 0;
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = read(sc);
    }
    if (c == '.') {
        c = read(sc);
        double factor = 1;
        while ('0' <= c && c <= '9') {
            factor /= 10;
            n += (c - '0') * factor;
            c = read(sc);
        }
    }
    return neg ? -n : n;
}
