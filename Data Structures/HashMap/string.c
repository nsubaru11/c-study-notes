#include "string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

String *new_String() {
    String *str = malloc(sizeof(String));
    str->len = 0;
    str->capacity = 8;
    str->array = malloc(sizeof(char) * str->capacity);
    str->hashCode = 0;

    str->free_String = free_String;
    str->equals = equals;
    str->concat = concat;
    str->concat_chars = concat_chars;
    str->append = append;
    str->charAt = charAt;
    str->set = set;
    return str;
}

String *new_String_from_chars(const char *c) {
    String *str = malloc(sizeof(String));
    str->len = (int) strlen(c);
    str->capacity = 1 << (32 - __builtin_clz(str->len - 1));
    str->array = malloc(sizeof(char) * str->capacity);
    memcpy(str->array, c, str->len);
    for (int i = 0; i < str->len; i++) {
        str->hashCode = str->hashCode * 31 + str->array[i];
    }

    str->free_String = free_String;
    str->equals = equals;
    str->concat = concat;
    str->concat_chars = concat_chars;
    str->append = append;
    str->charAt = charAt;
    return str;
}

void free_String(String *str) {
    if (str) {
        free(str->array);
        free(str);
    }
}

int equals(const String *str1, const String *str2) {
    if (str1->len != str2->len) {
        return 0;
    }
    return !memcmp(str1->array, str2->array, str1->len);
}

void concat(String *str1, const String *str2) {
    while (str1->len + str2->len > str1->capacity) {
        resize(str1);
    }
    memcpy(str1->array + str1->len, str2->array, str2->len);
    for (int i = 0; i < str2->len; i++) {
        str1->hashCode = str1->hashCode * 31 + str1->array[str1->len + i];
    }
    str1->len += str2->len;
}

void concat_chars(String *str1, const char *str2) {
    const int len = (int) strlen(str2);
    while (str1->len + len > str1->capacity) {
        resize(str1);
    }
    memcpy(str1->array + str1->len, str2, len);
    for (int i = 0; i < len; i++) {
        str1->hashCode = str1->hashCode * 31 + str1->array[str1->len + i];
    }
    str1->len += len;
}

void append(String *str1, const char c) {
    if (str1->len + 1 > str1->capacity) {
        resize(str1);
    }
    str1->array[str1->len++] = c;
    str1->hashCode = str1->hashCode * 31 + c;
}

char charAt(const String *str, const int index) {
    if (index < 0 || index >= str->len) {
        printf("%s", "Index out of bounds");
        exit(1);
    }
    return str->array[index];
}

void set(String *str, const int index, const char c) {
    if (index < 0 || index >= str->len) {
        printf("%s", "Index out of bounds");
        exit(1);
    }
    str->array[index] = c;
    for (int i = 0; i < str->len; i++) {
        str->hashCode = str->hashCode * 31 + str->array[i];
    }
}
