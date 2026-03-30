#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>  // для использования PRIu64

typedef struct list {
    uint64_t address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

uint64_t findMaxBlock(list *head) {
    if (head == NULL) {
        return 0;
    }

    uint64_t maxAddress = head->address;
    size_t maxSize = head->size;

    list *current = head->next;

    while (current != NULL) {
        if (current->size > maxSize) {
            maxSize = current->size;
            maxAddress = current->address;
        }
        current = current->next;
    }

    return maxAddress;
}

int main() {
    // Создание элементов списка
    list *n1 = malloc(sizeof(list));
    list *n2 = malloc(sizeof(list));
    list *n3 = malloc(sizeof(list));

    // Заполнение первого узла
    n1->address = 140525067852320ULL;
    n1->size = 10;
    strcpy(n1->comment, "Block 1");
    n1->next = n2;

    // Заполнение второго узла
    n2->address = 140525067852350ULL;
    n2->size = 30;
    strcpy(n2->comment, "Block 2");
    n2->next = n3;

    // Заполнение третьего узла
    n3->address = 140525067852900ULL;
    n3->size = 100;
    strcpy(n3->comment, "Block 3");
    n3->next = NULL;

    // Вызов функции и вывод результата
    uint64_t result = findMaxBlock(n1);
    printf("Max block address: %" PRIu64 "\n", result);  // Ожидается: 140525067852900

    // Очистка памяти
    free(n1);
    free(n2);
    free(n3);

    return 0;
}

