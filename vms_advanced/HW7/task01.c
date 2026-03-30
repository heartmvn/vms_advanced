#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Очередь для BFS
typedef struct qnode {
    struct tree *node;
    int hd; // horizontal distance
    struct qnode *next;
} qnode;

qnode* new_qnode(struct tree *n, int hd) {
    qnode *temp = (qnode*)malloc(sizeof(qnode));
    temp->node = n;
    temp->hd = hd;
    temp->next = NULL;
    return temp;
}

typedef struct {
    qnode *front, *rear;
} queue;

void enqueue(queue *q, struct tree *node, int hd) {
    qnode *temp = new_qnode(node, hd);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

qnode* dequeue(queue *q) {
    if (q->front == NULL) return NULL;
    qnode *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    return temp;
}

int is_empty(queue *q) {
    return q->front == NULL;
}

// Узел словаря горизонтальных координат
typedef struct map_node {
    int hd;
    int key;
    struct map_node *next;
} map_node;

void insert_map(map_node **map, int hd, int key) {
    map_node *curr = *map;
    while (curr) {
        if (curr->hd == hd)
            return;
        curr = curr->next;
    }
    map_node *new_node = (map_node*)malloc(sizeof(map_node));
    new_node->hd = hd;
    new_node->key = key;
    new_node->next = *map;
    *map = new_node;
}

void print_map(map_node *map) {
    int count = 0;
    map_node *curr = map;
    while (curr) {
        count++;
        curr = curr->next;
    }

    int *hds = (int*)malloc(sizeof(int) * count);
    int *keys = (int*)malloc(sizeof(int) * count);
    curr = map;
    for (int i = 0; i < count; i++) {
        hds[i] = curr->hd;
        keys[i] = curr->key;
        curr = curr->next;
    }

    for (int i = 1; i < count; i++) {
        int hd = hds[i], key = keys[i];
        int j = i - 1;
        while (j >= 0 && hds[j] > hd) {
            hds[j+1] = hds[j];
            keys[j+1] = keys[j];
            j--;
        }
        hds[j+1] = hd;
        keys[j+1] = key;
    }

    for (int i = 0; i < count; i++) {
        printf("%d", keys[i]);
        if (i != count - 1) printf(" ");
    }
    printf("\n");

    free(hds);
    free(keys);
}

void btUpView(struct tree *root) {
    if (!root) return;

    queue q = {NULL, NULL};
    enqueue(&q, root, 0);

    map_node *map = NULL;

    while (!is_empty(&q)) {
        qnode *temp = dequeue(&q);
        struct tree *node = temp->node;
        int hd = temp->hd;
        free(temp);

        insert_map(&map, hd, node->key);

        if (node->left)
            enqueue(&q, node->left, hd - 1);
        if (node->right)
            enqueue(&q, node->right, hd + 1);
    }

    print_map(map);

    while (map) {
        map_node *tmp = map;
        map = map->next;
        free(tmp);
    }
}

