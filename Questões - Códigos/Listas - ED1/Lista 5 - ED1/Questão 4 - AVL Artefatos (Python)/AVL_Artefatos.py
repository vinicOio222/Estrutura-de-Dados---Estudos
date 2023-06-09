class Artefato:
    def __init__(self, id, data):
        self.id = id
        self.data = data
        self.altura = 1
        self.esq = None
        self.dir = None

class ArvAVL :
    def __init__(self):
        self.raiz = None

    def insere_Artefato(self, id, data):
        self.raiz = self.insere_No(self.raiz, id, data)

    def insere_No(self, no, id, data):
        if no is None:
            return Artefato(id, data)
        elif data < no.data:
            no.esq = self.insere_No(no.esq, id, data)
        else:
            no.dir = self.insere_No(no.dir, id, data)

        no.altura = 1 + max(self.get_altura(no.esq), self.get_altura(no.dir))

        fator_balanceamento = self.get_fatorbalanceamento(no)

        if fator_balanceamento > 1:
            if data > no.esq.data:
                return self.rotacaoLL(no)
            else:
                no.esq = self.rotacaoRR(no.esq)
                return self.rotacaoLL(no)

        if(fator_balanceamento < -1):
            if data < no.dir.data:
                return self.rotacaoRR(no)
            else:
                no.dir = self.rotacaoLL(no.dir)
                return self.rotacaoRR(no)

        return no

    def get_altura(self, no):
        if no is None:
            return 0
        return no.altura

    def get_fatorbalanceamento(self, no):
        if no is None:
            return 0
        return self.get_altura(no.esq) - self.get_altura(no.dir)

    def rotacaoRR(self, no):
        no1 = no.dir
        no2 = no1.esq

        no1.esq = no
        no.dir = no2

        no.altura = 1 + max(self.get_altura(no.esq), self.get_altura(no.dir))
        no1.altura = 1 + max(self.get_altura(no1.esq), self.get_altura(no1.dir))

        return no1

    def rotacaoLL(self, no):
        no1 = no.esq
        no2 = no1.dir

        no1.dir = no
        no.esq = no2

        no.altura = 1 + max(self.get_altura(no.esq), self.get_altura(no.dir))
        no1.altura = 1 + max(self.get_altura(no1.esq), self.get_altura(no1.dir))

        return no1

    def getLastestArtifact(self):
        if self.raiz is None:
            return None

        atual = self.raiz
        while atual.dir is not None:
            atual = atual.dir

        return atual.id

    def getOldestArtifact(self):
        if self.raiz is None:
            return None
        atual = self.raiz
        while atual.esq is not None:
            atual = atual.esq

        return atual.id

    def imprimir_Arv(self):
        self.imprimir_No(self.raiz)

    def imprimir_No(self, no):
        if no is not None:
            self.imprimir_No(no.esq)
            print("-------------------------------")
            print("ID: ", no.id)
            print("Data de Descoberta: ", no.data)
            print("-------------------------------\n")
            self.imprimir_No(no.dir)


arvore = ArvAVL()              #'ano-dia-mês'
arvore.insere_Artefato(345133, '2003-27-01')
arvore.insere_Artefato(122455, '1990-04-10')
arvore.insere_Artefato(909283, '2007-18-12')
arvore.insere_Artefato(988231, '1945-08-05')
arvore.insere_Artefato(567522, '1974-26-09')
arvore.insere_Artefato(567522, '1930-24-10')

mais_antigo = arvore.getOldestArtifact()
mais_novo = arvore.getLastestArtifact()

print("Artefato mais antigo - ID: ", mais_antigo)
print("Artefato mais novo - ID: ", mais_novo)
print("\n===Lista de Artefatos===\n")
arvore.imprimir_Arv()
print("\nArtefato Raiz: ", arvore.raiz.id)



