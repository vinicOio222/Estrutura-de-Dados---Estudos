#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"pilha_palindromo.h"

void empilhar(Pilha *pi, char caracter){
    pi->dados[++pi->topo] = caracter;
}

int desempilhar(Pilha *pi){
    return pi->dados[pi->topo--];
}

char topoPilha(Pilha *pi){
    return pi->dados[pi->topo];
}

int pilhaVazia(Pilha *pi){
    return pi->topo == -1;
}

int eUmPalindromo(char *palavra){
    int tamanho_palav = strlen(palavra);
    Pilha pi;
    pi.topo = -1;
    for(int i = 0; i < tamanho_palav; i++){
        if(isalpha(palavra[i])){
            empilhar(&pi, tolower(palavra[i]));
        }
    }
    int i = 0;
    while(!pilhaVazia(&pi)){
        if(isalpha(palavra[i]) && tolower(palavra[i]) != desempilhar(&pi)){
            return 0;
        }
        i++;
    }
    return 1;
}

int main(){
    char palavra[MAX];
    printf("Digite uma palavra: ");
    fgets(palavra, MAX, stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    if(eUmPalindromo(palavra)){
        printf("%s eh um palindromo! \n", palavra);

    }else{
        printf("%s nao eh um palindromo! \n", palavra);
    }

    return 0;
}


