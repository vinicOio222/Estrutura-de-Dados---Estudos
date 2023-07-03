typedef struct ListaTelefonica Lista;

Lista* criaLista(int DDD);
void liberaLista(Lista* li);
int insereRegistro_Ordenado(Lista* li, int telefone,  char nome[], char endereco[]);
int removeRegistro(Lista* li, int telefone);
void consultaAproximada(Lista* li, int telefone);
void listaTelefonicaNome(Lista* li);
