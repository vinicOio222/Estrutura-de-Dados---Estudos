#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"HashEncAberto.h"

struct hash{
    int qtd, TABLE_SIZE;
    struct item **itens;
};

Hash* criaHash(int tamanho){
    Hash* ha = (Hash*)malloc(sizeof(Hash));
    if(ha != NULL){
        ha->TABLE_SIZE = tamanho;
        ha->itens = (struct item**)malloc(tamanho*sizeof(struct item*));
        if(ha->itens == NULL){
            free(ha);
            return NULL;
        }
    ha->qtd = 0;
    for(int i = 0; i<ha->TABLE_SIZE; i++)
        ha->itens[i] = NULL;
    }
    return ha;

}

void liberaHash(Hash* ha){
    if(ha != NULL){
        for(int i = 0; i<ha->TABLE_SIZE; i++){
            if(ha->itens[i] != NULL)
               free(ha->itens[i]);
        }
        free(ha->itens);
        free(ha);
    }
}

int chaveDivisao(int chave, int tamanho){
    return (chave & 0x7FFFFFFF) % tamanho;
}

int insereHash_SemColisao(Hash* ha, int valor){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;
    struct item* novo = (struct item*)malloc(sizeof(struct item));
    novo->valor = valor;
    int chave = novo->valor;
    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    if(novo == NULL)
       return 0;
    ha->itens[pos] = novo;
    ha->qtd++;
    return 1;

}

int sondagemLinear(int pos, int i, int TABLE_SIZE){
    return ((pos + i) & 0x7FFFFFFF) % TABLE_SIZE;
}

int insereHash_EnderAberto(Hash* ha, int valor){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
       return 0;

    int chave = valor;
    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    for(int i = 0; i<ha->TABLE_SIZE; i++){
        int newPos = sondagemLinear(pos, i, ha->TABLE_SIZE);
        if(ha->itens[newPos] == NULL){
            struct item* novo = (struct item*)malloc(sizeof(struct item));
            if(novo == NULL)
               return 0;
            novo->valor = valor;
            ha->itens[newPos] = novo;
            ha->qtd++;
            return 1;
        }
    }
    return 0;
}

int buscaHash_EnderAberto(Hash* ha, int valor){
    if(ha == NULL){
        printf("Erro: Tabela Hash não criada!\n");
        return 0;
    }
    int pos = chaveDivisao(valor, ha->TABLE_SIZE);
    for(int i = 0; i<ha->TABLE_SIZE; i++){
        int newPos = sondagemLinear(pos, i, ha->TABLE_SIZE);
        if(ha->itens[newPos] == NULL){
            printf("Item com valor %d não encontrado na tabela!\n", valor);
            return 0;
        }
        if(valor == ha->itens[newPos]->valor){
            printf("\n===ALUNO ENCONTRADO===\n");
            printf("Posição: %d \n", pos);
            printf("Valor: %d\n", ha->itens[newPos]->valor);
            printf("----------------------\n");
            return 1;

        }
    }
    return 0;
}

void imprimeHash(Hash* ha){
    if(ha == NULL){
        printf("Erro: Tabela Hash não criada!\n");
        return;
    }
    if(ha->qtd == 0){
        printf("Erro: Tabela Vazia!\n");
        return;
    }
    printf("\n====TABELA HASH====\n");
    for(int i = 0; i < ha->TABLE_SIZE; i++){
        printf("Posição %d: \n", i);
        if(ha->itens[i] != NULL){
            printf("Valor: %d\n", ha->itens[i]->valor);
        }
        printf("-------------------\n");

    }

}

int main(){
    Hash* ha = criaHash(20);
    int num[12] = {
        1,
        2,
        3,
        4,
        11,
        34,
        45,
        7,
        34,
        12,
        67,
        333
    };

    for(int i = 0; i<12; i++){
        insereHash_EnderAberto(ha, num[i]);
    }
    imprimeHash(ha);
    buscaHash_EnderAberto(ha, 333);
    buscaHash_EnderAberto(ha, 7);
    liberaHash(ha);

    return 0;
}
