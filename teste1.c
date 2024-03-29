#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;           //aqui armazenamos o valor do nó, poderiam ser mais termos
    struct node * next; // e aqui criamos um ponteiro para o próximo nó, o 'struct node' é para definir o tipo que o ponteiro irá apontar
};


void iterar_na_lista(struct node * head){

    if (head == NULL){
        printf("lista vazia");
    }else{
        struct node * i = head;
        while (i != NULL){
            printf("valor da pilha: %d\n" , i->data);
            i=i->next;
        }
        
    }
    

} 

struct node *empilharnoinicio(struct node *head, int data) {
    struct node *temp = malloc(sizeof(struct node));

    if (temp == NULL) {
        printf("erro, memória insuficiente\n");
        return head;
    }

    temp->data = data;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }

    return head;
}


int main() {
    struct node *head = NULL;

    head = empilharnoinicio(head, 20);
    head = empilharnoinicio(head, 30);
    head = empilharnoinicio(head, 40);

    iterar_na_lista(head);

    return 0;
}

