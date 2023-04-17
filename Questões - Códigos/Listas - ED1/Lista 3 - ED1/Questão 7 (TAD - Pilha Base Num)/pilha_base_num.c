#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"pilha_base_num.h"

void empilhar(Pilha* pi, int item){
    if(pi->topo == MAX - 1){
        printf("slha cheia!\n");
        return;
    }
    pi->dados[++pi->topo] = item;

}

int desempilhar(Pilha* pi){
    if(pi->topo == -1){
        printf("Pilha vazia!\n");
        return 0;
    }
    return pi->dados[pi->topo--];

}

int converterParaDecimal(Pilha* pi, int base){
    int dec = 0;
    int pos = 0;
    while(pi->topo != -1){
        int digito = desempilhar(pi);
        dec += digito * pow(base, pos++);
    }
    return dec;

}

int main() {
    Pilha pi;
    pi.topo = -1;
    empilhar(&pi, 1);
    empilhar(&pi, 1);
    empilhar(&pi, 1);
    empilhar(&pi, 1);
    empilhar(&pi, 0);

    int base = 2;
    int decimal = converterParaDecimal(&pi, base);
    printf("Valor decimal: %d\n", decimal);
    return 0;
}
