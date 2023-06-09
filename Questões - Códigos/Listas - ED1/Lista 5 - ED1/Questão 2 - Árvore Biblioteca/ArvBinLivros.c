#include<stdio.h>
#include<stdlib.h>
#include"ArvBinLivros.h"

struct No{
    char titulo[40];
    char autor[30];
    int id;
    int ano;
    struct No* esq;
    struct No* dir;

};

ArvBinLivros* cria_ArvBin(){
    ArvBinLivros* raiz = (ArvBinLivros*)malloc(sizeof(ArvBinLivros));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_No(struct No* no){
    if(no == NULL)
       return;
    libera_No(no->esq);
    libera_No(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBinLivros* raiz){
    if(raiz == NULL)
       return;
    libera_No(*raiz);
    free(raiz);
}

int insere_Livro(ArvBinLivros* raiz, char nome[], char autor[], int id, int ano) {
    if (raiz == NULL)
        return 0;

    struct No* novo = (struct No*)malloc(sizeof(struct No));
    if (novo == NULL)
        return 0;

    int i;
    for (i = 0; i < 41 && nome[i] != '\0'; i++) {
        novo->titulo[i] = nome[i];
    }
    novo->titulo[i] = '\0';

    for (i = 0; i < 31 && autor[i] != '\0'; i++) {
        novo->autor[i] = autor[i];
    }
    novo->autor[i] = '\0';

    novo->id = id;
    novo->ano = ano;
    novo->esq = NULL;
    novo->dir = NULL;

    if (*raiz == NULL)
        *raiz = novo;
    else {
        struct No* atual = *raiz;
        struct No* ant = NULL;

        while (atual != NULL) {
            ant = atual;
            if (id == atual->id) {
                free(novo);
                return 0;
            }
            if (id > atual->id)
                atual = atual->dir;
            else
                atual = atual->esq;
        }

        if (id > ant->id)
            ant->dir = novo;
        else
            ant->esq = novo;
    }

    return 1;
}


void imprime_Biblioteca(ArvBinLivros* raiz){
    if(raiz == NULL)
       return;
    if(*raiz != NULL){
        imprime_Biblioteca(&((*raiz)->esq));
        printf("Título: %s\n", (*raiz)->titulo);
        printf("Autor: %s\n", (*raiz)->autor);
        printf("ID: %d\n", (*raiz)->id);
        printf("Ano: %d\n", (*raiz)->ano);
        printf("---------------------\n");
        imprime_Biblioteca(&((*raiz)->dir));
    }
}

int comparaStrings(char str1[], char str2[]){
    int i = 0;
    while(str1[i] != '\0' && str2[i] != '\0'){
        if(str1[i] < str2[i])
           return -1;
        else if (str1[i] > str2[i])
           return 1;
        i++;
    }

    if(str1[i] == '\0' && str2[i] == '\0')
       return 0;
    else if(str1[i] == '\0')
       return -1;
    else
       return 1;
}


void consulta_Livro(ArvBinLivros* raiz, char autor[], int ano_inicial, int ano_final){
    if(raiz == NULL || *raiz == NULL)
        return;

    struct No* atual = *raiz;
    while(atual != NULL){
         if(comparaStrings(autor, atual->autor) > 0){
            atual = atual->esq;
        }else if(comparaStrings(autor, atual->autor) > 0){
            atual = atual->dir;
        }else{
            if(atual->ano >= ano_inicial && atual-> ano <= ano_final){
                printf("=====Livro de %s =====\n", autor);
                printf("Título: %s\n", atual->titulo);
                printf("Autor: %s\n", atual->autor);
                printf("ID: %d\n", atual->id);
                printf("Ano: %d\n", atual->ano);
                printf("-----------------------\n");
            }
            consulta_Livro(&(atual->esq), autor, ano_inicial, ano_final);
            consulta_Livro(&(atual->dir), autor, ano_inicial, ano_final);
            return;
        }

    }

}

int main(){
    ArvBinLivros* raiz = cria_ArvBin();
    insere_Livro(raiz, "Os Sertões", "Euclides da Cunha", 187299 , 1902);
    insere_Livro(raiz, "Grande Sertão - Veredas do Campo", "Guimarães Rosa", 187300, 1956);
    insere_Livro(raiz, "Vidas Secas", "Graciliano Ramos", 170331, 1938);
    insere_Livro(raiz, "A menina que roubava livros", "Markus Zusak", 131465, 2005);
    insere_Livro(raiz, "Jogador Nº 1", "Ernest Cline", 130044, 2011);
    insere_Livro(raiz, "Jogador Nº 2" ,"Ernest Cline", 166122, 2020);
    consulta_Livro(raiz, "Graciliano Ramos", 1938, 1989);
    consulta_Livro(raiz, "Markus Zusak", 2005, 2023);
    consulta_Livro(raiz, "Ernest Cline", 2000, 2023);
    printf("\n====BIBLIOTECA====\n");
    imprime_Biblioteca(raiz);
    printf("\nLivro Raiz: %s\n", (*raiz)->titulo);
    libera_ArvBin(raiz);

    return 0;
}
