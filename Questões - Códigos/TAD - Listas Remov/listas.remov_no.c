#include <stdio.h>
#include <stdlib.h>
#include "listas_remov_no.h"

void adicionar_Nodo(Nodo** cabeca, char valor){
    Nodo* no = (Nodo*)malloc(sizeof(Nodo));
    no->valor = valor;
    no->prox = NULL;
    if(*cabeca == NULL){
        *cabeca = no;
    }else{
        Nodo* atual = *cabeca;
        while(atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = no;
    }
}

void remover_Nodo_l1(Nodo* l1, int* l2, int* l3, int tamanho_l2, int tamanho_l3, char* result, int* tamanho_re){
    int i = 1, j = 0, k = 0; // iniciando com i = 1 para corresponder às posições da lista
    *tamanho_re = 0;
    Nodo* atual = l1;
    while(atual != NULL){
        while(j < tamanho_l2 && l2[j] < i){
            j++;
        }
        if(j < tamanho_l2 && l2[j] == i){
           atual = atual->prox;
           i++;
           continue;
        }
        while(k < tamanho_l3 && l3[k] < i){
            k++;
        }
        if(k < tamanho_l3 && l3[k] == i){
            atual = atual->prox;
            i++;
            continue;
        }

        result[*tamanho_re] = atual->valor;
        (*tamanho_re)++;
        atual = atual->prox;
        i++;
    }

}


int main(){
    Nodo* l1 = NULL;
    adicionar_Nodo(&l1, 'A');
    adicionar_Nodo(&l1, 'B');
    adicionar_Nodo(&l1, 'C');
    adicionar_Nodo(&l1, 'D');
    adicionar_Nodo(&l1, 'E');

    int l2[] = {2, 4, 8};
    int l3[] = {2, 5};
    char result[5];
    int tamanho_re = 0;

    remover_Nodo_l1(l1, l2,l3, 3, 2, result, &tamanho_re);
    printf("Resultado:\n");
    for(int i = 0; i < tamanho_re; i++){
        printf("%c ", result[i]);
    }
    printf("\n");

    return 0;
}
