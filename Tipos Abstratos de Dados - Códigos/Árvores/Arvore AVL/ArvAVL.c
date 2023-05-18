#include<stdio.h>
#include<stdlib.h>
#include"ArvAVL.h"

struct No{
    int info;
    int alt;
    struct No *esq;
    struct No *dir;
};

ArvAVL* cria_AVL(){
    ArvAVL* raiz = (ArvAVL*)malloc(sizeof(ArvAVL));
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

void libera_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    libera_No(*raiz);
    free(raiz);
}

int alt_No(struct No* no){
    if(no == NULL)
       return -1;
    else
       return no->alt;
}

int estaVazia_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNo_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int total_esq = totalNo_ArvAVL(&((*raiz)->esq));
    int total_dir = totalNo_ArvAVL(&((*raiz)->dir));
    return(total_esq + total_dir + 1);
}

int altura_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return 0;
    if(*raiz ==  NULL)
        return 0;
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));
    if(alt_esq > alt_dir)
        return(alt_esq + 1);
    else
        return(alt_dir + 1);
}

void preOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->info);
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
    }
}

void emOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
       return;
    if(*raiz != NULL){
        emOrdem_ArvAVL(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        emOrdem_ArvAVL(&((*raiz)->dir));
    }
}

void posOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
       return;
    if(*raiz != NULL){
        posOrdem_ArvAVL(&((*raiz)->esq));
        posOrdem_ArvAVL(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info);
    }
}

int consulta_ArvAVL(ArvAVL *raiz, int valor){
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

int fatorBalanceamento_No(struct No* no){
    return labs(alt_No(no->esq) - alt_No(no->dir));
}

int maior(int x, int y){
    if(x > y)
       return x;
    else
       return y;
}

void RotacaoLL(ArvAVL *raiz){
    struct No *no;
    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->alt = maior(alt_No((*raiz)->esq), alt_No((*raiz)->dir)) + 1;
    no->alt = maior(alt_No(no->esq), (*raiz)->alt) + 1;
    *raiz = no;
}

void RotacaoRR(ArvAVL *raiz){
    struct No *no;
    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = (*raiz);
    (*raiz)->alt = maior(alt_No((*raiz)->esq),alt_No((*raiz)->dir)) + 1;
    no->alt = maior(alt_No(no->dir), (*raiz)->alt) + 1;
    (*raiz) = no;
}

void RotacaoLR(ArvAVL* A){
    RotacaoRR(&(*A)->esq);
    RotacaoLL(A);
}

void RotacaoRL(ArvAVL* A){
    RotacaoLL(&(*A)->dir);
    RotacaoRR(A);
}

int insere_ArvAVL(ArvAVL *raiz, int valor){
    int res;
    if(*raiz == NULL){
        struct No* novo;
        novo = (struct No*)malloc(sizeof(struct No));
        if(novo == NULL)
           return 0;

    novo->info = valor;
    novo->alt = 0;
    novo->dir = NULL;
    novo->esq = NULL;
    *raiz = novo;
    return 1;
    }

    struct No *atual = *raiz;
    if(valor < atual->info){
        if((res = insere_ArvAVL(&(atual->esq), valor)) == 1){
            if(fatorBalanceamento_No(atual) >= 2){
                if(valor < (*raiz)->esq->info)
                   RotacaoLL(raiz);
                else
                   RotacaoLR(raiz);
            }

        }
    }else{
        if(valor > atual->info){
            if((res = insere_ArvAVL(&(atual->dir), valor)) == 1){
                if(fatorBalanceamento_No(atual) >= 2){
                   if((*raiz)->dir->info < valor)
                       RotacaoRR(raiz);
                    else
                       RotacaoRL(raiz);

               }
            }

       }else
           return 0;
    }
    atual->alt = maior(alt_No(atual->esq), alt_No(atual->dir)) + 1;
    return res;
}

struct No* procuraMenor(struct No* atual){
    struct No* no1 = atual, *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

int remove_ArvAVL(ArvAVL *raiz, int valor){
    if((*raiz) == NULL)
        return 0;

    int res;
    if(valor < (*raiz)->info){
        if((res = remove_ArvAVL(&(*raiz)->esq, valor)) == 1){
            if(fatorBalanceamento_No(*raiz) >= 2){
                if(alt_No((*raiz)->dir->esq) <= alt_No((*raiz)->esq->esq))
                    RotacaoRR(raiz);
                else
                    RotacaoRL(raiz);
            }
        }
    }
    if((*raiz)->info < valor){
        if((res = remove_ArvAVL(&(*raiz)->dir, valor)) == 1){
            if(fatorBalanceamento_No(*raiz) >= 2){
                if(alt_No((*raiz)->esq->dir) <= alt_No((*raiz)->esq->esq))
                   RotacaoLL(raiz);
                else
                   RotacaoLR(raiz);
            }
        }
    }
    if((*raiz)->info == valor){
        if(((*raiz)->esq == NULL || (*raiz)->dir == NULL)){
            struct No* oldNode = (*raiz);
            if((*raiz)->esq != NULL)
               *raiz = (*raiz)->esq;
            else
               *raiz = (*raiz)->dir;
            free(oldNode);
        }else{
            struct No* temp = procuraMenor((*raiz)->dir);
            (*raiz)->info = temp->info;
            remove_ArvAVL(&(*raiz)->dir, (*raiz)->info);
            if(fatorBalanceamento_No(*raiz) >= 2){
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

int main(){
    ArvAVL* raiz = cria_AVL();
    printf("Inserção na Árvore AVL:\n");
    insere_ArvAVL(raiz, 10);
    posOrdem_ArvAVL(raiz);
    printf("\n");
    printf("Raiz: %d\n",(*raiz)->info);
    printf("\n");
    insere_ArvAVL(raiz, 20);
    posOrdem_ArvAVL(raiz);
    printf("\n");
    printf("Raiz: %d\n",(*raiz)->info);
    printf("\n");
    insere_ArvAVL(raiz, 50);
    posOrdem_ArvAVL(raiz);
    printf("\n");
    printf("Raiz: %d\n",(*raiz)->info);
    printf("\n");
    insere_ArvAVL(raiz, 12);
    posOrdem_ArvAVL(raiz);
    printf("\n");
    printf("Raiz: %d\n",(*raiz)->info);
    printf("\n");
    printf("Remoção na Árvore AVL:\n");
    remove_ArvAVL(raiz, 50);
    emOrdem_ArvAVL(raiz);
    printf("\n");
    printf("Raiz: %d\n",(*raiz)->info);
    printf("\n");
    remove_ArvAVL(raiz, 20);
    posOrdem_ArvAVL(raiz);
    printf("\n");
    printf("Raiz: %d\n",(*raiz)->info);
    printf("\n");
    remove_ArvAVL(raiz, 12);
    posOrdem_ArvAVL(raiz);
    printf("\n");
    printf("Raiz: %d\n",(*raiz)->info);
    printf("\n");
    remove_ArvAVL(raiz, 10);
    posOrdem_ArvAVL(raiz);
    printf("\n");
    libera_ArvAVL(raiz);
    return 0;
}
