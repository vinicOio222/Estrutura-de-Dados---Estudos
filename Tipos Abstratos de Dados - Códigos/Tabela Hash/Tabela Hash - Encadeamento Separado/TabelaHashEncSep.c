#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"TabelaHashEncSep.h"

struct hash{
    int qtd, TABLE_SIZE;
    struct aluno **itens;
};

Hash* criaHash(int tamanho){
    Hash* ha = (Hash*)malloc(sizeof(Hash));
    if(ha != NULL){
        ha->TABLE_SIZE = tamanho;
        ha->itens = (struct aluno**)malloc(tamanho*sizeof(struct aluno*));
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

int chaveDivisao(int chave, int TABLE_SIZE){
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

int valorString(char *str){
    int valor = 7;
    int tam = strlen(str);
    for(int i = 0; i<tam; i++)
        valor = 31 * valor + (int) str[i];
    return valor;
}

int insereHash_EncSep(Hash* ha, struct aluno al){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;

    int chave = al.matricula;
    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    struct aluno* novo = (struct aluno*)malloc(sizeof(struct aluno));
    if(novo == NULL)
       return 0;
    *novo = al;
    novo->prox = NULL;
    if(ha->itens[pos] == NULL){
        ha->itens[pos] = novo;
    }else{
        struct aluno* aux = ha->itens[pos];
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    ha->qtd++;
    return 1;
}

int buscaHash_EncSep(Hash* ha, int mat){
    if(ha == NULL){
       printf("Erro: Tabela Hash não criada!\n");
       return 0;
    }
    int pos = chaveDivisao(mat, ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL){
        printf("Aluno(a) com a matrícula %d não encontrado(a) na tabela!\n", mat);
        return 0;
    }
    struct aluno* aux = ha->itens[pos];
    while(aux != NULL){
        if(mat == aux->matricula){
           printf("\n===ALUNO ENCONTRADO===\n");
            printf("Posição: %d\n", pos);
            printf("Nome: %s\n", aux->nome);
            printf("Matrícula: %d\n", aux->matricula);
            printf("Notas: %.2f, %.2f, %.2f\n", aux->notas[0],aux->notas[1],aux->notas[2]);
             printf("-----------------\n");
            return 1;
        }
        aux = aux->prox;

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
        struct aluno *aux = ha->itens[i];
        while(aux != NULL){
            printf("Nome: %s\n", aux->nome);
            printf("Matrícula: %d\n", aux->matricula);
            printf("Notas: %.2f, %.2f, %.2f\n", aux->notas[0], aux->notas[1], aux->notas[2]);
            printf("\n");
            aux = aux->prox;
        }
        printf("-------------------\n");
    }

}

int main(){
    Hash *ha = criaHash(13);
    struct aluno a1, a2, a3, a4, a5;
    strcpy(a1.nome, "Vinícius");
    a1.matricula = 1612520;
    a1.notas[0] = 8.90;
    a1.notas[1] = 10.00;
    a1.notas[2] = 9.56;
    strcpy(a2.nome, "Beatriz");
    a2.matricula = 17856551;
    a2.notas[0] = 7.90;
    a2.notas[1] = 9.00;
    a2.notas[2] = 8.05;
    strcpy(a3.nome, "Vitor");
    a3.matricula = 1819894;
    a3.notas[0] = 8.88;
    a3.notas[1] = 7.31;
    a3.notas[2] = 9.57;
    strcpy(a4.nome, "João");
    a4.matricula = 1519899;
    a4.notas[0] = 8.81;
    a4.notas[1] = 7.93;
    a4.notas[2] = 9.57;
    strcpy(a5.nome, "Lucas");
    a5.matricula = 1819895;
    a5.notas[0] = 9.89;
    a5.notas[1] = 8.64;
    a5.notas[2] = 9.17;
    insereHash_EncSep(ha, a1);
    insereHash_EncSep(ha, a2);
    insereHash_EncSep(ha, a3);
    insereHash_EncSep(ha, a4);
    insereHash_EncSep(ha, a5);
    imprimeHash(ha);
    buscaHash_EncSep(ha, 1612520);
    buscaHash_EncSep(ha, 1819895);
    buscaHash_EncSep(ha, 1519899);
    buscaHash_EncSep(ha, 1228831);

    return 0;

}
