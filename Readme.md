# Trabalho Prático 1 - Algoritmos e Estruturas de Dados III

- **Disciplina**: Algoritmos e Estruturas de Dados III
- **Curso**: Ciência da Computação
- **Instituição**: Universidade Federal de São João Del Rei
- **Docente**: Leonardo Chaves Dutra da Rocha
- **Data**: 13 de Abril de 2023

## 📖 Objetivo:

O objetivo deste trabalho é resolver um problema de geometria computacional envolvendo a conexão de pontos em um plano com a condição de que os segmentos de reta, ao serem desenhados entre os pontos e duas âncoras fixas, **não se interceptem** fora das âncoras. As âncoras são representadas pelos pontos \(A = (X_A, 0)\) e \(B = (X_B, 0)\), com \(0 < X_A < X_B\).

Dado um conjunto de **N pontos** no plano com coordenadas \((X_i, Y_i)\), onde \(X_i > 0\) e \(Y_i > 0\), a tarefa é encontrar a **máxima quantidade de pontos** que podem ser conectados aos dois pontos âncoras **A** e **B**, sem que as linhas que ligam esses pontos se cruzem fora das âncoras.

## 🖥️ Tecnologias

- **Linguagem**: C
- **Ambiente**: Linux

## 📝​ Descrição do Projeto

[Ver descrição](./descricao.pdf)

## 📚 Documentação do Projeto

[Ver documentação](./documentacao.pdf)

## 📥 Entrada

O programa recebe como entrada um arquivo de texto com a seguinte estrutura:

1. **N**, **XA**, **XB**: O número de pontos e as coordenadas das âncoras A e B.
2. **N linhas** com os pontos, onde cada ponto é descrito por suas coordenadas **Xi** e **Yi**.

### Exemplo de entrada:

```
4 1 10
2 4
5 1
6 5
7 8
```

## 🖨️ Saída

A saída deve imprimir uma linha contendo um inteiro, representando o número máximo
de pontos de P que podem ser ligados com interseção de segmentos apenas nas âncoras.

### Exemplo de saída:

```
3
```

## ✏️ Instruções

### ⚒️ Compilação

- Compilar os arquivos:
```
make
````

- Limpar os arquivos:
```
make clean
```

### 🚀 Execução

````
./tp1 -i <entrada.txt> -o <saida.txt>
````

⚠️ ***Obs***: entrada.txt é o nome do arquivo de teste que será lido e saida.txt é o arquivo de saída com a solução final.
