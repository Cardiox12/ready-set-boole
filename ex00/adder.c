#include <stdio.h>
#include <unistd.h>
#include "bitutils.h"

//                                                       |  Res  | Carry |.....................EMPTY.....................| 
// Result and Carry is encoded in 2 bits unsigned char : |   0   |   0   |   0   |   0   |   0   |   0   |   0   |   0   |


static inline byte_t half_adder(byte_t a, byte_t b) {
    return MAKE_RESULT(a ^ b, a & b);
}

static inline byte_t full_adder(byte_t a, byte_t b, byte_t cin) {
    byte_t ab_xor = a ^ b;

    return MAKE_RESULT(ab_xor ^ cin, (ab_xor & cin) | (a & b));
}

static byte_t full_adder4(byte_t a, byte_t b, byte_t cin) {
    byte_t res, r1, r2, r3, r4;

    r1 = full_adder(GET_BIT(a, 0), GET_BIT(b, 0), cin);
    r2 = full_adder(GET_BIT(a, 1), GET_BIT(b, 1), GET_CARRY(r1));
    r3 = full_adder(GET_BIT(a, 2), GET_BIT(b, 2), GET_CARRY(r2));
    r4 = full_adder(GET_BIT(a, 3), GET_BIT(b, 3), GET_CARRY(r3));
    return MAKE_RESULT(
        (GET_RESULT(r1) << 0) | (GET_RESULT(r2) << 1) | 
        (GET_RESULT(r3) << 2) | (GET_RESULT(r4) << 3),
        GET_CARRY(r4)
    );
}

// int32_t adder(int32_t a, int32_t b) {
    
// }

int     main(){
    // int bytes[4][2] = {
    //     {0, 0},
    //     {0, 1},
    //     {1, 0},
    //     {1, 1}
    // };

    // for (size_t i = 0 ; i < 4 ; ++i){
    //     byte_t result = half_adder(bytes[i][0], bytes[i][1]);
    //     printf("Sum: %i - Carry: %i\n", GET_RESULT(result), GET_CARRY(result));
    // }
    // puts("");
    // int full_adder_bytes[8][3] = {
    //     {0, 0, 0},
    //     {0, 1, 0},
    //     {1, 0, 0},
    //     {1, 1, 0},
    //     {0, 0, 1},
    //     {0, 1, 1},
    //     {1, 0, 1},
    //     {1, 1, 1},
    // };

    // for (size_t i = 0 ; i < 8 ; ++i){
    //     byte_t result = full_adder(
    //         full_adder_bytes[i][0],
    //         full_adder_bytes[i][1],
    //         full_adder_bytes[i][2]
    //     );
    //     printf("Sum: %i - Carry: %i\n", GET_RESULT(result), GET_CARRY(result));
    // }
    // int x = 3389;

    // print32(x);
    // print8(GET_BIT(x, 0));
    // print8(GET_BIT(x, 1));
    // print8(GET_BIT(x, 3));

    puts("4(0100) + 5(0101)");
    byte_t res = full_adder4(4, 5, 0);
    
    return 0;
}