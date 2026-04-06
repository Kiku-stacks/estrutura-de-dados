#include "filaCircular.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void initFila(FilaCircular *f, int n){
    f->ptrFila = (int*)malloc(n * sizeof(int));

    if(f->ptrFila == NULL){
        printf("Erro ao iniciar a fila !!!\n");
        exit(1);
    }

    f->maximo = n;
    f->tamanho = 0;
    f->primeiro = 0;
    f->ultimo = -1;

    printf("Fila Circular inicializada com sucesso !\n");
}

bool vazia(FilaCircular *f){
    return f->tamanho == 0;
}

bool cheia(FilaCircular *f){
    return f->tamanho == f->maximo;
}

int inicio(FilaCircular *f){
    if(vazia(f)){
        printf("A fila está vazia e não é possivel acessar o inicio");
    }else{
        return f->ptrFila[f->primeiro];
    }
}

int fim(FilaCircular *f){
       if(vazia(f)){
        printf("A fila está vazia e não é possivel acessar o fim");
    }else{
        return f->ptrFila[f->ultimo];
    }
}

void inserir(FilaCircular *f, int item){
    int proximaPosi = (f->ultimo + 1) % (f->maximo);

    if(cheia(f)){
        printf("A fila está cheia, substituindo o elemento %d pelo %d\n",f->ptrFila[f->primeiro],item);
        f->primeiro = (f->primeiro + 1) % (f->maximo);
    }else{
        f->tamanho++;
    }
    
    f->ptrFila[proximaPosi] = item;
    printf("Elemento %d inserido com sucesso!\n",item);
    f->ultimo = proximaPosi;
} 

#include <stdio.h>
#include <stdbool.h>

bool remover(FilaCircular *f, int *elem){
    if(elem == NULL){
        printf("Ponteiro invalido\n");
        return false;
    }

    if(vazia(f)){
        printf("Nao e possivel remover: fila vazia!\n");
        return false;
    }

    *elem = f->ptrFila[f->primeiro];         
    f->primeiro = (f->primeiro + 1) % f->maximo;
    f->tamanho--;                          

    printf("Elemento %d removido com sucesso!\n", *elem); 
    return true;                               
}

void apagarFila(FilaCircular *f){
    for(int i = 0; i < f->maximo; i++){
        f->ptrFila[i] = -1;
    }
    f->tamanho = 0;
    f->primeiro = 0;
    f->ultimo = -1;
}

void destroyFila(FilaCircular *f){
    if(f->ptrFila != NULL){
        free(f->ptrFila);
        f->ptrFila = NULL;
    }
    f->maximo = 0;
    f->tamanho = 0;
    f->primeiro = 0;
    f->ultimo = -1;
}

int PosicaoElemento(FilaCircular *f, int item){
    for(int i = 0; i < f->tamanho; i++){
        int posi = (f->primeiro + i) % (f->maximo);
        if(f->ptrFila[posi] == item){
            return posi;
        }
    }
    return -1;
}

void imprimir(FilaCircular *f){
    if(vazia(f)){
        printf("A fila esta vazia e nao ha elementos a ser impresso!\n");
    }else{
        printf("---Fila circular---\n");
        for(int i = 0; i < f->tamanho; i++){
            int posi = (f->primeiro + i) % (f->maximo);
            printf("%d ",f->ptrFila[posi]);
        }
        printf("\n");
    }
}
    
