#define MAX_EXPR 100

struct pilha{
    char dados[MAX_EXPR];
    int topo;

};

typedef struct pilha Pilha;
void empilhar(Pilha* pi, char elementos);
char desempilhar(Pilha* pi);
int checarParenteses(char *expressao);
