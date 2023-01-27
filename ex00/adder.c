#include <stdio.h>
#include <unistd.h>
#include "bitutils.h"

//                                                       |  Res  | Carry |.....................EMPTY.....................| 
// Result and Carry is encoded in 2 bits unsigned char : |   0   |   0   |   0   |   0   |   0   |   0   |   0   |   0   |


byte_t half_adder(byte_t a, byte_t b) {
    return MAKE_RESULT(a ^ b, a & b);
}

byte_t full_adder(byte_t a, byte_t b, byte_t cin) {
    byte_t ab_xor = a ^ b;

    return MAKE_RESULT(ab_xor ^ cin, (ab_xor & cin) | (a & b));
}

// int32_t adder(int32_t a, int32_t b) {
    
// }

int     main(){
    int bytes[4][2] = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };

    for (size_t i = 0 ; i < 4 ; ++i){
        print8(half_adder(bytes[i][0], bytes[i][1]));
    }
    puts("\n\n");
    int full_adder_bytes[8][3] = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 0, 0},
        {1, 1, 0},
        {0, 0, 1},
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
    };

    for (size_t i = 0 ; i < 8 ; ++i){
        print8(full_adder(
            full_adder_bytes[i][0],
            full_adder_bytes[i][1],
            full_adder_bytes[i][2]
        ));
    }
    return 0;
}