#ifndef SCANNER_H
#define SCANNER_H
#include "../String/string.h"

typedef struct Scanner {
	unsigned char* buffer;
	int BUFFER_SIZE, pos;
	unsigned long long cnt;

	void (*free_Scanner)(struct Scanner*);

	int (*hasNext)(struct Scanner*);

	String* (*next)(struct Scanner*);

	String* (*nextLine)(struct Scanner*);

	int (*nextInt)(struct Scanner*);

	long long (*nextLong)(struct Scanner*);

	double (*nextDouble)(struct Scanner*);
} Scanner;

Scanner* new_Scanner();

void free_Scanner(Scanner*);

int hasNext(Scanner*);

String* next(Scanner*);

String* nextLine(Scanner*);

int nextInt(Scanner*);

long long nextLong(Scanner*);

double nextDouble(Scanner*);

#endif
