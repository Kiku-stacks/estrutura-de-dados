#include "listaEncadeada.h"
#include <stdlib.h>

void init_lista(ListaEncadeada* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanhoLista = 0;
}

bool lista_vazia(ListaEncadeada* lista) {
    return lista->tamanhoLista == 0;
}

void esvazia_lista(ListaEncadeada* lista) {
    Node* atual = lista->inicio;
    while (atual != NULL) {
        Node* proximo = atual->next;
        free(atual);
        atual = proximo;
    }
    lista->inicio= NULL;
    lista->fim=NULL;
    lista->tamanhoLista = 0;
    printf("Lista esvaziada com sucesso.\n");
}

void add_item_end(ListaEncadeada* lista, int item) {
    Node* novo = createNode(item, NULL);
    if (lista_vazia(lista)) {
        lista->inicio = novo;
    } else {
        lista->fim->next = novo;
    }
    lista->fim = novo;
    lista->tamanhoLista++;
    printf("Elemento %d inserido no fim.\n", item);
}

void add_item_beginning(ListaEncadeada* lista, int item) {
    Node* novo = createNode(item, lista->inicio);
    lista->inicio = novo;
    if (lista->tamanhoLista == 0) {
        lista->fim = novo;
    }
    lista->tamanhoLista++;
    printf("Elemento %d inserido no inicio.\n", item);
}

void add_item_pos(ListaEncadeada* lista, int item, int posicao) {
    if (posicao < 0 || posicao > lista->tamanhoLista) {
        printf("Posicao invalida! A lista tem %d elemento(s). Posicoes validas: 0 a %d.\n",
                lista->tamanhoLista, lista->tamanhoLista);
        return;
    }
    if (posicao == 0) {
        add_item_beginning(lista, item);
        return;
    }
    if (posicao == lista->tamanhoLista) {
        add_item_end(lista, item);
        return;
    }
    Node* atual = lista->inicio;
    for (int i = 0; i < posicao - 1; i++) {
        atual = atual->next;
    }
    Node* novo = createNode(item, atual->next);
    atual->next = novo;
    lista->tamanhoLista++;
    printf("Elemento %d inserido na posicao %d.\n", item, posicao);
}

void remove_item_beginning(ListaEncadeada* lista) {
    if (lista_vazia(lista)) {
        printf("Lista vazia! Nao e possivel remover.\n");
        return;
    }
    Node* alvo = lista->inicio;
    printf("Elemento %d removido do inicio.\n", alvo->dado);
    lista->inicio = alvo->next;
    if (lista->inicio == NULL) {
        lista->fim = NULL;
    }
    free(alvo);
    lista->tamanhoLista--;
}

void remove_item_end(ListaEncadeada* lista) {
    if (lista_vazia(lista)) {
        printf("Lista vazia! Nao e possivel remover.\n");
        return;
    }
    Node* alvo = lista->fim;
    printf("Elemento %d removido do fim.\n", alvo->dado);
    if (lista->tamanhoLista == 1) {
        free(alvo);
        lista->inicio = NULL;
        lista->fim    = NULL;
    } else {
        Node* atual = lista->inicio;
        while (atual->next != alvo) {
            atual = atual->next;
        }
        atual->next = NULL;
        lista->fim  = atual;
        free(alvo);
    }
    lista->tamanhoLista--;
}

void remove_item_pos(ListaEncadeada* lista, int posicao) {
    if (lista_vazia(lista)) {
        printf("Lista vazia! Nao e possivel remover.\n");
        return;
    }
    if (posicao < 0 || posicao >= lista->tamanhoLista) {
        printf("Posicao invalida! A lista tem %d elemento(s). Posicoes validas: 0 a %d.\n",
               lista->tamanhoLista, lista->tamanhoLista - 1);
        return;
    }
    if (posicao == 0) {
        remove_item_beginning(lista);
        return;
    }
    if (posicao == lista->tamanhoLista - 1) {
        remove_item_end(lista);
        return;
    }
    Node* atual = lista->inicio;
    for (int i = 0; i < posicao - 1; i++) {
        atual = atual->next;
    }
    Node* alvo = atual->next;
    atual->next = alvo->next;
    printf("Elemento %d removido da posicao %d.\n", alvo->dado, posicao);
    free(alvo);
    lista->tamanhoLista--;
}

void remove_item(ListaEncadeada* lista, int item) {
    if (lista_vazia(lista)) {
        printf("Lista vazia! Nao e possivel remover.\n");
        return;
    }
    Node* atual=lista->inicio;
    Node* anterior = NULL;
    while (atual != NULL) {
        if (atual->dado == item) {
            if (anterior == NULL) {
                lista->inicio = atual->next;
            } else {
                anterior->next = atual->next;
            }
            if (atual->next == NULL) {
                lista->fim = anterior;
            }
            printf("Elemento %d removido.\n", item);
            free(atual);
            lista->tamanhoLista--;
            return;
        }
        anterior = atual;
        atual    = atual->next;
    }
    printf("Elemento %d nao encontrado na lista.\n", item);
}

void print_list(ListaEncadeada* lista) {
    if (lista_vazia(lista)) {
        printf("Lista vazia!\n");
        return;
    }
    printf("---Lista: (%d elemento(s)): ", lista->tamanhoLista);
    Node* atual = lista->inicio;
    while (atual != NULL) {
        printf("[%d]", atual->dado);
        if (atual->next != NULL) printf(" -> ");
        atual = atual->next;
    }
    printf("\n");
}

void find_item(ListaEncadeada* lista, int item) {
    if (lista_vazia(lista)) {
        printf("Lista vazia!\n");
        return;
    }
    Node* atual = lista->inicio;
    int posicao = 0;
    bool encontrado = false;
    while (atual != NULL) {
        if (atual->dado == item) {
            printf("Elemento %d encontrado na posicao %d.\n", item, posicao);
            encontrado = true;
            break;
        }
        atual = atual->next;
        posicao++;
    }
    if (!encontrado) {
        printf("Elemento %d nao encontrado na lista.\n", item);
    }
}

void get_min_max(ListaEncadeada* lista) {
    if (lista_vazia(lista)) {
        printf("Lista vazia!\n");
        return;
    }
    int min = lista->inicio->dado;
    int max = lista->inicio->dado;
    Node* atual = lista->inicio->next;
    while (atual != NULL) {
        if (atual->dado < min) min = atual->dado;
        if (atual->dado > max) max = atual->dado;
        atual = atual->next;
    }
    printf("Minimo: %d | Maximo: %d\n", min, max);
}

void modify_item(ListaEncadeada* lista, int posicao, int item) {
    if (lista_vazia(lista)) {
        printf("Lista vazia!\n");
        return;
    }
    if (posicao < 0 || posicao >= lista->tamanhoLista) {
        printf("Posicao invalida! A lista tem %d elemento(s). Posicoes validas: 0 a %d.\n",
               lista->tamanhoLista, lista->tamanhoLista - 1);
        return;
    }
    Node* atual = lista->inicio;
    for (int i = 0; i < posicao; i++) {
        atual = atual->next;
    }
    printf("Elemento na posicao %d alterado de %d para %d.\n", posicao, atual->dado, item);
    atual->dado = item;
}

void ordenar(ListaEncadeada* lista) {
    if (lista_vazia(lista) || lista->tamanhoLista == 1) {
        printf("Lista ja esta ordenada.\n");
        return;
    }
    Node* i = lista->inicio;
    while (i != NULL) {
        Node* minimo = i;
        Node* j = i->next;
        while (j != NULL) {
            if (j->dado < minimo->dado) {
                minimo = j;
            }
            j = j->next;
        }
        if (minimo != i) {
            int aux = i->dado;
            i->dado = minimo->dado;
            minimo->dado = aux;
        }
        i = i->next;
    }
    printf("Lista ordenada com sucesso.\n");
    print_list(lista);
}

void concatenarListas(ListaEncadeada* lista1, ListaEncadeada* lista2) {
    if (lista_vazia(lista2)) {
        printf("Lista 2 esta vazia. Nada a concatenar.\n");
        return;
    }
    Node* atual = lista2->inicio;
    while (atual != NULL) {
        add_item_end(lista1, atual->dado);
        atual = atual->next;
    }
    printf("Listas concatenadas com sucesso. Lista 1 agora tem %d elemento(s).\n",
           lista1->tamanhoLista);
}

void mesclarListas(ListaEncadeada* lista1, ListaEncadeada* lista2) {
    if (lista_vazia(lista1) && lista_vazia(lista2)) {
        printf("Ambas as listas estao vazias. Nada a mesclar.\n");
        return;
    }

    concatenarListas(lista1, lista2);
    ordenar(lista1);

    printf("Listas mescladas com sucesso. A lista agora tem %d elemento(s).\n",
           lista1->tamanhoLista);
}
