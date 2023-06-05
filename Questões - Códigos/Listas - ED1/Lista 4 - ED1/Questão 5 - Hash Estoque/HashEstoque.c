#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"HashEstoque.h"

struct HashEstoque{
    int qtd, TABLE_SIZE;
    struct produto **itens;
};

Hash* criaHash(int tamanho){
    Hash* ha = (Hash*)malloc(sizeof(Hash));
    if(ha != NULL){
        ha->TABLE_SIZE = tamanho;
        ha->itens = (struct produto**)malloc(tamanho*sizeof(struct produto*));
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

int chaveDivisao(int chave, int TABLE_SIZE){
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

int insereHash_EncSep(Hash* ha, struct produto p){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;

    int chave = p.codigo;
    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    struct produto* novo = (struct produto*)malloc(sizeof(struct produto));
    if(novo == NULL)
       return 0;
    *novo = p;
    novo->prox = NULL;
    if(ha->itens[pos] == NULL){
        ha->itens[pos] = novo;
    }else{
        struct produto* aux = ha->itens[pos];
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    ha->qtd++;
    return 1;
}

int removeHash_EncSep(Hash* ha, int codigo){
    if(ha == NULL){
        printf("Erro: Tabela Hash não criada!\n");
        return 0;
    }
    if(ha->qtd == 0){
        printf("Erro: Tabela Hash vazia!\n");
        return 0;
    }
    int pos = chaveDivisao(codigo, ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL){
        printf("Produto com o código %d não encontrado!\n", codigo);
        return 0;
    }
    struct produto *atual = ha->itens[pos];
    struct produto *anterior = NULL;
    while(atual != NULL){
        if(codigo == atual->codigo){
            if(anterior == NULL)
               ha->itens[pos] = atual->prox;
            else{
            anterior->prox = atual->prox;
            }
            free(atual);
            ha->qtd--;
            printf("Produto com o código %d removido com sucesso!\n", codigo);
            return 0;
        }
    anterior = atual;
    atual = atual->prox;
    }
    return 0;
}

int buscaHash_EncSep(Hash* ha, int codigo){
    if(ha == NULL){
       printf("Erro: Tabela Hash não criada!\n");
       return 0;
    }
    int pos = chaveDivisao(codigo, ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL){
        printf("Produto com a código de barras %d não encontrado na tabela!\n", codigo);
        return 0;
    }
    struct produto* aux = ha->itens[pos];
    while(aux != NULL){
        if(codigo == aux->codigo){
            printf("\n===PRODUTO ENCONTRADO===\n");
            printf("Posição: %d\n", pos);
            printf("Nome: %s\n", ha->itens[pos]->nome);
            printf("Código: %d\n", ha->itens[pos]->codigo);
            printf("Preço: R$%.2f\n", ha->itens[pos]->preco);
            printf("Quantidade Disponível: %d\n", ha->itens[pos]->qtd);
            printf("-------------------------\n");
            return 1;
        }
        aux = aux->prox;

    }
    return 0;
}

int atualizaPreco(Hash* ha, int codigo, float preco) {
    if (ha == NULL) {
        printf("Erro: Tabela Hash não criada!\n");
        return 0;
    }
    int pos = chaveDivisao(codigo, ha->TABLE_SIZE);
    if (ha->itens[pos] == NULL) {
        printf("Produto com o código %d não encontrado!\n", codigo);
        return 0;
    }
    struct produto* aux = ha->itens[pos];
    while (aux != NULL) {
        if (codigo == aux->codigo) {
            aux->preco = preco;
            printf("Preço do produto com o código %d atualizado para R$%.2f.\n", codigo, preco);
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

void buscaMaisCaro(Hash* ha) {
    if (ha == NULL) {
        printf("Erro: Tabela Hash não criada!\n");
        return;
    }
    struct produto* produtoMaisCaro = NULL;
    for (int i = 0; i < ha->TABLE_SIZE; i++) {
        struct produto* aux = ha->itens[i];
        while (aux != NULL) {
            if (produtoMaisCaro == NULL || aux->preco > produtoMaisCaro->preco) {
                produtoMaisCaro = aux;
            }
            aux = aux->prox;
        }
    }

    if (produtoMaisCaro != NULL) {
        printf("\n===PRODUTO MAIS CARO===\n");
        printf("Nome: %s\n", produtoMaisCaro->nome);
        printf("Código: %d\n", produtoMaisCaro->codigo);
        printf("Preço: R$%.2f\n", produtoMaisCaro->preco);
        printf("Quantidade Disponível: %d\n", produtoMaisCaro->qtd);
        printf("==========================\n");
    } else {
        printf("Nenhum produto encontrado!\n");
    }
}

void imprimeHash(Hash* ha){
    if(ha == NULL){
        printf("Erro: Tabela Hash não criada!\n");
        return ;
    }
    if(ha->qtd == 0){
        printf("Erro: Tabela Hash vazia!\n");
        return;
    }
    printf("\n====Estoque de Produtos====\n");
    for(int i = 0; i<ha->TABLE_SIZE; i++){
        printf("Posição: %d\n", i);
        struct produto *aux = ha->itens[i];
        while(aux != NULL){
            printf("Nome: %s\n", aux->nome);
            printf("Código: %d\n", aux->codigo);
            printf("Preço: R$%.2f\n", aux->preco);
            printf("Quantidade Disponível: %d\n", aux->qtd);
            printf("\n");
            aux = aux->prox;
        }
        printf("-------------------\n");
    }

}

int main(){
    Hash *ha = criaHash(13);
    struct produto p1, p2, p3, p4, p5;
    strcpy(p1.nome, "Leite Itambé - 2L");
    p1.codigo = 1552553;
    p1.preco = 8.90;
    p1.qtd = 123;
    strcpy(p2.nome, "Cereal Nescau Radical - 300g");
    p2.codigo = 1665002;
    p2.preco = 11.99;
    p2.qtd = 908;
    strcpy(p3.nome, "Xampu Palmo Live");
    p3.codigo = 9823371;
    p3.preco = 29.53;
    p3.qtd = 33;
    strcpy(p4.nome, "Cerveja Skol - 2l");
    p4.codigo = 4444444;
    p4.preco = 8.74;
    p4.qtd = 16;
    strcpy(p5.nome, "Caneta Esfereográfica Bic");
    p5.codigo = 1010101;
    p5.preco = 1.90;
    p5.qtd = 367;
    insereHash_EncSep(ha, p1);
    insereHash_EncSep(ha, p2);
    insereHash_EncSep(ha, p3);
    insereHash_EncSep(ha, p4);
    insereHash_EncSep(ha, p5);
    buscaMaisCaro(ha);
    imprimeHash(ha);
    buscaHash_EncSep(ha, 9900000);
    buscaHash_EncSep(ha, 4444444);
    buscaHash_EncSep(ha, 9823371);
    removeHash_EncSep(ha, 9823371);
    buscaMaisCaro(ha);
    imprimeHash(ha);
    buscaHash_EncSep(ha, 9900000);
    buscaHash_EncSep(ha, 4444444);
    buscaHash_EncSep(ha, 9823371);
    atualizaPreco(ha, 4444444, 16.50);
    atualizaPreco(ha, 1010101, 2.50);
    buscaMaisCaro(ha);
    imprimeHash(ha);
    buscaHash_EncSep(ha, 9900000);
    buscaHash_EncSep(ha, 4444444);
    buscaHash_EncSep(ha, 9823371);

    return 0;
}
