typedef struct No* ArvBin;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
void libera_No(struct No* no);
int insere_ArvBin(ArvBin* raiz, int valor);
int consulta_ArvBin(ArvBin* raiz, int valor);
int maiorValor_ArvBin(ArvBin* raiz);
int mediaValores_ArvBin(ArvBin* raiz);
int numeroNULLS_ArvBin(ArvBin* raiz);
int somaChaves_Nos(ArvBin* raiz);
int multTres_Nos(ArvBin* raiz);
int totalNo_ArvBin(ArvBin* raiz);
int totalFolhas_ArvBin(ArvBin* raiz);
int altura_ArvBin(ArvBin* raiz);
int verifica_ArvBin(ArvBin* raiz);
void preOrdem_ArvBin(ArvBin* raiz);
void emOrdem_ArvBin(ArvBin* raiz);
void posOrdem_ArvBin(ArvBin* raiz);
