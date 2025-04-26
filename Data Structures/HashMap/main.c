#include "printer.h"
#include "scanner.h"
#include "string.h"

int main() {
    Printer *out = new_Printer();
    out->methods->println("Step1");
    Scanner *sc = new_Scanner();
    out->methods->println("Step2");
    String *s = sc->methods->next(sc);
    out->methods->println("Step3");
    out->methods->print_string(out, s);
    out->methods->println("Step4");
    free_Scanner(sc);
    free_Printer(out);
    return 0;
}