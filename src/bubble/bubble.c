// Peguei de https://www.javatpoint.com/bubble-sort

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "criaVetor.c"
#include "salvarArq.c"


void print(int a[], int n){ 
    //função para imprimir elementos da matriz
    int i;  
    for(i = 0; i < n; i++){    
        printf("%d \n",a[i]);    
    }
    printf("\n");
}  


void bubble(int a[], int n)  {
    // function to implement bubble sort
    int i, j, temp;  
    for(i = 0; i < n; i++){    
        for(j = i+1; j < n; j++){    
            if(a[j] < a[i]){    
                temp = a[i];    
                a[i] = a[j];    
                a[j] = temp;     
            }     
        }     
    }     
}


int main () {    
    
    int *a;
    int n = 500000;
    
    FILE *arq;
    clock_t tempo;

    arq = fopen("bubble.csv","a");
    a = gerarVetor(a, n);

    tempo = clock();
    bubble(a, n);
    salvar(arq, &tempo, n);

    free(a);
    fclose(arq);

    printf("%d \n", n);

    return 0;

}