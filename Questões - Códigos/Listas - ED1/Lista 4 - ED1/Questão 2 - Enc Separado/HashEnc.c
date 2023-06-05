#include<stdio.h>
#include<stdlib.h>
#include"HashEnc.h"

struct HashEnc{
    int qtd, TABLE_SIZE;
    struct item **itens;
};

Hash* criaHash(int TABLE_SIZE){
    Hash* ha = (Hash*)malloc(sizeof(Hash));
    if(ha != NULL){
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct item**)malloc(TABLE_SIZE*sizeof(struct item*));
        if(ha->itens == NULL){
           free(ha);
           return 0;
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

int chaveDivisao(int chave, int TABLE_SIZE){
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

int insereHash_EncSep(Hash* ha, int valor){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
       return 0;
    struct item *novo = (struct item*)malloc(sizeof(struct item));
    if(novo == NULL)
       return 0;
    novo->valor = valor;
    novo->prox = NULL;
    int chave = novo->valor;
    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL){
        ha->itens[pos] = novo;
    }else{
        struct item *aux = ha->itens[pos];
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    ha->qtd++;
    return 1;
}

void buscaHash_EncSep(Hash* ha, int valor){
    if(ha == NULL){
        printf("Erro: Tabela Hash não criada!\n");
        return;
    }
    int pos = chaveDivisao(valor,ha->TABLE_SIZE);
    struct item* aux = ha->itens[pos];
    while(aux != NULL){
        if(valor == aux->valor){
            printf("\n==ITEM ENCONTRADO==\n");
            printf("Posição: %d\n", pos);
            printf("Valor: %d\n", aux->valor);
            printf("-------------------\n");
            return;
        }
        aux = aux->prox;
    }
    printf("Item com o valor %d não encontrado!\n", valor);
    return;
}

int removeHash(Hash* ha, int valor){
    if(ha == NULL){
        printf("Erro: Tabela Hash não criada!\n");
        return 0;
    }
    if(ha->qtd == 0){
        printf("Erro: Tabela Hash vazia!\n");
        return 0;
    }
    int pos = chaveDivisao(valor, ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL){
        printf("Item com o valor %d não encontrado!\n", valor);
        return 0;
    }
    struct item *atual = ha->itens[pos];
    struct item *anterior = NULL;
    while(atual != NULL){
        if(valor == atual->valor){
            if(anterior == NULL)
               ha->itens[pos] = atual->prox;
            else{
            anterior->prox = atual->prox;
            }
            free(atual);
            ha->qtd--;
            printf("Item com o valor %d removido com sucesso!\n", valor);
            return 0;
        }
    anterior = atual;
    atual = atual->prox;
    }
    return 0;
}

void imprimeHash(Hash* ha){
    if(ha == NULL){
        printf("Erro: Tabela Hash não criada!\n");
        return ;
    }
    if(ha->qtd == 0){
        printf("Erro: Tabela Hash vazia!\n");
        return;
    }
    printf("\n====TABELA HASH====\n");
    for(int i = 0; i<ha->TABLE_SIZE; i++){
        printf("Posição: %d\n", i);
        struct item *aux = ha->itens[i];
        while(aux != NULL){
            printf("Valor: %d\n", aux->valor);
            aux = aux->prox;
        }
        printf("-------------------\n");
    }
    return;
}

int main(){
    Hash* ha = criaHash(12);
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
        insereHash_EncSep(ha, num[i]);
    }
    imprimeHash(ha);
    buscaHash_EncSep(ha, 333);
    buscaHash_EncSep(ha, 7);
    removeHash(ha, 333);
    removeHash(ha, 7);
    imprimeHash(ha);
    buscaHash_EncSep(ha, 333);
    buscaHash_EncSep(ha, 7);
    liberaHash(ha);
}
