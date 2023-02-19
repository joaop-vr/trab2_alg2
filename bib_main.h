#ifndef BIB_MAIN_H
#define BIB_MAIN_H

void subConjuntos (int v[], int p[], int n, int p_max);

void vetBinarios (int v[], int p[], int bi[], int saida_v[], int saida_p[], int n, int *soma_anterior, int *qntd_anterior, int *cont, int p_max, int i);

int eh_valido (int v[], int p[], int bi[], int n, int *soma_anterior, int *qntd_anterior, int p_max);

#endif