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

    imprimir(&f);

    int numero;
    removerElemento(&f,&numero);
    printf("Removacao do elemento %d concluida\n",numero);

    inserirElemento(&f,140);
    inserirElemento(&f,300);

    imprimir(&f);

    destruirFila(&f);

    

    return 0;
}
