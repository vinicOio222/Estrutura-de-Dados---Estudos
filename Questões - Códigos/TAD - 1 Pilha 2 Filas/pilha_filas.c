#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "pilha_filas.h"

struct pilha{
    Fila* f1;
    Fila* f2;

};

Fila* criarFila(){
    Fila* fi = (Fila*)malloc(sizeof(Fila));
    fi->inicio = 0;
    fi->final = -1;
    return fi;
}

void enfileirar(Fila* fi, int elemento){
    if(filaCheia(fi)){
        printf("Fila cheia!\n");
        return;
    }
    fi->final++;
    fi->dados[fi->final] = elemento;

}

int desenfileirar(Fila* fi){
    if(filaVazia(fi)){
        printf("Fila vazia!\n");
        return -1;
    }
    int elemento = fi->dados[fi->inicio];
    fi->inicio++;
    return elemento;

}

int filaVazia(Fila* fi){
    return fi->inicio > fi->final;
}

int filaCheia(Fila* fi){
    return fi->final == MAX - 1;
}

void liberaFila(Fila* fi){
    free(fi);
}

Pilha* criarPilha(){
    Pilha *pi = (Pilha*)malloc(sizeof(Pilha));
    pi->f1 = criarFila();
    pi->f2 = criarFila();
    return pi;
}

int pilhaVazia(Pilha *pi){
    return filaVazia(pi->f1);
}

void empilhar(Pilha *pi, int elemento){
    enfileirar(pi->f2, elemento);
    while(!filaVazia(pi->f1)){
        enfileirar(pi->f2, desenfileirar(pi->f1));
    }
    Fila *temp = pi->f1;
    pi->f1 = pi->f2;
    pi->f2 = temp;
}

int desempilhar(Pilha *pi){
    if(pilhaVazia(pi)){
        printf("Pilha vazia!\n");
        exit(1);
    }
    return desenfileirar(pi->f1);
}

int topoPilha(Fila* fi){
    if(filaVazia(fi)){
        printf("Fila vazia!\n");
        return -1;
    }
    return fi->dados[fi->inicio];

}

void liberaPilha(Pilha* pi){
    liberaFila(pi->f1);
    liberaFila(pi->f2);
    free(pi);
}

int main(){
    Pilha* pi = criarPilha();
    empilhar(pi, 1);
    empilhar(pi, 2);
    empilhar(pi, 3);
    empilhar(pi, 4);

    printf("Desempilhando o valor %d da pilha\n", desempilhar(pi));
    printf("Desempilhando o valor %d da pilha\n", desempilhar(pi));
    printf("Desempilhando o valor %d da pilha\n", desempilhar(pi));
    printf("Desempilhando o valor %d da pilha\n", desempilhar(pi));
    printf("Desempilhando o valor %d da pilha\n", desempilhar(pi));


    return 0;

}






