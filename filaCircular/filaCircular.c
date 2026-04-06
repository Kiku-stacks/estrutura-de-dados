#include "filaCircular.h"
#include <stdio.h>
#include <stdlib.h>

void initFila(FilaCircular *f, int n){
    f->ptrFila = (int*)malloc(n * sizeof(int))

    if(f->ptrFila == NULL){
        printf("Erro ao iniciar a fila !!!\n")
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
    return f->ptrFila[f->primeiro];
}

int fim(FilaCircular *f){
    return f->ptrFila[f->ultimo];
}

void inserir(FilaCircular *f, int item){
    int proximaPosi = (f->ultimo + 1) % (f->maximo);

    if(f->tamanho == f->maximo){
        printf("A fila está cheia, substiuindo o elemento %d pelo %d\n",f->ptrFila[f->primeiro],item);
        f->primeiro = (f->primeiro + 1) % (f->maximo);
    }else{
        f->tamanho++;
    }
    
    f->ptrFila[proximaPosi] = item;
    f->ultimo = proximaPosi;
} 

void remover(FilaCircular *f){
    if(vazia(f)){
        printf("Nao e possivel remover o elemento, pois a fila ja esta vazia !\n");
    }else{
        f->ptrFila[f->primeiro] = -1;
        f->primeiro = (f->primeiro + 1) % (f->maximo);
        f->tamanho--;
    }
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
    f->ultimo = 0;
}
