#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void iniciarFila(Fila* f){
    f->front=NULL;
    f->back=NULL;
    f->tamanho=0;

    printf("Fila inicializada com sucesso!\n");
}

void destruirFila(Fila* f){
    Node* aux;
    while(f->front !=NULL){
        aux = f->front;
        f->front = aux->next;
        free(aux);
        f->tamanho--;
    }
    f->back=NULL;

    printf("Fila destruida com sucesso\n");
}

void removerElemento(Fila* f, int *elemento){ //teste de fila vazia
    Node* aux = f->front;
    if(f->front==NULL){
        f->back==NULL;
    }else{
        f->front=aux->next;
        f->tamanho--;
        *elemento=aux->dado;
        free(aux);
    }
    

    printf("Elemento %d removido com sucesso\n\n",*elemento);

}

int frente(Fila* f){
    return f->front->dado;
}

int tamanho(Fila* f){
    return f->tamanho;
}

void imprimir(Fila* f){
    Node* aux=f->front;
    printf("------MINHA FILA------\n\n");
    while(aux !=NULL){
        printf("%d-> ",aux->dado);
        aux=aux->next;
    }
    printf("\n\n");
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
        printf("Elemento %d inserido com sucesso\n",elem);
    }else{
        f->back->next=novo; 
        f->back=novo;
        f->tamanho++;
        printf("Elemento %d inserido com sucesso\n",elem);
    }
}
