#include <stdio.h>

#include "string.h"

int main() {
    String *str = new_String_from_chars("abcdefghijklmnopqrstuvwxyz");
    for (int i = 0; i < str->len; i++) {
        printf("%c", str->array[i]);
    }
    printf("\n");
    printf("%d\n", str->hashCode);
    String *str2 = new_String();
    for (char i = 'a'; i <= 'z'; i++) {
        str2->append(str2, i);
    }
    printf("%d\n", str2->hashCode);
    String *str3 = new_String();
    str3->concat_chars(str3, "abc");
    str3->concat_chars(str3, "defghijklmnopqrstuvwxyz");
    printf("%d\n", str3->hashCode);
    printf("%d\n", equals(str, str2));
    printf("%d\n", equals(str, str3));
    free_String(str);
    free_String(str2);
    free_String(str3);
    return 0;
}