#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "salvarArq.h"

void salvarNums(FILE *arq, int *vetor, int tam){
	int i;
	
	for(i=0; i<tam; i++){
		fprintf(arq, "%d\n", vetor[i]);
	}

	fclose(arq);
}


void salvar(FILE *arq, clock_t *tempo, int n){

    double total;
	double tempo_final;
	double mili;
	double seg;

	tempo_final = clock();
	total = tempo_final - *tempo;

	mili = total / CLOCKS_PER_SEC;
	seg = mili * 1000;

    fprintf(arq, "%d,%lf,%lf\n", n, mili, seg);
}