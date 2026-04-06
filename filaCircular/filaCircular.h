#ifndef FILACIRCULAR_H
#define FILACIRCULAR_H

#include <stdbool.h>

typedef struct {
    int *ptrFila;
    int primeiro;
    int ultimo;
    int tamanho;
    int maximo;
}FilaCircular;

void initFila(FilaCircular *f, int n);
void destroyFila(FilaCircular *f);
bool vazia(FilaCircular *f);
bool cheia(FilaCircular *f);
int PosicaoElemento(FilaCircular *f, int item);
int inicio(FilaCircular *f);
int fim(FilaCircular *f);
bool remover(FilaCircular *f, int *elem);
void apagarFila(FilaCircular *f);
void inserir(FilaCircular *f, int item);
void imprimir(FilaCircular *f);

#endif
