#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"ArvBin.h"

struct No{
    int valor;
    struct No* esq;
    struct No* dir;

};

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*)malloc(sizeof(ArvBin));
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

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
       return;
    libera_No(*raiz);
    free(raiz);
}

int totalNo_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
       return 0;
    if(*raiz == NULL)
       return 0;

    int total_esq = totalNo_ArvBin(&((*raiz)->esq));
    int total_dir = totalNo_ArvBin(&((*raiz)->dir));
    return (total_esq + total_dir + 1);
}

int totalFolhas_ArvBin(ArvBin* raiz){
    if(raiz == NULL || *raiz == NULL)
        return 0;

    if((*raiz)-> esq == NULL && (*raiz)->dir == NULL)
       return 1;

    int total_esq = totalFolhas_ArvBin(&((*raiz)->esq));
    int total_dir = totalFolhas_ArvBin(&((*raiz)->dir));

    return total_esq + total_dir;
}

int altura_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
       return 0;
    if(*raiz == NULL)
       return 0;

    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if(alt_esq > alt_dir)
        return(alt_esq + 1);
    else
        return(alt_dir + 1);
}

void preOrdem_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
       return;
    if(*raiz != NULL){
       printf("%d\n", (*raiz)->valor);
       preOrdem_ArvBin(&((*raiz)->esq));
       preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void emOrdem_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
       return;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d\n", (*raiz)->valor);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
       return;
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%d\n", (*raiz)->valor);
    }
}

int maiorValor_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
       return -1;
    if(*raiz == NULL)
       return -1;

    struct No* atual = *raiz;
    while(atual->dir != NULL)
       atual = atual->dir;
    return atual->valor;
}

int somaValores_ArvBin(ArvBin* raiz, int *cont){
    if(raiz == NULL)
       return 0;
    if(*raiz == NULL)
       return 0;
    int soma_esq = somaValores_ArvBin(&((*raiz)->esq), cont);
    int soma_dir = somaValores_ArvBin(&((*raiz)->dir), cont);
    int total = soma_esq + soma_dir + (*raiz)->valor;
    (*cont)++;

    return total;

}

int mediaValores_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
       return 0;
    if(*raiz == NULL)
       return 0;

    int cont = 0;
    int soma = somaValores_ArvBin(raiz, &cont);
    if(cont == 0)
       return 0;

    return soma/cont;
}

int numeroNULLS_ArvBin(ArvBin* raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 1;
    int nulls_esq = numeroNULLS_ArvBin(&((*raiz)->esq));
    int nulls_dir = numeroNULLS_ArvBin(&((*raiz)->dir));
    return nulls_esq + nulls_dir;

}

int somaChaves_Nos(ArvBin* raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;

    int soma_esq = somaChaves_Nos(&((*raiz)->esq));
    int soma_dir = somaChaves_Nos(&((*raiz)->dir));
    int soma_atual = (*raiz)->valor;
    return soma_esq + soma_dir + soma_atual;

}

int multTres_Nos(ArvBin* raiz) {
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;

    int mult_esq = multTres_Nos(&((*raiz)->esq));
    int mult_dir = multTres_Nos(&((*raiz)->dir));
    int mult_atual = 0;

    if ((*raiz)->valor % 3 == 0)
        mult_atual = 1 ;

    return mult_esq + mult_dir + mult_atual;
}


int consulta_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct No* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->valor)
            printf("Valor encontrado: %d\n", atual->valor);
            return 1;
        if(valor > atual->valor)
            atual = atual->dir;
        else
            atual = atual->esq;
    }

    printf("Valor %d não encontrado na árvore!", valor);
    return 0;

}

int verifica_ArvBinRec(struct No* no, int min, int max){
    if(no == NULL)
       return 1;
    if(no->valor < min || no->valor > max)
       return 0;

    return verifica_ArvBinRec(no->esq, min, no->valor - 1) && verifica_ArvBinRec(no->dir, no->valor + 1, max);

}

int verifica_ArvBin(ArvBin* raiz){
    if(raiz == NULL || *raiz == NULL)
       return 1;

    return verifica_ArvBinRec(*raiz, INT_MIN, INT_MAX);
}

int insere_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL)
       return 0;
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    if(novo == NULL)
       return 0;
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    if(*raiz == NULL)
       *raiz = novo;
    else{
        struct No* atual = *raiz;
        struct No* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->valor){
                free(novo);
                return 0;
            }
            if(valor > atual->valor)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->valor)
            ant->dir = novo;
        else
            ant->esq = novo;
        }
        return 1;

}

int main(){
    ArvBin* raiz = cria_ArvBin();
    printf("Inserção na Árvore Binária - Pós-Ordem:\n");
    insere_ArvBin(raiz, 3);
    posOrdem_ArvBin(raiz);
    printf("\n");
    printf("Raiz: %d\n",(*raiz)->valor);
    printf("\n");
    insere_ArvBin(raiz, 20);
    posOrdem_ArvBin(raiz);
    printf("\n");
    printf("Raiz: %d\n",(*raiz)->valor);
    printf("\n");
    insere_ArvBin(raiz, 50);
    posOrdem_ArvBin(raiz);
    printf("\n");
    printf("Raiz: %d\n",(*raiz)->valor);
    printf("\n");
    insere_ArvBin(raiz, 12);
    posOrdem_ArvBin(raiz);
    printf("\n");
    printf("Raiz: %d\n",(*raiz)->valor);
    printf("\n");
    insere_ArvBin(raiz, 1);
    posOrdem_ArvBin(raiz);
    printf("\n");
    printf("Raiz: %d\n",(*raiz)->valor);
    printf("\n");
    consulta_ArvBin(raiz, 20);
    printf("\n====Outras funções====\n");
    printf("Maior Valor: %d\n", maiorValor_ArvBin(raiz));
    printf("Média de Valores: %d\n", mediaValores_ArvBin(raiz));
    printf("Soma de Chaves: %d\n", somaChaves_Nos(raiz));
    printf("Nós múltiplos de 3: %d\n", multTres_Nos(raiz));
    printf("Total de Nós: %d\n", totalNo_ArvBin(raiz));
    printf("Total de Nós Folha: %d\n", totalFolhas_ArvBin(raiz));
    printf("Altura da Árvore: %d\n", altura_ArvBin(raiz));
    printf("A Árvore é Binária ? %d\n", verifica_ArvBin(raiz));
    printf("\nÁrvore - Pré-Ordem\n");
    preOrdem_ArvBin(raiz);
    printf("\n");
    printf("Raiz: %d\n", (*raiz)->valor);
    printf("\n");
    printf("\nÁrvore - Em Ordem\n");
    emOrdem_ArvBin(raiz);
    printf("\n");
    printf("Raiz: %d\n", (*raiz)->valor);
    printf("\n");
    printf("\nÁrvore - Pós-Ordem\n");
    posOrdem_ArvBin(raiz);
    printf("\n");
    printf("Raiz: %d\n", (*raiz)->valor);

    libera_ArvBin(raiz);


    return 0;

}

