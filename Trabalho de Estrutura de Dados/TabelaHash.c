#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"TabelaHash.h"
#include"ArvAVLDDD.c"
#include"Lista.c"

struct TabelaHash{
    int TABLE_SIZE, qtd;
    struct HashNo** itens;
};

Hash* criaHash(int TABLE_SIZE){
    Hash* ha = (Hash*)malloc(sizeof(Hash));
    if(ha != NULL){
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct HashNo**)malloc(TABLE_SIZE*sizeof(struct HashNo*));
        if(ha->itens == NULL){
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for(int i = 0; i<ha->TABLE_SIZE; i++)
           ha->itens[i] = NULL;
    }
    return ha;

}

void liberaHash(Hash* ha){
    if(ha != NULL){
        for(int i = 0; i<ha->TABLE_SIZE; i++){
            if(ha->itens[i] != NULL)
                free(ha->itens[i]);
        }
        free(ha->itens);
        free(ha);
    }
}

int metodoDivisao(int TABLE_SIZE, int DDD){
    return DDD % TABLE_SIZE;
}

int verificaDuplicatas(Hash*ha, int telefone, char nome[]){
    if(ha == NULL){
        printf("Catalogo de contatos vazio!\n");
        return 0;
    }
    for(int i = 0; i<ha->TABLE_SIZE; i++){
        struct HashNo* aux = ha->itens[i];
        while(aux != NULL){
            struct Registro* atual = aux->li->itens;
            while(atual != NULL){
                if(atual->telefone == telefone){
                    printf("Contato com telefone duplicado!\nTel: %d\n\n", telefone);
                    return 1;
                }
                if(strcmp(atual->nome, nome) == 0){
                    printf("Contato com nome duplicado!\nNome: %s\n\n", nome);
                    return 1;
                }
                atual = atual->prox;
            }
            aux = aux->prox;
        }
    }
    return 0;
}

int insereContato_Hash(Hash* ha, int DDD, int telefone, char nome[], char endereco[]){
    int pos = metodoDivisao(ha->TABLE_SIZE, DDD);
    if (verificaDuplicatas(ha, telefone, nome))
        return 0;

    struct HashNo* aux = ha->itens[pos];
    while (aux != NULL) {
        if (aux->DDD == DDD) {
            insere_Contato(aux->raiz, DDD, telefone, nome, endereco);
            insereRegistro_Ordenado(aux->li, telefone, nome, endereco);
            ha->qtd++;
            return 1;
        }
        aux = aux->prox;
    }

    AVLDDD* raiz = cria_AVL();
    insere_Contato(raiz, DDD, telefone, nome, endereco);
    Lista* liDDD = criaLista(DDD);
    insereRegistro_Ordenado(liDDD, telefone, nome, endereco);
    struct HashNo* novo = (struct HashNo*)malloc(sizeof(struct HashNo));
    if (novo == NULL)
        return 0;

    novo->raiz = raiz;
    novo->DDD = DDD;
    novo->li = liDDD;
    novo->prox = ha->itens[pos];
    ha->itens[pos] = novo;

    ha->qtd++;
    return 1;
}

int removeContato_Hash(Hash* ha, int DDD, int telefone) {
    if (ha == NULL || ha->qtd == 0) {
        printf("Catalogo de contatos vazio!\n");
        return 0;
    }

    int pos = metodoDivisao(ha->TABLE_SIZE, DDD);
    if (ha->itens[pos] == NULL) {
        printf("Posicao vazia no catalogo!\n\n");
        return 0;
    }

    struct HashNo* aux = ha->itens[pos];
    while (aux != NULL) {
        if (DDD == aux->DDD) {
            if (aux->raiz != NULL) {
                AVLDDD* raiz = aux->raiz;
                printf("\n\n* Altura da AVLDDD antes da remocao: %d\n", altura_AVL(raiz));
                int removido = remove_Contato(aux->raiz, telefone);
                if (removido == 1) {
                    removeRegistro(aux->li, telefone);
                    ha->qtd--;
                    printf("\n* Altura da AVLDDD apos a remocao: %d\n\n", altura_AVL(raiz));
                    printf("Contato removido com sucesso! Retornando ao Menu Principal...\n");
                    return 1;
                } else {
                    printf("Contato com telefone %d nao encontrado!\n", telefone);
                    return 0;
                }
            } else {
                printf("DDD %d nao possui contatos cadastrados!\n", DDD);
                return 0;
            }
        }
        aux = aux->prox;
    }

    printf("DDD %d nao cadastrado no catalogo!\n\n", DDD);
    return 0;
}

struct Usuario* buscaContato_Hash(Hash* ha, int DDD, int telefone) {
    if (ha == NULL || ha->qtd == 0){
        return NULL;
    }else{
        int pos = metodoDivisao(ha->TABLE_SIZE, DDD);
        struct HashNo* aux = ha->itens[pos];

        while (aux != NULL) {
            if (DDD == aux->DDD) {
                struct Usuario* resultado = buscaContato(aux->raiz, telefone);
                if (resultado != NULL)
                    return resultado;
            }
         aux = aux->prox;
        }
    }
    return NULL;
}

void imprimeHash_emOrdem(Hash* ha){
    if(ha == NULL){
       printf("Erro: Catalogo não criado!\n");
       return;
    }
    if(ha->qtd == 0){
        printf("Catalogo de contatos vazio!\n");
        return;
    }
    printf("==== Catalogo Nacional de Contatos =====\n\n");
    for(int i = 0; i < ha->TABLE_SIZE; i++){
        printf("~ Posicao[%d]\n", i);
        if(ha->itens[i] != NULL) {
            struct HashNo* aux = ha->itens[i];
            int ultimoDDD = -1;
            while(aux != NULL){
                emOrdemHash(aux->raiz, &ultimoDDD, 0);
                aux = aux->prox;
            }
        }
    }
    printf("\n Total de Contatos: %d\n", ha->qtd);
    printf("======================================\n\n");
}

void preOrdem_DDD(Hash* ha, int DDD){
    int pos = metodoDivisao(ha->TABLE_SIZE, DDD);
    if(ha->itens[pos] == NULL){
        printf("DDD %d nao cadastrado no catálogo!\n",DDD);
        return;
    }
    printf("==== Contatos de DDD %d em Pre-Ordem ====\n\n", DDD);
    struct HashNo* aux = ha->itens[pos];
    while(aux != NULL){
        if(DDD == aux->DDD)
            preOrdem(aux->raiz);
        aux = aux->prox;
    }
}

void emOrdem_DDD(Hash* ha, int DDD){
    int pos = metodoDivisao(ha->TABLE_SIZE, DDD);
    if(ha->itens[pos] == NULL){
        printf("DDD %d nao cadastrado no catalogo!\n",DDD);
        return;
    }
    printf("==== Contatos de DDD %d em Em Ordem ====\n\n", DDD);
    struct HashNo* aux = ha->itens[pos];
    while(aux != NULL){
        if(DDD == aux->DDD)
            emOrdem(aux->raiz);
        else{
            printf("DDD %d nao cadastrado no catalogo!\n",DDD);
            break;
        }
        aux = aux->prox;
    }
}

void posOrdem_DDD(Hash* ha, int DDD){
    int pos = metodoDivisao(ha->TABLE_SIZE, DDD);
    if(ha->itens[pos] == NULL){
        printf("DDD %d nao cadastrado no catálogo!\n",DDD);
        return;
    }
    printf("==== Contatos de DDD %d em Pos-Ordem ====\n\n", DDD);
    struct HashNo* aux = ha->itens[pos];
    while(aux != NULL){
        if(DDD == aux->DDD)
            posOrdem(aux->raiz);
        aux = aux->prox;
    }
}

void inicializaGeradorAleatorio() {
    srand(time(NULL));
}

int geraTelefones() {
    int telefone = (rand() % 10000000) + 990000000;
    char numeroFormatado[10];
    sprintf(numeroFormatado,"%03d", telefone);
    telefone = atoi(numeroFormatado);
    return telefone;
}

int geraSugestao(Hash* ha, int DDD, int telefone){
    int pos = metodoDivisao(ha->TABLE_SIZE, DDD);
    struct HashNo* aux = ha->itens[pos];
    while(aux != NULL){
        if(DDD == aux->DDD){
            int resultado = busca_Numero(aux->raiz,telefone);
            if(resultado == 0){
                return telefone;
            }else{
                return 0;
            }
        }
        aux = aux->prox;
    }
    return 0;
}

void exibirListaNomes(Hash* ha, int DDD){
    int pos = metodoDivisao(ha->TABLE_SIZE, DDD);
    if(ha == NULL || ha->qtd == 0){
       printf("Catalogo de contatos vazio!\n");
       return;
    }
    struct HashNo* aux = ha->itens[pos];
    while(aux != NULL){
        if(DDD == aux->li->DDD){
           printf("**** Lista Telefonica em Ordem Alfabetica do DDD %d ****\n", DDD);
           listaTelefonicaNome(aux->li);
           break;
        }else{
           printf("O DDD %d nao foi cadastrado no Catalogo!\n", DDD);
           break;
        }
        aux = aux->prox;
    }
}

void exibirListaNumeros(Hash* ha, int DDD){
    int pos = metodoDivisao(ha->TABLE_SIZE, DDD);
    printf("**** Lista Telefonica em Ordem Crescente de Numero do DDD %d ****\n", DDD);
    struct HashNo* aux = ha->itens[pos];
    while(aux != NULL){
        if(DDD == aux->DDD)
            emOrdem(aux->raiz);
        else{
            printf("DDD %d nao cadastrado no catalogo!\n",DDD);
            break;
        }
        aux = aux->prox;
    }
}

int contemTelefone(int telefone, int valorBusca) {
    char telefoneStr[11];
    char buscaStr[11];
    sprintf(telefoneStr, "%d", telefone);
    sprintf(buscaStr, "%d", valorBusca);
    return strstr(telefoneStr, buscaStr) != NULL;
}

void buscaAproximadaNumero(Hash* ha, int valorBusca) {
    printf("~~~~~~ Resultados aproximados para o numero %d ~~~~~~\n", valorBusca);
    for (int i = 0; i < ha->TABLE_SIZE; i++) {
        struct HashNo* aux = ha->itens[i];
        while (aux != NULL) {
            Lista* li = aux->li;
            struct Registro* atual = li->itens;
            while (atual != NULL) {
                if (contemTelefone(atual->telefone, valorBusca)) {
                    printf("DDD: %d\n", aux->DDD);
                    printf("Telefone: %d\n", atual->telefone);
                    printf("Nome: %s\n", atual->nome);
                    printf("Endereco: %s\n\n", atual->endereco);
                }
                atual = atual->prox;
            }
            aux = aux->prox;
            break;
        }
    }
}
