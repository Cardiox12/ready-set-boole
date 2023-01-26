#ifndef __BITUTILS_H__
#define __BITUTILS_H__

#include <stddef.h>
#include <stdint.h>

typedef unsigned char byte_t;

#define LSB 0x01
#define clear_bits(x) x & LSB

//                                                       |  Res  | Carry |.....................EMPTY.....................| 
// Result and Carry is encoded in 2 bits unsigned char : |   0   |   0   |   0   |   0   |   0   |   0   |   0   |   0   |
#define MAKE_RESULT(sum, carry) (byte_t)(sum | ((carry) << 1))

// Bit stream

// Print bits of value V and type T
#define print_bits(T, V) {                      \
    T tmp = V;                                  \
    _print_bits_((byte_t*)&tmp, sizeof(tmp));   \
}
#define print64(V) print_bits(uint64_t, V)
#define print32(V) print_bits(uint32_t, V)
#define print16(V) print_bits(uint16_t, V)
#define print8(V)  print_bits(uint8_t, V)

void _print_bits_(byte_t *val, size_t size);

#endif