typedef struct Usuario* AVLDDD;

AVLDDD* cria_AVL();
void libera_AVL(AVLDDD* raiz);
int altura_AVL(AVLDDD* raiz);
int maior(int x,int y);
int fatorBalanceamento(struct Usuario* user);
int totalNo_AVL(AVLDDD* raiz);
int insere_Contato(AVLDDD* raiz, int DDD, int telefone, char nome[], char endereco[]);
int busca_Numero(AVLDDD* raiz, int telefone);
void busca_MenorNum(AVLDDD* raiz);
int remove_Contato(AVLDDD* raiz, int telefone);
void preOrdem(AVLDDD* raiz);
void emOrdem(AVLDDD* raiz);
void posOrdem(AVLDDD* raiz);
void emOrdemHash(AVLDDD*raiz, int *ultimoDDD,int nivel);

