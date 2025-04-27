#include "printer.h"
#include "scanner.h"
#include "string.h"

int main() {
    Printer *out = new_Printer();
    Scanner *sc = new_Scanner();
    String *str = sc->next(sc);
    out->println_string(out, str);

    int n = sc->nextInt(sc);
    out->println_int(out, n);

    long long m = sc->nextLong(sc);
    out->println_long(out, m);

    double d = sc->nextDouble(sc);
    out->println_double(out, d, 2);

    String *str2 = sc->nextLine(sc);
    out->println_string(out, str2);

    free_String(str2);
    free_String(str);
    free_Scanner(sc);
    free_Printer(out);
    return 0;
}
