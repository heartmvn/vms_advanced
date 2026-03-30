#include <stdio.h>
#include <string.h>

#define MAX_LEN 110

int main() {
    char number[MAX_LEN];
    int found[1000] = {0};  // От 0 до 999
    int count = 0;

    // Ввод числа как строки
    scanf("%s", number);
    int len = strlen(number);

    // Перебор всех троек цифр (в порядке следования)
    for (int i = 0; i < len - 2; i++) {
        for (int j = i + 1; j < len - 1; j++) {
            for (int k = j + 1; k < len; k++) {
                // Преобразуем три символа в число
                int d1 = number[i] - '0';
                int d2 = number[j] - '0';
                int d3 = number[k] - '0';

                if (d1 == 0) continue; // Пропускаем, если число начинается с 0

                int num = d1 * 100 + d2 * 10 + d3;

                if (!found[num]) {
                    found[num] = 1;
                    count++;
                }
            }
        }
    }

    printf("%d\n", count);
    return 0;
}

