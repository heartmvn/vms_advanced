#include <stdio.h>
#include <string.h>

#define MAX_LEN 10005

int main() {
    char s1[MAX_LEN] = {0}, s2[MAX_LEN] = {0};

    // Считываем две строки
    if (fgets(s1, MAX_LEN, stdin) == NULL || fgets(s2, MAX_LEN, stdin) == NULL) {
        // Если не удалось считать две строки — выводим 0 0
        printf("0 0\n");
        return 0;
    }

    // Удаляем символ новой строки, если есть
    size_t len1 = strlen(s1);
    if (len1 > 0 && s1[len1 - 1] == '\n') {
        s1[--len1] = '\0';
    }

    size_t len2 = strlen(s2);
    if (len2 > 0 && s2[len2 - 1] == '\n') {
        s2[--len2] = '\0';
    }

    // Поиск длины наибольшего префикса s1, являющегося суффиксом s2
    int prefix_len = 0;
    for (int i = 1; i <= len1 && i <= len2; i++) {
        if (strncmp(s1, s2 + len2 - i, i) == 0) {
            prefix_len = i;
        }
    }

    // Поиск длины наибольшего суффикса s1, являющегося префиксом s2
    int suffix_len = 0;
    for (int i = 1; i <= len1 && i <= len2; i++) {
        if (strncmp(s1 + len1 - i, s2, i) == 0) {
            suffix_len = i;
        }
    }

    // Вывод результата
    printf("%d %d\n", prefix_len, suffix_len);

    return 0;
}

