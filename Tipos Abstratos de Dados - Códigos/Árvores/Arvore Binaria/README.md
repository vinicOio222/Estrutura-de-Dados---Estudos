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



**Código feito para Estudo da cadeira de Estrutura de Dados**
