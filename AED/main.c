#include "playlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void limparBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

static void lerLinha(const char *prompt, char *dest, int max)
{
    printf("  %s", prompt);
    fflush(stdout);
    if (fgets(dest, max, stdin))
        dest[strcspn(dest, "\n")] = '\0';
}

static void tocarAtual(Playlist *pl, Deque *cache)
{
    if (!pl->atual) {
        printf("  Playlist vazia.");
        return;
    }

    SongNode *s = pl->atual;
    printf("\n  >> Tocando: \"%s\" - %s  [%02d:%02d]\n",
           s->titulo, s->artista,
           s->duracao / 60, s->duracao % 60);

    dequePushFrente(cache, s->titulo, s->artista);
}

static void imprimirMenu(void)
{
    printf(
        "\n"
        "  +------------------------------------------+\n"
        "  |     GERENCIADOR DE PLAYLIST  v1.0        |\n"
        "  +------------------------------------------+\n"
        "  |  [1]  Adicionar musica                   |\n"
        "  |  [2]  Tocar musica atual      (Play)     |\n"
        "  |  [3]  Proxima musica          (->)       |\n"
        "  |  [4]  Musica anterior         (<-)       |\n"
        "  |  [5]  Buscar musica                      |\n"
        "  |  [6]  Remover musica                     |\n"
        "  |  [7]  Exibir playlist                    |\n"
        "  |  [8]  Exibir cache                       |\n"
        "  |  [9]  Inserir no fundo do cache          |\n"
        "  |  [0]  Sair                               |\n"
        "  +------------------------------------------+\n"
        "  Opcao: "
    );
    
}

int main(void)
{
    Playlist pl;
    Deque    cache;

    playlistInit(&pl);
    dequeInit(&cache);

    puts("\n  Carregando playlist inicial...");
    playlistAdicionar(&pl, "Tem franguinho na panela",       "Um cantor ai",          354);
    playlistAdicionar(&pl, "Voce de uns dias pra ca",        "Lourenco e Lorival",         391);
    playlistAdicionar(&pl, "Flores em vida",      "Zeze de camargo e Luciano",   482);
    playlistAdicionar(&pl, "Sublime renuncia", "Leandro e Leonardo",        301);
    playlistAdicionar(&pl, "Chega de sujeira",                 "Tiao Carreiro",    187);
    puts("  Playlist pronta. Musica atual: \"Tem franguin na panela\"\n");

    int  opcao;
    char titulo[STR_MAX];
    char artista[STR_MAX];
    int  duracao;

    do {
        imprimirMenu();

        if (scanf("%d", &opcao) != 1) {
            limparBuffer();
            opcao = -1;
            printf("  Entrada invalida. Digite um numero.");
            continue;
        }
        limparBuffer();

        switch (opcao) {

            case 1:
                lerLinha("Titulo  : ", titulo,  STR_MAX);
                lerLinha("Artista : ", artista, STR_MAX);
                printf("  Duracao (segundos): ");
                if (scanf("%d", &duracao) != 1) duracao = 0;
                limparBuffer();
                playlistAdicionar(&pl, titulo, artista, duracao);
                break;

            case 2:
                tocarAtual(&pl, &cache);
                break;

            case 3:
                playlistProxima(&pl);
                printf("  [->] Avancou para a proxima musica.\n");
                tocarAtual(&pl, &cache);
                break;

            case 4:
                playlistAnterior(&pl);
                printf("  [<-] Voltou para a musica anterior.\n");
                tocarAtual(&pl, &cache);
                break;

            case 5:
                lerLinha("Titulo a buscar: ", titulo, STR_MAX);
                {
                    SongNode *enc = playlistBuscar(&pl, titulo);
                    if (enc)
                        printf("  Encontrada: \"%s\" - %s  [%02d:%02d]\n",
                               enc->titulo, enc->artista,
                               enc->duracao / 60, enc->duracao % 60);
                    else
                        printf("  \"%s\" nao encontrada.\n", titulo);
                }
                break;

            case 6:
                lerLinha("Titulo a remover: ", titulo, STR_MAX);
                if (playlistRemover(&pl, titulo))
                    printf("  \"%s\" removida com sucesso.\n", titulo);
                else
                    printf("  \"%s\" nao encontrada.\n", titulo);
                break;

            case 7:
                playlistExibir(&pl);
                break;

            case 8:
                dequeExibir(&cache);
                break;

            case 9:
                lerLinha("Titulo  : ", titulo,  STR_MAX);
                lerLinha("Artista : ", artista, STR_MAX);
                dequePushFundo(&cache, titulo, artista);
                printf("  \"%s\" inserida no fundo do cache.\n", titulo);
                break;

            case 0:
                printf("  Encerrando. Ate logo!");
                break;

            default:
                printf("  Opcao invalida.");
        }

    } while (opcao != 0);

    playlistLiberar(&pl);
    dequeLiberar(&cache);

    return EXIT_SUCCESS;
}
