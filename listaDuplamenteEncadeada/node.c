#include "node.h"
#include <stdlib.h>
#include <stdio.h>

Node* createNode(int elem, Node* ptr) {
    Node* novo = (Node*) malloc(sizeof(Node));
    if (novo == NULL) {
        printf("Erro: memoria insuficiente ao criar no.\n");
        exit(1);
    }
    novo->dado = elem;
    novo->next = ptr;
    novo->prev = NULL;
    return novo;
}
