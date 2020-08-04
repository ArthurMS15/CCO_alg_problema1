# CCO_alg_problema1
Trabalho final da disciplina de Algoritmos CCO_alg-IFC

Utilizar vetores e/ou matrizes dinâmico (ponteiros);
Utilizar estruturas de repetição;
Implementar utilizando modularização (no mínimo um módulo de procedimento e dois módulos de ação);
Utilizar passagem de parâmetro por valor e referência. É proibido usar variável global!;
Utilizar registros;
Utilizar alocação dinâmica de memória;
Trabalho individual.

Problema 1: Processamento de array
Este problema demonstra cálculos de um array de elementos 2D, onde uma função é avaliada sobre cada elemento (ou pequeno conjunto de elementos) do array. O cálculo é independente para cada elemento (ou conjunto) em relação aos outros elementos do array.

Um exemplo do código sequencial poderia ser:
do j = 1,n
    do i = 1,n
        a(i,j) = fcn(i,j)
    end do
end do

Exemplo de Aplicação prática: convolução 2D onde uma máscara de convolução (ou kernel) é aplicado sobre uma imagem para gerar uma imagem filtrada


# Resumo da Programação (retirado do relatório)

Assim como o problema já demonstra pelas imagens e textos disponibilizados, foi decidido começar por uma listagem de aspectos obrigatórios
para o algoritmo: 
1. Não houve uso de variável global; 
2. Estruturas de repetição;
3. Modularização (mín.: 1 módulo de procedimento e 2 de ação); 
4. Passagem de parâmetro por valor e referência; 
5. Registros; 
6. Alocação dinâmica de memória
7. Matrizes dinâmicas (ponteiros).

Antes de compreender o código em si é preciso ter a concepção de dois termos para a resolução do problema, que é convolução e kernel. 
Respectivamente o processo de convolução discreta, como é conhecido, envolve o processamento de imagens. A imagem original será interpretada pelo computador através de uma matriz com diferentes números, e essa matriz entrará em contato com outra matriz com valores já determinados chamada de “núcleo” ou “kernel”. Esse contato entre elas é representado através de uma função (que será abordada posteriormente), gerando então uma terceira matriz feita pelo contato entre a matriz original e a de kernel.


