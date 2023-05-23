# Data-Structure---Student-Hash-Table

* **Princípio do Método de Busca** - o mais ideal -> O(1)
  * Procurar a informação desejada com base na comparação de algum valor que compões as suas chaves.

### Tabelas Hash
* Tabela de indexação ou de espalhamento;
* É um generalização do array;

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/f422c997-14b0-4958-a78d-8083edd5c0b5)

* Permite a associação de valores a **chaves**;
  * A **chave** é uma parte da informação que compõe o elemento a ser inserido ou buscado na tabela, sendo o valor retornado pela função a posição (índice) em que o elemento se encontra na tabela.
  * A partir de uma chave podemos acessar de forma rápida determinada posição do array.
* **Ideia Central**: utiliza uma função chamada **função de hashing**, para espalhar os elementos a serem armazenados na tabela(de maneira não ordenada);
* **Colisão**: ocorrência de duas ou mais chaves na tabela hash com o mesmo valor de posição.
* Ao escolher o tamanho da tabela hash, o ideal é escolher um número primo e evitar valores que sejam uma potência de dois, reduzindo assim a probabilidade de colisões.

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/6fb4a260-e9bb-41c7-afea-cbdf9f15f4b6)

* **Função de Hashing**
  * Calcula posições na tabela por meio de uma chave escolhida a partir dos dados manipulados.

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/95c40ee1-a770-4fd9-a1c1-4019292dcef3)

**Métodos de Cálculo da Posição na Tabela Hash**:
 * **Método da Divisão** : calcular o resto da divisão do valor inteiro que representa o elemento pelo tamanho da tabela, TABLE_SIZE. No entanto, valores diferentes podem resultar na mesma posição. **Ex**:

                      11 % 10 = 1
                      21 % 10 = 1

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/77eea9d9-b8ae-48b3-a10e-35ac6a219f1a)

 * **Método da Multiplicação** : utiliza uma constante fracionária A, **0<A<1**, para multiplicar o valor da chave que representa o elemento. Em seguida, a parte fracionária é multiplicada pelo tamanho da tabela para calcular a posição do elemento. **Ex**: chave = 123456, A = 0.618, TABLE_SIZE = 1024

                     - Posição = ParteInteira(TABLE_SIZE * ParteFracionária(chave * A))
                     - Posição = ParteInteira(1024 * ParteFracionária(123456 * 0.618))
                     - Posição = ParteInteira(1024 * ParteFracionária(76295.808))
                     - Posição = ParteInteira(1024 * 0.808)
                     - Posição = ParteInteira(827.392)

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/53364c35-508e-4a05-9e22-02781cba4669)

 * **Método da Dobra**: utiliza um esquema de dobrar e somar os dígitos do valor para calcular a sua posição. Considera o valor inteiro que representa o elemento uma sequência de dígitos escritos em uma pedaço de papel. Enquanto este valor for maior que o tamanho da tabela, o papel é dobrado e os dígitos sobrepostos são somados, desconsiderando-se as dezenas.

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/1cf4b26b-caf7-4d44-b247-2499f6fabc8e)

Também pode ser aplicado para valores binários. Em vez de soma, deve ser utilizada a operação de "ou exclusivo". A dobra é realizada de k em k bits, o que resulta em um valor de posição entre 0 e 2^k - 1. **Ex**: k = 5

                        71(0001000111 em binário)        46(0000101110 em binário)
                        - Posição = 00010 ^ 00111        - Posição = 00001 ^ 01110
                        - Posição = 00101                - Posição = 01111
                        - Posição = 5                    - Posição = 15

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/235db820-f94e-4bbe-9dc6-e72f708a9f96)

Para o caso da chave ser uma string , deve-se calcular o valor numérico da mesma. O valor pode ser facilmente calculado somando os valores ASCII dos caracteres que compõem a string. O resultado dessa função pode ser utilizado como parâmetro para uma função de hashing.

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/16cc7596-7432-45c1-a431-53a3127ef347)

**Inserção e Busca** - Calcular a posição dos dados na tabela a partir de parte dos dados(chave) a serem inseridos e buscados.

  * **Sem Tratamento de Colisão**: neste caso não há nenhuma função auxiliar que previne que dois ou mais itens venham a ter a mesma chave e por consequência mesma posição;
    * Hashing Imperfeito: podem ocorrer colisões das chaves armazenadas;
    * Hashing Perfeito: chaves diferentes vão sempre produzir posições diferentes;

  * **Com Tratamento de Colisão**

    a) **Encadeamento Separado**: Armazena dentro de cada posição da tabela o início de uma lista dinâmica encadeada. É dentro desta lista que serão armazenadas as colisões (elementos com chaves iguais) para aquela posição da tabela.

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/6d804058-1152-4a2d-816d-f85bfd6d20e2)

  b) **Endereçamento Aberto**: Utiliza lugares vazios na própria tabela para resolver as colisões. Quando uma colisão ocorre, calcula-se uma nova posição da tabela. Se esta nova posição estiver ocupada, uma nova posição é calculada. O cálculo da posição é refeito até que uma posção vaga seja encontrada. Há **três estratégias** para isso:

1. *Sondagem Linear* - tenta espalhar os elementos de forma sequencial a partir da posição calculada utilizando a função de hashing.

                           Hj = (h(x)+j) mod M, para 1 <= j <= M-1.

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/6f8f8c08-1a34-4bcc-9117-17408db6c3e8)

 **Ex**: chaves : L U N E S;  M = 7

 ![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/f8df655b-1927-4582-b255-de1ad3b6ae6b)

 2. *Sondagem Quadrática* - a ideia agora é obter sequências de endereços diversos para endereços-base próximos, porém diferentes.

                          Hj = (h(x) + c1k + c2k^2)) mod M, para 1<=j<=M-1

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/e026a2a2-50b8-4e36-9a3f-0f1ab64d2dd3)

3. *Duplo Hash* - tenta espalhar os elementos utilizando duas funções de hashing.
    - 1ª função(H1) : calcula a **posição inicial do elemento**;
    - 2ª função(H2) : calcula o **deslocamento** em relação à posição inicial(no caso de uma colisão);

                         H1 + i * H2 (i é a tentativa atual de inserção do elemento)

![image](https://github.com/vinicOio222/Estrutura-de-Dados---Estudos/assets/101837153/fbd3ebff-02f6-490d-9480-df3c333ebb26)


**Projeto feito para estudo da cadeira de Estrutura de Dados**
