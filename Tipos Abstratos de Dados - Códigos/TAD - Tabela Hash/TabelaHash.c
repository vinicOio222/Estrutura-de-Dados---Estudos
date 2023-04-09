#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "TabelaHash.h"

struct hash{
    int qtd, TABLE_SIZE;
    struct aluno **itens;
};

Hash *cria_Hash(int TABLE_SIZE){
    Hash* ha = (Hash*)malloc(sizeof(Hash));
    if(ha != NULL){
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct aluno**)malloc(TABLE_SIZE * sizeof(struct aluno*));
        if(ha->itens == NULL){
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for(int i = 0; i < ha->TABLE_SIZE; i++)
            ha->itens[i] = NULL;
    }
    return ha;

}

void libera_Hash(Hash* ha){
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

int insereHash_SemColisao(Hash* ha, struct aluno al){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;
    int chave = al.matricula;
    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    struct aluno* novo;
    novo = (struct aluno*)malloc(sizeof(struct aluno));
    if(novo == NULL)
       return 0;
    *novo = al;
    ha->itens[pos] = novo;
    ha->qtd++;
    return 1;

}

void buscaHash_SemColisao(Hash* ha, int mat){
    if(ha == NULL){
       printf("Erro: Tabela Hash não foi criada!\n");
       return;
    }
    int pos = chaveDivisao(mat, ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL){
       printf("Aluno(a) com matrícula %d não encontrado(a) na Tabela Hash!\n", mat);;
       return;
    }
    if(mat == ha->itens[pos]->matricula){
        printf("\n===ALUNO ENCONTRADO===\n");
        printf("Posição: %d \n", pos);
        printf("Nome: %s\n", ha->itens[pos]->nome);
        printf("Matricula: %d\n", ha->itens[pos]->matricula);
        printf("Notas: %.2f, %.2f, %.2f\n", ha->itens[pos]->notas[0], ha->itens[pos]->notas[1], ha->itens[pos]->notas[2]);
        printf("----------------------------\n");
        return;
    }

}

int sondagemLinear(int pos, int i, int TABLE_SIZE){
    return ((pos + i) & 0x7FFFFFFF) % TABLE_SIZE;
}

int insereHash_EnderAberto(Hash* ha, struct aluno al){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
       return 0;
    int chave = al.matricula;
    int newPos;
    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    for(int i = 0; i<ha->TABLE_SIZE; i++){
        newPos = sondagemLinear(pos, i, ha->TABLE_SIZE);
        if(ha->itens[newPos] == NULL){
            struct aluno* novo;
            novo = (struct aluno*)malloc(sizeof(struct aluno));
            if(novo == NULL)
               return 0;
            *novo = al;
            ha->itens[newPos] = novo;
            ha->qtd++;
            return 1;
        }

    }
    return 0;
}

void buscaHash_EnderAberto(Hash* ha, int mat){
    if(ha == NULL){
       printf("Erro: Tabela Hash não criada!\n");
       return;
    }
    int pos, newPos;
    pos = chaveDivisao(mat, ha->TABLE_SIZE);
    for(int i = 0; i<ha->TABLE_SIZE; i++){
        newPos = sondagemLinear(pos, i, ha->TABLE_SIZE);
        if(ha->itens[newPos] == NULL){
           printf("Aluno(a) com matrícula %d não encontrado(a) na lista!\n",mat);
           return;
        }
        if(mat == ha->itens[newPos]->matricula){
            printf("\n===ALUNO ENCONTRADO===\n");
            printf("Posição %d: \n", newPos);
            printf("Nome: %s\n", ha->itens[newPos]->nome);
            printf("Matricula: %d\n", ha->itens[newPos]->matricula);
            printf("Notas: %.2f, %.2f, %.2f\n", ha->itens[newPos]->notas[0],  ha->itens[newPos]->notas[1], ha->itens[newPos]->notas[2]);
            printf("----------------------------\n");
            return;
        }
    }
}

void imprime_Hash(Hash* ha){
    if(ha == NULL){
       printf("Erro: Tabela Hash não foi criada!\n");
       return;
    }
    if(ha->qtd == 0){
       printf("Tabela Hash vazia!\n");
       return;
    }
    printf("\n===TABELA HASH===\n");
    for(int i = 0; i < ha->TABLE_SIZE; i++){
        if(ha->itens[i] != NULL){
            printf("Posição %d: \n", i);
            printf("Nome: %s\n", ha->itens[i]->nome);
            printf("Matricula: %d\n", ha->itens[i]->matricula);
            printf("Notas: %.2f, %.2f, %.2f\n", ha->itens[i]->notas[0], ha->itens[i]->notas[1], ha->itens[i]->notas[2]);
            printf("-----------------------\n");
        }
    }
}


int main(){
    Hash *hash = cria_Hash(13);
    struct aluno a1, a2, a3, a4;
    strcpy(a1.nome, "Vinicius");
    a1.matricula = 1612520;
    a1.notas[0] = 10;
    a1.notas[1] = 8.56;
    a1.notas[2] = 8.00;
    strcpy(a2.nome, "Caio");
    a2.matricula = 1912304;
    a2.notas[0] = 10;
    a2.notas[1] = 8.56;
    a2.notas[2] = 8.00;
    strcpy(a3.nome, "Janaina");
    a3.matricula = 1900227;
    a3.notas[0] = 7.99;
    a3.notas[1] = 8.76;
    a3.notas[2] = 8.80;
    strcpy(a4.nome, "Tales");
    a4.matricula = 1115690;
    a4.notas[0] = 9;
    a4.notas[1] = 7.56;
    a4.notas[2] = 8.90;
    insereHash_EnderAberto(hash, a1);
    insereHash_SemColisao(hash, a3);
    insereHash_EnderAberto(hash, a4);
    insereHash_EnderAberto(hash, a2);
    imprime_Hash(hash);
    buscaHash_EnderAberto(hash,1612520);
    buscaHash_SemColisao(hash,1912304);
    libera_Hash(hash);

    return 0;
}



