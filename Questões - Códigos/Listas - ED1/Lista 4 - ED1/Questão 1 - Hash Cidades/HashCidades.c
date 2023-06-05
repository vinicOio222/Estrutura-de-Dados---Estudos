#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"HashCidades.h"

struct HashCidades {
    int qtd, tamanho;
    struct cidade** itens;
};

typedef struct HashCidades Hash;

Hash* criaHash() {
    Hash* ha = (Hash*)malloc(sizeof(Hash));
    if (ha != NULL) {
        ha->tamanho = TABLE_SIZE;
        ha->itens = (struct cidade**)malloc(TABLE_SIZE * sizeof(struct cidade*));
        if (ha->itens == NULL) {
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for (int i = 0; i < ha->tamanho; i++)
            ha->itens[i] = NULL;
    }
    return ha;
}

void liberaHash(Hash* ha) {
    if (ha != NULL) {
        for (int i = 0; i < ha->tamanho; i++) {
            if (ha->itens[i] != NULL)
                free(ha->itens[i]);
        }
        free(ha->itens);
        free(ha);
    }
}

int valorString(char* str) {
    int valor = 7;
    int tam = strlen(str);
    for (int i = 0; i<tam; i++)
        valor = 31 * valor + (int)str[i];
    return valor;
}

int chaveDivisao(int chave, int tamanho) {
    return (chave & 0x7FFFFFFF) % tamanho;
}

int insereCidade(Hash* ha, struct cidade ci) {
    if(ha == NULL || ha->qtd == ha->tamanho)
        return 0;

    int chave = valorString(ci.nome);
    int pos = chaveDivisao(chave, ha->tamanho);
    struct cidade* nova;
    nova = (struct cidade*)malloc(sizeof(struct cidade));
    if (nova == NULL)
        return 0;
    *nova = ci;
    nova->prox = NULL;
    if(ha->itens[pos] == NULL){
        ha->itens[pos] = nova;
    }else{
        struct cidade* aux = ha->itens[pos];
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = nova;
    }
    ha->qtd++;
    return 1;
}

void imprimeResultados(Hash* ha) {
    if(ha == NULL){
        printf("Erro: Tabela Hash não criada!\n");
        return;
    }
    if(ha->qtd == 0){
        printf("Erro: Tabea hash vazia!\n");
        return;
    }
    int col = 0;
    int num_ender[11] = {0};
    for(int i = 0; i<ha->tamanho; i++){
        int cont = 0;
        if(ha->itens[i] != NULL){
            struct cidade* aux = ha->itens[i];
            while(aux != NULL){
                cont++;
                aux = aux->prox;
            }
            if(cont > 1){
                col++;
            }
            if(cont <= 10){
                num_ender[cont]++;
            }else{
                num_ender[10]++;
            }
        }else{
            num_ender[0]++;
        }
        printf("Endereço: %d\n",i);
        struct cidade *aux = ha->itens[i];
        while(aux != NULL){
            printf("%s\n", aux->nome);
            aux = aux->prox;
        }
        printf("\n");
    }
    printf("\nNúmero de colisões: %d\n", col);
    for(int i = 0; i<=10; i++){
        printf("Número de endereços com %d cidade(s): %d\n", i, num_ender[i]);
    }
    printf("Número de endereços com mais de 10 cidades associadas: %d\n", num_ender[10]);
}

int main() {
    Hash* ha = criaHash();
    struct cidade cidades[31] = {
        {"Acarape"},
        {"Acaraú"},
        {"Aquiraz"},
        {"Aracati"},
        {"Arneiroz"},
        {"Aratuba"},
        {"Assaré"},
        {"Amontada"},
        {"Caridade"},
        {"Cascavel"},
        {"Caucaia"},
        {"Crato"},
        {"Cruz"},
        {"Cariré"},
        {"Croatá"},
        {"Fortaleza"},
        {"Farias Brito"},
        {"Forquilha"},
        {"Frecheirinha"},
        {"Pacajus"},
        {"Pacatuba"},
        {"Paraipaba"},
        {"Parambu"},
        {"Paramoti"},
        {"Pentecoste"},
        {"Pereiro"},
        {"Pindoretama"},
        {"Poranga"},
        {"Porteiras"},
        {"Potiretama"},
    };

    for (int i = 0; i<31; i++) {
        insereCidade(ha, cidades[i]);
    }
    imprimeResultados(ha);
    liberaHash(ha);

    return 0;
}
