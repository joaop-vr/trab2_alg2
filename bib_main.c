#include <stdio.h>
#include <stdlib.h>

#include "bib_main.h"

int eh_valido (int v[], int p[], int bi[], int n, int *soma_anterior, int *qntd_anterior, int p_max) {

    int soma_peso = 0;
    int soma_valor = 0;
    int cont_zeros = 0;     //será utilizado para identificar o subconjunto vazio
    int qntd_atual = 0;
    int i;

    for (i = 0; i < n; i++) {

        if (bi[i] == 0)
            cont_zeros++;

        if (bi[i] == 1) {
            soma_valor = soma_valor + v[i];
            soma_peso = soma_peso + p[i];
            qntd_atual++;
        }
    };
    
    if (cont_zeros == n)
        return -1;                  //desconsiderando o subconjunto vazio
    if (soma_peso > p_max)
        return -1;
    if (soma_valor < *soma_anterior)      //soma_valor < soma_anterior
        return -1;
    if ((soma_peso <= p_max)&&((soma_valor == *soma_anterior)&&(qntd_atual < *qntd_anterior))) {    //qntd de presentes atual < qntd presentes anterior
        return -1;
    }
    
    *qntd_anterior = qntd_atual;
    *soma_anterior = soma_valor;
    return 1;
}

void vetBinarios (int v[], int p[], int bi[], int saida_v[], int saida_p[], int n, int *soma_anterior, int *qntd_anterior, int *cont, int p_max, int i) {

    if (i == n) {        
        
        if (eh_valido(v, p, bi, n, soma_anterior, qntd_anterior, p_max) == 1) { 

            for (i = 0; i < *cont; i++) {                             
                saida_v[i] = 0;                                     //limpando a saida_v
                saida_p[i] = 0;                                     //limpando a saida_p
            }
            *cont = 0;     
            int i;                                         //restart no cont
            for (i = 0; i < n; i++) {
                if (bi[i] == 1) {
                    saida_v[*cont] = v[i];
                    saida_p[*cont] = p[i];
                    *cont = *cont + 1;
                }
            }
        }
        return;
    }

    bi[i] = 0;
    vetBinarios(v, p, bi, saida_v, saida_p, n, soma_anterior, qntd_anterior, cont, p_max, i+1);
    bi[i] = 1;
    vetBinarios(v, p, bi, saida_v, saida_p, n, soma_anterior, qntd_anterior, cont, p_max, i+1);
}

void subConjuntos (int v[], int p[], int n, int p_max) {

    int soma_anterior = 0;
    int qntd_anterior = 0;
    int bi[n];
    int cont = 0;  
    int saida_v[n];
    int saida_p[n];
    int i;
    for (i = 0; i < n; i++) {
        saida_v[i] = 0;
        saida_p[i] = 0;
    }

    vetBinarios(v, p, bi, saida_v, saida_p, n, &soma_anterior, &qntd_anterior, &cont, p_max, 0);
    
    for (i = 0; i < n; i++) {
        if (saida_v[i] != 0)
            printf("valor: %d  peso: %d\n", saida_v[i], saida_p[i]);
    }

    int soma = 0;
    int j = 0;
    printf("\n=====================\n");
    printf("\nIndices: ");
    for (i = 0; i < n; i++) {
        if (v[i] == saida_v[j]) {
            printf("%d  ", i+1);
            j++;
        }
        if (saida_v[i] != 0) {
            soma = soma + saida_v[i];
        }
    }
    printf("\nSoma: %d\n\n", soma);
}