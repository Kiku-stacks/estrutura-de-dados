 #include <stdio.h>
 #include "pilha.h"
 #include "node.h"

 int main() {

   Pilha p;
   initPilha(&p);

   push(&p,10);
   push(&p,20);
   push(&p,30);

   print(&p);

   int valor;
   pop(&p,&valor);
   push(&p,100);

   printf("\n");
   print(&p);

    return 0;
 }
