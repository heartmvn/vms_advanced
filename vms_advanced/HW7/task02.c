#include <stdio.h>
#include <stdlib.h>

// Предполагается, что структура tree уже объявлена внешне

// Поиск узла по ключу
tree* findNode(tree *root, int key) {
    if (root == NULL) return NULL;
    if (root->key == key) return root;
    
    tree *leftResult = findNode(root->left, key);
    if (leftResult) return leftResult;

    return findNode(root->right, key);
}

// Основная функция
tree * findBrother(tree *root, int key) {
    tree *node = findNode(root, key);
    if (node == NULL || node->parent == NULL) return NULL;

    if (node->parent->left == node)
        return node->parent->right;
    else if (node->parent->right == node)
        return node->parent->left;

    return NULL;
}

