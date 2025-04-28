#ifndef SCANNER_H
#define SCANNER_H
#include "string.h"

typedef struct Scanner {
    unsigned char *buffer;
    int BUFFER_SIZE, pos;
    unsigned long long cnt;

    void (*free_Scanner)(struct Scanner *);

    int (*hasNext)(struct Scanner *);

    String *(*next)(struct Scanner *);

    String *(*nextLine)(struct Scanner *);

    int (*nextInt)(struct Scanner *);

    long long (*nextLong)(struct Scanner *);

    double (*nextDouble)(struct Scanner *);
} Scanner;

Scanner *new_Scanner();

void free_Scanner(Scanner *sc);

int hasNext(Scanner *sc);

String *next(Scanner *sc);

String *nextLine(Scanner *sc);

int nextInt(Scanner *sc);

long long nextLong(Scanner *sc);

double nextDouble(Scanner *sc);

#endif
