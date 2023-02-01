#include <stdio.h>
#include <unistd.h>
#include "bitutils.h"


static inline res_t half_adder(byte_t a, byte_t b) {
    return (res_t){
        .res = a ^ b, 
        .carry = a & b
    };
}

static inline res_t full_adder(byte_t a, byte_t b, byte_t cin) {
    byte_t ab_xor = a ^ b;

    return (res_t){ 
        .res = ab_xor ^ cin, 
        .carry = (ab_xor & cin) | (a & b)
    };
}

static inline res_t full_adder4(byte_t a, byte_t b, byte_t cin) {
    res_t r1, r2, r3, r4;

    print8(a);
    print8(b);
    r1 = full_adder(GET_BIT(a, 0), GET_BIT(b, 0), cin);
    r2 = full_adder(GET_BIT(a, 1), GET_BIT(b, 1), r1.carry);
    r3 = full_adder(GET_BIT(a, 2), GET_BIT(b, 2), r2.carry);
    r4 = full_adder(GET_BIT(a, 3), GET_BIT(b, 3), r3.carry);
    return (res_t){
        .res = (r1.res << 0) | (r2.res << 1) | (r3.res << 2) | (r4.res << 3),
        .carry = r4.carry
    };
}

static inline res_t full_adder8(byte_t a, byte_t b, byte_t cin) {
    res_t r1, r2;

    puts("BEFORE");
    print8(a);
    print8(b);

    puts("ADDER 1");
    r1 = full_adder4(a, b, cin);
    puts("RESULT 1");
    print8(r1.res);

    puts("ADDER 2");
    r2 = full_adder4(a << 4, b << 4, r1.carry);
    puts("RESULT 1");
    print8(r2.res);
    return (res_t){
        .res = r1.res | (r2.res << 4),
        .carry = r2.carry
    };
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
    //     res_t result = half_adder(bytes[i][0], bytes[i][1]);
    //     printf("Sum: %i - Carry: %i\n", result.res, result.carry);
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
    //     res_t result = full_adder(
    //         full_adder_bytes[i][0],
    //         full_adder_bytes[i][1],
    //         full_adder_bytes[i][2]
    //     );
    //     printf("Sum: %i - Carry: %i\n", result.res, result.carry);
    // }

    // res_t res = full_adder4(100, 10, 0);
    // printf("Result: %i + %i = %i (%i)\n", 100, 10, res.res, res.carry);
    
    res_t res = full_adder8(100, 10, 0);
    printf("Result: %i + %i = %i (%i)\n", 100, 10, res.res, res.carry);
    return 0;
}