#include"ArvAVLDDD.h"
#include"Lista.h"

struct HashNo{
    int DDD;
    AVLDDD *raiz;
    Lista* li;
    struct HashNo* prox;
};

typedef struct TabelaHash Hash;

Hash* criaHash(int TABLE_SIZE);
void liberaHash(Hash* ha);
int insereContato_Hash(Hash* ha, int DDD, int telefone, char nome[], char endereco[]);
int removeContato_Hash(Hash* ha, int DDD, int telefone);
struct Usuario* buscaContato_Hash(Hash* ha, int DDD, int telefone);
void imprimeHash_emOrdem(Hash* ha);
int verificaDuplicatas(Hash*ha, int telefone, char nome[]);
void preOrdem_DDD(Hash* ha, int DDD);
void emOrdem_DDD(Hash* ha, int DDD);
void posOrdem_DDD(Hash* ha, int DDD);
int geraTelefones();
void exibirListaNomes(Hash* ha, int DDD);
void exibirListaNumeros(Hash* ha, int DDD);
void buscaAproximadaNumero(Hash* ha, int valorBusca);


