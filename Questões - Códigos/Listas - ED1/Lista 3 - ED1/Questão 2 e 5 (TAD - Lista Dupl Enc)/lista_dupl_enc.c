#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lista_dupl_enc.h"

struct lista_enc{
    Nodo* inicio;
};

ListaEnc* cria_lista_dupl(){
    ListaEnc *li = (ListaEnc*)malloc(sizeof(ListaEnc));
    li->inicio = NULL;
    return li;
}

void inserir_elemento_inicio(ListaEnc* li, int valor){
    Nodo* no = (Nodo*)malloc(sizeof(Nodo));
    no->dados = valor;
    no->ant = NULL;
    no->prox = li->inicio;
    if(li->inicio != NULL){
        li->inicio->ant = no;
    }
    li->inicio = no;
}

void remover_elemento_inicio(ListaEnc* li){
    if(li->inicio == NULL){
        return;
    }
    Nodo* no_atual = li->inicio;
    li->inicio = no_atual->prox;
    if(no_atual->prox != NULL){
        no_atual->prox->ant = NULL;
    }
    free(no_atual);
}

void imprimir_lista(ListaEnc* li){
    Nodo* no_atual = li->inicio;
    while(no_atual != NULL){
        printf("%d ", no_atual->dados);
        no_atual = no_atual->prox;
    }
    printf("\n");
}

void liberar_lista(ListaEnc *l) {
    Nodo *no_atual = l->inicio;
    while (no_atual != NULL) {
        Nodo *prox_no = no_atual->prox;
        free(no_atual);
        no_atual = prox_no;
    }
    free(l);
}

int main() {
    ListaEnc *l = cria_lista_dupl();
    inserir_elemento_inicio(l, 1);
    inserir_elemento_inicio(l, 2);
    inserir_elemento_inicio(l, 3);
    printf("Lista atual: ");
    imprimir_lista(l);
    remover_elemento_inicio(l);
    printf("Lista atualizada: ");
    imprimir_lista(l);
    return 0;
}
