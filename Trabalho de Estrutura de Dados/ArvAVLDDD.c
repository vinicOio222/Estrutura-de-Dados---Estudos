#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"ArvAVLDDD.h"

struct Usuario{
    int telefone, DDD;
    char nome[30];
    char endereco[50];
    int alt;
    struct Usuario* esq;
    struct Usuario* dir;

};

AVLDDD* cria_AVL(){
    AVLDDD* raiz = (AVLDDD*)malloc(sizeof(AVLDDD));
    if(raiz != NULL)
       *raiz = NULL;
    return raiz;
}

void libera_No(struct Usuario* user){
    if(user == NULL)
       return;
    libera_No(user->esq);
    libera_No(user->dir);
    free(user);
    user = NULL;
}

void libera_AVL(AVLDDD* raiz){
    if(raiz == NULL)
       return;
    libera_No(*raiz);
    free(raiz);
}

int alt_No(struct Usuario* user){
    if(user == NULL)
       return -1;
    else
       return user->alt;
}

int totalNo_AVL(AVLDDD* raiz){
    if(raiz == NULL)
       return 0;
    if(*raiz == NULL)
       return 0;
    int total_esq = totalNo_AVL(&((*raiz)->esq));
    int total_dir = totalNo_AVL(&((*raiz)->dir));
    return (total_esq + total_dir + 1);
}

int altura_AVL(AVLDDD* raiz){
    if(raiz == NULL)
       return 0;
    if(*raiz == NULL)
       return 0;
    int alt_esq = altura_AVL(&((*raiz)->esq));
    int alt_dir = altura_AVL(&((*raiz)->dir));
    if(alt_esq > alt_dir)
       return (alt_esq + 1);
    else
       return (alt_dir + 1);
}

void preOrdem(AVLDDD* raiz){
    if(raiz == NULL)
       return;
    if(*raiz != NULL){
        printf("DDD: %d\n", (*raiz)->DDD);
        printf("Telefone: %d\n", (*raiz)->telefone);
        printf("Nome: %s\n", (*raiz)->nome);
        printf("Endereco: %s\n\n", (*raiz)->endereco);
        preOrdem(&((*raiz)->esq));
        preOrdem(&((*raiz)->dir));
    }
}

void emOrdem(AVLDDD* raiz){
    if(raiz == NULL)
       return;
    if(*raiz != NULL){
        emOrdem(&((*raiz)->esq));
        printf("DDD: %d\n", (*raiz)->DDD);
        printf("Telefone: %d\n", (*raiz)->telefone);
        printf("Nome: %s\n", (*raiz)->nome);
        printf("Endereco: %s\n\n", (*raiz)->endereco);
        emOrdem(&((*raiz)->dir));
    }
}

void posOrdem(AVLDDD* raiz){
    if(raiz == NULL)
       return;
    if(*raiz != NULL){
        posOrdem(&((*raiz)->esq));
        posOrdem(&((*raiz)->dir));
        printf("DDD: %d\n", (*raiz)->DDD);
        printf("Telefone: %d\n", (*raiz)->telefone);
        printf("Nome: %s\n", (*raiz)->nome);
        printf("Endereco: %s\n\n", (*raiz)->endereco);
    }
    return;
}

void emOrdemHash(AVLDDD* raiz, int *ultimoDDD, int nivel) {
    if (*raiz != NULL) {
        emOrdemHash(&((*raiz)->esq), ultimoDDD, nivel + 1);
        if ((*raiz)->DDD != *ultimoDDD) {
            printf("\n----- DDD %d -----\n", (*raiz)->DDD);
            *ultimoDDD = (*raiz)->DDD;
        }
        printf("Telefone: %d\n", (*raiz)->telefone);
        printf("Nome: %s\n", (*raiz)->nome);
        printf("Endereco: %s\n\n", (*raiz)->endereco);
        emOrdemHash(&((*raiz)->dir), ultimoDDD, nivel + 1);
    }
    if (nivel == 0) {
        printf("Nome do Contato Raiz: %s\n\n\n", (*raiz)->nome);
    }
}


struct Usuario* buscaContato(AVLDDD* raiz, int telefone){
    if(raiz == NULL || *raiz == NULL)
       return NULL;
    struct Usuario* atual = *raiz;
    if(telefone == atual->telefone){
        return atual;
    }
    if(telefone < atual->telefone)
        return buscaContato(&(atual->esq), telefone);
    else
        return buscaContato(&(atual->dir), telefone);

}

int busca_Numero(AVLDDD* raiz, int telefone){
    if(raiz == NULL)
       return 0;
    struct Usuario* atual = *raiz;
    while(atual != NULL){
        if(telefone == atual->telefone){
            printf("\n-----Contato Encontrado-----\n");
            printf("DDD: %d\n", (*raiz)->DDD);
            printf("Telefone: %d\n", atual->telefone);
            printf("Nome: %s\n", atual->nome);
            printf("Endereco: %s\n", atual->endereco);
            printf("-----------------------------\n");
            return 1;
        }
        if(telefone > atual->telefone)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

void busca_MenorNum(AVLDDD* raiz){
    if(raiz == NULL)
       return;
    struct Usuario* atual = *raiz;
    while(atual->esq != NULL)
        atual = atual->esq;
    printf("=====Menor Telefone=====\n");
    printf("DDD: %d\n", (*raiz)->DDD);
    printf("Telefone: %d\n", atual->telefone);
    printf("Nome: %s\n", atual->nome);
    printf("Endereco: %s\n", atual->endereco);
}


struct Usuario* procuraMenor(struct Usuario* atual){
    struct Usuario *no1 = atual, *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

int fatorBalanceamento(struct Usuario* user){
    return labs(alt_No(user->esq) - alt_No(user->dir));
}

int maior(int x, int y){
    if(x > y)
       return x;
    else
       return y;
}

void RotacaoLL(AVLDDD* raiz){
    struct Usuario* no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->alt = maior(alt_No((*raiz)->esq), alt_No((*raiz)->dir)) + 1;
    no->alt = maior(alt_No(no->esq), (*raiz)->alt) + 1;
    *raiz = no;
}

void RotacaoRR(AVLDDD* raiz){
    struct Usuario* no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = (*raiz);
    (*raiz)->alt = maior(alt_No((*raiz)->esq), alt_No((*raiz)->dir)) + 1;
    no->alt = maior(alt_No(no->dir), (*raiz)->alt) + 1;
    *raiz = no;
}

void RotacaoLR(AVLDDD* A){
    RotacaoRR(&(*A)->esq);
    RotacaoLL(A);
}

void RotacaoRL(AVLDDD* A){
    RotacaoLL(&(*A)->dir);
    RotacaoRR(A);
}

int insere_Contato(AVLDDD* raiz, int DDD, int telefone, char nome[], char endereco[]){
    int res;
    if (*raiz == NULL) {
        struct Usuario* novo = (struct Usuario*)malloc(sizeof(struct Usuario));
        if (novo == NULL) {
            return 0;
        }

        int i, j;
        for (i = 0; i < 31 && nome[i] != '\0'; i++) {
            novo->nome[i] = nome[i];
        }
        novo->nome[i] = '\0';

        for (j = 0; j < 51 && endereco[j] != '\0'; j++) {
            novo->endereco[j] = endereco[j];
        }
        novo->endereco[j] = '\0';

        novo->telefone = telefone;
        novo->DDD = DDD;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->alt = 0;
        *raiz = novo;
        return 1;
    }

    struct Usuario* atual = *raiz;
    if (telefone > atual->telefone) {
        if ((res = insere_Contato(&(atual->dir), DDD, telefone, nome, endereco)) == 1) {
            if (fatorBalanceamento(atual) >= 2) {
                if ((*raiz)->dir->telefone < telefone)
                    RotacaoRR(raiz);
                else
                    RotacaoRL(raiz);
            }
        }
    } else if (telefone < atual->telefone) {
        if ((res = insere_Contato(&(atual->esq), DDD, telefone, nome, endereco)) == 1) {
            if (fatorBalanceamento(atual) >= 2) {
                if (telefone < (*raiz)->esq->telefone)
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
            }
        }
    } else {
        return 0;
    }

    atual->alt = maior(alt_No(atual->esq), alt_No(atual->dir)) + 1;
    return res;
}


int remove_Contato(AVLDDD *raiz, int telefone){
    if((*raiz) == NULL)
        return 0;

    int res;
    if(telefone < (*raiz)->telefone){
        if((res = remove_Contato(&(*raiz)->esq, telefone)) == 1){
            if(fatorBalanceamento(*raiz) >= 2){
                if(alt_No((*raiz)->dir->esq) <= alt_No((*raiz)->esq->esq))
                    RotacaoRR(raiz);
                else
                    RotacaoRL(raiz);
            }
        }
    }
    if((*raiz)->telefone < telefone){
        if((res = remove_Contato(&(*raiz)->dir, telefone)) == 1){
            if(fatorBalanceamento(*raiz) >= 2){
                if(alt_No((*raiz)->esq->dir) <= alt_No((*raiz)->esq->esq))
                   RotacaoLL(raiz);
                else
                   RotacaoLR(raiz);
            }
        }
    }
    if((*raiz)->telefone == telefone){
        if(((*raiz)->esq == NULL || (*raiz)->dir == NULL)){
            struct Usuario* oldNode = (*raiz);
            if((*raiz)->esq != NULL)
               *raiz = (*raiz)->esq;
            else
               *raiz = (*raiz)->dir;
            free(oldNode);
        }else{
            struct Usuario* temp = procuraMenor((*raiz)->dir);
            (*raiz)->telefone = temp->telefone;
            strcpy((*raiz)->nome, temp->nome);
            strcpy((*raiz)->endereco, temp->endereco);
            remove_Contato(&(*raiz)->dir, (*raiz)->telefone);
            if(fatorBalanceamento(*raiz) >= 2){
                if(alt_No((*raiz)->esq->dir) <= alt_No((*raiz)->esq->esq))
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);

            }
        }
        if(*raiz != NULL)
            (*raiz)->alt = maior(alt_No((*raiz)->esq), alt_No((*raiz)->dir)) + 1;
        return 1;
    }
    (*raiz)->alt  = maior(alt_No((*raiz)->esq), alt_No((*raiz)->dir)) + 1;
    return res;
}
