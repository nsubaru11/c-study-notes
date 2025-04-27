#include "printer.h"
#include "string.h"

int main() {
    Printer *out = new_Printer();
    String *str = new_String_from_chars("abcdefghijklmnopqrstuvwxyz");
    out->println_string(out, str);
    out->println_int(out, str->hashCode);
    String *str2 = new_String();
    for (char i = 'a'; i <= 'z'; i++) {
        str2->append(str2, i);
    }
    out->println_int(out, str2->hashCode);
    String *str3 = new_String();
    str3->concat_chars(str3, "abc");
    str3->concat_chars(str3, "defghijklmnopqrstuvwxyz");
    out->println_int(out, str3->hashCode);
    out->println_boolean(out, equals(str, str2));
    out->println_boolean(out, equals(str, str3));
    free_String(str);
    free_String(str2);
    free_String(str3);
    free_Printer(out);
    return 0;
}
