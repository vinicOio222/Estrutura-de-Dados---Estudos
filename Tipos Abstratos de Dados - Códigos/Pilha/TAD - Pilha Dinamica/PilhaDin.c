#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "PilhaDin.h"

struct Nodo{
    struct livro dados;
    struct Nodo *prox;

};

typedef struct Nodo nodo;

Pilha* cria_pilha(){
    Pilha* pi = (Pilha*)malloc(sizeof(Pilha));
    if(pi != NULL){
        *pi = NULL;
    }
    return pi;
}

void libera_pilha(Pilha* pi){
    if(pi != NULL){
        nodo* no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }

}

void tamanho_pilha(Pilha* pi){
    if(pi == NULL){
       printf("Erro: a pilha não foi criada!\n");
       return;
    }
    int cont = 0;
    nodo* no = *pi;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    printf("Tamanho da pilha: %d\n", cont);
}

int insere_pilha(Pilha* pi, struct livro li){
    if(pi == NULL)
       return 0;
    nodo* no;
    no = (nodo*)malloc(sizeof(nodo));
    if(no == NULL)
       return 0;
    no->dados = li;
    no->prox = (*pi);
    *pi = no;
    return 1;

}

int remove_pilha(Pilha* pi){
    if(pi == NULL)
       return 0;
    if((*pi) == NULL)
       return 0;
    nodo* no = *pi;
    *pi = no->prox;
    free(no);
    return 1;

}

void consulta_pilha(Pilha* pi, int pos){
    if(pi == NULL)
    printf("Erro: Pilha não criada!");
    nodo *no = *pi;
    int i = 1;
    while(no != NULL && i>pos){
        no = no->prox;
        i++;
    }
    if(no == NULL || pos <= 0 )
      printf("Livro com posição %d não encontrado na pilha!\n", pos);
    else{
        printf("\n===LIVRO ENCONTRADO===\n");
        printf("Titulo: %s\n", no->dados.titulo);
        printf("Autor: %s\n", no->dados.autor);
        printf("ID: %d\n", no->dados.id);
        printf("---------------------------\n");
    }

}

void acessa_pilha_topo(Pilha* pi){
    if(pi == NULL){
       printf("Erro: Pilha não criada!");
       return;
    }
    if((*pi) == NULL){
        printf("Erro: Pilha vazia!");
       return;
    }
    printf("\n===TOPO DA PILHA===\n");
    printf("Titulo: %s\n", (*pi)->dados.titulo);
    printf("Autor: %s\n",  (*pi)->dados.autor);
    printf("ID: %d\n",  (*pi)->dados.id);
    printf("---------------------------\n");

}

void imprime_pilha(Pilha* pi){
    if(pi == NULL){
       printf("Erro: Lista não criada!");
       return;
    }
    nodo *no = *pi;
    printf("\n===PILHA DE LIVROS===\n");
    while(no != NULL){
        printf("Titulo: %s\n", no->dados.titulo);
        printf("Autor: %s\n", no->dados.autor);
        printf("ID: %d\n", no->dados.id);
        printf("---------------------------\n");
        no = no->prox;
    }
}



int main(){
    Pilha* pi = cria_pilha();
    struct livro l1, l2, l3;
    strcpy(l1.titulo, "Dom Casmurro");
    strcpy(l1.autor,"Machado de Assis");
    l1.id = 1555;
    strcpy(l2.titulo, "O Diário de Anne Franke");
    strcpy(l2.autor,"Anne Franke");
    l2.id = 1556;
    strcpy(l3.titulo, "Super-Man - Entre a Foice e o Martelo");
    strcpy(l3.autor,"Mark Miller");
    l3.id = 1557;
    insere_pilha(pi, l1);
    insere_pilha(pi, l2);
    insere_pilha(pi, l3);
    imprime_pilha(pi);
    acessa_pilha_topo(pi);
    tamanho_pilha(pi);
    remove_pilha(pi);
    imprime_pilha(pi);
    tamanho_pilha(pi);
    consulta_pilha(pi,2);
    acessa_pilha_topo(pi);
    libera_pilha(pi);
    return 0;

}

