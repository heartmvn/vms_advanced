#include <stdio.h>

int main()
{
    unsigned int n; //беззнаковый тип
    int k;
    scanf("%u %d", &n, &k);
    
    unsigned int a = n >> k | (n << (32 - k)); // сдвиг вправо, биты которые "выпали" из правой части, сдвигаются влево на 32 - k битов
    
    printf("%u\n", a);
    
    return 0;
}

