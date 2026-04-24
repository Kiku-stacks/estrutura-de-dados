#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

#include "node.h"
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    Node* inicio;
    Node* fim;
    int tamanhoLista;
}ListaEncadeada;

// Protótipos das funções
void init_lista(ListaEncadeada* lista);
void esvazia_lista(ListaEncadeada* lista);
bool lista_vazia(ListaEncadeada* lista);
void add_item_end(ListaEncadeada* lista, int item);
void add_item_beginning(ListaEncadeada* lista, int item);
void add_item_pos(ListaEncadeada* lista, int item, int posicao);
void remove_item_beginning(ListaEncadeada* lista);
void remove_item_end(ListaEncadeada* lista);
void remove_item_pos(ListaEncadeada* lista, int posicao);
void remove_item(ListaEncadeada* lista, int item);
void print_list(ListaEncadeada* lista);
void get_min_max(ListaEncadeada* lista);
void find_item(ListaEncadeada* lista, int item);
void modify_item(ListaEncadeada* lista, int posicao, int item);
void ordenar(ListaEncadeada* lista);
void concatenarListas(ListaEncadeada* lista1, ListaEncadeada* lista2);
void mesclarListas(ListaEncadeada* lista1, ListaEncadeada* lista2);

#endif
