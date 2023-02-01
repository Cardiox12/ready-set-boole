#ifndef __BITUTILS_H__
#define __BITUTILS_H__

#include <stddef.h>
#include <stdint.h>

typedef unsigned char byte_t;

#define LSB 0x01
#define CLEAR_BITS(x) x & LSB
#define GET_BIT(x, n) (x >> n) & LSB

typedef struct {
    int32_t res;
    byte_t carry;
}       res_t;

//                                                       |  Res  | Carry |.....................EMPTY.....................| 
// Result and Carry is encoded in 2 bits unsigned char : |   0   |   0   |   0   |   0   |   0   |   0   |   0   |   0   |
#define MAKE_RESULT(result, carry) (byte_t)(result | ((carry) << 1))
#define GET_CARRY(result) result >> 1
#define GET_RESULT(result) result & LSB

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