#include <stdio.h>


int main() {

    int i, n, p_max;
    printf("Informe o numero de presentes: ");
    scanf("%i\n", &n);
    printf("Informe o peso maximo: ");
    scanf("%i", &p_max);

    int v[n/2];
    int p[n/2];
    int j = 0;                    //j: indice no vetor v
    int k = 0;                    //k: indice no vetor p

    for (i = 0; i < 2*n; i++) {
        if (i/2 == 0) {
            int valor;
            printf("Insira valor: ");
            scanf("%d", &valor);
            v[j] = valor;
            j++;
        }
        else {
            int peso;
            printf("    Insira valor: ");
            scanf("%d\n", &peso);
            p[k] = peso;
            k++;
        }
    }
    return 0;
}
