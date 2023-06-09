typedef struct No* ArvBinLivros;

ArvBinLivros* cria_ArvBin();
void libera_ArvBin(ArvBinLivros* raiz);
void libera_No(struct No* no);
int insere_Livro(ArvBinLivros* raiz, char nome[], char autor[], int id, int ano);
void consulta_Livro(ArvBinLivros* raiz, char autor[], int ano1, int ano2);
void imprime_Biblioteca(ArvBinLivros* raiz);


