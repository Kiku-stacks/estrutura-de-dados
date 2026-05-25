#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    int linha;
    int coluna;
    int valor;
    struct Node *proxima_coluna;
    struct Node *proxima_linha;
} Node;
 
typedef struct {
    int total_linhas;
    int total_colunas;
    Node **linhas;
    Node **colunas;
} MatrizEsparsa;
 
MatrizEsparsa* criar_matriz(int l, int c) {
    MatrizEsparsa *m = (MatrizEsparsa*) malloc(sizeof(MatrizEsparsa));
    m->total_linhas = l;
    m->total_colunas = c;
 
    m->linhas  = (Node**) malloc(l * sizeof(Node*));
    m->colunas = (Node**) malloc(c * sizeof(Node*));
 
    for (int i = 0; i < l; i++) m->linhas[i]  = NULL;
    for (int i = 0; i < c; i++) m->colunas[i] = NULL;
 
    return m;
}
 
void inserir_elemento(MatrizEsparsa *m, int l, int c, int valor) {
    Node *novo = (Node*) malloc(sizeof(Node));
    novo->linha   = l;
    novo->coluna  = c;
    novo->valor   = valor;
    novo->proxima_linha   = NULL;
    novo->proxima_coluna  = NULL;
 
    if (m->linhas[l] == NULL) {
        m->linhas[l] = novo;
        novo->proxima_linha = novo;
    } else {
        Node *atual = m->linhas[l];
        while (atual->proxima_linha != m->linhas[l]) {
            atual = atual->proxima_linha;
        }
        atual->proxima_linha = novo;
        novo->proxima_linha  = m->linhas[l];
    }
 
    if (m->colunas[c] == NULL) {
        m->colunas[c] = novo;
        novo->proxima_coluna = novo;
    } else {
        Node *atual = m->colunas[c];
        while (atual->proxima_coluna != m->colunas[c]) {
            atual = atual->proxima_coluna;
        }
        atual->proxima_coluna = novo;
        novo->proxima_coluna  = m->colunas[c];
    }
}

void imprimir_matriz(MatrizEsparsa *m) {
    printf("\nMatriz %dx%d:\n", m->total_linhas, m->total_colunas);
 
    for (int i = 0; i < m->total_linhas; i++) {
        for (int j = 0; j < m->total_colunas; j++) {
            int valor = 0;
 
            if (m->linhas[i] != NULL) {
                Node *atual = m->linhas[i];
                do {
                    if (atual->coluna == j) {
                        valor = atual->valor;
                        break;
                    }
                    atual = atual->proxima_linha;
                } while (atual != m->linhas[i]);
            }
 
            printf("%4d", valor);
        }
        printf("\n");
    }
}
 
void liberar_matriz(MatrizEsparsa *m) {
    for (int i = 0; i < m->total_linhas; i++) {
        if (m->linhas[i] == NULL) continue;
 
        Node *inicio = m->linhas[i];
        Node *atual  = inicio;
        Node *proximo;
 
        do {
            proximo = atual->proxima_linha;
            free(atual);
            atual = proximo;
        } while (atual != inicio);
    }
 
    free(m->linhas);
    free(m->colunas);
    free(m);
}
 
int main() {
    FILE *arquivo = fopen("matriz.txt", "r");
    if (arquivo == NULL) {
        printf("Erro: nao foi possivel abrir o arquivo matriz.txt\n");
        return 1;
    }
 
    int total_linhas, total_colunas;
    fscanf(arquivo, "%d %d", &total_linhas, &total_colunas);
 
    MatrizEsparsa *m = criar_matriz(total_linhas, total_colunas);
 
    int l, c, valor;
    while (fscanf(arquivo, "%d %d %d", &l, &c, &valor) == 3) {
        inserir_elemento(m, l, c, valor);
    }
 
    fclose(arquivo);
 
    imprimir_matriz(m);
 
    liberar_matriz(m);
 
    return 0;
}
 
