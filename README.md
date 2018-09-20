# Dijkstra-Kruskal-Prim

Algoritmo de grafos que possui: Algoritmo de Djikstra, Prim e Kruskal.

## Motivação

A principal função do projeto é entender o funcinamento dos seguintes algoritmos: 
[Djikstra](https://pt.wikipedia.org/wiki/Algoritmo_de_Dijkstra "Dijkstra"),
[Prim](https://pt.wikipedia.org/wiki/Algoritmo_de_Prim "Prim") e 
[Kruskal](https://pt.wikipedia.org/wiki/Algoritmo_de_Kruskal "Kruskal")
O algoritmo foi desenvolvido para a disciplina de Estruturas de Dados 2, do curso de Ciências da Computação da UPF, em 2017.

## Entrada

A única forma de entrada do algoritmo é através de um arquivo texto (.txt), onde deve ser escrito o grafo que será lido pelo algoritmo, o nome do arquivo deverá ser informado no terminal e caso o arquivo não
esteja no mesmo diretório, este deverá ser informado também (ex: `Testes/e1`).
O padrão para a entrada deve ser: primeiro informa-se o número vertices, em seguida informa-se os n vertices,
com um identificador qualquer (ex: `V01`, `V02`, etc...); 
após deve ser informado o número de arestas, seguido das n arestas, com o identificador qualquer da aresta, os vertices que a ligam, e seu
respectivo peso (ex: `A01 V01 V02 23`).

## Exemplo

Exemplo de grafo que pode ser lido pelo algoritmo: (Existem alguns exemplos na pasta 'Testes')

`5` - `(Número de Vertices)`

`V01`

`V02`

`V03`

`V04`

`V05`

`7` - `(Número de Arestas)`

`A01 V01 V02 23`

`A02 V02 V04 22`

`A03 V04 V01 123`

`A04 V03 V01 1`

`A05 V02 V03 44`

`A06 V03 V05 18`

`A07 V01 V05 99`

## Operação Kruskal

 O algoritmo de Kruskal consiste em solucionar o caminho mais curto entre dois vertices presentes em um grafo. 
 Então após a leitura do grafo deve-se informar a letra `D` no terminal para indicar que deseja realizar o Kruskal, 
 em seguida deve ser informado o vertice de origem e o de destino (ex: `V01 V05`).
 
 Assim o Algoritmo ira retornar o caminho percorrendo todos os vertices e
 informar o peso do menor caminho possível entre a origem e o destino.
 
 ## Operação de Prim
 
 O algoritmo de Prim, é um algoritmo que tentará encontrar a árvore geradora mínima para determinado grafo, ou seja,
 o algoritmo irá transformar o grafo em uma árvore, partindo de determinado vertice.
 Então após a leitura do grafo deve-se informar a letra `P` no terminal para indicar que deseja realizar o Prim, em seguida
 deve ser informado o vertice que será o ponto de partida da árvore, a 'raiz'.
 
 ## Operação de Kruskal
 
 A função do algoritmo de kruskal é a mesma do algoritmo de prim, gerar uma Árvore Geradora Mínima, mas seu funcionamento 
 se difere bastante, enquanto o Prim gera uma árvore única, Kruskal gera uma floresta, que em seguida será transformada em uma Árvore Geradora Mínima
 Para a realização do algoritmo de Kruskal deve-se ler o grafo anteriormente e informar a opção `K` no terminal, em seguida informar 
 o vertice que será o ponto de partida da árvore, a 'raiz'.
 
 ## Informações do código
 
 O Algoritmo foi desenvolvido em C++, seu arquivo fonte está com o nome de 'Trabalho Grafos', e os outros códigos, Kruskal, Prim, etc, estão em formato 
 `.h` arquivo header.
 
 ## Desenvolvedor
 
  Bruno de Almeida Zampirom 
  brunozampirom@outlook.com / 
  158788@upf.br

Universidade de Passo Fundo - ICEG
Ciências da Computação
 
 
