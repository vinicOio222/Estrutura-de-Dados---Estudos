# Data-Structure---AVL-Tree

Código feito em **Linguagem C** de uma **Árvore AVL** criada a partir de nós(valores numéricos) e vértices, com **lógica de inserção (menores valores á esquerda de um nó; maiores valores á direita do nó), de remoção(rearranja os nós segundo a ideia da inserção)**.

Tais inserções e remoções passam pelo **critério de balanceamento(fator de balanceamento - fb)**:

O **fator de balanceamento** trata-se da diferença entre as alturas das subárvores esquerda e direita da raiz -> **fb = AE-AD**, sendo seus valores de equilíbrio **-1<=fb<=1**. Para isso, há as seguintes rotações:

**Simples**

   -> **LL**: Rotação à Direita: nós com ambos fb positivos; **Ex**:  C(fb = 0)<-B(fb = +1)<-A(fb = +2)

   -> **RR**: Rotação à Esquerda: nós com ambos fb negativos **Ex**:  C(fb = 0)<-B(fb = -1)<-A(fb = -2)

**Compostas**

   -> **LR**: Rotação à Esquerda e à Direita: nós com fb de sinais diferentes (nó pai positivo e nó filho negativo);
   **Ex**:  C(fb = 0)<-B(fb = -1)<-A(fb = +2)

   -> **RL**: Rotação à Esquerda e à Direita: nós com fb de sinais diferentes (nó pai negativo e nó filho positivo);
   **Ex**:  C(fb = 0)<-B(fb = +1)<-A(fb = -2)


A consulta e impressão(em ordem; ordem pré e ordem posterior) de uma Árvore AVL**.

**Código feito para Estudo da cadeira de Estrutura de Dados**
