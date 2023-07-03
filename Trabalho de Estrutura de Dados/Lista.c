#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Lista.h"

struct Registro{
    int telefone;
    char nome[30];
    char endereco[50];
    struct Registro* prox;
};

struct ListaTelefonica{
    struct Registro* itens;
    int qtd, DDD;
};

Lista* criaLista(int DDD){
    Lista* li = (Lista*)malloc(sizeof(Lista));
    if(li != NULL){
       li->DDD = DDD;
       li->itens = NULL;
    }
    return li;
}

void liberaLista(Lista* li){
    if(li != NULL){
        struct Registro* atual = li->itens;
        while(atual != NULL){
            struct Registro* temp = atual;
            atual = atual->prox;
            free(temp);
        }
        free(li);
    }
}

int insereRegistro_Ordenado(Lista* li, int telefone, char nome[], char endereco[]) {
    if (li == NULL)
        return 0;

    struct Registro* novo = (struct Registro*)malloc(sizeof(struct Registro));
    if (novo == NULL)
        return 0;

    novo->telefone = telefone;
    strcpy(novo->nome, nome);
    strcpy(novo->endereco, endereco);
    novo->prox = NULL;

    if (li->itens == NULL || strcmp(novo->nome, li->itens->nome) < 0) {
        novo->prox = li->itens;
        li->itens = novo;
        li->qtd++;
        return 1;
    }
    struct Registro* atual = li->itens;
    struct Registro* ant = NULL;
    while (atual != NULL && strcmp(novo->nome, atual->nome) >= 0) {
        ant = atual;
        atual = atual->prox;
    }
    novo->prox = atual;
    if (ant != NULL)
        ant->prox = novo;
    else
        li->itens = novo;

    li->qtd++;
    return 1;
}


int removeRegistro(Lista* li, int telefone){
    if(li == NULL || li->qtd == 0)
        return 0;
    struct Registro* atual = li->itens;
    struct Registro* ant = NULL;
    while(atual != NULL && atual->telefone != telefone){
        ant = atual;
        atual = atual->prox;
    }
    if(atual == NULL)
        return 0;

    if(ant == NULL){
        li->itens = atual->prox;
    }else{
        ant->prox = atual->prox;
    }
    li->qtd--;
    free(atual);
    return 1;
}

void listaTelefonicaNome(Lista* li){
    if(li == NULL || li->qtd == 0){
        printf("Lista Vazia!\n");
        return;
    }
    struct Registro* atual = li->itens;
    while(atual != NULL){
        printf("Nome: %s\n", atual->nome);
        printf("Telefone: %d\n", atual->telefone);
        printf("Endereco: %s\n\n", atual->endereco);
        atual = atual->prox;
    }
}
