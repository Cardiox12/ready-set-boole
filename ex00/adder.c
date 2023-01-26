#include <stdio.h>
#include <unistd.h>
#include "bitutils.h"

//                                                       |  Res  | Carry |.....................EMPTY.....................| 
// Result and Carry is encoded in 2 bits unsigned char : |   0   |   0   |   0   |   0   |   0   |   0   |   0   |   0   |

byte_t half_adder(uint32_t a, uint32_t b) {
    return MAKE_RESULT(a ^ b, a & b);
}

// Encode Sum and Carry
// int64_t full_adder(int32_t a, int32_t b) {
//     int32_t sum = ()
// }

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
        puts("");
    }
    return 0;
}