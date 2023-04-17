#define MAX 100

struct pilhadupla{
    int A[MAX];
    int topo1;
    int topo2;
};

typedef struct pilhadupla PilhaDupla;

void criarPilha(PilhaDupla *pi);
int pilhaCheia(PilhaDupla *pi);
int pilhaVazia1(PilhaDupla *pi);
int pilhaVazia2(PilhaDupla *pi);
void empilhar(PilhaDupla *pi, int i, int x);
int desempilhar(PilhaDupla *pi, int i);
void imprimirPilhaDupl(PilhaDupla* pi);

