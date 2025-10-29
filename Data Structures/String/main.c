#include <stdio.h>

#include "../String/string.h"

int main(void) {
	String* str = new_String();
	str->concat(str, new_String_from_chars("Hello, "));
	str->concat(str, new_String_from_chars("World"));
	str->strSort(str);
	printf("%s", str->array);
	free_String(str);
	return 0;
}
