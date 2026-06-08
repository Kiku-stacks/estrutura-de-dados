#include "playlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SongNode *songCriar(const char *titulo, const char *artista, int duracao)
{
    SongNode *n = (SongNode *)malloc(sizeof(SongNode));

    if (!n) {
        fputs("ERRO: malloc falhou para SongNode.\n", stderr);
        exit(EXIT_FAILURE);
    }

    strncpy(n->titulo,  titulo,  STR_MAX - 1);
    n->titulo[STR_MAX - 1]  = '\0';

    strncpy(n->artista, artista, STR_MAX - 1);
    n->artista[STR_MAX - 1] = '\0';

    n->duracao = duracao;
    n->prox = n;
    n->ant = n;

    return n;
}

DequeNode *dequeNodeCriar(const char *titulo, const char *artista)
{
    DequeNode *n = (DequeNode *)malloc(sizeof(DequeNode));

    if (!n) {
        fputs("ERRO: malloc falhou para DequeNode.\n", stderr);
        exit(EXIT_FAILURE);
    }

    strncpy(n->titulo,  titulo,  STR_MAX - 1);
    n->titulo[STR_MAX - 1]  = '\0';

    strncpy(n->artista, artista, STR_MAX - 1);
    n->artista[STR_MAX - 1] = '\0';

    n->prox = NULL;
    n->ant  = NULL;

    return n;
}
