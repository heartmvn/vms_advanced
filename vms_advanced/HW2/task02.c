#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct list {
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

size_t totalMemoryUsage(list *head) {
    size_t total = 0;
    while (head) {
        total += head->size;
        head = head->next;
    }
    return total;
}

int main() {
    list *n1 = malloc(sizeof(list));
    list *n2 = malloc(sizeof(list));
    list *n3 = malloc(sizeof(list));

    n1->address = (void*)(uintptr_t)140525067852320ULL;
    n1->size = 10;
    strcpy(n1->comment, "Block 1");
    n1->next = n2;

    n2->address = (void*)(uintptr_t)140525067852350ULL;
    n2->size = 30;
    strcpy(n2->comment, "Block 2");
    n2->next = n3;

    n3->address = (void*)(uintptr_t)140525067852900ULL;
    n3->size = 100;
    strcpy(n3->comment, "Block 3");
    n3->next = NULL;

    printf("%zu\n", totalMemoryUsage(n1)); // Ожидаем 140

    free(n1);
    free(n2);
    free(n3);

    return 0;
}

