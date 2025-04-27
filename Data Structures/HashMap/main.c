#include <stdio.h>

#include "string.h"

int main() {
    String *str = new_String_from_chars("abcdefg");
    for (int i = 0; i < str->len; i++) {
        printf("%c", str->array[i]);
    }
    printf("\n");
    printf("%d\n", str->hashCode);
    String *str2 = new_String();
    for (char i = 'a'; i <= 'g'; i++) {
        str2->append(str2, i);
    }
    printf("%d\n", str2->hashCode);
    String *str3 = new_String();
    str3->concat_chars(str3, "abc");
    str3->concat_chars(str3, "defg");
    printf("%d\n", str3->hashCode);
    free_String(str);
    free_String(str2);
    free_String(str3);
    return 0;
}