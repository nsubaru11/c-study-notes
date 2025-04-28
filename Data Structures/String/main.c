#include <stdio.h>

#include "string.h"

int main(void) {
    String *str = new_String();
    str->concat(str, new_String_from_chars("Hello, "));
    str->concat(str, new_String_from_chars("World"));
    str->sort(str);
    printf("%s", str->array);
    free_String(str);
    return 0;
}
