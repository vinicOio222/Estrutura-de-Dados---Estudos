#include<stdio.h>
#include<stdlib.h>
#include"AVLEleicoes.h"

struct No{
    int numero;
    int votos;
    int alt;
    struct No* esq;
    struct No* dir;
};

struct NoListado{
    struct Candidato dados;
    struct NoListado *prox;
};

ArvEleicoes* cria_ArvAVL(){
    ArvEleicoes* raiz = (ArvEleicoes*)malloc(sizeof(ArvEleicoes));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}


Lista* cria_Lista(){
    Lista* li = (Lista*)malloc(sizeof(Lista));
    if(li != NULL)
      *li = NULL;
    return li;
}

void libera_Lista(Lista* li){
    if(li != NULL){
        struct NoListado* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

void libera_No(struct No* no){
    if(no == NULL)
       return;
    libera_No(no->esq);
    libera_No(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvAVLeLista(ArvEleicoes* raiz, Lista* li){
    if(raiz == NULL)
       return;
    libera_No(*raiz);
    free(raiz);
    libera_Lista(li);
}


int alt_No(struct No* no){
    if(no == NULL)
       return -1;
    else
       return no->alt;
}

int altura_ArvAVL(ArvEleicoes* raiz){
    if(raiz == NULL)
       return 0;
    if(*raiz == NULL)
       return 0;
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));
    if(alt_esq > alt_dir)
       return(alt_esq + 1);
    else
       return(alt_dir + 1);

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

void RotacaoLL(ArvEleicoes* raiz){
    struct No* no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->alt = maior(alt_No((*raiz)->esq), alt_No((*raiz)->dir));
    no->alt = maior(alt_No(no->esq), (*raiz)->alt) + 1;
    *raiz = no;
}

void RotacaoRR(ArvEleicoes* raiz){
    struct No* no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = (*raiz);
    (*raiz)->alt = maior(alt_No((*raiz)->esq), alt_No((*raiz)->dir)) + 1;
    no->alt = maior(alt_No(no->esq), (*raiz)->alt) + 1;
    *raiz = no;
}

void RotacaoLR(ArvEleicoes* A){
    RotacaoRR(&(*A)->esq);
    RotacaoLL(A);
}

void RotacaoRL(ArvEleicoes* A){
    RotacaoLL(&(*A)->dir);
    RotacaoRR(A);
}

int insereLista(Lista* li, int numero, int votos){
    if(li == NULL)
       return 0;
    struct NoListado* no = (struct NoListado*)malloc(sizeof(struct NoListado));
    if(no == NULL)
       return 0;
    no->dados.numero = numero;
    no->dados.votos = votos;
    no->prox = NULL;
    if(*(li) == NULL){
        *li = no;
    }else{
        struct NoListado* aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

void imprimeLista(Lista* li){
    if(li == NULL)
      return;
    struct NoListado* no = *li;
    int i = 1;
    while(no != NULL ){
        printf("Nº: %d\n", no->dados.numero);
        printf("Votos: %d\n", no->dados.votos);
        printf("---------------------------\n");
        no = no->prox;
    }
}

int busca_Votos(Lista* li, int numero) {
    if (li == NULL || *li == NULL)
        return 0;

    struct NoListado* no = *li;
    while (no != NULL) {
        if (no->dados.numero == numero) {
            return no->dados.votos;
        }
        no = no->prox;
    }
    return 0;
}


int insere_Candidato(ArvEleicoes* raiz, Lista* li, int numero, int votos){
    int res;
    if(*raiz == NULL){
        struct No* novo = (struct No*)malloc(sizeof(struct No));
        if(novo == NULL)
           return 0;

    novo->numero = numero;
    novo->votos = votos;
    novo->alt = 0;
    novo->dir = NULL;
    novo->esq = NULL;
    *raiz = novo;
    insereLista(li, numero, votos);
    return 1;
    }

    struct No* atual = *raiz;
    if(votos < atual->votos){
        if((res = insere_Candidato(&(atual->esq),li,numero, votos)) == 1){
            if(fatorBalanceamento_No(atual) >= 2){
                if(votos < (*raiz)->esq->votos)
                   RotacaoLL(raiz);
                else
                   RotacaoLR(raiz);
            }
        }
    }else{
        if(votos > atual->votos){
            if((res = insere_Candidato(&(atual->dir), li, numero, votos)) == 1){
                if(fatorBalanceamento_No(atual) >= 2){
                    if((*raiz)->dir->votos < votos)
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

int remove_Candidato(ArvEleicoes *raiz, Lista* li,  int numero){
    if((*raiz) == NULL)
        return 0;

    int res;
    int votos = busca_Votos(li, numero);
    if(votos < (*raiz)->votos){
        if((res = remove_Candidato(&(*raiz)->esq, li, numero)) == 1){
            if(fatorBalanceamento_No(*raiz) >= 2){
                if(alt_No((*raiz)->dir->esq) <= alt_No((*raiz)->esq->esq))
                    RotacaoRR(raiz);
                else
                    RotacaoRL(raiz);
            }
        }
    }
    if((*raiz)->votos < votos){
        if((res = remove_Candidato(&(*raiz)->dir,li, numero)) == 1){
            if(fatorBalanceamento_No(*raiz) >= 2){
                if(alt_No((*raiz)->esq->dir) <= alt_No((*raiz)->esq->esq))
                   RotacaoLL(raiz);
                else
                   RotacaoLR(raiz);
            }
        }
    }
    if((*raiz)->votos == votos){
        if(((*raiz)->esq == NULL || (*raiz)->dir == NULL)){
            struct No* oldNode = (*raiz);
            if((*raiz)->esq != NULL)
               *raiz = (*raiz)->esq;
            else
               *raiz = (*raiz)->dir;
            free(oldNode);
        }else{
            struct No* temp = procuraMenor((*raiz)->dir);
            (*raiz)->votos = temp->votos;
            (*raiz)->numero = temp->numero;
            remove_Candidato(&(*raiz)->dir, li, (*raiz)->numero);
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


void imprime_Resultados(ArvEleicoes* raiz){
    if(raiz == NULL)
       return;
    if(*raiz != NULL){
        imprime_Resultados(&((*raiz)->dir));
        printf("------------------------------\n");
        printf("Nº do Candidato: %d\n", (*raiz)->numero);
        printf("Total de Votos: %d\n", (*raiz)->votos);
        printf("------------------------------\n");
        imprime_Resultados(&((*raiz)->esq));
    }
}

int main(){
    ArvEleicoes* raiz = cria_ArvAVL();
    Lista* li = cria_Lista();
    printf("++++Inserindo Candidatos++++\n");
    insere_Candidato(raiz, li,  12, 190);
    insere_Candidato(raiz, li,  20, 90);
    insere_Candidato(raiz, li, 19, 175);
    insere_Candidato(raiz, li, 34, 65);
    insere_Candidato(raiz, li,  27, 203);
    insere_Candidato(raiz, li, 39, 119);
    imprime_Resultados(raiz);
    printf("\nCandidato raiz: %d\n", (*raiz)->numero);
    printf("\nFator de Balanceamento da Raiz: %d\n", fatorBalanceamento_No((*raiz)));
    printf("----Removendo Candidatos----\n");
    remove_Candidato(raiz, li, 34);
    imprime_Resultados(raiz);
    printf("\nCandidato raiz: %d\n", (*raiz)->numero);
    printf("\nFator de Balanceamento da Raiz: %d\n", fatorBalanceamento_No((*raiz)));
    printf("%d\n",busca_Votos(li, 34));
    libera_ArvAVLeLista(raiz, li);

    return 0;

}
