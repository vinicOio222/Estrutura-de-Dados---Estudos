#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"HashAlunos.h"

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

int insereHash_EncSep(Hash* ha, char nome[30], int mat){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;
    struct aluno* novo = (struct aluno*)malloc(sizeof(struct aluno));
    for (int i = 0; i < 30; i++) {
        novo->nome[i] = nome[i];
        if (nome[i] == '\0')
            break;
    }
    novo->matricula = mat;
    int chave = novo->matricula;
    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    if(novo == NULL)
       return 0;
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

int removeHash_EncSep(Hash* ha, int mat){
    if(ha == NULL){
        printf("Erro: Tabela Hash não criada!\n");
        return 0;
    }
    if(ha->qtd == 0){
        printf("Erro: Tabela Hash vazia!\n");
        return 0;
    }
    int pos = chaveDivisao(mat, ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL){
        printf("Aluno(a) com matrícula %d não encontrado(a)!\n", mat);
        return 0;
    }
    struct aluno *atual = ha->itens[pos];
    struct aluno *anterior = NULL;
    while(atual != NULL){
        if(mat == atual->matricula){
            if(anterior == NULL)
               ha->itens[pos] = atual->prox;
            else{
            anterior->prox = atual->prox;
            }
            free(atual);
            ha->qtd--;
            printf("Aluno(a) com matrícula %d removido(a) com sucesso!\n", mat);
            return 0;
        }
    anterior = atual;
    atual = atual->prox;
    }
    return 0;
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
            printf("Nome: %s\n", ha->itens[pos]->nome);
            printf("Matrícula: %d\n", ha->itens[pos]->matricula);
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
            printf("\n");
            aux = aux->prox;
        }
        printf("-------------------\n");
    }

}

float mediaMatriculas(Hash* ha){
    if(ha == NULL || ha->qtd == 0){
        return 0.0;
    }
    int totalAlunos = 0;
    int somaMatriculas = 0;
    for(int i = 0; i<ha->TABLE_SIZE; i++){
        struct aluno* aux = ha->itens[i];
        while(aux != NULL){
            somaMatriculas += aux->matricula;
            totalAlunos++;
            aux = aux->prox;
        }
    }
    float media  = (float)somaMatriculas/totalAlunos;
    return media;
}

int main(){
    Hash *ha = criaHash(10);
    insereHash_EncSep(ha, "Vinícius", 1612520);
    insereHash_EncSep(ha, "Lucas", 1676589);
    insereHash_EncSep(ha, "Italo", 1218524);
    insereHash_EncSep(ha, "Kalil", 1345652);
    insereHash_EncSep(ha, "Maria", 1553452);
    imprimeHash(ha);
    buscaHash_EncSep(ha, 1612520);
    buscaHash_EncSep(ha, 1676589);
    buscaHash_EncSep(ha, 1345652);
    buscaHash_EncSep(ha, 1228831);
    printf("\nMédia dos números de matrículas: %.2f\n\n",mediaMatriculas(ha));
    removeHash_EncSep(ha, 1612520);
    removeHash_EncSep(ha, 1218524);
    imprimeHash(ha);
    buscaHash_EncSep(ha, 1612520);
    buscaHash_EncSep(ha, 1218524);
    printf("\nMédia dos números de matrículas: %.2f\n\n",mediaMatriculas(ha));


    return 0;

}
