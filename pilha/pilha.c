#include "pilha.h"
#include <stdio.h>

void initPilha(Pilha* p){
    p->topo = NULL;
    p->tamanho = 0;
}

void destroyPilha(Pilha* p){
    Node* aux;
    while(p->topo !=NULL){
        aux = p->topo;
        p->topo = aux->next;
        free(aux);
    }
    p->tamanho = 0;
}

bool isEmpty(Pilha* p){
    return p->topo == NULL;
}

void push(Pilha* p, int elem){
    Node* novo=createNode(elem,NULL);
    novo->next = p->topo;
    p->topo = novo;
    p->tamanho++;
}

void pop(Pilha* p, int *elemento){
    Node* aux;
    aux = p->topo;
    p->topo = aux->next;
    p->tamanho--;
    *elemento=aux->dado;
    free(aux);
}

Node* top(Pilha* p){
    return p->topo;
}

int size(Pilha* p){
    return p->tamanho;
}

void print(Pilha* p){
    Node* aux = p->topo;
    while(aux !=NULL){
        printf("%d\n",aux->dado);
        aux = aux->next;
    }
}
