#include <stdio.h>
#include <stdlib.h>
#include "filaCircular.h"

int main() {
    FilaCircular fila;
    int capacidade = 5;
    int elem;

    // Inicializa a fila
    initFila(&fila, capacidade);

    // Inserindo elementos
    inserir(&fila, 60);
    inserir(&fila, 70);
    inserir(&fila, 80);
    inserir(&fila, 90);
    imprimir(&fila);

    // Removendo elementos
    int numero;
    for(int i = 0; i < 2; i++){
        remover(&fila, &numero); 
    }
    
    //inserindo mais elementos
    inserir(&fila, 10);
    inserir(&fila, 450);
    inserir(&fila, 230);
    imprimir(&fila);

    // Mostrar início e fim da fila
    printf("Elemento no inicio: %d\n", inicio(&fila));
    printf("Elemento no fim: %d\n", fim(&fila));

    // Apagar toda a fila
    apagarFila(&fila);
    imprimir(&fila);

    // Destruir fila
    destroyFila(&fila);
    printf("\nFila destruida com sucesso!\n");

    return 0;
}
