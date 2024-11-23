#include "double_to_ieee754.h"
#include <stdint.h>

void double_to_ieee754(double num, char *binary) {
    uint64_t bits = *(uint64_t *)&num;
    for (int i = 63; i >= 0; i--) {
        binary[63 - i] = (bits & ((uint64_t)1 << i)) ? '1' : '0';
    }
    binary[64] = '\0';
}
