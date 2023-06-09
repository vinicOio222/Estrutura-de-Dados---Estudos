#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ArvSports.h"

struct No{
    char nome[60];
    int pontos;
    struct No* esq;
    struct No* dir;
};

ArvSports* cria_Arv(){
    ArvSports* raiz = (ArvSports*)malloc(sizeof(ArvSports));
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

void libera_Arv(ArvSports* raiz){
    if(raiz == NULL)
       return;
    libera_No(*raiz);
    free(raiz);
}

int insere_Time(ArvSports* raiz, char nome[], int pontuacao){
    if(raiz == NULL)
        return 0;
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    if(novo == NULL)
        return 0;

    int i;
    for(i = 0; i<61 && nome[i]!= '\0'; i++){
        novo->nome[i] = nome[i];
    }
    novo->nome[i] = '\0';
    novo->pontos = pontuacao;
    novo->esq = NULL;
    novo->dir = NULL;

    if(*raiz == NULL)
       *raiz = novo;
    else{
        struct No* atual = *raiz;
        struct No* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(pontuacao == atual->pontos){
                free(novo);
                return 0;
            }
            if(pontuacao > atual->pontos)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(pontuacao > ant->pontos)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

int remove_Time(ArvSports* raiz, char nome[]) {
    if (raiz == NULL || *raiz == NULL)
        return 0;

    struct No* atual = *raiz;
    struct No* antecessor = NULL;

    while (atual != NULL) {
        int comp = strcmp(nome, atual->nome);

        if (comp == 0) {
            if (antecessor == NULL) {
                if (atual->esq == NULL && atual->dir == NULL) {
                    free(atual);
                    *raiz = NULL;
                } else if (atual->esq == NULL) {
                    *raiz = atual->dir;
                    free(atual);
                } else if (atual->dir == NULL) {
                    *raiz = atual->esq;
                    free(atual);
                } else {
                    struct No* sucessor = atual->dir;
                    struct No* antecessor_sucessor = atual;

                    while (sucessor->esq != NULL) {
                        antecessor_sucessor = sucessor;
                        sucessor = sucessor->esq;
                    }

                    if (antecessor_sucessor != atual) {
                        antecessor_sucessor->esq = sucessor->dir;
                        sucessor->dir = atual->dir;
                    }

                    sucessor->esq = atual->esq;
                    free(atual);
                    *raiz = sucessor;
                }
            } else {
                if (atual->esq == NULL && atual->dir == NULL) {
                    if (antecessor->esq == atual) {
                        antecessor->esq = NULL;
                    } else {
                        antecessor->dir = NULL;
                    }
                    free(atual);
                } else if (atual->esq == NULL) {
                    if (antecessor->esq == atual) {
                        antecessor->esq = atual->dir;
                    } else {
                        antecessor->dir = atual->dir;
                    }
                    free(atual);
                } else if (atual->dir == NULL) {
                    if (antecessor->esq == atual) {
                        antecessor->esq = atual->esq;
                    } else {
                        antecessor->dir = atual->esq;
                    }
                    free(atual);
                } else {
                    struct No* sucessor = atual->dir;
                    struct No* antecessor_sucessor = atual;

                    while (sucessor->esq != NULL) {
                        antecessor_sucessor = sucessor;
                        sucessor = sucessor->esq;
                    }

                    if (antecessor_sucessor != atual) {
                        antecessor_sucessor->esq = sucessor->dir;
                        sucessor->dir = atual->dir;
                    }

                    sucessor->esq = atual->esq;
                    if (antecessor->esq == atual) {
                        antecessor->esq = sucessor;
                    } else {
                        antecessor->dir = sucessor;
                    }
                    free(atual);
                }
            }

        return 1;
        } else if (comp < 0) {
            antecessor = atual;
            atual = atual->esq;
        } else {
            antecessor = atual;
            atual = atual->dir;
        }
    }
    return 0;
}


int reinsere_Time(ArvSports* raiz, char nome[], int pontuacao) {
    if (raiz == NULL)
        return 0;

    struct No* novo = (struct No*)malloc(sizeof(struct No));
    if (novo == NULL)
        return 0;

    int i;
    for (i = 0; i < 61 && nome[i] != '\0'; i++) {
        novo->nome[i] = nome[i];
    }
    novo->nome[i] = '\0';
    novo->pontos = pontuacao;
    novo->esq = NULL;
    novo->dir = NULL;

    if (*raiz == NULL) {
        *raiz = novo;
        return 1;
    } else{
        struct No* atual = *raiz;
        struct No* antecessor = NULL;

        while (atual != NULL) {
            antecessor = atual;
            if (pontuacao == atual->pontos) {
                free(novo);
                return 0;
            } else if (pontuacao < atual->pontos) {
                atual = atual->esq;
            } else {
                atual = atual->dir;
            }
        }

        if (pontuacao < antecessor->pontos) {
            antecessor->esq = novo;
        } else {
            antecessor->dir = novo;
        }

        return 1;
    }
}

int alteraPontos_Time(ArvSports* raiz, char nome[], int novos_pontos) {
    if (raiz == NULL)
        return 0;
    if (!remove_Time(raiz, nome))
        return 0;
    if (!insere_Time(raiz, nome, novos_pontos))
        return 0;

    return 1;
}


void classificao_Arv(ArvSports* raiz){
    if(raiz == NULL)
       return;
    if(*raiz != NULL){
        classificao_Arv(&((*raiz)->dir));
        printf("Time: %s\n", (*raiz)->nome);
        printf("Pontuação: %d\n", (*raiz)->pontos);
        printf("----------------------\n");
        classificao_Arv(&((*raiz)->esq));
    }
}

int main(){
    ArvSports* raiz = cria_Arv();
    insere_Time(raiz, "Asgardians", 17);
    insere_Time(raiz, "Sentinels of Heaven", 333);
    insere_Time(raiz, "Em Paulo Henrique nós confiamos!", 452);
    insere_Time(raiz, "Gusta, casa comigo!", 999);
    insere_Time(raiz, "Metallica", 18);
    insere_Time(raiz, "Areuokin!", 38);
    insere_Time(raiz, "Larces Soldiers", 286);
    insere_Time(raiz, "Gesaders", 246);
    insere_Time(raiz, "Laurasianos", 152);
    printf("===Classificação(1)===\n");
    classificao_Arv(raiz);
    printf("\nTime raiz: %s\n", (*raiz)->nome);
    printf("\n");
    alteraPontos_Time(raiz, "Metallica", 353);
    printf("===Classificação(2)===\n");
    classificao_Arv(raiz);
    printf("\nTime raiz: %s\n", (*raiz)->nome);
    printf("\n");
    alteraPontos_Time(raiz, "Asgardians", 166);
    printf("===Classificação(3)===\n");
    classificao_Arv(raiz);
    printf("\nTime raiz: %s\n", (*raiz)->nome);
    libera_Arv(raiz);

    return 0;
}
