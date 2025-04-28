#ifndef STRING_H
#define STRING_H
#include <string.h>

typedef struct String {
    char *array;
    int len, capacity, hashCode;

    void (*free_String)(struct String *);

    int (*equals)(const struct String *, const struct String *);

    void (*concat)(struct String *, const struct String *);

    void (*concat_chars)(struct String *, const char *);

    void (*append)(struct String *, char);

    char (*charAt)(const struct String *, int);

    void (*set)(struct String *, int, char);

    void (*sort)(struct String *);
} String;

String *new_String();

String *new_String_from_chars(const char *c);

void free_String(String *str);

int equals(const String *str1, const String *str2);

void concat(String *str1, const String *str2);

void concat_chars(String *str1, const char *str2);

void append(String *str1, char c);

char charAt(const String *str, int index);

void set(String *str, int index, char c);

void sort(String *str);
#endif
