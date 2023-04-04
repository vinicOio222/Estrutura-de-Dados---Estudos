#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "FilaDin.h"

struct Nodo{
    struct aluno dados;
    struct Nodo *prox;
};

struct fila{
    struct Nodo *inicio;
    struct Nodo *final;
    int qtd;
};

typedef struct Nodo nodo;

Fila* cria_Fila(){
    Fila *fi = (Fila *)malloc(sizeof(struct fila));
    if(fi != NULL) {
        fi->inicio = NULL;
        fi->final = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    if(fi != NULL){
        nodo* no = fi->inicio;
        while(no != NULL){
            fi->inicio = fi->inicio->prox;
            free(no);
            no = fi->inicio;
        }
        free(fi);
    }
}

int insere_Fila(Fila* fi, struct aluno al){
    if(fi == NULL)
        return 0;
    nodo* no = (nodo*)malloc(sizeof(nodo));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if(fi->final == NULL)
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

int remove_Fila(Fila* fi){
    if(fi == NULL || fi->inicio == NULL)
        return 0;
    nodo *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    free(no);

    if(fi->inicio == NULL)
        fi->final = NULL;

    fi->qtd--;
    return 1;
}

void consulta_Fila(Fila* fi, int pos){
    if(fi == NULL || pos <= 0 || pos > fi->qtd){
        printf("Posição inválida.\n");
        return;
    }
    nodo *no = fi->inicio;
    int i;
    for(i = 1; i < pos; i++){
        no = no->prox;
    }
    printf("\n==ALUNO ENCONTRADO==\n");
    printf("Nome: %s\n", no->dados.nome);
    printf("Matrícula: %d\n", no->dados.matricula);
    printf("NotaS: %.2f, %.2f, %.2f\n", no->dados.notas[0], no->dados.notas[1], no->dados.notas[2]);
    printf("\n");
}

void imprime_Fila(Fila* fi){
    if(fi == NULL){
        printf("Fila não existe.\n");
        return;
    }
    nodo *no = fi->inicio;
    printf("\n===FILA DE ALUNOS===\n");
    while(no != NULL){
        printf("Nome: %s\n", no->dados.nome);
        printf("Matrícula: %d\n", no->dados.matricula);
        printf("NotaS: %.2f, %.2f, %.2f\n", no->dados.notas[0], no->dados.notas[1], no->dados.notas[2]);
        printf("----------------------\n");
        no = no->prox;
    }
}


void tamanho_Fila(Fila *fi){
    if(fi == NULL)
      printf("Erro: a lista não foi criada!\n");
    printf("Tamanho da lista: %d\n",fi->qtd);
}


int main(){
    Fila* queue = cria_Fila();
    struct aluno a1, a2, a3;
    strcpy(a1.nome,"Vinícius");
    a1.matricula = 1612520;
    a1.notas[0] = 8.0;
    a1.notas[1] = 9.67;
    a1.notas[2] = 7.56;
    strcpy(a2.nome, "Andrei");
    a2.matricula = 1612520;
    a2.notas[0] = 9.37;
    a2.notas[1] = 9.60;
    a2.notas[2] = 7.85;
    strcpy(a3.nome,"Marina");
    a3.matricula = 1612520;
    a3.notas[0] = 8.8;
    a3.notas[1] = 8.67;
    a3.notas[2] = 7.92;
    insere_Fila(queue, a1);
    insere_Fila(queue, a2);
    insere_Fila(queue, a3);
    imprime_Fila(queue);
    tamanho_Fila(queue);
    remove_Fila(queue);
    imprime_Fila(queue);
    tamanho_Fila(queue);
    consulta_Fila(queue,1);
    libera_Fila(queue);
    return 0;
}


