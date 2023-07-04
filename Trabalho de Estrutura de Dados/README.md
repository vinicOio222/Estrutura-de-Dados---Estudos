# Sistema Nacional de Catálogo de Telefones - Tabela Hash, Árvore AVL e Lista Encadeada

Este código em **linguagem C** implementa um **sistema de gerenciamento de registros de telefone**. Cada contato possui **nome, telefone e endereço**. Foram implementadas
as estruturas de dados **Tabela Hash**, **Árvore AVL** e **Lista Encadeada**. O desenvolvimento deste programa seguiu as seguintes funcionalidades requisitadas para
o projeto:

* **PRIMEIRA PARTE**
  
Criar uma árvore AVL para cada DDD. Cada nó da árvore corresponde a um
usuário de celular e deve conter as seguintes informações: número do telefone
sem DDD, nome e endereço. Os códigos DDD a serem inseridos devem ser
informados pelo usuário do sistema.

* **SEGUNDA PARTE**
  
Criar a tabela hash contendo os endereços de cada árvore. A escolha da função
hashing é livre (escolha a que considerar mais interessante para o problema).
Para tratamento de colisões, deve ser utilizado encadeamento separado.

* **TERCEIRA PARTE**
  
*Acessar as informações*

1. Encontrar o nome e o endereço de um usuário a partir de um dado número
de telefone.
2. Remover o número de telefone de um usuário descadastrado do sistema
   - Informar a altura da árvore antes e depois da remoção.
3. Listar todos os números de telefone de uma determinada área (DDD), de
acordo com os seguintes percursos:
   - Pré-ordem
   -  Em-ordem
   - Pós-ordem
4. Ao ser solicitado um novo número de telefone para um novo registro em
um determinado DDD, sugerir três números de telefone que ainda não
estejam em uso.
5. Gerar uma lista telefônica, por DDD, com as informações cadastradas de
cada usuário, considerando dois tipos de ordenação:
   - Por número de telefone
   - Por nome do usuário
6. Realizar uma busca aproximada por número de telefone, onde o sistema
deve retornar os números de telefone que correspondam parcialmente a
um dado número fornecido. Por exemplo, se o número fornecido for
"1234", o sistema deve retornar números como "123456", "412345", entre
outros. Explore técnicas de busca eficiente, como índices invertidos ou
árvores de sufixos, para melhorar o desempenho desta operação.
7. Implementar um mecanismo de detecção de duplicatas utilizando uma
tabela hash. Durante a inserção de novos registros, o sistema deve
verificar se o número de telefone ou o nome já existem na estrutura de
dados, evitando a inserção de duplicatas. Utilize uma tabela hash com
tratamento de colisões por encadeamento separado para realizar essa
detecção.

**Projeto feito para a Conclusão dos Estudos da Cadeira de Estrutura de Dados**
