#include <stdio.h>
#include "scanner.h"

int main(void) {
	Scanner* sc = new_Scanner();
	while (sc->hasNext(sc)) {
		String* s = sc->next(sc);
		printf("%c\n", s->charAt(s, 0));
	}
	return 0;
}
