#include <stdio.h>

int recursao(int n){

    if (n == 0){
        printf("tudo certo, %d desceu a igual a 0 \n\n" , n );
    }

    else{
        printf("o valor de %d atual: \n" , n);
        return n-- + recursao(n);
    }


}

int hounai_tower(n){



}

int sort( int array[]  , int i , int size) { 

    if (i == size - 1)
    {
        return 1;
    }
    


    if( array[i] > array[i+1] ){
        printf("nao esta em ordem o array! \n"); 
        return 0;       
    }

    else{
        printf("por enquanto tudo certo \n ");
        return sort( array , i+1 , size);
    }


}


int main()
{
    int iterador = 0;
    int lista[] = {1, 2, 3, 4, 5 , 6 , 7 , 8 , 5 , 6};
    int size = sizeof(lista)/ sizeof(lista[0]);
    //printf(" o tamanho do array é %d" , tamanho_array);
    sort(lista , iterador , size);


    /*int n;
    printf("escolha um numero");
    scanf("%d" , &n);
    recursao(n);
    */return 0;
    
}



