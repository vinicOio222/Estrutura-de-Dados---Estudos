#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "PilhaEstatica.h"

struct pilha{
    int qtd;
    struct livro dados[MAX];

};

Pilha* cria_pilha(){
    Pilha* pi = (Pilha*)malloc(sizeof(struct pilha));
    if(pi != NULL){
        pi->qtd = 0;
    }
    return pi;
}

void libera_pilha(Pilha* pi){
    free(pi);

}

void tamanho_pilha(Pilha* pi){
    if(pi == NULL){
       printf("Erro: a pilha não foi criada!\n");
       return;
    }else{
       printf("Tamanho da pilha: %d\n", pi->qtd);
    }
}

int insere_pilha(Pilha* pi, struct livro li){
    if(pi == NULL)
       return 0;
    if(pi->qtd == MAX)
       return 0;
    pi->dados[pi->qtd] = li;
    pi->qtd++;
    return 1;

}

int remove_pilha(Pilha* pi){
    if(pi == NULL || pi->qtd == 0)
       return 0;
    pi->qtd--;
    return 1;

}

void consulta_pilha(Pilha *pi, int pos){
    if(pi == NULL || pi->qtd == 0){
        printf("Erro: a pilha não foi criada!\n");
    }
    if(pos >= 0 && pos < pi->qtd){
        printf("\n==ALUNO ENCONTRADO==\n\n");
        printf("Titulo: %s\n",pi->dados[pos].titulo);
        printf("Autor: %s\n",pi->dados[pos].autor);
        printf("ID: %d\n", pi->dados[pos].id);
        printf("\n");
    }else{
        printf("Livro com posicao %d nao encontrado na pilha!",pos);
    }
}

void imprime_pilha(Pilha* pi){
    if(pi == NULL)
        printf("Erro: a pilha não foi criada!\n");
    printf("\n===PILHA DE LIVROS===\n");
    for(int i = 0; i<pi->qtd; i++){
        printf("Nome: %s\n", pi->dados[i].titulo);
        printf("Autor: %s\n", pi->dados[i].autor);
        printf("ID: %d\n", pi->dados[i].id);
        printf("---------------------\n");
    }
}

void acessa_topo_pilha(Pilha *pi){
    if(pi == NULL){
        printf("Erro: a pilha não foi criada!\n");
    }else{
        printf("\n===TOPO DA PILHA===\n");
        printf("Nome: %s\n", pi->dados[pi->qtd-1].titulo);
        printf("Autor: %s\n", pi->dados[pi->qtd-1].autor);
        printf("ID: %d\n", pi->dados[pi->qtd-1].id);
        printf("---------------------\n");

    }
}


int main(){
    Pilha* pi = cria_pilha();
    struct livro l1, l2, l3;
    strcpy(l1.titulo, "Duna");
    strcpy(l1.autor,"Frank Herbet");
    l1.id = 1555;
    strcpy(l2.titulo, "Scott Pilgrim - Contra o Mundo");
    strcpy(l2.autor,"Bryan Lee O'Malley");
    l2.id = 1556;
    strcpy(l3.titulo, "O Cortiço");
    strcpy(l3.autor,"Aluíso de Azevedo");
    l3.id = 1557;
    insere_pilha(pi, l1);
    insere_pilha(pi, l2);
    insere_pilha(pi, l3);
    imprime_pilha(pi);
    acessa_topo_pilha(pi);
    tamanho_pilha(pi);
    remove_pilha(pi);
    imprime_pilha(pi);
    tamanho_pilha(pi);
    consulta_pilha(pi,0);
    acessa_topo_pilha(pi);
    libera_pilha(pi);
    return 0;

}
