#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdbool.h>
#include "node.h"

typedef struct {
    Node* front;
    Node* back;
    int tamanho;
}Fila;

void iniciarFila(Fila* f);
void destruirFila(Fila* f);
bool vazia(Fila* f);
int frente(Fila* f);
void removerElemento(Fila* f, int *elemento);
void esvazia(Fila* f);
void inserirElemento(Fila* f, int elem);
int tamanho(Fila* f);
void imprimir(Fila* f);

#endif
