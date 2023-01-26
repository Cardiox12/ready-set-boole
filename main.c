#include "utils/bitutils.h"

union {
    struct {
        unsigned char sum: 1;
        unsigned char carry: 1;
    }  res;
    unsigned char raw;
}   res;

int main() {
    res.res.sum = 0;
    res.res.carry = 1;

    // print_bits(unsigned char, res.raw);
    print8(MAKE_RESULT(0, 1));
    print8(MAKE_RESULT(1, 0));
    print8(MAKE_RESULT(1, 1));
    // print8(res.raw);
    // print8(0x01);
}
