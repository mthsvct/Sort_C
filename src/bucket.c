// Peguei de https://www.javatpoint.com/bucket-sort

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "criaVetor.c"
#include "salvarArq.c"


int getMax(int a[], int n) {
    // função para obter o elemento máximo da matriz dada 
    int max = a[0];  
    for (int i = 1; i < n; i++)  
        if (a[i] > max)  
            max = a[i];  
    return max;  
}


void bucket(int a[], int n) { 
    // Função para implementar o tipo de balde
    
    int max = getMax(a, n); // max é o elemento máximo da matriz  
    int bucket[max], i;  
    
    for (int i = 0; i <= max; i++){  
        bucket[i] = 0;  
    }  
    
    for (int i = 0; i < n; i++){  
        bucket[a[i]]++;  
    }

    for (int i = 0, j = 0; i <= max; i++){  
        while (bucket[i] > 0) {  
            a[j++] = i;  
            bucket[i]--;  
        }  
    }
}  

void printArr(int a[], int n) {  
    // função para imprimir elementos da matriz 
    for (int i = 0; i < n; ++i)  
        printf("%d  ", a[i]);  
}

int main() {  
    int *a;
    int n = 500000;

    FILE *arq;
    clock_t tempo;

    arq = fopen("bucket.csv","a");

    a = gerarVetor(a, n);

    tempo = clock();
    bucket(a, n);
    salvar(arq, &tempo, n);
    
    free(a);

    fclose(arq);

    printf("\n");

    return 0;

}