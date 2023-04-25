#include<stdio.h>
#include<stdlib.h>
#include"ArvBin.h"

struct No{
    int info;
    struct No *esq;
    struct No *dir;
};

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_No(struct No *no){
    if(no == NULL)
        return;
    libera_No(no->esq);
    libera_No(no->dir);
    free(no);
    no = NULL;

}

void libera_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    libera_No(*raiz);
    free(raiz);
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNo_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int total_esq = totalNo_ArvBin(&((*raiz)->esq));
    int total_dir = totalNo_ArvBin(&((*raiz)->dir));
    return(total_esq + total_dir + 1);
}

int altura_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 0;
    if(*raiz ==  NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if(alt_esq > alt_dir)
        return(alt_esq + 1);
    else
        return(alt_dir + 1);
}

void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void emOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
       return;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
       return;
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info);
    }
}

int consulta_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct No* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info)
            return 1;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }

    return 0;

}

int insere_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct No* novo;
    novo = (struct No*)malloc(sizeof(struct No));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
       *raiz = novo;
    else{
        struct No* atual = *raiz;
        struct No* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
               free(novo);
               return 0;
        }
        if(valor > atual->info)
           atual = atual->dir;
        else
           atual = atual->esq;
    }
    if(valor > ant->info)
        ant->dir = novo;
    else
        ant->esq = novo;
    }
    return 1;

}

struct No* remove_atual(struct No* atual){
    struct No *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int remove_ArvBin(ArvBin *raiz, int valor){
    if(*raiz == NULL)
       return 0;
    struct No* ant = NULL;
    struct No* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
           if(atual == *raiz)
              *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                   ant->dir = remove_atual(atual);
                else
                   ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor >atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int main(){
    ArvBin* raiz = cria_ArvBin();
    printf("Inserção na Árvore Binária:\n");
    insere_ArvBin(raiz, 10);
    posOrdem_ArvBin(raiz);
    printf("\n");
    insere_ArvBin(raiz, 20);
    posOrdem_ArvBin(raiz);
    printf("\n");
    insere_ArvBin(raiz, 50);
    posOrdem_ArvBin(raiz);
    printf("\n");
    insere_ArvBin(raiz, 12);
    posOrdem_ArvBin(raiz);
    printf("\n");
    printf("Remoção na Árvore Binária:\n");
    remove_ArvBin(raiz, 10);
    emOrdem_ArvBin(raiz);
    printf("\n");
    remove_ArvBin(raiz, 20);
    posOrdem_ArvBin(raiz);
    printf("\n");
    remove_ArvBin(raiz, 50);
    posOrdem_ArvBin(raiz);
    printf("\n");
    remove_ArvBin(raiz, 12);
    posOrdem_ArvBin(raiz);
    printf("\n");
    libera_ArvBin(raiz);
    return 0;

}
