#include <stdio.h>

int main() {
    unsigned int n;
    int k;

    scanf("%u %d", &n, &k);

    unsigned int max_n = 0;

    
    for (int i = 0; i <= 32 - k; i++) // перебираем все возможные позиции для извлечения K битов
    {
        unsigned int x = (n >> i) & ((1U << k) - 1);// сдвигаем n вправо на i битов, чтобы получить k битов на правой части
        
        if (x > max_n) // проверяем, если это число больше текущего максимума 
        {
            max_n = x;
        }
    }

    printf("%u\n", max_n);

    return 0;
}

