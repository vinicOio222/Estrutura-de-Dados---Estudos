#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"pilha_mat.h"

#define MAX_EXPR 100

void empilhar(Pilha* pi, char elementos){
    if(elementos == '(' || elementos == ')'){
        pi->topo++;
        pi->dados[pi->topo] = elementos;
    }
}

char desempilhar(Pilha* pi){
    char elemento = pi->dados[pi->topo];
    pi->topo--;
    return elemento;
}

int checarParenteses(char *expressao){
    Pilha pi;
    pi.topo = - 1;
    int tamanho_expr = strlen(expressao);
    for(int i = 0; i < tamanho_expr; i++){
        char caract = expressao[i];
        if(caract == '(' || caract == ')') {
            if(caract == '('){
                empilhar(&pi, caract);
            } else if(caract == ')') {
                if(pi.topo != -1 && desempilhar(&pi) == '('){
                    continue;
                } else{
                    return 0;
                }
            }
        }
    }
    if(pi.topo == -1){
        return 1;
    } else{
        return 0;
    }
}

int main() {
    char expr[MAX_EXPR];
    printf("Digite a expressao: ");
    scanf("%[^\n]", expr);

    if(checarParenteses(expr)) {
        printf("A expressao esta com a parentizacao correta.\n");
    }
    else {
        printf("A expressao esta com a parentizacao incorreta.\n");
    }

    return 0;
}
