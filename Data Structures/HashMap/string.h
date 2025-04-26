#ifndef STRING_H
#define STRING_H
#include <string.h>

typedef struct String {
    char *array;
    int len, capacity;
    int hashCode;

    struct String * (*new_String)(char *);

    void (*free_String)(struct String *);

    void (*resize)(struct String *);

    int (*hash)(struct String *);

    int (*equals)(struct String *, struct String *);

    int (*length)(const struct String *);

    struct String * (*concat)(struct String *, const struct String *);

    void (*append)(struct String *, char);

    char (*charAt)(struct String *, int);

    char * (*chars)(struct String *);
} String;

String *new_String();

int hash(const String *str);

char charAt(const String *str, int index);

int equals(const String *str1, const String *str2);

char *chars(const String *str);

void free_String(String *str);

void resize(String *str);

int length(const String *str);

String *concat(String *str1, const String *str2);

void append(String *str1, char c);

#endif
