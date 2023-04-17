#include <stdio.h>
#include "pilhas_inversas.h"

void criarPilha(PilhaDupla *pi) {
    pi->topo1 = -1;
    pi->topo2 = MAX;
}

int pilhaCheia(PilhaDupla *pi) {
    return pi->topo1 == pi->topo2 - 1;
}

int pilhaVazia1(PilhaDupla *pi) {
    return pi->topo1 == -1;
}

int pilhaVazia2(PilhaDupla *pi) {
    return pi->topo2 == MAX;
}

void empilhar(PilhaDupla *pi, int i, int x) {
    if (pilhaCheia(pi)) {
        printf("Erro: array 'A' cheio.\n");
        return;
    }
    if (i == 1) {
        pi->topo1++;
        pi->A[pi->topo1] = x;
    } else if (i == 2) {
        pi->topo2--;
        pi->A[pi->topo2] = x;
    } else {
        printf("Erro: Pilha inválida.\n");
    }
}

int desempilhar(PilhaDupla *pi, int i) {
    int x;
    if (i == 2) {
        if (pilhaVazia1(pi)) {
            printf("Erro: Pilha 2 vazia.\n");
            return -1;
        }
        x = pi->A[pi->topo1];
        pi->topo1--;
    } else if (i == 1) {
        if (pilhaVazia2(pi)) {
            printf("Erro: Pilha 1 vazia.\n");
            return -1;
        }
        x = pi->A[pi->topo2];
        pi->topo2++;
    } else {
        printf("Erro: Pilha inválida.\n");
        return -1;
    }
    return x;
}


void imprimirPilhaDupl(PilhaDupla* pi) {
    printf("Array 'A': ");
    for (int i = 0 ; i <= pi->topo1; i++) {
        printf("%d ", pi->A[i]);
        if((sizeof(pi->A)) == 0){
            printf("Array 'A' está vazio! %d\n", sizeof(pi->A));
        }
    }
    for (int i = pi->topo2; i <= MAX-1; i++) {
        printf("%d ", pi->A[i]);
    }
    printf("\n");
}

int main() {
    PilhaDupla pi;
    criarPilha(&pi);
    empilhar(&pi, 1, 10);
    imprimirPilhaDupl(&pi);
    empilhar(&pi, 2, 40);
    imprimirPilhaDupl(&pi);
    empilhar(&pi, 1, 20);
    imprimirPilhaDupl(&pi);
    empilhar(&pi, 2, 50);
    imprimirPilhaDupl(&pi);
    empilhar(&pi, 1, 30);
    imprimirPilhaDupl(&pi);
    empilhar(&pi, 2, 60);
    imprimirPilhaDupl(&pi);

    desempilhar(&pi, 1);
    imprimirPilhaDupl(&pi);
    desempilhar(&pi, 2);
    imprimirPilhaDupl(&pi);
    desempilhar(&pi, 1);
    imprimirPilhaDupl(&pi);
    desempilhar(&pi, 2);
    imprimirPilhaDupl(&pi);
    desempilhar(&pi, 1);
    imprimirPilhaDupl(&pi);
    desempilhar(&pi, 2);
    imprimirPilhaDupl(&pi);
    desempilhar(&pi, 2);

    return 0;
}
