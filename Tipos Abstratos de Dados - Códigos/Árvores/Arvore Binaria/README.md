# Data-Structure---Binary-Tree

Código feito em **Linguagem C** de uma **Árvore Binária** criada a partir de nós(valores numéricos) e vértices, com **lógica de inserção (menores valores á
esquerda de um nó; maiores valores á direita do nó), de remoção(rearranja os nós segundo a ideia da inserção), de consulta e impressão(em ordem; ordem pré
e ordem posterior) de uma Árvore Binária Pura**.

### Árvore
* Abstração matemática usada para representar estruturas hierárquicas não lineares dos objetos modelados.
* Definida usando um conjunto de :
  * **Nós**(ou **vértices**): são os itens representados na árvore e dependem da natureza do problema modelo;
  * **Arestas**: são utilizadas para conectar qualquer par de nós ou vértices;

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/811f5a9f-a91d-4fec-95f2-4ce5959eda69)

1.**Notação**
  * **Raiz**: é o nó localizado na parte mais alta da árvore, o único não tem pai;
  * **Pai**: também chamado de ancestral, é o nó antecessor imediato de outro nó;
  * **Filho**: é o nó sucessor imediato de outro nó;
  * **Nó folha**: também chamado de nó terminal, é qualquer nó que não possui filhos;
  * **Nó interno**: também chamado de nó não terminal, é qualquer nó que possui ao menos um filho;
  * **Caminho**: é uma sequência de nós de modo que existe sempre uma aresta ligando o nó anterior com o seguinte
      * Existe exatamente um caminho entre a raiz e cada um dos nós da árvores.

  * **Grau de um nó e subárvores**
 
![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/c8c7be9a-5fc4-4cb1-bd7f-a1168e8e9d5f)

* **Altura e Nível**

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/a3bd7cc9-7f97-4966-8936-ab9237d3dc85)

2.**Tipos**:
* **Árvore binária de busca**
* **Árvore AVL**
* Árvore B, B+ e B*
* Árvore rubro-negra
* Árvore 2-3
* Árvore 2-3-4
* Quadtree
* Octree
* etc

3.**Árvore Binária**
- Tipo especial de árvore em que cada nó pode possuir **zero**, **uma** ou no máximo **duas** subárvores. Caso o nó possua nenhuma subárvore, este será um nó folha.

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/ec3961f2-5539-4550-a4b7-0d22ad26868e)

**Tipos de Árvores Binárias** - Diferem-se pelo número de subárvores de um nó e pelo posicionamento do nó na árvore:

 * a) *Estritamente binária*: Cada nó possui sempre **zero**(no caso do nó folha) ou **duas subárvores**. Não existe qualquer nó interno com apenas um filho, todos têm sempre dois.

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/8f8a9ac9-5c01-4490-bcf4-aa21c0c05cda)
 
 * b) *Cheia*: Se um nó tem alguma subárvore vazia então ele está no último nível.
 
 ![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/a212ec9c-fbec-4407-877b-f950bbf043ee)

 
*  c) *Completa*: Árvore estritamente binária na qual todos os seus nós estão no mesmo nível. É possível calcular o número de nós por nível, assim como o número total de nós da árvore:
      * Um nível *n* possui exatamente *2^n* nós;
      * Se um nível *n* possui *m* nós, o nível *n+1*, possuirá *2m* nós;
      * Um árvore de altura *H* possui *2^(H)- 1*.
      * **Árvore Binária Quase Completa**: A diferença de altura entre as subárvores de qualquer nó é, no máximo, 1. Ou seja, cada nó folha da árvore deve estar no dível *D* ou *D-1*

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/65e8078e-ab92-4081-a72e-d097f64db6eb)

* **Árvore Binária - Operações Básicas**
  * Criação de árvore
  * Inserção de um elemento
  * Remoção de um elemento
  * Busca por um elemento
  * Destruição da árvore
  * Informações como número de nós, altura ou se está vazia

-> Acesso Encadeado: Cada nó da árvore é um ponteiro para um estrutura contendo três campos de informação:

* **dado**: utilizado para armazenar a informação inserida na árvore;
* **esq**: (ponteiro para a subárvore da esquerda);
* **dir**: (ponteiro para a subárvore da direita);

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/b54998f6-35fe-4bc2-99d0-f137f3be3729)

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/599192fa-6e04-4ec3-98f6-0b262d62716d)

-> Árvore Binária como TAD

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/ce8121bb-67bc-4146-9f25-db38cdc232a9)

**Liberando uma Árvore Binária**
  * **Liberar árvore binária com alocação dinâmica e acesso encadeado** -> Percorrer toda a árvore liberando a memória alocada de cada nó inserido nela;
  * **Liberar um nó da árvore** -> Liberar a suas subárvores direita e esquerda. O nó se torna então um nó folha e pode ser liberado(sem prejuízos para o restante da árvore);

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/ad2b80a8-c691-4231-be59-48b3717dfa52)

**Altura da Árvore**

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/38ccab39-e434-4906-9584-a373c653d9bb)

**Percorrendo uma Árvore Binária** -> O(n) - **n**: número de nós

Não existe uma ordem "natural" para se percorrer todos os nós de uma árvore binária. Algumas formas são muito utilizadas. A diferença entre elas está na ordem em que cada nó é visitado ao longo do percurso.

* Percurso **pré-ordem**: visita **raiz**->filho da esquerda->filho da direita;

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/7dd25cf0-154f-4bec-88d3-cd8cac8afe70)

* Percurso **em-ordem**: visita filho da esquerda->**raiz**->filho da direita;

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/7f38eee8-fe18-4168-8c0a-9e183ea3e7a1)

* Percurso **pós-ordem**: visita filho da esquerda->filho da direita->**raiz**;

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/9d6b320b-1c3e-46ed-8c0b-12618c955948)

**Árvore Binária de Busca**
* Tipo especial de árvore binária;
* Possui as mesmas propriedades. No entanto, cada nó possui um valor (chave) associado a ele, que determina a posição do nó na árvore;
* Regra para posicionamento deos valores na árvore, para cada nó pai:
  * Todos os valores da subárvore **esquerda** são **menores** do que o nó pai;
  * Todos os valores da subárvore **direita** são **maiores** do que o nó pai;
* A inserção e remoção de nós na árvore binária de busca devem ser realizadas respeitando essa regra de posicionamento de nós;

Ex: Procurando o valor 30

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/f7b2f104-d78a-4622-8048-4ffe6c6be7ed)

Ex 2: Procurando o valor 28

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/97630e34-8894-4e05-8bc4-79fec0593304)

Os nós encontrados formam um caminho simples descendente, partindo da raiz da árvore, e portanto, o tempo de execução é *O(h)*, onde *h* é a altura da árvore.

**Inserindo um Nó em uma Árvore Binária de Busca**
1. Compare o valor a ser inserido com a raiz;
2. Se o valor for menos que a raiz: vá para a subárvore à esquerda;
3. Se o valor for maior que a raiz: vá para a subárvore à direita;
4. Aplique o método recursivamente(pode ser feito sem recursão) até cheagar a um nó folha;

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/a0c12167-1768-4415-8794-d7dee61399c8)

**Removendo um Nó de uma Árvore Binária de Busca**

Remover um nó de uma árvore binária de busca não é um tarefa tão simples quando uma inserção. O nó a ser removido da árvore pode ser:
* Um nó folha;

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/7cddeb62-ebda-4fec-928a-362bb8a77629)


* Um nó interno:
  * Pode ter um ou dois filhos;

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/561d3068-f96d-4f0d-9fc6-c32124087dc1)

  * Pode ser a raiz;
  * É preciso reorganizar  árvore para que ela continue sendo uma árvore binária de busca;

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/2b0615bf-9a79-4595-9c5d-90185df1cd4a)


**Código feito para Estudo da cadeira de Estrutura de Dados**
