#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "fila_inv.h"

struct fila{
    int itens[MAX];
    int inicio;
    int final;

};

void criar_fila(Fila* fi){
    fi->inicio = 0;
    fi->final = 0;

}

int fila_vazia(Fila* fi){
    if(fi->inicio == fi->final)
       return 1;
    else
       return 0;

}

int fila_cheia(Fila* fi){
    if(fi->final == MAX)
       return 1;
    else
       return 0;
}

void adicionar_fila(Fila* fi, int valor){
    if(fila_cheia(fi)){
        printf("Fila cheia!\n");
    }else{
        fi->itens[fi->final] = valor;
        fi->final++;
    }
}

int remover_fila(Fila* fi){
    int item;
    if(fila_vazia(fi)){
        printf("Fila está vazia!\n");
        item = -1;
    }else{
        item = fi->itens[fi->inicio];
        fi->inicio++;
    }
    return item;
}

void imprimir_fila(Fila* fi){
    int i;
    if(fila_vazia(fi)){
      printf("Fila está vazia!\n");
    }else{
        printf("\n====FILA====\n");
        for(i = fi->inicio; i < fi->final; i++){
            printf("%d ", fi->itens[i]);
        }
        printf("\n");
    }
}

void criar_pilha(Pilha* pi){
    pi->topo = -1;

}

int pilha_vazia(Pilha* pi){
    if(pi->topo == -1)
       return 1;
    else
       return 0;

}

int pilha_cheia(Pilha* pi){
    if(pi->topo == MAX - 1)
        return 1;
    else
        return 0;
}

void adicionar_pilha(Pilha* pi, int valor){
    if(pilha_cheia(pi)){
        printf("Pilha cheia!\n");
    }else{
        pi->topo++;
        pi->itens[pi->topo] = valor;
    }
}

int remover_pilha(Pilha* pi){
    int item;
    if(pilha_vazia(pi)){
        printf("Pilha vazia!\n");
        item = -1;

    }else{
        item = pi->itens[pi->topo];
        pi->topo--;
    }
    return item;
}

void reverter_fila(Fila* fi){
    Pilha pi;
    criar_pilha(&pi);
    while(!fila_vazia(fi)){
        adicionar_pilha(&pi, remover_fila(fi));
    }
    while(!pilha_vazia(&pi)){
        adicionar_fila(fi, remover_pilha(&pi));
    }
}

int main(){
    Fila fi;
    criar_fila(&fi);

    adicionar_fila(&fi, 5);
    adicionar_fila(&fi, 2);
    adicionar_fila(&fi, 3);
    adicionar_fila(&fi, 4);
    adicionar_fila(&fi, 333);

    imprimir_fila(&fi);

    reverter_fila(&fi);

    imprimir_fila(&fi);

    return 0;
}
