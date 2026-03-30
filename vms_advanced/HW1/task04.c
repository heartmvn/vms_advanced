#include <stdio.h>

int main()
{
    unsigned int n; //беззнаковый тип
    int k;
    scanf("%u %d", &n, &k);

   
    unsigned int mask = (1U << k) - 1; // Создание маски для K младших битов

   
    unsigned int a = n & mask; // Извлечение K младших битов

    
    printf("%u\n", a);// Выводим результат

    return 0;
}

