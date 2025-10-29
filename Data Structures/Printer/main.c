#include "printer.h"

int main(void) {
	Printer* out = new_Printer();
	out->println_int(out, 10);
	out->println_double(out, 10.123456789, 2);
	out->println_boolean(out, 1);
	out->println_boolean(out, 0);
	out->println_chars(out, "hello world");
	free_Printer(out);
	return 0;
}
