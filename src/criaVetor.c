#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "criaVetor.h"

int *aloca(int tam){
    int *novo;
    novo = (int *)malloc(tam * sizeof(int));
    return novo;
}

int *gerarVetor(int *v, int tam){
    int i, j=tam;
    v = aloca(tam);

    for(i=0; i<tam; i++){
        //v[i] = rand() % 1000000;
        v[i] = j;
        j--;
    }
        
    return v;    
}
