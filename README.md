# Resumo da Programação (retirado do relatório)
## Tarefas iniciais realizadas:

Assim como o problema demonstra pelas imagens e textos, foi decidido começar pela listagem de aspectos obrigatórios para o algoritmo disponibilizados pelo orientador: Não houve uso de variável global; estruturas de repetição; modularização (mín.: 1 módulo de procedimento e 2 de ação); passagem de parâmetro por valor e referência; registros; alocação dinâmica de memória e matrizes dinâmicas (ponteiros).

Para o código é preciso ter a concepção do processo de convolução discreta, que envolve o processamento de imagens. A imagem original será interpretada pelo computador através de uma matriz com diferentes números, e essa matriz entrará em contato com outra matriz com valores já determinados chamada de “núcleo” ou “kernel”.                               
O contato entre elas é representado através de uma função, gerando então uma outra matriz filtrada feita pelo contato entre a matriz original e a de Kernel.

**Figura 1 – Exemplo atrelado a imagem original e como o computador a interpreta.**
![convolucao-2](https://github.com/ArthurMS15/CCO_alg_problema1/blob/master/convolucao-2.png)                                                                                   
**Fonte: ELO7 (2020).**

## Construção do algoritmo e resultados:

No início do código, contém as bibliotecas: *<stdio.h>* e *<stdlib.h>*, possibilitando o funcionamento do mesmo, além da declaração das constantes *TAM*, sendo a quantidade de números que podem ter dentro da matriz, e *LINHA* e *COLUNA* representando as dimensões da matriz original.                                                                     
Em seguida é feita a declaração do registro, que conterá as informações das dimensões (linha e coluna) da matriz (gerada aleatoriamente entre 0 e 15).             
Depois há a prototipação, sendo toda a modularização feita no algoritmo (havendo a passagem de parâmetro por valor e referência).

Dentro da função *int main*, teremos a variável *matriz1* para o registro *sDimensaoMatriz*, tendo assim as variáveis *matriz1.linha* e *matriz1.coluna* dentro de suas funções: *int EscolhaLinhaMax* e *int EscolhaColunaMax*. 
Vale ressaltar que foram criadas as variáveis *linhamax* e *colunamax*, sendo essas o valor retornado das funções citadas anteriormente.

Em seguida é criada duas variáveis (*matriz* e *matrizaux*), com ambas tendo um ponteiro (linha) dentro de outro ponteiro (coluna) e sendo atreladas a seus respectivos módulos: "int** CriarMatriz" e "int** CriarMatrizAuxiliar", formando assim o registro e alocação dinâmica de memória para as linhas e colunas.

O motivo da existência de duas matrizes, se deve que a função que gera a nova matriz alteraria os valores de dentro da matriz original, sendo assim a matriz original passaria pelo processo de convolução considerando valores já alterados dentro da mesma, ou seja, não se baseando nos valores originais, sendo assim, os resultados são passados para a segunda matriz, não alterando os valores na matriz principal.

Posteriormente, encontra-se os módulos *void EscolhaValoresDentroMatriz* e *void EscreverValoresDentroMatriz*, onde o primeiro indica os valores inteiros gerados aleatoriamente entre 0 e 255 (código de cores RGB, mas sem ter 3 valores em cada coordenada) dentro da matriz, baseada também nas dimensões que ele havia escolhido anteriormente, já o outro módulo mostrará a matriz completa.

O próximo módulo na função *int main* é *void ProcessoConvolucaoEscolhaKernel*. Nele será encontrado outras funções, como no caso: *int EscolhaKernel*, onde dependendo do número escolhido, leva para um filtro diferente que modifica a matriz, variando entre 6 filtros (*KernelCaso1*, *KernelCaso2* e etc), além de posteriormente com a alteração dos valores, será escrito a nova matriz formada através da original e do filtro escolhido. Por último há uma outra função *void FinalizarPrograma*. Por conta de cada um dos casos apresentarem um filtro diferente, a função de como esses valores são calculados muda em cada um dos casos.

**Figura 2 – Parte do código exemplificando o parágrafo anterior.**
![algoritmo](https://github.com/ArthurMS15/CCO_alg_problema1/blob/master/algoritmo.png)                                                                                         
**Fonte: O Autor (2020).**

Com relação a função do caso kernel 1, essa é sua forma no código, adaptando isso para um desenho da matriz fica dessa forma (seguindo o mesmo padrão para os outros filtros):

**Figura 3 – Exemplo da função mostrada na figura anterior.**
![convolucao-algoritmo](https://github.com/ArthurMS15/CCO_alg_problema1/blob/master/convolucao-algoritmo.png)                                                                   
**Fonte: O Autor (2020).**    

Considerando os dados da figura acima e colocando-os na função mostrada na figura 2 seria resolvido dessa forma:

**Figura 4 – Desenvolvimento da função.**
![convolucao-algoritmo2](https://github.com/ArthurMS15/CCO_alg_problema1/blob/master/convolucao-algoritmo2.png)                                                                 
**Fonte: O Autor (2020).**

Vale ressaltar que caso não houvesse a *matrizaux*, o resultado para o número original “2” não seria igual, pois sofreria a influência do outro número original “5” que agora nessa etapa já teria se transformado em “-4”, dando em seu resultado “-(-4)+2=6” sendo então, incorreto.

Seguindo com o algoritmo, o resultado no final é visto da seguinte forma:

**Figura 5 – Resultado da função.**                                                                                                                                             
![resultado-convolucao](https://github.com/ArthurMS15/CCO_alg_problema1/blob/master/resultado-convolucao.png)                                                                   
**Fonte: O Autor (2020).**

No resultado, todos os valores na borda da matriz são ignorados e são apenas mostrados os que não se encontram consequentemente na primeira ou última linha e na primeira e última coluna.
Para finalizar então é retornado à função *int main* onde será realizada a desalocação da memória com a função *void DesalocaMatrizeMatrizaux*, desalocando então as informações que haviam sido armazenadas em "int** matriz" e “int** matrizaux".

# Referências

CASTRO, Wellington. **DIP03 – Matriz de convolução e detecção de bordas.** Disponível em: <https://capivararex.wordpress.com/2016/04/25/dip03-matriz-de-convolucao-e-deteccao-de-bordas/>. Acesso em: 18 jul. 2020.

DOCS.GIMP. **Matriz de convolução.** Disponível em: <https://docs.gimp.org/2.8/pt_BR/plug-in-convmatrix.html>. Acesso em: 18 jul. 2020.

ELO7. **Princípios de Processamento de Imagens: Uma introdução à Convolução.** Disponível em: <https://elo7.dev/convolucao/>. Acesso em: 18 jul. 2020.

UFPR. **Exame Final de Algoritmos e Estruturas de Dados I.** Disponível em: <http://www.inf.ufpr.br/cursos/ci055/Provas_antigas/final-20181.pdf>. Acesso em: 18 jul. 2020.

