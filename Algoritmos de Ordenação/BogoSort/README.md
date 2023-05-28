# Sorting-Algorithm---Bogosort

Este código implementa o algoritmo de ordenação **Bogosort** em C, que é um **algoritmo de ordenação aleatória que não tem garantia de ordenar corretamente todos os elementos da lista**. O algoritmo funciona da seguinte forma:

* Inicializa um array com números aleatórios;
* Verifica se o array está ordenado. Se não estiver, embaralhe aleatoriamente os elementos do array;
* Repete as etapas 2 e 3 até que o array esteja ordenado;

### Funções

* **is_sorted**: Essa função recebe um ponteiro para o array a ser verificado e o tamanho do array como parâmetros. A função percorre o array do início ao fim e compara cada elemento com o elemento anterior. Se o elemento atual for menor que o anterior, a função retorna 0 (falso), indicando que o array não está ordenado. Se todos os elementos estiverem ordem, retorna 1 (verdadeiro), ou seja, array ordenado.

* **shuffle**: Essa função recebe um ponteiro para o array a ser embaralhado e o tamanho do array como parâmetros. A função usa a função **rand()** da biblioteca **stdlib** para gerar um número aleatório entre 0 e o tamanho do array - 1. Em seguida, a função troca o elemento atual do array com o elemento aleatório gerado. Isso simula a aleatoriedade do algoritmo de ordenação.

* **bogosort**: Essa função recebe um ponteiro para o array a ser ordenado e o tamanho do array como parâmetros. A função inicia um contador de iterações e percorre o array do início ao fim. Se o array não estiver ordenado, a função embaralha aleatoriamente os elementos do array e incrementa o contador de iterações. A função continua percorrendo o array até que o array esteja ordenado. Quando o array estiver ordenado, a função imprime o número de iterações e o array ordenado.

### Complexidade do Código

* **Melhor Caso** - O(n): Todos os elementos do array estão ordenados ou são idênticos. Portanto, o algoritmo vai percorrer o array (tamanho n), verificando que o array já está ordenado e a função **is_sorted** retornando 1 e a função **bogosort** não precisando realizar mais nenhuma iteração.

* **Pior Caso** - O(n*n!): Todos os elementos são distintos e estão desordenados, sendo que o algoritmo que segue a ideia a mesma ideia do **teorema do macaco infinito**, ou seja , **existe alguma probabilidade de que aconteça a permutação correta**.
