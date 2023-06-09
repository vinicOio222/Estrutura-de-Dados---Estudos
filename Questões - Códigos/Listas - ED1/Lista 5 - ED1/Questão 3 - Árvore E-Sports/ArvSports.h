typedef struct No* ArvSports;

ArvSports* cria_Arv();
void libera_No(struct No* no);
void libera_Arv(ArvSports* raiz);
int insere_Time(ArvSports* raiz, char nome[], int pontos);
int alteraPontos_Time(ArvSports* raiz, char nome[], int novos_pontos);
void classificao_Arv(ArvSports* raiz);

