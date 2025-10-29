#ifndef STRING_H
#define STRING_H
#include <string.h>

typedef struct String {
	char* array;
	int len, capacity, hashCode;

	void (*free_String)(struct String*);

	int (*equals)(const struct String*, const struct String*);

	int (*compareTo)(const struct String*, const struct String*);

	void (*concat)(struct String*, const struct String*);

	void (*concatChars)(struct String*, const char*);

	void (*append)(struct String*, char);

	char (*charAt)(const struct String*, int);

	void (*set)(struct String*, int, char);

	void (*strSort)(struct String*);
} String;

String* new_String();

String* new_String_from_chars(const char*);

void free_String(String*);

int equals(const String*, const String*);

int compareTo(const String*, const String*);

void concat(String*, const String*);

void concatChars(String*, const char*);

void append(String*, char);

char charAt(const String*, int);

void set(String*, int, char);

void strSort(String*);
#endif
