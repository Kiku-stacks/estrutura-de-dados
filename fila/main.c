#include <stdio.h>
#include "node.h"
#include "fila.h"

int main(){

    Fila f;
    
    iniciarFila(&f);

    inserirElemento(&f,20);
    inserirElemento(&f,30);
    inserirElemento(&f,40);
    inserirElemento(&f,50);
    printf("\n");
    
    imprimir(&f);

    int numero;
    removerElemento(&f,&numero);

    inserirElemento(&f,140);
    inserirElemento(&f,300);
    printf("\n");

    imprimir(&f);

    printf("Primeiro elemento: %d\n",frente(&f));

    destruirFila(&f);
    imprimir(&f);

    return 0;
}
