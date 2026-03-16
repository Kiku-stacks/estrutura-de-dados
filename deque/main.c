#include <stdio.h>
#include "node.h"
#include "deque.h"

int main(){

    Deque d;
    initDeque(&d);

    pushBack(&d,20);
    pushBack(&d,30);
    pushBack(&d,40);
    pushBack(&d,50);
    printf("\n");
    
    printFrontBack(&d);

    int numero;
    popFront(&d,&numero);

    pushBack(&d,140);
    pushBack(&d,300);
    printf("\n");

    printFrontBack(&d);

    printf("Primeiro elemento: %d\n",front(&d));

    destroyDeque(&d);
    printFrontBack(&d);

    pushBack(&d,200);
    pushBack(&d,300);
    pushBack(&d,400);
    pushBack(&d,500);
    pushBack(&d,600);
    printFrontBack(&d);

    popBack(&d,&numero);
    printFrontBack(&d);
    printBackFront(&d);


    pushBack(&d,700);
    pushFront(&d,100);
    printFrontBack(&d);

    findItem(&d,300);
    findItem(&d,800);

    makeEmpty(&d);
    printFrontBack(&d);

    return 0;
}
