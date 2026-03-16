    #include "deque.h"
    #include <stdio.h>
    #include <stdlib.h>

    void initDeque(Deque* d){
        d->front=NULL;
        d->back=NULL;
        d->tamanho=0;

        printf("Deque inicializada com sucesso!\n");
    }

    void destroyDeque(Deque* d){
        Node* aux;
        while(d->front !=NULL){
            aux = d->front;
            d->front = aux->next;
            free(aux);
            d->tamanho--;
        }
        d->back=NULL;

        printf("Deque destruida com sucesso\n");
    }

    void popFront(Deque* d, int *elemento){ //teste de deque vazia
        Node* aux = d->front;
        if(isEmpty(d)){
            printf("Deque vazia, não é possível remover elemento\n");
        }else{
            d->front=aux->next;
            d->tamanho--;
            *elemento=aux->dado;
            free(aux);
        }
        

        printf("Elemento %d removido com sucesso\n\n",*elemento);

    }

    int front(Deque* d){
        return d->front->dado;
    }

    int size(Deque* d){
        return d->tamanho;
    }

    int back(Deque* d){
        return d->back->dado;
    }

    void printFrontBack(Deque* d){
        Node* aux=d->front;
        printf("------MINHA DEQUE------\n\n");
        while(aux !=NULL){
            printf("%d-> ",aux->dado);
            aux=aux->next;
        }
        printf("\n\n");
    }

    bool isEmpty(Deque* d){
        return d->front==NULL;
    }

    void pushBack(Deque* d, int elem){
        Node* novo = createNode(elem,NULL);
        
        if(isEmpty(d)){
            d->back=novo;
            d->front=d->back;
            novo->next=NULL;
            d->tamanho++;
            printf("Elemento %d inserido com sucesso\n",elem);
        }else{
            novo->prev=d->back;
            d->back->next=novo; 
            d->back=novo;
            d->tamanho++;
            printf("Elemento %d inserido com sucesso\n",elem);
        }
    }

    void popBack(Deque* d, int *elemento){
        Node* aux = d->back;
        if(isEmpty(d)){  
            printf("Deque vazia, não é possível remover elemento\n");
        }else{
            d->back=aux->prev;
            if(d->back!=NULL){
                d->back->next=NULL;
            }else{
                d->front=NULL;
            }
            d->tamanho--;
            *elemento=aux->dado;
            free(aux);
        }
    }   

    void printBackFront(Deque* d){
        Node* aux=d->back;
        if(isEmpty(d)){
            printf("Deque vazia, não é possível imprimir elementos\n");
        }else{
            printf("------MINHA DEQUE------\n\n");
            while(aux !=NULL){
                printf("%d-> ",aux->dado);
                aux=aux->prev;
            }
            printf("\n\n");
        }
    }

    void pushFront(Deque* d, int elem){
        Node* novo = createNode(elem,NULL);
        if(isEmpty(d)){
            d->front=novo;
            d->back=d->front;
            novo->prev=NULL;
            d->tamanho++;
            printf("Elemento %d inserido com sucesso\n",elem);
        }else{
            novo->next=d->front;
            d->front->prev=novo;
            d->front=novo;
            d->tamanho++;
            printf("Elemento %d inserido com sucesso\n",elem);
        }

    }

    void findItem(Deque* dq, int item){
        Node* aux = dq->front;
        bool found=false;
        while(aux !=NULL){
            if(aux->dado==item){
                found=true;
                break;
            }
            aux=aux->next;
        }
        if(found){
            printf("Elemento %d encontrado na deque\n",item);
        }else{
            printf("Elemento %d nao encontrado na deque\n",item);
        }
    }

    void makeEmpty(Deque* d){
        Node* aux;
        while(d->front !=NULL){
            aux = d->front;
            d->front = aux->next;
            free(aux);
            d->tamanho--;
        }
        d->back=NULL;

        printf("Deque esvaziada com sucesso\n");
    }
