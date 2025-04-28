#include <stdlib.h>

#include "HashMultiSet.h"
#include "printer.h"
#include "scanner.h"
#include "string.h"

int main() {
    Printer *out = new_Printer();
    Scanner *sc = new_Scanner();
    String **arr = malloc(sizeof(String *) * 1000);
    HashMultiSet *multi_set = new_HashMultiSet();
    int cnt = 0;
    while (hasNext(sc)) {
        String *s = next(sc);
        arr[cnt++] = s;
        multi_set->insert(multi_set, s);
    }
    for (int i = 0; i < cnt; i++) {
        out->print_string(out, arr[i]);
        out->print_chars(out, ": ");
        out->println_int(out, multi_set->count(multi_set, arr[i]));
    }
    free(arr);
    free_HashMultiSet(multi_set);
    free_Scanner(sc);
    free_Printer(out);
    return 0;
}
