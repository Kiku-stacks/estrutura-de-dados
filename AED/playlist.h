#ifndef NODE_H
#define NODE_H

#define MAX_CACHE  5
#define STR_MAX   100

typedef struct SongNode {
    char titulo[STR_MAX];
    char artista[STR_MAX];
    int  duracao;
    struct SongNode *prox;
    struct SongNode *ant;
} SongNode;

typedef struct {
    SongNode *cabeca;
    SongNode *atual;
    int tamanho;
} Playlist;

typedef struct DequeNode {
    char titulo[STR_MAX];
    char artista[STR_MAX];
    struct DequeNode *prox;
    struct DequeNode *ant;
} DequeNode;

typedef struct {
    DequeNode *frente;
    DequeNode *fundo;
    int tamanho;
} Deque;

#endif
