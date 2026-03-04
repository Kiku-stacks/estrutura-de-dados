#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    Node* front;
    Node* back;
    int tamanho;
} Fila;

void iniciaFila(Fila* f);
void destroiFila(Fila* f);
bool vazia(Fila* f);
int frente(Fila* f);
void remove(Fila* f);
void esvazia(Fila* f);
void insere(Fila* f, int elem);
int tamanho(Fila* f);
void imprimir(Fila* f);

#endif
