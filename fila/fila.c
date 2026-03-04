#include "pilha.h"
#include <stdio.h>

void iniciarFila(Fila* f){
    f->front=NULL;
    f->back=NULL;
    f->tamanho=0;
}

void destruirFila(Fila* f){
    Node* aux = f->front;
    while(f->front !=NULL){
        aux = f->front;
        free(aux);
        f->front = aux->next;
        f->tamanho--;
    }
    f->back=NULL;
}

void removerElemento(Fila* f, int *elemento){
    Node* aux = f->front;
    f->front=aux->next;
    f->tamanho--;
    *elemento=aux->dado;
    free(aux);
    
    if(f->front==NULL)
        f->back==NULL;

}

void frente(Fila* f){
    return f->back;
}

void tamanho(Fila* f){
    return f->tamanho;
}

void inserirElemento(Fila* f, int elem){
    Node* novo = createNode(elem,NULL);
}

void imprimir(Fila* p){
    Node* aux=f->front;
    while(f->front!=NULL){
        f->front=aux->next;
        printf("%d ",aux->dado);
    }
}
