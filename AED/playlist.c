#include "playlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void playlistInit(Playlist *pl)
{
    pl->cabeca  = NULL;
    pl->atual   = NULL;
    pl->tamanho = 0;
}

void playlistAdicionar(Playlist *pl, const char *titulo,
                        char *artista, int duracao)
{
    SongNode *novo = songCriar(titulo, artista, duracao);

    if (!pl->cabeca) {
        pl->cabeca = pl->atual = novo;
    } else {
        SongNode *cauda = pl->cabeca->ant;

        cauda->prox = novo;
        novo->ant = cauda;
        novo->prox = pl->cabeca;
        pl->cabeca->ant = novo;
    }

    pl->tamanho++;
    printf("  [+] \"%s\" adicionada a playlist.\n", titulo);
}

SongNode *playlistProxima(Playlist *pl)
{
    if (!pl->atual) return NULL;
    pl->atual = pl->atual->prox;
    return pl->atual;
}

SongNode *playlistAnterior(Playlist *pl)
{
    if (!pl->atual) return NULL;
    pl->atual = pl->atual->ant;
    return pl->atual;
}

SongNode *playlistBuscar(Playlist *pl, const char *titulo)
{
    if (!pl->cabeca) return NULL;

    SongNode *n = pl->cabeca;
    do {
        if (strcmp(n->titulo, titulo) == 0) return n;
        n = n->prox;
    } while (n != pl->cabeca);

    return NULL;
}

int playlistRemover(Playlist *pl, const char *titulo)
{
    SongNode *alvo = playlistBuscar(pl, titulo);
    if (!alvo) return 0;

    if (pl->tamanho == 1) {
        free(alvo);
        pl->cabeca  = NULL;
        pl->atual   = NULL;
        pl->tamanho = 0;
        return 1;
    }

    alvo->ant->prox = alvo->prox;
    alvo->prox->ant = alvo->ant;

    if (pl->cabeca == alvo) pl->cabeca = alvo->prox;
    if (pl->atual  == alvo) pl->atual  = alvo->prox;

    free(alvo);
    pl->tamanho--;
    return 1;
}

void playlistExibir(const Playlist *pl)
{
    int i;

    if (!pl->cabeca) {
        puts("  Playlist vazia.");
        return;
    }

    printf("\n  %-4s  %-32s  %-22s  %s\n", "No.", "Titulo", "Artista", "Dur.");
    printf("  ");
    for (i = 0; i < 66; i++) putchar('-');
    putchar('\n');

    SongNode *n = pl->cabeca;
    i = 1;
    do {
        int m = n->duracao / 60;
        int s = n->duracao % 60;
        const char *marca = (n == pl->atual) ? "  << ATUAL" : "";
        printf("  %-4d  %-32s  %-22s  %02d:%02d%s\n",
               i++, n->titulo, n->artista, m, s, marca);
        n = n->prox;
    } while (n != pl->cabeca);
}

void playlistLiberar(Playlist *pl)
{
    if (!pl->cabeca) return;

    SongNode *cauda = pl->cabeca->ant;
    cauda->prox = NULL;

    SongNode *n = pl->cabeca;
    while (n) {
        SongNode *prox = n->prox;
        free(n);
        n = prox;
    }

    pl->cabeca  = NULL;
    pl->atual   = NULL;
    pl->tamanho = 0;
}

void dequeInit(Deque *dq)
{
    dq->frente  = NULL;
    dq->fundo   = NULL;
    dq->tamanho = 0;
}

void dequePushFrente(Deque *dq, const char *titulo, const char *artista)
{
    DequeNode *novo = dequeNodeCriar(titulo, artista);

    if (!dq->frente) {
        dq->frente = dq->fundo = novo;
    } else {
        novo->prox      = dq->frente;
        dq->frente->ant = novo;
        dq->frente      = novo;
    }
    dq->tamanho++;

    if (dq->tamanho > MAX_CACHE) {
        DequeNode *desc = dq->fundo;
        printf("  [-] Cache cheio -- descartando do fundo: \"%s\"\n", desc->titulo);

        if (dq->fundo->ant) {
            dq->fundo       = dq->fundo->ant;
            dq->fundo->prox = NULL;
        } else {
            dq->frente = dq->fundo = NULL;
        }
        free(desc);
        dq->tamanho--;
    }
}

void dequePushFundo(Deque *dq, const char *titulo, const char *artista)
{
    DequeNode *novo = dequeNodeCriar(titulo, artista);

    if (!dq->fundo) {
        dq->frente = dq->fundo = novo;
    } else {
        novo->ant       = dq->fundo;
        dq->fundo->prox = novo;
        dq->fundo       = novo;
    }
    dq->tamanho++;

    if (dq->tamanho > MAX_CACHE) {
        DequeNode *desc = dq->frente;
        printf("  [-] Cache cheio -- descartando da frente: \"%s\"\n", desc->titulo);

        if (dq->frente->prox) {
            dq->frente      = dq->frente->prox;
            dq->frente->ant = NULL;
        } else {
            dq->frente = dq->fundo = NULL;
        }
        free(desc);
        dq->tamanho--;
    }
}

DequeNode *dequePopFrente(Deque *dq)
{
    if (!dq->frente) return NULL;

    DequeNode *n = dq->frente;

    if (dq->frente == dq->fundo) {
        dq->frente = dq->fundo = NULL;
    } else {
        dq->frente      = dq->frente->prox;
        dq->frente->ant = NULL;
    }

    n->prox = n->ant = NULL;
    dq->tamanho--;
    return n;
}

DequeNode *dequePopFundo(Deque *dq)
{
    if (!dq->fundo) return NULL;

    DequeNode *n = dq->fundo;

    if (dq->frente == dq->fundo) {
        dq->frente = dq->fundo = NULL;
    } else {
        dq->fundo       = dq->fundo->ant;
        dq->fundo->prox = NULL;
    }

    n->prox = n->ant = NULL;
    dq->tamanho--;
    return n;
}

void dequeExibir(const Deque *dq)
{
    int i;

    if (!dq->frente) {
        puts("  Cache vazio.");
        return;
    }

    printf("\n  Cache -- mais recente -> mais antiga  [%d/%d]\n",
           dq->tamanho, MAX_CACHE);
    printf("  ");
    for (i = 0; i < 50; i++) putchar('-');
    putchar('\n');

    DequeNode *n = dq->frente;
    i = 1;
    while (n) {
        printf("  %d. \"%s\" - %s\n", i++, n->titulo, n->artista);
        n = n->prox;
    }
}

void dequeLiberar(Deque *dq)
{
    DequeNode *n = dq->frente;
    while (n) {
        DequeNode *prox = n->prox;
        free(n);
        n = prox;
    }
    dq->frente  = NULL;
    dq->fundo   = NULL;
    dq->tamanho = 0;
}
