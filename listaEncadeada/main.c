#include <stdio.h>
#include "node.h"
#include "listaEncadeada.h"
 
int main() {
    ListaEncadeada lista1;
    init_lista(&lista1);
 
    add_item_end(&lista1, 10);
    add_item_end(&lista1, 20);
    add_item_end(&lista1, 30);
    add_item_end(&lista1, 40);
    printf("\n");
 
    print_list(&lista1);
    add_item_beginning(&lista1, 5);
    add_item_pos(&lista1, 99, 2);
    printf("\n");
 
    print_list(&lista1);
    remove_item_beginning(&lista1);
    print_list(&lista1);
    remove_item_end(&lista1);
    print_list(&lista1);
    remove_item_pos(&lista1, 1);
    print_list(&lista1);
    remove_item(&lista1, 20);
    print_list(&lista1);
    printf("\n");
 
    find_item(&lista1, 30);
    find_item(&lista1, 999);
    get_min_max(&lista1);
    modify_item(&lista1, 0, 77);
    print_list(&lista1);
    printf("\n");
 
    add_item_end(&lista1, 15);
    add_item_end(&lista1, 3);
    add_item_end(&lista1, 50);
    print_list(&lista1);
    ordenar(&lista1);
    printf("\n");
 
    ListaEncadeada lista2;
    init_lista(&lista2);
    add_item_end(&lista2, 100);
    add_item_end(&lista2, 200);
    add_item_end(&lista2, 300);
    print_list(&lista2);
    concatenarListas(&lista1, &lista2);
    print_list(&lista1);
    printf("\n");
 
    ListaEncadeada lista3;
    ListaEncadeada lista4;
    init_lista(&lista3);
    init_lista(&lista4);
    add_item_end(&lista3, 90);
    add_item_end(&lista3, 12);
    add_item_end(&lista3, 43);
    print_list(&lista3);
    add_item_end(&lista4, 4);
    add_item_end(&lista4, 55);
    add_item_end(&lista4, 6);
    print_list(&lista4);
    concatenarListas(&lista3,&lista4);
    print_list(&lista3);
    mesclarListas(&lista3, &lista4);
    printf("\n");
 
    esvazia_lista(&lista1);
    esvazia_lista(&lista2);
    esvazia_lista(&lista3);
    esvazia_lista(&lista4);
    print_list(&lista1);
 
    return 0;
}
