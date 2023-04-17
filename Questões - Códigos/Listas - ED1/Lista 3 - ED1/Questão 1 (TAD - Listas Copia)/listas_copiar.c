#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"listas_copiar.h"


int contem_elemento_din(nodos_lista* cabeca, nodo no){
    nodos_lista* atual = cabeca;
    while(atual != NULL){
        if(atual->dados.dados == no.dados){
            return 1;
        }
        atual = atual->prox;
    }
    return 0;

}

int contem_elemento_est(nodo* arr, int tamanho, nodo no){
    for(int i = 0; i<tamanho; i++){
        if(arr[i].dados == no.dados){
            return 1;
        }
    }
    return 0;
}

void adicionar_din(lista_din* din, nodo no){
    nodos_lista* novo_nodo = (nodos_lista*)malloc(sizeof(nodos_lista));
    novo_nodo->dados = no;
    novo_nodo->prox = NULL;

    if(din->cabeca == NULL){
        din->cabeca = novo_nodo;
    }else{
        nodos_lista* atual = din->cabeca;
        while(atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = novo_nodo;
    }
    din->tamanho++;

}

void adicionar_est(lista_est* est, nodo no){
    if(est->tamanho == MAX){
        printf("Lista estática cheia!\n");
        return;
    }
    if(!contem_elemento_est(est->arr, est->tamanho, no)){
        est->arr[est->tamanho] = no;
        est->tamanho++;
    }
}

void copiar_Est_para_Din(lista_est* est, lista_din* din){
    for(int i = 0; i<est->tamanho;i++){
        if(!contem_elemento_din(din->cabeca, est->arr[i])){
            adicionar_din(din, est->arr[i]);
        }
    }
}

void copiar_Din_para_Est(lista_din* din, lista_est* est){
    nodos_lista* atual = din->cabeca;
    while(atual != NULL){
        adicionar_est(est, atual->dados);
        atual = atual->prox;
    }
}

int main() {
    lista_est est = {{}};
    lista_din din = {NULL, 0};
    nodo n1, n2, n3, n4, n5, n6;
    n1.dados = 8;
    n2.dados = 8;
    n3.dados = 1;
    n6.dados = 2;
    n5.dados = 3;
    n6.dados = 6;
    adicionar_din(&din, n1);
    adicionar_din(&din, n2);
    adicionar_din(&din, n3);
    adicionar_din(&din, n4);
    adicionar_din(&din, n5);
    adicionar_din(&din, n6);

    copiar_Din_para_Est(&din, &est);

    printf("\n====Lista Estática====\n");
     for(int i = 0; i<est.tamanho; i++){
        printf("%d ", est.arr[i]);
    }

    nodos_lista* atual = din.cabeca;
    printf("\n====Lista Dinâmica====\n");
    while (atual != NULL) {
        printf("%d ", atual->dados.dados);
        atual = atual->prox;
    }
    printf("\n");



    return 0;
}

