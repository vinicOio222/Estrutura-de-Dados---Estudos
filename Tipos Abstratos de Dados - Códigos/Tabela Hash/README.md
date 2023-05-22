# Data-Structure---Student-Hash-Table

Código de uma **Tabela Hash** feita em C que possui uma **struct aluno** cujos dados são nome, matrícula e 3 notas. Suas operações seguem
a ideia de uma função hash que armezena os dados em forma de pares de chaves e valores numa tabela. Possui operações como **inicializar a tabela hash**, **liberar a tabela hash**,**criar uma chave pelo método de divisão**, **as inserções na Tabela Hash com e sem o tratamento de colisão**, **busca do elemento aluno pela sua chave matrícula
com e sem o tratamento de colisão**, **a sondagem linear - que evita a colisão de dados e ajuda na realocação do dado** ; e por fim **a impressão da tabela hash com
a posição do aluno na mesma**.

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



**Projeto feito para estudo da cadeira de Estrutura de Dados**
