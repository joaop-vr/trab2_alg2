#include <stdio.h>

#include "bib_main.h"


int main() {

    int i, n, p_max;
    printf("\nInforme o numero de presentes: ");
    scanf("%i", &n);
    printf("Informe o peso maximo: ");
    scanf("%i", &p_max);
    printf("\n");

    int v[n];
    int p[n];
    int j = 0;                    //j: indice no vetor v
    int k = 0;                    //k: indice no vetor p

    for (i = 0; i < 2*n; i++) {
        if ((i%2) == 0) {
            int valor;
            printf("Insira o valor: ");
            scanf("%i", &valor);
            v[j] = valor;
            j++;
        }
        else {
            int peso;
            printf("Insira o peso: ");
            scanf("%i", &peso);
            p[k] = peso;
            k++;
            printf("\n");
        }
    }

    subConjuntos(v,p,n,p_max);

    return 0;
}