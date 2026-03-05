#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

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

int frente(Fila* f){
    return f->back->dado;
}

int tamanho(Fila* f){
    return f->tamanho;
}

void imprimir(Fila* f){
    Node* aux=f->front;
    while(aux !=NULL){
        printf("%d ",aux->dado);
        aux=aux->next;
    }
    printf("\n");
}

bool vazia(Fila* f){
    return f->front==NULL;
}

void inserirElemento(Fila* f, int elem){
    Node* novo = createNode(elem,NULL);
    
    if(vazia(f)){
        f->back=novo;
        f->front=f->back;
        novo->next=NULL;
        f->tamanho++;
    }else{
        f->back->next=novo; 
        f->back=novo;
        f->tamanho++;
    }
}
