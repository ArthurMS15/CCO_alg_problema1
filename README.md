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
