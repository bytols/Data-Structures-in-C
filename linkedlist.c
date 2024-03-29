#include <stdio.h>
#include <stdlib.h>

// criamos a estrutura de um nó
struct node
{
    int data;           //aqui armazenamos o valor do nó, poderiam ser mais termos
    struct node * next; // e aqui criamos um ponteiro para o próximo nó, o 'struct node' é para definir o tipo que o ponteiro irá apontar
};

#include <stdio.h>
#include <stdlib.h>

struct node *empilharnoinicio ( struct node * head , int data){

    struct node * temp = malloc(sizeof(struct node));

    if(temp == NULL){
        printf("erro, memória insuficiente");
        return head;
    }

    temp->data = data;
    temp->next = NULL; 


     if (head == NULL){
        head = temp;
        head->next = NULL;
    }else{
        temp->next = head;
        head = temp;
        printf("nó adicionado\n");
        printf("valor do no: %d \n" , head->data);
    }

    return head;

}


struct node * empilharnofim ( struct node *head , int data) {

    struct node * temp = malloc(sizeof(struct node)) ;

    temp->data = data;
    temp->next = NULL;

    if (head == NULL){
        head = temp;
        head->next = NULL;
    }
    else{
        struct node * i = head;
        while(i->next != NULL){
            i = i->next;
        }
        i->next = temp;
        printf("nó adicionado\n");
        printf("valor do no: %d \n" , i->data);
    }
    
    return head;
    


}


void iterar_na_lista(struct node * head){

    if (head == NULL) {
        printf("lista vazia");
    } else {
        struct node *i = head;
        while (i != NULL) {
            printf("valor da pilha: %d \n", i->data);  // Access the `data` member using ->
            i = i->next;
        }
    }
    

} 

struct node * adicionar_no_meio(struct node * head, struct node *new, int n) {
    struct node *ptr = head;
    int i = 0;

    // Traverse the list until the desired position or the end of the list
    while (i < n && ptr != NULL) {
        ptr = ptr->next;
        i++;
    }

    if (head == NULL || n <= 0) {
        // If the list is empty or the desired position is the beginning
        new->next = head;
        head = new;
    } else if (ptr != NULL) {
        // Insert the new node in the middle
        new->next = ptr->next;
        ptr->next = new;
        printf("Nodulo adicionado.\n");
    } else {
        // If the desired position is beyond the end of the list,
        // append the new node to the end
        printf("Posicao %d esta alem do final da lista. Adicionando ao final.\n", n);

        // Traverse to the end of the list
        while (head->next != NULL) {
            head = head->next;
        }

        // Append the new node
        head->next = new;
        new->next = NULL;
    }

    return head;
}



int main(){

struct node * head = NULL;

struct node *novo = malloc(sizeof(struct node));
novo->data = 3;
novo->next = NULL;


empilharnoinicio(&head , 20 );
empilharnoinicio(&head , 30 );
empilharnoinicio(&head , 60 );

adicionar_no_meio(head , novo, 1);

iterar_na_lista(&head);
    
return 0;
}

