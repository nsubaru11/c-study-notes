#include "string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

String *new_String() {
    String *str = malloc(sizeof(String));
    str->len = 0;
    str->capacity = 8;
    str->hashCode = hash(str);
    str->array = malloc(sizeof(char) * str->capacity);
    str->free_String = free_String;
    str->concat = concat;
    str->append = append;
    str->charAt = charAt;
    str->chars = chars;
    str->equals = equals;
    str->length = length;
    str->hash = hash;
    str->resize = resize;
    return str;
}

String *new_String(char *c) {
    String *str = malloc(sizeof(String));
    return str;
}

void free_String(String *str) {
    if (str) {
        free(str->array);
        free(str);
    }
}

void resize(String *str) {
    str->capacity *= 2;
    char *tmp = realloc(str->array, str->capacity);
    if (tmp) {
        str->array = tmp;
    } else {
        str->free_String(str);
        printf("%s", "Memory allocation error");
        exit(1);
    }
}

int hash(const String *str) {
    int result = 0;
    for (int i = 0; i < str->len; i++) {
        result = result * 31 + str->array[i];
    }
    return result;
}

int equals(const String *str1, const String *str2) {
    if (str1->length != str2->length) {
        return 0;
    }
    return !memcmp(str1->array, str2->array, str1->len);
}

int length(const String *str) {
    return str->len;
}

String *concat(String *str1, const String *str2) {
    while (str1->len + str2->len > str1->capacity) {
        resize(str1);
    }
    memcpy(str1->array + str1->len, str2->array, str2->len);
    str1->len += str2->len;
    return str1;
}

String *concat(String *str1, char *str2) {

    return str1;
}

void append(String *str1, char c) {
    if (str1->len + 1 > str1->capacity) {
        resize(str1);
    }
    str1->array[str1->len++] = c;
}

char charAt(const String *str, int index) {
    if (index < 0 || index >= str->len) {
        printf("%s", "Index out of bounds");
        exit(1);
    }
    return str->array[index];
}

char *chars(const String *str) {
    return str->array;
}
