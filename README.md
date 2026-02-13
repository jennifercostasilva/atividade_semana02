# ANÁLISE DE ALGORITMOS - ARVORES E GRAFOS

# Sobre a atividade:
Esta atividade teve como objetivo implementar dois algoritmos clássicos de ordenação: Bubble Sort e Selection Sort, utilizando a linguagem C.

Os algoritmos foram aplicados em vetores preenchidos em ordem decrescente (pior caso), com os seguintes tamanhos:

- 100 elementos;
- 1000 elementos;
- 10000 elementos;

Para cada execução, foram medidos:

- Tempo de execução (em ms), utilizando clock();
- Número de comparações;
- Número de movimentações;

| Algoritmo      | Tamanho | Tempo (ms) | Comparações | Movimentações |
| -------------- | ------- | ---------- | ----------- | ------------- |
| Bubble Sort    | 100     | 0.000      | 4950        | 4950          |
| Selection Sort | 100     | 0.000      | 4950        | 50            |
| Bubble Sort    | 1000    | 3.000      | 499500      | 499500        |
| Selection Sort | 1000    | 1.000      | 499500      | 500           |
| Bubble Sort    | 10000   | 389.000    | 49995000    | 49995000      |
| Selection Sort | 10000   | 197.000    | 49995000    | 5000          |


# Análise
A partir dos resultados, foi possível observar que ambos os algoritmos apresentam crescimento quadrático no número de comparações, o que confirma a complexidade O(n²).

No entanto, existe uma diferença significativa no número de movimentações:

- O Bubble Sort realiza uma troca sempre que encontra dois elementos fora de ordem, o que gera um número muito alto de movimentações.

- O Selection Sort, por outro lado, realiza apenas uma troca por posição, reduzindo bastante esse número.

Essa diferença impactou diretamente o tempo de execução, principalmente para vetores maiores.
Nos testes realizados, o Selection Sort apresentou melhor desempenho geral, principalmente devido ao menor número de movimentações.

# Conclusão
Ambos os algoritmos funcionam corretamente, porém tornam-se pouco eficientes para grandes volumes de dados devido à complexidade O(n²).

Entre os dois, o Selection Sort demonstrou melhor desempenho nos testes realizados, sendo mais eficiente em termos de movimentações e tempo de execução.
