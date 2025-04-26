#ifndef SCANNER_H
#define SCANNER_H
#include "string.h"

typedef struct ScannerMethods {
    struct Scanner * (*new_Scanner)();

    void (*free_Scanner)(struct Scanner *);

    String * (*next)(struct Scanner *);

    int (*nextInt)(struct Scanner *);

    long long (*nextLong)(struct Scanner *);

    double (*nextDouble)(struct Scanner *);

    String * (*nextLine)(struct Scanner *);
} ScannerMethods;

typedef struct Scanner {
    unsigned char *buffer;
    int BUFFER_SIZE, pos;
    unsigned long long cnt;
    ScannerMethods *methods;
} Scanner;

Scanner *new_Scanner();

void free_Scanner(Scanner *sc);

String *next(Scanner *sc);

int nextInt(Scanner *sc);

long long nextLong(Scanner *sc);

double nextDouble(Scanner *sc);

String *nextLine(Scanner *sc);

#endif
