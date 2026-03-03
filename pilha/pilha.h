#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>
#include "node.h"

typedef struct {
    Node* topo;
    int tamanho;
} Pilha;

void initPilha(Pilha* p);
void destroyPilha(Pilha* p);
bool isEmpty(Pilha* p);
void push(Pilha* p, int elem);
void pop(Pilha* p, int *elemento);
Node* top(Pilha* p);
int size(Pilha* p);
void print(Pilha* p);

#endif 
