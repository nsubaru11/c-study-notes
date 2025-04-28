#include "string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ================== private ===================

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

// ------------------ ƒƒ‚ƒŠŠm•Û -------------------

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
    str->sort = sort;
    return str;
}

String *new_String_from_chars(const char *c) {
    String *str = malloc(sizeof(String));
    str->len = (int) strlen(c);
    str->capacity = 1 << (32 - __builtin_clz(str->len - 1));
    str->array = malloc(sizeof(char) * str->capacity);
    memcpy(str->array, c, str->len);
    for (int i = 0; i < str->len; i++) {
        str->hashCode = (str->hashCode << 5) - str->hashCode + str->array[i];
    }

    str->free_String = free_String;
    str->equals = equals;
    str->concat = concat;
    str->concat_chars = concat_chars;
    str->append = append;
    str->charAt = charAt;
    str->sort = sort;
    return str;
}

// ------------------ ƒƒ‚ƒŠ‰ð•ú -------------------

void free_String(String *str) {
    if (str) {
        free(str->array);
        free(str);
    }
}

// ------------------ String Methods -------------------

int equals(const String *str1, const String *str2) {
    if (str1->len != str2->len) {
        return 0;
    }
    if (str1->hashCode != str2->hashCode) {
        return 0;
    }
    return !memcmp(str1->array, str2->array, str1->len);
}

void concat(String *str1, const String *str2) {
    char *arr = str1->array;
    const int len1 = str1->len;
    const int len2 = str2->len;
    while (len1 + len2 > str1->capacity) {
        resize(str1);
    }
    memcpy(arr + len1, str2->array, len2);
    for (int i = 0; i < len2; i++) {
        str1->hashCode = (str1->hashCode << 5) - str1->hashCode + arr[len1 + i];
    }
    str1->len += len2;
}

void concat_chars(String *str1, const char *str2) {
    char *arr = str1->array;
    const int len1 = str1->len;
    const int len2 = (int) strlen(str2);
    while (len1 + len2 > str1->capacity) {
        resize(str1);
    }
    memcpy(arr + len1, str2, len2);
    for (int i = 0; i < len2; i++) {
        str1->hashCode = (str1->hashCode << 5) - str1->hashCode + arr[len1 + i];
    }
    str1->len += len2;
}

void append(String *str1, const char c) {
    if (str1->len + 1 > str1->capacity) resize(str1);
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
        str->hashCode = (str->hashCode << 5) - str->hashCode + str->array[i];
    }
}

void swap(String *str, int i, int j) {
    char tmp = str->array[i];
    str->array[i] = str->array[j];
    str->array[j] = tmp;
}

void sort_range(String *str, int left, int right) {
    if (right <= left) return;
    int l = left;
    int r = right;
    int mid = (left + right) / 2;
    char pivot = str->array[mid];
    while (l < r) {
        while (l < r && pivot > str->array[l]) l++;
        while (l < r && pivot <= str->array[r]) r--;
        if (l >= r) break;
        swap(str, l, r);
        l++;
        r--;
    }
    while (r < right && str->array[r] <= pivot) r++;
    if (mid > r) {
        swap(str, mid, r);
        r++;
    }
    sort_range(str, left, l);
    sort_range(str, r, right);
}

void sort(String *str) {
    sort_range(str, 0, str->len - 1);
}
