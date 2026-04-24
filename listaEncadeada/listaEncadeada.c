#include "listaEncadeada.h"
#include <stdio.h>
#include <stdbool.h>

void init_lista(ListaEncadeada* lista){
    lista->fim = NULL;
    lista->inicio = NULL;
    lista->tamanhoLista = 0;
}



void add_item_end(ListaEncadeada* lista, int item){
    Node* novo = createNode(item,NULL);

    if(tamanhoLista==0){
        lista->inicio=novo;
        lista->fim=novo;
    }else{
        novo->next=fim;
    }
}
