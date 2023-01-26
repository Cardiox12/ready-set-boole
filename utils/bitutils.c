#include "bitutils.h"
#include <unistd.h>

static void _print_byte_(byte_t val) {
    write(1, (val & (0x01     )) ? "1" : "0", 1);
    write(1, (val & (0x01 << 1)) ? "1" : "0", 1);
    write(1, (val & (0x01 << 2)) ? "1" : "0", 1);
    write(1, (val & (0x01 << 3)) ? "1" : "0", 1);
    write(1, (val & (0x01 << 4)) ? "1" : "0", 1);
    write(1, (val & (0x01 << 5)) ? "1" : "0", 1);
    write(1, (val & (0x01 << 6)) ? "1" : "0", 1);
    write(1, (val & (0x01 << 7)) ? "1" : "0", 1);
}

void _print_bits_(byte_t *val, size_t size) {
    while (size > 0) {
        _print_byte_(*val++);
        --size;
        if (size != 0) {
            write(STDOUT_FILENO, " ", 1);
        }
    }
    write(STDOUT_FILENO, "\n", 1);
}

