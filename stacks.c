#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack
{
    int top;
    int capacity;
    int * array;
};


struct stack * inicializar_stacks(int capacity){
    struct stack *S = malloc(sizeof(struct stack));

    S->top = -1;
    S->capacity = capacity;
    S->array = malloc(capacity * sizeof(int));

    if (!S)
    {
        return NULL;
    }
    printf("inicializou bacana");
    return S;

}

int isempty (struct stack * S){
    return(S->top == -1);
}


int size(struct stack * S){
    return (S->top + 1);
}

int isfull (struct stack *S){
    return (S->top == S->capacity -1);
}

void push (struct stack * S , int x){
    if (isfull(S))
    {
        printf("stack overflow");
        doublestack(S);
    }
    S->top++ ;
    S->array[S->top] =  x;
  
}

void doublestack(struct stack *S){
    S->capacity = S->capacity * 2;
    S->array = realloc(S->array , S->capacity * sizeof(int) );



}

void pop (struct stack * S){
    if (isempty(S))
    {
        printf("stack underflow");
    }else{
        return S->array[--S->top];
    }
    

}

int peek (struct stack * S){
    if (isempty(S)){
        printf("stack underflow");
    }else{
        return S->array[S->top];
    }
}

int deletestack (struct stack * S){
    if(S){
        if(S->array){
            free(S->array);
            free(S);
        }
    }
}

int main(){
    struct stack * torre = inicializar_stacks(5);
    isempty(torre);
}
