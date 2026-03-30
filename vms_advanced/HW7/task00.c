#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 20
#define MAX_INPUT_LEN 1000

struct list {
    char word[MAX_WORD_LEN];
    struct list *next;
};

// Добавление слова в конец списка
void add_to_list(struct list **head, const char *word) {
    struct list *new_node = (struct list *)malloc(sizeof(struct list));
    strncpy(new_node->word, word, MAX_WORD_LEN - 1);
    new_node->word[MAX_WORD_LEN - 1] = '\0';
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct list *current = *head;
        while (current->next != NULL)
            current = current->next;
        current->next = new_node;
    }
}

// Меняет местами значения двух узлов списка
void swap_elements(struct list *a, struct list *b) {
    char temp[MAX_WORD_LEN];
    strcpy(temp, a->word);
    strcpy(a->word, b->word);
    strcpy(b->word, temp);
}

// Сортировка списка пузырьком по алфавиту
void sort_list(struct list *head) {
    if (head == NULL) return;
    int swapped;
    struct list *ptr;
    do {
        swapped = 0;
        ptr = head;
        while (ptr->next != NULL) {
            if (strcmp(ptr->word, ptr->next->word) > 0) {
                swap_elements(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
    } while (swapped);
}

// Вывод списка
void print_list(struct list *head) {
    struct list *current = head;
    while (current != NULL) {
        printf("%s", current->word);
        if (current->next != NULL) {
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
}

// Удаление списка
void delete_list(struct list *head) {
    struct list *current = head;
    while (current != NULL) {
        struct list *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    char input[MAX_INPUT_LEN];
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 1;
    }

    // Удаляем точку
    char *dot = strchr(input, '.');
    if (dot != NULL) *dot = '\0';

    struct list *head = NULL;

    // Разбиение на слова
    char *token = strtok(input, " ");
    while (token != NULL) {
        add_to_list(&head, token);
        token = strtok(NULL, " ");
    }

    // Сортировка и вывод
    sort_list(head);
    print_list(head);

    // Освобождение памяти
    delete_list(head);

    return 0;
}

