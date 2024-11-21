#include <stdio.h>
#include "double_to_ieee754.h"

int main() {
    char binary[65];
    double num = 3.14;

    double_to_ieee754(num, binary);
    printf("IEEE 754 Representation: %s\n", binary);

    return 0;
}
