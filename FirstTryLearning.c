#include<stdio.h>
#include<stdint.h>
  
typedef union {
    float f;
    struct{
        unsigned int mantissa : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;    
    }raw;
}convFloat;

int main()
{
    convFloat var;
    uint32_t x;
    var.f = -2.25;
    x = var.raw.sign << 31;
    x = x | (var.raw.exponent << 23);
    x = x | (var.raw.mantissa);
    printf("%X\n", x);
    return 0;
}
