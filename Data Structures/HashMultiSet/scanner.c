#include "scanner.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "string.h"

Scanner *new_Scanner() {
    Scanner *sc = malloc(sizeof(Scanner));
    sc->BUFFER_SIZE = 1024;
    sc->pos = 0;
    sc->cnt = 0;
    sc->buffer = malloc(sc->BUFFER_SIZE * sizeof(unsigned char));

    sc->free_Scanner = free_Scanner;
    sc->next = next;
    sc->nextLine = nextLine;
    sc->nextInt = nextInt;
    sc->nextLong = nextLong;
    sc->nextDouble = nextDouble;
    return sc;
}

void free_Scanner(Scanner *sc) {
    if (sc) {
        free(sc->buffer);
        free(sc);
    }
}

int isDelimiter(int c) {
    return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == ',' || c == '.';
}

int read_stdin(Scanner *sc) {
    if (sc->pos >= sc->cnt) {
        sc->cnt = read(STDIN_FILENO, sc->buffer, sc->BUFFER_SIZE);
        if (sc->cnt <= 0) {
            return 0;
        }
        sc->pos = 0;
    }
    return sc->buffer[sc->pos++];
}

int hasNext(Scanner *sc) {
    if (sc->pos < sc->cnt) {
        return 1;
    }
    sc->cnt = read(STDIN_FILENO, sc->buffer, sc->BUFFER_SIZE);
    if (sc->cnt <= 0) {
        return 0;
    }
    sc->pos = 0;
    return 0;
}

String *next(Scanner *sc) {
    String *s = new_String();
    unsigned char c = read_stdin(sc);
    while (isDelimiter(c)) {
        c = read_stdin(sc);
    }
    while (!isDelimiter(c) && c != 0) {
        s->append(s, (char) c);
        c = read_stdin(sc);
    }
    return s;
}

String *nextLine(Scanner *sc) {
    String *s = new_String();
    unsigned char c = read_stdin(sc);
    while (isDelimiter(c)) {
        c = read_stdin(sc);
    }
    while (c != '\n' && c != 0) {
        s->append(s, (char) c);
        c = read_stdin(sc);
    }
    return s;
}

int nextInt(Scanner *sc) {
    unsigned char c = read_stdin(sc);
    while (isDelimiter(c)) {
        c = read_stdin(sc);
    }
    const int neg = c == '-';
    if (neg) c = read_stdin(sc);
    int n = 0;
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = read_stdin(sc);
    }
    return neg ? -n : n;
}

long long nextLong(Scanner *sc) {
    unsigned char c = read_stdin(sc);
    while (isDelimiter(c)) {
        c = read_stdin(sc);
    }
    const int neg = c == '-';
    if (neg) c = read_stdin(sc);
    long long n = 0;
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = read_stdin(sc);
    }
    return neg ? -n : n;
}

double nextDouble(Scanner *sc) {
    unsigned char c = read_stdin(sc);
    while (isDelimiter(c)) {
        c = read_stdin(sc);
    }
    const int neg = c == '-';
    if (neg) c = read_stdin(sc);
    double n = 0;
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = read_stdin(sc);
    }
    if (c == '.') {
        c = read_stdin(sc);
        double factor = 1;
        while ('0' <= c && c <= '9') {
            factor /= 10;
            n += (c - '0') * factor;
            c = read_stdin(sc);
        }
    }
    return neg ? -n : n;
}
