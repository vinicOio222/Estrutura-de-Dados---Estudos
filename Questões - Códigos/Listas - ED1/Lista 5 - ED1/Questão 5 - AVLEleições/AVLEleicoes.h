struct Candidato{
    int numero;
    int votos;

};

typedef struct NoListado* Lista;
typedef struct No* ArvEleicoes;

ArvEleicoes* cria_ArvAVL();
Lista* cria_Lista();
int insereLista(Lista* li, int numero, int votos);
void libera_Lista(Lista* li);
void libera_ArvAVLeLista(ArvEleicoes* raiz, Lista* li);
void libera_No(struct No* no);
int insere_Candidato(ArvEleicoes* raiz, Lista* li, int numero, int votos);
int remove_Candidato(ArvEleicoes* raiz, Lista* li,  int numero);
void imprime_Resultados(ArvEleicoes* raiz);
